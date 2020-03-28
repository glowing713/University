#!/usr/bin/env python
# coding: utf-8

# In[1]:


# TensorBoard에 의하여 가시화하는데 있어서는 tf.summary.FileWriter를 이용하여 필요한 정보를 저장
import tensorflow as tf

LOG_DIR = './logs'

a = tf.constant(1, name='a')
b = tf.constant(1, name='b')
c = a + b

graph = tf.get_default_graph()
with tf.summary.FileWriter(LOG_DIR) as writer:
    writer.add_graph(graph)


# In[4]:


# TensorBoard에 점 하나 찍는 예제
import tensorflow as tf

a = tf.constant(3.0)
b = tf.constant(5.0)
c = a * b

# tensorboard에 point라는 이름으로 표시됨
c_summary = tf.summary.scalar('point', c)
merged = tf.summary.merge_all()

with tf.Session() as sess:
    writer = tf.summary.FileWriter('./board/sample_1', sess.graph)
    
    result = sess.run([merged])
    sess.run(tf.global_variables_initializer())
    
    writer.add_summary(result[0])


# In[28]:


# 2개의 직선 출력
import tensorflow as tf

tf.reset_default_graph() #

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

add = tf.add(X, Y)
mul = tf.multiply(X, Y)

# step 1: node 선택
add_hist = tf.summary.scalar('add_scalar', add)
mul_hist = tf.summary.scalar('mul_scalar', mul)

# step 2: summary 통합. 두 개의 코드 모두 동작
merged = tf.summary.merge_all()
# merged = tf.summary.merge([add_hist, mul_hist])

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    
    # step 3: writer 생성
    writer = tf.summary.FileWriter('./board/sample_2', sess.graph)
    
    for step in range(100):
        # step 4: 노드 추가
        summary = sess.run(merged, feed_dict={X: step*1.0, Y: 2.0})
        writer.add_summary(summary, step)
        
# step 5: 콘솔에서 명령 실행
# tensorboard --logdir=./board/sample_2
# 콘솔폴더가 현재폴더(.)가 아니라면, 절대 경로 지정
# tensorboard --logdir=~/PycharProjects/test/board/sample_2


# In[ ]:





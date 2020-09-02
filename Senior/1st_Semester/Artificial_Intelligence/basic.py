#!/usr/bin/env python
# coding: utf-8

# In[31]:


import tensorflow as tf

a = tf.constant(1, name='a')
b = tf.constant(1, name='b')
c = a + b

'''
sess = tf.Session()
print(sess.run(c))
sess.close()
이걸 간단하게 한 표현이 아래와 같다.
'''
with tf.Session() as sess:
    print(sess.run(c))  # 여기에서 실제 연산이 수행


# In[8]:


import tensorflow as tf

a = tf.constant(1, name='a')
b = tf.constant(1, name='b')
c = a + b

print(c)


# In[11]:


import tensorflow as tf

a = tf.constant(1, name='a')
b = tf.constant(1, name='b')
c = a + b

# 그래프 흐름의 정의 표시
graph = tf.get_default_graph()
print(graph.as_graph_def())


# In[13]:


import tensorflow as tf

a = tf.Variable(1, name='a')
b = tf.constant(1, name='b')
c = tf.assign(a, a + b)  # "a에 a+b의 값을 대입해서 대입 후의 a값을 리턴한다."

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())  # 모든 변수들을 일괄적으로 초기화 (변수를 이용할 경우에 세션시작에 반드시 초기화해야함)
    print('1회째: [c,a] = ', sess.run([c,a]))
    # 변수 c가 갱신되고 있다.
    print('2회째: [c,a] = ', sess.run([c,a]))


# In[52]:


import tensorflow as tf

a = tf.Variable(1, name='a')
b = tf.constant(1, name='b')
c = tf.assign(a, a + b)
d = tf.assign(b, a + b)  # 상수인 변수 b의 값을 변경하려해서 오류가 뜬다.
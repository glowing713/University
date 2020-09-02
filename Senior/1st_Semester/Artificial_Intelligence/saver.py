#!/usr/bin/env python
# coding: utf-8

# In[2]:


import tensorflow as tf

a = tf.Variable(1, name='a')
b = tf.assign(a, a + 1)

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    print('1회째 b = ', sess.run(b))
    print('2회째 b = ', sess.run(b))
    
# 세션이 바뀌면 본래의 값으로 되돌아 감
with tf.Session() as sess:
    print('-- 새로운 세션 --')
    sess.run(tf.global_variables_initializer())
    print('1회째 b = ', sess.run(b))
    print('2회째 b = ', sess.run(b))    


# In[8]:


import tensorflow as tf

a = tf.Variable(1, name='a')
b = tf.assign(a, a + 1)

saver = tf.train.Saver()

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    print(sess.run(b))
    print(sess.run(b))
    # 변수 값을 model/model.ckpt에 저장한다
    saver.save(sess, 'model/model.ckpt')
    
# Saver을 이용하면
# saver = tf.train.Saver()
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    # model/model.ckpt로부터 변수 값을 다시 저장한다.
    saver.restore(sess, save_path='model/model.ckpt')
    print(sess.run(b))
    print(sess.run(b))
    


# In[ ]:





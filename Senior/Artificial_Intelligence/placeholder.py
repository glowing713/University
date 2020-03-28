#!/usr/bin/env python
# coding: utf-8

# In[22]:


import tensorflow as tf

a = tf.placeholder(dtype=tf.int32, name='a')  # a를 int32 데이터형을 갖는 플레이스홀더로 정의(shape 생략)
b = tf.constant(1, name='b')
c = a + b

'''
placeholder의 전달 파라미터
placeholder {
    dtype,  // dtype: 데이터 타입을 의미하며 반드시 적어주어야 한다.
    shape=None,  // shape: 입력 데이터의 형태를 의미한다. 상수 값이 될 수도 있고 다차원 배열이 들어올 수도 있다. (디폴트 파라미터로 None 지정)
    name=None  // name: 해당 placeholder의 이름을 부여하는 것으로 적지 않아도 된다. (디폴트 파라미터로 None 지정)
}
'''

with tf.Session() as sess:
    print('a + b = ', sess.run(c, feed_dict={a: 1}))  # 세션을 통하여 그래프를 실행할 때 feed_dict 변수를 이용하여 플레이스홀더 a에 1을 피드


# In[29]:


import tensorflow as tf

a = tf.constant(2, name='a')
b = tf.constant(3, name='b')
c = tf.add(a, b)  # equals to a + b
d = tf.multiply(a, b)  # equals to a * b

with tf.Session() as sess:
    print('a + b = ', sess.run(c))
    print('a * b = ', sess.run(d))


# In[36]:


# 벡터 연산
import tensorflow as tf

a = tf.constant([1, 2, 3], name='a')
b = tf.constant([4, 5, 6], name='b')
c = a + b

with tf.Session() as sess:
    print('a + b = ', c)


# In[38]:


# 행렬 연산
import tensorflow as tf

a = tf.constant([[1, 2], [3, 4]], name='a')
b = tf.constant([[1], [2]], name='b')
c = tf.matmul(a, b)

print('shape of a: ', a.shape)
print('shape of b: ', b.shape)
print('shape of c: ', c.shape)

with tf.Session() as sess:
    print('a = \n', sess.run(a))
    print('b = \n', sess.run(b))
    print('c = \n', sess.run(c))


# In[48]:


import tensorflow as tf

a = tf.placeholder(shape=(None, 2), dtype=tf.int32, name='a')  # 텐서 크기가 미정인 상태일 때, 그 차원 방향에 대하여 None을 지정

with tf.Session() as sess:
    print('-- [[1, 2]]를 대입 --')
    print('a = ', sess.run(a, feed_dict={a: [[1, 2]]}))
    print('\n-- [[1, 2], [3, 4]]를 대입 --')
    print('a = ', sess.run(a, feed_dict={a: [[1, 2], [3, 4]]}))
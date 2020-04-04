#!/usr/bin/env python
# coding: utf-8

# In[10]:


# 경사하강법에 의한 2차 함수의 최소화
import tensorflow as tf

# 매개변수는 변수로서 정의
x = tf.Variable(0., name='x')
# 매개변수를 사용해서 최소화하고자 하는 함수를 정의
func = (x - 1)**2

# learning_rate는 한 번에 이동시키는 크기를 결정
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1)

# train_step이 x를 조금씩 이동시키는 동작을 나타냄
train_step = optimizer.minimize(func)

# train_step을 반복해서 실행
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    for i in range(200):
        sess.run(train_step)
    print('x = ', sess.run(x))


# In[26]:


## 데이터 집합(Data Set) 준비 ##
import keras

(x_train, y_train), (x_test, y_test) = tf.keras.datasets.boston_housing.load_data()


# In[27]:


## 학습 데이터 (x_train, y_train) 분석 ##
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.size'] = 10
plt.rcParams['figure.figsize'] = [12, 8]

plt.hist(y_train, bins=20)
plt.xlabel('Housing price($1,000 units)')
plt.ylabel('Number of data')
plt.show()
plt.plot(x_train[:,5], y_train, 'o')
plt.xlabel('Number of rooms')
plt.ylabel('Housing price($1,000 units)')


# In[28]:


## 데이터 표준화 ##

x_train_mean = x_train.mean(axis=0)
x_train_std = x_train.std(axis=0)
y_train_mean = y_train.mean(axis=0)
y_train_std = y_train.std(axis=0)

x_train = (x_train - x_train_mean)/x_train_std
y_train = (y_train - y_train_mean)/y_train_std

# x_test에 대해서도 x_train_mean 와 x_train_std을 사용함
x_test = (x_test - x_train_mean)/x_train_std
# y_test에 대해서도 y_train_mean 와 y_train_std을 사용함
y_test = (y_test - y_train_mean)/y_train_std

plt.plot(x_train[:, 5], y_train, 'o')
plt.xlabel('Number of rooms(Normalized)')
plt.ylabel('Housing price(Normalized)')


# In[29]:


## 주택가격을 추정하는 모델 정의 ##

# 설명변수 x 플레이스 홀더(Placeholder)
x = tf.placeholder(tf.float32, (None, 13), name='x')
# 정답 데이터(주택가격)용 플레이스 홀더(Placeholder)
y = tf.placeholder(tf.float32, (None, 1), name='y')

# 설명변수 x를 가중치 w와 곱셈한 간단한 모델
w = tf.Variable(tf.random_normal((13, 1)))
pred = tf.matmul(x, w)


# In[30]:


## 손실함수의 정의와 학습 ##

# 실측치 y와 추정치 pred의 차를 제곱승(2승)의 평균을 오차로 한다.
loss = tf.reduce_mean((y - pred)** 2)
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1)
train_step = optimizer.minimize(loss)


# In[34]:


# 학습의 루프
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    for step in range(100):
        train_loss, _ = sess.run( [loss, train_step],
                                 feed_dict = {x: x_train, y:y_train.reshape((-1, 1))}
                                )
        if(step%20 == 0):
            print('step: {}, train_loss: {}'.format(step, train_loss))
    
    # 학습 완료 후, 평가를 위한 데이터 예측
    pred_ = sess.run(pred, feed_dict={x:x_test})


# In[11]:


import numpy as np

def get_batches(x, y, batch_size):
    n_data = len(x)
    indices = np.arange(n_data)
    np.random.shuffle(indices)
    x_shuffled = x[indices]
    y_shuffled = y[indices]
    
    # 원본 데이터에서 무작위로 batch_size 개수 만큼 데이터 추출
    for i in range(0, n_data, batch_size):
        x_batch = x_shuffled[i: i + batch_size]
        y_batch = y_shuffled[i: i + batch_size]
        yield x_batch, y_batch


# In[12]:


# minibatch 크기
BATCH_SIZE = 32

step = 0
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    # 100 Epoch 회 반복
    for epoch in range(100):
        for x_batch, y_batch in get_batches(x_train, y_train, 32):
            train_loss, _ = sess.run(
                [loss, train_step],
                feed_dict = {
                    x: x_batch,
                    y: y_batch.reshape((-1, 1))
                }
            )
            print('step: {}, train_loss: {}'.format(
                step, train_loss
            ))
            step += 1
            
    pred_ = sess.run(
        pred,
        feed_dict = {
            x: x_test
        }
    )


# In[14]:


BATCH_SIZE = 32
step = 0
loss_list = []
step_list = []
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    for epoch in range(100):
        for x_batch, y_batch in get_batches(x_train, y_train, 32):
            train_loss, _ = sess.run([loss, train_step],
                                    feed_dict = {x: x_batch, y: y_batch.reshape((-1, 1))})
            loss_list.append(train_loss)
            step_list.append(step)
            step += 1
            
    pred_ = sess.run(pred, feed_dict = {x: x_test})
    
import matplotlib.pyplot as plt
plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.size'] = 10*3
plt.rcParams['figure.figsize'] = [18, 12]
plt.plot(step_list, loss_list)
plt.xlabel('step')
plt.ylabel('train loss')

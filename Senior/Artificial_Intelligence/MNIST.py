#!/usr/bin/env python
# coding: utf-8

# ## Sequencial API를 이용하여 다층 신경망 구축

# In[10]:


# MNIST 데이터의 Import
from tensorflow.python.keras.datasets import mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()


# In[2]:


# Import 한 데이터의 형을 확인
print('x_train.shape:', x_train.shape)
print('x_test.shape:', x_test.shape)
print('y_train.shape:', y_train.shape)
print('y_test.shape:', y_test.shape)


# In[3]:


# 입력데이터(x)의 구조변형 및 정규화
x_train = x_train.reshape(60000, 784)
x_train = x_train/255

x_test = x_test.reshape(10000, 784)
x_test = x_test/255


# In[4]:


# 출력데이터(y)를 신경망에 대응하도록 변환
from tensorflow.python.keras.utils import to_categorical
y_train = to_categorical(y_train, 10)
y_test = to_categorical(y_test, 10)

''' 신경망에 입력될 데이터 수정 완료 '''


# In[5]:


# 순차모델 생성
from tensorflow.python.keras.models import Sequential
model = Sequential()


# In[6]:


# Dense 층을 이용하여 완전연결층(Fully-Connected Layer)을 추가
from tensorflow.python.keras.layers import Dense

model.add(
    Dense(
        units=64,
        input_shape=(784,),
        activation='relu'
    )
)


# In[7]:


# Dense 레이어를 하나 더 추가하여 출력층 추가
model.add(
    Dense(
        units=10,
        activation='softmax'
    )
)


# In[9]:


# Adam을 이용한 본 모델에서 MNIST 데이터 학습
from tensorflow.python.keras.callbacks import TensorBoard
from tensorboard.plugins.hparams import api as hp

model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)

tsb = TensorBoard(log_dir='./logs')

history_adam = model.fit(
    x_train,
    y_train,
    batch_size=32,
    epochs=20,
    validation_split=0.2,
    callbacks=[tsb]
)


# ## Functional API를 이용하여 모델 구축

# In[12]:


from tensorflow.python.keras.datasets import mnist
from tensorflow.python.keras.utils import to_categorical
from tensorflow.python.keras.callbacks import TensorBoard
from tensorflow.python.keras.layers import Input, Dense
from tensorflow.python.keras.models import Model

(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train = x_train.reshape(60000, 784)
x_train = x_train/255.
x_test = x_test.reshape(10000, 784)
x_test = x_test/255.
y_train = to_categorical(y_train, 10)
y_test = to_categorical(y_test, 10)
tsb = TensorBoard(log_dir='./logs')


# In[13]:


input = Input(shape=(784,))
middle = Dense(units=64, activation='relu')(input)
output = Dense(units=10, activation='softmax')(middle)
model = Model(inputs=[input], outputs=[output])


# In[ ]:


model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)

model.fit(
    x_train,
    y_train,
    batch_size=32,
    epochs=20,
    callbacks=[tsb],
    validation_split=0.2
)


# In[ ]:





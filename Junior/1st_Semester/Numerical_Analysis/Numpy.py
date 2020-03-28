#!/usr/bin/env python
# coding: utf-8

# In[4]:


def adding(a,b):
    c=a+b
    if c>0:
        return c
    elif c<0:
        return 'negative'
    else:
        return 'zero'
print(adding(4,5))
print(adding(-9,2))
print(adding(3,-3))


# In[5]:


from numpy import array
alist=[0,1,2,3,4]
yvector=array(alist)
avector=array([0,1,2,3,4])

print(yvector)
print(avector)
print(len(avector))


# In[6]:


from numpy import arange
brange=arange(5)
crange=arange(0,10,3)
print(brange)
print(crange)


# In[12]:


from numpy import array
amat=array([[0,1,2],[3,4,5],[6,7,8]])
print(amat)


# In[17]:


from numpy import linspace
aspace=linspace(0,10,11)
print(aspace)


# In[18]:


from numpy import ones,zeros,eye
aones=ones((3,3))
azeros=zeros((3,3))
aeye=eye(3)
print('ones= ',aones)
print('zeros= ',azeros)
print('eye= ',aeye)


# In[28]:


from numpy import array
A=array([[1,2,3],[4,5,6],[7,8,9]])
B=array([[-1,1,2],[5,4,2],[3,1,-2]])

madd=A+B
msub=A-B

print(madd)
print(msub)


# In[31]:


from numpy import array
a=array([1,2])
b=array([3,4])
dots=a.dot(b)
print(dots)


# In[34]:


from numpy import array,dot
A=array([[1,2,3],[4,5,6],[7,8,9]])
B=array([[-1,1,2],[5,4,2],[3,1,-2]])
mnt=A*B
dotp=A.dot(B)
print('matrix multiplication= ',mnt)
print('dot product= ',dotp)


# In[ ]:





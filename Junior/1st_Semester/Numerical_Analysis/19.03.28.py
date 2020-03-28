#!/usr/bin/env python
# coding: utf-8

# In[13]:


from numpy import array
a = array([1,2,3,4,5])
print('a[1] = ',a[1])
print('a[3] = ',a[3])
print('a[-1] = ',a[-1])


# In[15]:


from numpy import array
A = array([[1,2,3],[4,5,6],[7,8,9]])
print(A[1,1])
print(A[2,1])


# In[20]:


from numpy import array
a = array([0,1,2,3,4,5,6,7,8])
print('a[1:5] = ',a[1:5])


# In[28]:


from numpy import array
a = array([0,1,2,3,4,5,6,7,8])
print('a[:3] = ',a[:3])


# In[31]:


from numpy import linspace, zeros, cos
x = linspace(0,2,10)
n = len(x)
y = zeros(n)
for i in range(n):
    y[i] = cos(x[i])
    print('%8.4f '%y[i])


# In[34]:


from numpy import linspace, zeros, cos
x = linspace(0,2,10)
y = cos(x)
print(y)


# In[39]:


from numpy import linspace, cos, pi
import matplotlib.pyplot as plt
x = linspace(0,2.0*pi,40)
y = cos(x)
plt.plot(x,y,'k')
plt.xlabel('x')
plt.ylabel('y')
plt.title('y = cos(x)')
plt.show()


# In[44]:


from numpy import linspace, cos, sin, pi
import matplotlib.pyplot as plt
x = linspace(0,2.0*pi,40)
yc = cos(x)
ys = sin(x)
plt.plot(x,yc,'ko--',label='cos(x)')
plt.plot(x,ys,'k--',label='sin(x)')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('y = cos(x) & sin(x)')
plt.show()


# In[2]:


filename = 'file.txt'
with open(filename) as file_object:
    lines = file_object.readlines()
print(lines)


# In[25]:


from numpy import zeros
import matplotlib.pyplot as plt
def g(x):
    return 1.0/6.0*(x**2 + 5)
n = 15
x0 = 2.0
x = zeros(n)
e = zeros(n)
itr = range(1,16)
x[0] = x0
e[0] = "0"

for i in range(n-1):
    x[i+1] = g(x[i])
    e[i+1] = ((x[i+1]-x[i])/x[i+1])*100
#printing output
print("%5s %8s %10s"%('k','x','E (%)'))
for k in range(n):
    print("%5d %9.4f %9.4f"%(k+1,x[k],e[k]))
    
plt.plot(itr,x,'--ko')
plt.xlabel('iteration')
plt.ylabel('x')
plt.show()


# In[ ]:





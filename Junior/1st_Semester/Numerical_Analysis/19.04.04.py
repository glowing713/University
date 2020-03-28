#!/usr/bin/env python
# coding: utf-8

# In[56]:


# 예제 11.2

from numpy import linspace, zeros
import matplotlib.pyplot as plt

def f(x):
    return -x**2 + 6.0*x - 5.0
def df(x):
    return -2.0*x + 6.0

num = input()
m = int(num)
itr = range(0,m)
x = zeros(m)
x[0] = -2.0

for k in range(m-1):
    x[k+1] = x[k] - f(x[k]) / df(x[k])
    

#printing output
print("%5s %8s" % ('k','x'))
for k in range(m):
    print("%5d %9.9f" % (k+1,x[k]))
    
plt.plot(itr,x,'-ko')
plt.xlabel('iteration')
plt.ylabel('x')
plt.show()


# In[69]:


# 예제 12.2

from numpy import linspace, zeros
import matplotlib.pyplot as plt

def f(x):
    return -x**2 + 6.0*x - 5.0

n = input()
m = int(n)
xs = zeros(m)
x0 = -2.0
x1 = 3.0
itr = range(0,m)

for k in range(m):
    x2 = x1 - f(x1) * ((x1 - x0) / (f(x1) - f(x0)))
    x0 = x1
    x1 = x2
    xs[k] = x2

# printing output
print("%5s %8s" % ('k', 'x'))
for k in range(m):
    print("%5d %9.4f" % (k+1, xs[k]))
    
plt.plot(itr, xs, '-ko')
plt.xlabel('iteration')
plt.ylabel('xs')
plt.show()


# In[ ]:





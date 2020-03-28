#!/usr/bin/env python
# coding: utf-8

# In[45]:


from numpy import linspace, zeros, sign, cos
import matplotlib.pyplot as plt

def f(x):
    return -x**2 + 6.0*x - 5.0
a=-2.0
b=3.0
n=16
c=zeros(n)
x = linspace(1,16,16)
for i in range(n):
    c[i]=(a+b)/2.0
    if ( sign(f(c[i])) == sign(f(a)) ):
        a=c[i]
    else:
            b=c[i]
            
#printing output
print("%5s %7s" % ('k','c'))
for k in range(n):
    print("%5d %9.4f" % (k+1,c[k]))

plt.plot(x,c,'-ko')
plt.show()


# In[24]:


from numpy import linspace, cos, pi
import matplotlib.pyplot as plt
x=linspace(0,2.0*pi,40)
y=cos(x)
plt.plot(x,y,'r')
plt.show()


# In[ ]:





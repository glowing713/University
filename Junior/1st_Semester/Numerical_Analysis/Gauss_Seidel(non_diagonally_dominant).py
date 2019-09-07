from numpy import zeros
import matplotlib.pyplot as plt

m = 8
x1 = zeros(m)
x2 = zeros(m)
x3 = zeros(m)
itr = range(1, m+1)

print('%7s %9s %9s %9s' % ('k', 'x1', 'x2', 'x3'))
print('%7d %9.5f %9.5f %9.5f' % (0, x1[0], x2[0], x3[0]))

for i in range(m-1):
    x1[i+1] = (-1.0 + 2.0*x2[i] - 3.0*x3[i])/5.0
    x2[i+1] = (-3.0 + 2.0*x1[i+1] - 7.0*x3[i])
    x3[i+1] = (2.0 + 3.0*x1[i+1] - 9.0*x2[i+1])
    print('%7d %9.5f %9.5f %9.5f' % (i+1, x1[i+1], x2[i+1], x3[i+1]))

plt.plot(itr, x1, '-ko', label='x1')
plt.plot(itr, x2, '--ko', label='x2')
plt.plot(itr, x3, 'k', label='x3')
plt.legend()
plt.xlabel('Iteration')
plt.ylabel('Approximate solutions')
plt.show()
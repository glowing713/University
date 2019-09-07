from numpy import array, linspace
import matplotlib.pyplot as plt

def linearintp(x0, x1, f0, f1):
    a1 = (f1 - f0) / (x1 - x0)
    a0 = f0
    return a0, a1

# dataset
x = array([0, 1, 2])
y = array([1, 3, 2])
n = len(x)
for i in range(n-1):
    x0 = x[i]
    x1 = x[i + 1]
    inp = linspace(x0, x1, 2)
    f0 = y[i]
    f1 = y[i + 1]
    a0, a1 = linearintp(x0, x1, f0, f1)
    print('f(x) = ', a0, '+', a1, '(x - ', x0, ')')
    out = a0 + a1 * (inp - x0)
    if(i == 0):
        intp = a0 + a1 * (0.5 - x0)
        plt.scatter(0.5, intp, c='w', s=55, edgecolor='k', marker='o')
        plt.plot(inp, out, 'k--', marker='o')
    elif(i == 1):
        plt.plot(inp, out, 'k-.', marker='o')

plt.xlabel('x')
plt.ylabel('y')
plt.show()
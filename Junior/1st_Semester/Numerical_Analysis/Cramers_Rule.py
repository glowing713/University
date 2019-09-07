from numpy import array
from numpy.linalg import det

a = [[0, 0], [0, 0]]
b = [[0], [0]]
k = 0
fp = open('input.txt', 'r')
num = fp.read().split()

for i in range(0, 2):
    for j in range(0, 2):
        a[i][j] = int(num[k])
        k = k + 1
for l in range(0, 2):
    for m in range(0, 1):
        b[l][m] = int(num[k])
        k = k + 1

a1 = array([[b[0][0], a[0][1]], [b[1][0], a[1][1]]])
a2 = array([[a[0][0], b[0][0]], [a[1][0], b[1][0]]])

detA = det(a)
detA1 = det(a1)
detA2 = det(a2)

print('|A| = %.2f' % detA, '|A1| = %.2f' % detA1, '|A2| = %.2f' % detA2)

x1 = detA1 / detA
x2 = detA2 / detA

print('x1 = %.2f' % x1, 'x2 = %.2f' % x2)
fp.close()
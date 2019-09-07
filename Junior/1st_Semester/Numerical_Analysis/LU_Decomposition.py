from numpy import zeros, eye

L2 = eye(2)
R2 = zeros((2, 2))
B1 = zeros((2, 1))
L3 = eye(3)
R3 = zeros((3, 3))
B2 = zeros((3, 1))

fp1 = open('input.txt', 'r')
fp2 = open('output.txt', 'w')
num = [int(x) for x in fp1.read().split()]
matSize = len(num)

if matSize == 6:
    R2[0][0] = num[0]
    R2[0][1] = num[1]
    L2[1][0] = num[2] / R2[0][0]
    R2[1][1] = num[3] - (L2[1][0]*R2[0][1])
    B1[0][0] = num[4]
    B1[1][0] = num[5]
    print("L = ", L2, "\nR = ", R2)
    y1 = B1[0][0]
    y2 = B1[1][0] - (L2[1][0]*y1)
    x2 = y2 / R2[1][1]
    x1 = (y1 - (R2[0][1]*x2)) / R2[0][0]
    print("x1 = %.2f" % x1, "\nx2 = %.2f" % x2)
    fp2.write("L=%s\tR=%s\nx1 = %.2f\nx2 = %.2f" % (L2, R2, x1, x2))
elif matSize == 12:
    for i in range(0, 3):
        R3[0][i] = num[i]

    L3[1][0] = num[3] / R3[0][0]
    R3[1][1] = num[4] - (L3[1][0]*R3[0][1])
    R3[1][2] = num[5] - (L3[1][0]*R3[0][2])
    L3[2][0] = num[6] / R3[0][0]
    L3[2][1] = (num[7] - (L3[2][0]*R3[0][1]))/R3[1][1]
    R3[2][2] = num[8] - (L3[2][0]*R3[0][2]) - (L3[2][1]*R3[1][2])
    B2[0][0] = num[9]
    B2[1][0] = num[10]
    B2[2][0] = num[11]
    print("L = ", L3, "\nR = ", R3)
    y1 = B2[0][0]
    y2 = B2[1][0] - (L3[1][0]*y1)
    y3 = B2[2][0] - (L3[2][0]*y1) - (L3[2][1]*y2)
    x3 = y3 / R3[2][2]
    x2 = (y2 - (R3[1][2]*x3)) / R3[1][1]
    x1 = (y1 - (R3[0][1]*x2) - (R3[0][2]*x3)) / R3[0][0]
    print("x1 = %.2f" % x1, "\nx2 = %.2f" % x2, "\nx3 = %.2f" % x3)
    fp2.write("L=%s\nR=%s\nx1 = %.2f\nx2 = %.2f\nx3 = %.2f" % (L3, R3, x1, x2, x3))
else:
    print("행렬은 2*2 또는 3*3을 입력하세요.")
    fp2.write("Matrix input error")

fp1.close()
fp2.close()
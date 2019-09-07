from numpy import zeros, argsort

matrix2 = zeros((2, 3))
matrix3 = zeros((3, 4))
k = 0
temp = 0
x1 = 0
x2 = 0

fp1 = open('input.txt', 'r')
fp2 = open('output.txt', 'w')

num = [int(x) for x in fp1.read().split()]
matSize = len(num)

if matSize == 6:                        # 2 * 2 matrix case
    for i in range(0, 2):                    # 확장된 행렬 생성
        for j in range(0, 2):
            matrix2[i][j] = num[k]
            k = k + 1
    matrix2[0][2] = num[4]
    matrix2[1][2] = num[5]

    matrix2 = matrix2[argsort(-matrix2[:, 0])]       # 부분 피보팅 수행

    temp = matrix2[1][0] / matrix2[0][0]    # a21/a11 값
    for i in range(0, 3):                   # 행렬 변환
        matrix2[1][i] -= (temp * matrix2[0][i])

    x2 = matrix2[1][2] / matrix2[1][1]      # x값 계산
    x1 = (matrix2[0][2] - x2) / matrix2[0][0]

    print("x1 = %.2f" % x1, "\nx2 = %.2f" % x2)
    fp2.write("x1 = %.2f\nx2 = %.2f" % (x1, x2))

elif matSize == 12:                     # 3 * 3 matrix case
    for i in range(0, 3):                   # 확장된 행렬 생성
        for j in range(0, 3):
            matrix3[i][j] = num[k]
            k = k + 1
    matrix3[0][3] = num[9]
    matrix3[1][3] = num[10]
    matrix3[2][3] = num[11]

    matrix3 = matrix3[argsort(-matrix3[:, 0])]       # 부분 피보팅 수행

    temp = matrix3[1][0] / matrix3[0][0]        # a21/a11 값
    for i in range(0, 4):                       # 행렬 변환 1
        matrix3[1][i] -= (temp * matrix3[0][i])
    temp = matrix3[2][0] / matrix3[0][0]        # a31/a11 값
    for i in range(0, 4):                       # 행렬 변환 2
        matrix3[2][i] -= (temp * matrix3[0][i])
    temp = matrix3[2][1] / matrix3[1][1]        # a32/a22 값
    for i in range(0, 4):                       # 행렬 변환 3
        matrix3[2][i] -= (temp * matrix3[1][i])

    x3 = matrix3[2][3] / matrix3[2][2]          # x값 계산
    x2 = (matrix3[1][3] - (matrix3[1][2] * x3)) / matrix3[1][1]
    x1 = (matrix3[0][3] - (matrix3[0][1] * x2) - (matrix3[0][2] * x3)) / matrix3[0][0]

    print("x1 = %.2f" % x1, "\nx2 = %.2f" % x2, "\nx3 = %.2f" % x3)
    fp2.write("x1 = %.2f\nx2 = %.2f\nx3 = %.2f" % (x1, x2, x3))

fp1.close()
fp2.close()
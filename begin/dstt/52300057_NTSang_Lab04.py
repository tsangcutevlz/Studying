import numpy as np
import sympy as sp

x, y, z, t = sp.symbols('x y z t')


def solve_2(a1, a2, b1, b2, c1, c2):
    A = np.array([[a1, b1],
                  [a2, b2]])
    
    k = np.linalg.det(A)
    
    if k == 0:
        if c1 * b2 == c2 * b1:
            return "Hệ có vô số nghiệm"
        else:
            return "Hệ vô nghiệm"
    else:
        x = (c1 * b2 - c2 * b1) / k
        y = (a1 * c2 - a2 * c1) / k
        return f"Hệ có nghiệm duy nhất: x = {x}, y = {y}"


def solve_3(a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3):
    A = np.array([[a1, b1, c1],
                  [a2, b2, c2],
                  [a3, b3, c3]])
    B = np.array([[a1, b1, c1, d1],
                  [a2, b2, c2, d2],
                  [a3, b3, c3, d3],
                  [1, 1, 1, 1]])
    k = np.linalg.det(A)
    h = np.linalg.det(B)
    if k == 0:
        return "he vo nghiem"
    elif k == 0 and h == 0:
        return "he co vo so nghiem"
    else:
        return "he co nghiem duy nhat"

def Gauss_3x3(C):
    print(C)
    temp_row_1 = (C[1,0] / C[0,0])
    temp_row_2 = (C[2,0] / C[0,0])
    for i in len(C[0]):
        C[1,i] = C[1,i] - (temp_row_1 * C[0,i])
    for i in len(C[0]):
        C[2, i] = C[2, i] - (temp_row_2 * C[0,i])
    temp_col_2 = (C[2,1] / C[2,2])
    for i in len(C):
        C[i,1] = C[i,1] - (temp_col_2 * C[i,2])
    
    # z = C[2,3] / C[2,2]
    # y = (C[1,3] - (C[1,2] * z)) / C[1,1]
    # x = (C[0,3] - (C[0,2] * z + C[0,1] * y)) / C[0,0]
    print(C)


def ex1():
    A = [[1, 2, 1], [2, -1, 1], [2, 1, 0]]
    B = [0, 0, 0]
    k = np.linalg.solve(A, B)
    print("cau 1a: ", k)
    c = sp.Eq(2*x + y + z + t, 1)
    d = sp.Eq(x + 2*y + z + t, 1)
    e = sp.Eq(x + y + 2*z + t, 1)
    f = sp.Eq(x + y + z + 2*t, 1)
    p = sp.solve((c, d, e, f), (x, y, z, t))
    print("cau 1b: ", p)


def ex2():
    a1, b1, c1 = 1, 2, 3
    a2, b2, c2 = 3, 4, 5
    result = solve_2(a1, a2, b1, b2, c1, c2)

    print("bai 2: ", result)


def ex3():
    a1, b1, c1, d1 = 1, 1, 1, 1
    a2, b2, c2, d2 = 1, 1, 1, 1
    a3, b3, c3, d3 = 1, 1, 1, 1
    solve_3(a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3)


# def ex4():
#     A = np.array([[1, 1, 2], [3, 6, -5], [2, 4, -3]])
#     B = np.array([1,-1,0])
#     C = np.array([[1, 1, 2, 1], 
#                   [3, 6, -5, -1], 
#                   [2, 4, -3, 0]], dtype=float)
#     det_A = np.linalg.det(A)
#     if det_A != 0:
#         print("4a: A is invertible")
#     else:
#         print("4a: A is not invertible")

#     det_ivA = np.linalg.inv(A)
#     result = np.dot(det_ivA,B)
#     print("x y z:", result)
#     Gauss_3x3(C)

# ex4()

ex1()
ex2()
ex3()
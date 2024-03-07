import numpy as np


def ex1():
    vector_x = np.arange(1, 6, 1)
    vector_b = np.arange(1, 7, 1)
    c = np.arange(1, 31, 1)
    d = np.arange(1, 26, 1)
    print("cau 1a: \n", np.tile(vector_x, (5, 1)).transpose())
    print("cau 1b: \n", np.tile(vector_b, (6, 1)))
    print("cau 1c: \n", (np.reshape(c, (6, 5))).transpose())
    print("cau 1d: \n", np.reshape(d, (5, 5)))


def ex2():
    matrix = np.random.randint(100, size=(5, 6))
    print("cau 2: \n", matrix)


def ex3():
    print("cau 3: \n", np.flip(np.reshape(np.arange(1, 10, 1), (3, 3)), axis=1))


def ex4():
    print("cau 4: \n", (np.reshape(np.arange(1, 10, 1), (3, 3)))[::-1])


def ex5():
    vector_Y = np.array([[1, 2, 16, 31, 22], 
                         [2, 8, 12, 21, 23],
                         [4, 9, 11, 14, 25], 
                         [3, 6, 10, 16, 34]])
    print("cau 5a: \n", vector_Y[1, 1:4])
    print("cau 5b: \n", vector_Y[:, 2].reshape(4, 1))
    print("cau 5c: \n", vector_Y[[1, 2], 1:4])
    print("cau 5d: \n", vector_Y[:, [0, 2, 4]])
    print("cau 5e: \n", vector_Y[1:4, [0, 2, 3, 4]])
    print("cau 5f: \n", vector_Y[vector_Y > 12])


def ex6():
    vector_A = np.array([[2, 4, 1], [6, 7, 2], [3, 5, 9]])
    x1 = vector_A[0, 0:4]
    Y = vector_A[1:3, 0:4]
    print("cau 6a: \n", x1)
    print("cau 6b: \n", Y)


def ex7():
    vector_A = np.array([[2, 7, 9, 7], [3, 1, 5, 6], [8, 1, 2, 5]])
    B = vector_A[:, [0, 2]]
    C = vector_A[1, :]
    print("cau 7a: \n", B)
    print("cau 7b: \n", C)
    print("cau 7c: \n", np.reshape(vector_A, (4, 3)))


def ex8():
    price = np.array(
        [[12*2, 15*2, 10*2, 16*2, 12*2], [5, 9, 14, 7, 10], [8*3, 12*3, 10*3, 9*3, 15*3]])
    sales = np.sum(price, axis=0)
    print("total sales on Monday: ", sales[0])
    print("total sales on Tuesday: ", sales[1])
    print("total sales on Wednesday: ", sales[2])
    print("total sales on Thursday: ", sales[3])
    print("total sales on Friday: ", sales[4])
    print(sales)


def ex9():
    T = np.array([[0.6, 0.7], [0.4, 0.3]])
    p = np.array([0.5, 0.5])
    k = np.array([1, 2, 10, 10, 100000])
    print("cau 9: ")
    for ki in k:
        print("For k =", ki, ", pk =", np.dot(
            p, np.linalg.matrix_power(T, ki)))


def ex10():
    A = np.array([[-1, 4, 8], [-9, 1, 2]])
    B = np.array([[5, 8], [0, -6], [5, 6]])
    C = np.array([[-4, 1], [6, 5]])
    D = np.array([[-6, 3, 1], [8, 9, -2], [6, -1, 5]])

    if A.shape[1] == B.T.shape[0]:
        print("cau 10a: \n", np.dot(A, B.T))
    else:
        print("cau 10a: not possible")
    if B.shape[1] == C.T.shape[0]:
        print("cau 10b: \n", np.dot(B, C.T))
    else:
        print("cau 10b: not possible")
    if C.shape[0] == C.shape[1]:
        print("10c: \n", C - C.T)
    else:
        print("cau 10c: not possible")
    if D.shape[0] == D.shape[1]:
        print("10d: \n", D - D.T)
    else:
        print("cau 10d: not possible")
    print("cau 10e: \n", (D.T).T)
    print("cau 10f: \n", 2*(C.T))
    if (A.T.shape[0] == B.shape[0]) and (A.T.shape[1] == B.shape[1]):
        print("cau 10g: \n", A.T + B)
    else:
        print("cau 10g: not possible")
    if (A.T.shape[0] == B.shape[0]) and (A.T.shape[1] == B.shape[1]):
        print("cau 10h: \n", (A.T + B).T)
    else:
        print("cau 10h: not possible")
    if (A.T.shape[0] == B.shape[0]) and (A.T.shape[1] == B.shape[1]):
        print("cau 10i: \n", (2*A.T - 5*B).T)
    else:
        print("cau 10i: not possible")
    print("cau 10j: \n", (-D).T)
    print("cau 10k: \n", -(D.T))
    print("cau 10l: \n", np.linalg.matrix_power(C, 2).T)
    print("cau 10m: \n", np.linalg.matrix_power(C.T, 2))


def ex11():
    A = np.array([[2, 4, 1], [6, 7, 2], [3, 5, 9]])
    if (A.shape[0] == A.shape[1]):
        print("11a: A is square matrix")
    else:
        print("11a: A is not square matrix")
    if np.allclose(A, A.T):
        print("11b: A is symmetric matrix")
    else:
        print("11b: A is not symmetric matrix")
    if np.allclose(A, -A.T):
        print("11c: A is skew-symmetric matrix")
    else:
        print("11c: A is not skew-symmetric matrix")
    print("11d: Upper triangular matrix of A: \n", np.triu(A))
    print("11e: Lower triangular matrix of A: \n", np.tril(A))


def ex12():
    A = np.array([[6, 0, 0, 5], [1, 7, 2, -5], [2, 0, 0, 0], [8, 3, 1, 8]])
    B = np.array([[1, -2, 5, 2], [0, 0, 3, 0], [2, -6, -7, 5], [5, 0, 4, 4]])
    C = np.array([[3, 5, -8, 4], [0, -2, 3, -7], [0, 0, 1, 5], [0, 0, 0, 2]])
    D = np.array([[4, 0, 0, 0], [7, -1, 0, 0], [2, 6, 3, 0],
                 [5, -8, 3, 0], [5, -8, 4, -3]])
    E = np.array([[4, 0, -7, 3, -5], [0, 0, 2, 0, 0], [7, 3, -6, 4, -8],
                 [5, 0, 5, 2, -3], [0, 0, 9, -1, 2]])
    F = np.array([[6, 3, 2, 4, 0], [9, 0, -4, 1, 0], [8, -5, 6, 7, 1],
                 [3, 0, 0, 0, 0], [4, 2, 3, 2, 0]])
    print("ex12")
    print("Determinant of matrix A:", round(np.linalg.det(A)))
    print("Determinant of matrix B:", round(np.linalg.det(B)))
    print("Determinant of matrix C:", round(np.linalg.det(C)))
    if (D.shape[0] == D.shape[1]):
        print("Determinant of matrix D:", round(np.linalg.det(D)))
    else:
        print("D does not have a Determinant")
    print("Determinant of matrix E:", round(np.linalg.det(E)))
    print("Determinant of matrix F:", round(np.linalg.det(F)))


def ex13sub(n):
    A = np.random.randint(10, size=(n, n))
    B = np.random.randint(10, size=(n, n))
    return np.linalg.det(A+B) - np.linalg.det(A) - np.linalg.det(B)


def ex13():
    n = [3, 4, 5, 6]
    print("ex13: ")
    for i in n:
        if ex13sub(i) == 0:
            print(f"For n = {i}, det(A + B)=detA+detB is true ")
        else:
            print(f"For n = {i}, det(A + B)=detA+detB is false ")


def ex14sub(n):
    A = np.random.randint(10, size=(n, n))
    B = np.random.randint(10, size=(n, n))

    return np.isclose(np.linalg.det(A @ B), np.linalg.det(A)*np.linalg.det(B))


def ex14():
    n = [3, 4, 5, 6]
    print("ex14: ")
    for i in n:
        if ex14sub(i) == True:
            print(f"For n = {i}, detAB=(detA)(detB) is true ")
        else:
            print(f"For n = {i}, detAB=(detA)(detB) is false ")


def ex15():
    A = np.array([[2, 4, 5/2], [-3/4, 2, 1/4], [1/4, 1/2, 2]])
    B = np.array([[1, -1/2, 3/4], [3/2, 1/2, -2], [1/4, 1, 1/2]])
    print("15a:")
    print("A**(-1)*B**(-1): \n", np.linalg.inv(A)@np.linalg.inv(B))
    print("(A*B)**(-1): \n", np.linalg.inv(A@B))
    print("(B*A)**(-1): \n", np.linalg.inv(B@A))
    print("15b:")
    print("(A**(-1))**T: \n", np.linalg.inv(A).T)
    print("(A**T)**(-1): \n", np.linalg.inv(A.T))



ex1()
ex2()
ex3()
ex4()
ex5()
ex6()
ex7()
ex8()
ex9()
ex10()
ex11()
ex12()
ex13()
ex14()
ex15()
import numpy as np
from fractions import Fraction

n = int(input("nhap n tu ban phim: "))


def checkPrimeNum(k):
    if k == 1:
        return False
    for i in np.arange(2, int(np.sqrt(k))+1, 1):
        if (k % i == 0):
            return False
    return True


def findPrimeNumIndex(k):
    z = 0
    for i in np.arange(2, 10000, 1):
        if (checkPrimeNum(i) == True):
            z += 1
            if (z == k):
                return i


def ex1():
    x_list = [1, 3, 5, 2, 9]
    vector_x = np.array(x_list)
    y_list = [-1, 3, 15, 27, 29]
    vector_y = np.array(y_list)
    print("cau 1. number of elements x: ", len(vector_x))
    print("cau 1. number of elements y: ", len(vector_y))


def ex2():
    vector_a = np.empty(n)
    vector_b = np.empty(n)
    vector_c = np.empty(n*2 + 1)
    vector_d = np.empty(n*2 + 1)
    vector_e = np.empty(n*2 + 1)
    vector_f = np.zeros(n, dtype=object)
    vector_f[0] = 1
    vector_g = np.zeros(n, dtype=object)
    vector_h = np.zeros(n, dtype=object)
    vector_i = np.empty(n)
    vector_j = np.zeros(n, dtype=object)
    vector_k = np.zeros(n, dtype=object)
    vector_k[0] = 0
    vector_l = [chr(i) for i in range(ord('a'), ord('z')+1)]
    vector_m = [chr(i) for i in range(ord('A'), ord('Z')+1)]
    a = 12
    b = 31
    f = 2
    j = 5
    jsub = 5

    for i in np.arange(1, n, 1):
        numerator, denominator = float(1 / (f)).as_integer_ratio()
        vector_f[i] = Fraction(numerator, denominator).limit_denominator() if i != 0 else Fraction(f)
        f = f*2


    for i in np.arange(-n, n+1):
        vector_c[i + n] = i
    for i in np.arange(n, -n-1, -1):
        vector_d[n-i] = i
    for i in np.arange(n, -n-1, -1):
        vector_e[n+i] = i*2

    dqa = 0
    dqb = 1
    dqc = dqa+dqb
    for i in np.arange(0, n, 1):
        if (i == 0):
            vector_g[i] = 1
        else:
            numerator, denominator = float(1/dqb).as_integer_ratio()
            vector_g[i] = Fraction(numerator, denominator).limit_denominator() if i != 0 else Fraction(f)
            # vector_g[i] = 1/dqb
        dqa = dqb
        dqb = dqc
        dqc = dqa + dqb
    for i in np.arange(0, n, 1):
        k = findPrimeNumIndex(i + 1)
        numerator, denominator = float(1/k).as_integer_ratio()
        vector_h[i] = Fraction(numerator, denominator).limit_denominator()

    for i in np.arange(0, n, 1):
        if (i == 0):
            vector_i[i] = 1
        else:
            vector_i[i] = vector_i[i-1] + (i+1)
    for i in np.arange(0, n, 1):
        if (i == 0):
            numerator, denominator = float(1/2).as_integer_ratio()
            vector_j[i] = Fraction(numerator, denominator)

        else:
            numerator, denominator = float(1/j).as_integer_ratio()
            vector_j[i] = Fraction(numerator, denominator).limit_denominator()
            j += jsub
            jsub += 2
    for i in np.arange(1, n, 1):
        numerator, denominator = float(i/(i+1)).as_integer_ratio()
        vector_k[i] = Fraction(numerator, denominator).limit_denominator()

    print("cau 2a: ", vector_a)
    print("cau 2b: ", vector_b)
    print("cau 2c: ", vector_c)
    print("cau 2d: ", vector_d)
    print("cau 2e: ", vector_e)
    print("cau 2f:", ', '.join(map(str, vector_f)))
    print("cau 2g: ", ', '.join(map(str, vector_g)))
    print("cau 2h: ", ', '.join(map(str, vector_h)))
    print("cau 2i: ", vector_i)
    print("cau 2j: ", ', '.join(map(str, vector_j)))
    print("cau 2k: ", ', '.join(map(str, vector_k)))    
    print("cau 2l: ", vector_l)
    print("cau 2m: ", vector_m)


def ex3():
    vector_x = np.array([])
    for i in np.arange(1, 4, 1):
        vector_x = np.append(vector_x, 10**i)
    print("cau 3: ", vector_x)


def ex4():
    vector_x = [1, 2, 3]
    vector_y = [98, 12, 33]
    vector_z = []
    for i in range(0, len(vector_x) + len(vector_y)):
        if (i < 3):
            vector_z.append(vector_x[i])
        else:
            vector_z.append(vector_y[i - len(vector_x)])

    print("cau 4: ", vector_z)


def ex5():
    vector_x = [1, 2, 3]
    vector_y = [4, 5, 6]
    num_inner_lists = 2
    vector_z = [[] for _ in range(num_inner_lists)]

    for i in range(0, 2):
        if (i == 0):
            for j in range(0, len(vector_x)):
                vector_z[i].append(vector_x[j])
        else:
            for j in range(0, len(vector_y)):
                vector_z[i].append(vector_y[j - len(vector_x)])

    print("cau 5: ", vector_z)


def ex6():
    vector_x = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
    print("6a: ", vector_x[6-1])
    print("6b: ", vector_x[len(vector_x) - 1 - 5])
    print("6c: ", vector_x[1-1], vector_x[4-1], vector_x[len(vector_x) - 1])
    print("6d: ", vector_x[1-1], vector_x[3-1], vector_x[5-1], vector_x[7-1])
    vector_sub = []
    vector_sub2 = []
    for i in range(0, len(vector_x), 2):
        vector_sub.append(vector_x[i])
    for i in range(1, len(vector_x), 2):
        vector_sub2.append(vector_x[i])
    print("6e: ", vector_sub)
    print("6f: ", vector_sub2)


def ex7():
    vector_x = np.array([3, 11, -9, -131, -1, 1, -11, 91, -6, 407, -12, -11, 12, 153, 371])
    print("7a: ", np.max(vector_x))
    print("7b: ", np.min(vector_x))
    print("7c: ", [index for index, num in enumerate(vector_x) if num > 10])
    print("7d: ", vector_x[::-1])
    print("7e: ", np.sort(vector_x))
    print("7f: ", np.sort(vector_x)[::-1])
    print("7g: ", sum(range(1, len(vector_x))))
    print("7h: ", len(vector_x) - len(np.unique(vector_x)))
    print("7i: ", [vector_x[i] + vector_x[len(vector_x)-i-1] for i in range(0, len(vector_x)) ])
    print("7j:", [num for num in vector_x if num >= 0 and num == sum(int(digit)**len(str(abs(num))) for digit in str(abs(num)))])
    print("7k:", [num for num in vector_x if (num > 0)])
    print("7l: ", np.median(vector_x))
    print("7m: ", np.sum(vector_x[vector_x < np.mean(vector_x)]))
    print("7n: ", [abs(num) for num in vector_x ])
                


ex1()
ex2()
ex3()
ex4()
ex5()
ex6()
ex7()
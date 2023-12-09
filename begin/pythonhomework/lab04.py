import math as m
import matplotlib.pyplot as plt
import numpy as np
import sympy as sp

x = sp.symbols("x")


def ex1a():
    f1a = abs(x**2 - x - 7)
    lm = sp.limit(f1a, x, 3)
    print("1a - The limit of f(x) at x = 3: " + str(lm))


def ex1b():
    f1b = abs(x - 1) / (x**2 - 1)
    lm = sp.limit(f1b, x, 1)
    print("1b - The limit of f(x) at x = 1: " + str(lm))


def ex1c():
    f1c = m.e ** (1 / x)
    lm = sp.limit(f1c, x, 1)
    print("1c - The limit of f(x) at x = 1: " + str(lm))


def ex1d():
    f1d = (x**4 - 16) / (x - 2)
    lm = sp.limit(f1d, x, 2)
    print("1d - The limit of f(x) at x = 2: " + str(lm))


def ex1e():
    f1e = (x**3 - x**2 - 5 * x - 3) / ((x + 1) ** 2)
    lm = sp.limit(f1e, x, -1)
    print("1e - The limit of f(x) at x = -1: " + str(lm))


def ex1f():
    f1f = (x**2 - 9) / ((x**2 + 7) ** (1 / 2) - 4)
    lm = sp.limit(f1f, x, 3)
    print("1f - The limit of f(x) at x = 3: " + str(lm))


def ex1g():
    f1g = abs(x) / sp.sin(x)
    lm = sp.limit(f1g, x, 1)
    print("1g - The limit of f(x) at x = 1: " + str(lm))


def ex1h():
    f1h = (1 - sp.cos(x)) / (x * sp.sin(x))
    lm = sp.limit(f1h, x, 0)
    print("1h - The limit of f(x) at x = 0: " + str(lm))


def ex1i():
    f1i = (2 * (x**2)) / (3 - 3 * sp.cos(x))
    lm = sp.limit(f1i, x, 0)
    print("1i - The limit of f(x) at x = 0: " + str(lm))


def ex1j():
    f1j = ((3 + x) / (x - 1)) ** x
    lm = sp.limit(f1j, x, sp.oo)
    print("1j - The limit of f(x) at x = vc: " + str(lm))


def ex1k():
    f1k = (1 - (2 / (3 + x))) ** x
    lm = sp.limit(f1k, x, sp.oo)
    print("1k - The limit of f(x) at x = vc: " + str(lm))


def ex1l():
    f1l = (1 / x) ** (1 / x)
    lm = sp.limit(f1l, x, sp.oo)
    print("1l - The limit of f(x) at x = vc: " + str(lm))


def ex1m():
    f1m = ((1 + x) ** (1 / 3) - (x) ** (1 / 3))
    ((1 + x) ** (1 / 2) - (x) ** (1 / 2))
    lm = sp.limit(f1m, x, sp.oo)
    print("1m - The limit of f(x) at x = vc: " + str(lm))


def ex1n():
    f1n = sp.factorial(x) / (x**x)
    lm = sp.limit(f1n, x, sp.oo)
    print("1n - The limit of f(x) at x = vc: " + str(lm))

def ex2a():
    f = abs(x**2 - x - 7)
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    
    #
    y = fx(k)
    plt.plot(k, y, label='f(x) = |x**2 - x - 7|')
    plt.plot(3, 1, 'ro')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2b():
    f = abs(x - 1) / (x**2 - 1)
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = |x-1| / (x^2 - 1)')
    plt.axvline(x=1, color='red', linestyle='--', label='x = 1 (limit line)')
    plt.axvline(x=-1, color='blue', linestyle='--',
                label='x = -1 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit')
    plt.legend()
    plt.show()



def ex2c():
    f = (m.e ** (1 / x))
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = e ** (1 / x)')
    plt.axvline(x=0, color='red', linestyle='--', label='x = 0 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()



def ex2d():
    f = (x**4 - 16) / (x - 2)
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = (x**4 - 16) / (x - 2)')
    plt.axvline(x=2, color='red', linestyle='--', label='x = 2 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2e():
    f = (x**3 - x**2 - 5 * x - 3) / ((x + 1) ** 2)
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = (x**3 - x**2 - 5 * x - 3) / ((x + 1) ** 2)')
    plt.axvline(x=-1, color='red', linestyle='--',
                label='x = -1 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2f():
    f = ((x**2 - 9) / ((x**2 + 7) ** (1 / 2) - 4))
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = ((x**2 - 9) / ((x**2 + 7) ** (1 / 2) - 4))')
    plt.axvline(x=3, color='red', linestyle='--', label='x = 3 (limit line)')
    plt.axvline(x=-3, color='red', linestyle='--',
                label='x = -3 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()



def ex2g():
    f = (abs(x) / sp.sin(x))
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = |x| / sin(x)')
    plt.axvline(x=0, color='red', linestyle='--', label='x = 0 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2h():
    f = ((1 - sp.cos(x)) / (x * sp.sin(x)))
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = (1 - cosx) / x*sinx')
    plt.axvline(x=0, color='red', linestyle='--', label='x = 0 (limit line)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2i():
    f = ((2 * (x**2)) / (3 - 3 * sp.cos(x)))
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = ((2 * (x**2)) / (3 - 3 * sp.cos(x)))')
    plt.axvline(x=0, color='red', linestyle='--', label='x = 0 (limit point)')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()



def ex2j():
    f = (((3 + x) / (x - 1)) ** x)
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = ((3 + x) / (x - 1)) ** x')
    plt.axvline(x=1, color='red', linestyle='--', label='x = 1 (limit line)')
    plt.axvline(x=-3, color='red', linestyle='--',
                label='x = -3 (limit line)')

    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2k():
    f = (1 - (2 / (3 + x))) ** x
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = (1 - (2 / (3 + x))) ** x')
    plt.axvline(x=-1, color='red', linestyle='--',
                label='x = -1 (limit point)')

    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()


def ex2l():
    f = (1 / x) ** (1 / x)
    fx = sp.lambdify(x, f, 'numpy')
    k = np.arange(-20, 21, 1)
    y = fx(k)
    plt.plot(k, y, label='f(x) = (1 / x) ** (1 / x)')
    plt.axvline(x=0, color='red', linestyle='--', label='x = 0 (limit point)')

    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title('Graph of the function and its limit point')
    plt.legend()
    plt.show()



def ex3aexe():
    print("Bai 3a: ")
    f1 = 1 / (1 + 2**(1/x))
    lmPo = sp.limit(f1, x, 0, "+")
    lmNe = sp.limit(f1, x, 0, "-")
    lm = sp.limit(f1, x, 0)
    plt.plot(0, lmPo, 'ro', label='0+')
    plt.plot(0, lmNe, 'mo', label='0-')
    plt.plot(0, lm, 'yo', label='0')
    plt.title("cau 3.1")
    plt.legend()
    plt.grid()
    plt.show()


def ex3bexe():
    print("Bai 3b: ")
    f2 = (x**2 + x) / ((x**3 + x**2) ** (1/2))
    lmPo = sp.limit(f2, x, 0, "+")
    lmNe = sp.limit(f2, x, 0, "-")
    lm = sp.limit(f2, x, 0)
    plt.plot(0, lmPo, 'ro', label='0+')
    plt.plot(0, lmNe, 'mo', label='0-')
    plt.plot(0, lm, 'yo', label='0')
    plt.title("cau 3.2")
    plt.legend()
    plt.grid()
    plt.show()


def ex4exe():
    print("Bai 4: ")

    x = sp.symbols('x')
    f2 = sp.sin(1/x)

    lmPoNe = sp.limit(f2, x, 0, dir='-')
    lmPoNe_right = sp.limit(f2, x, 0, dir='+')

    if sp.limit(f2, x, 0, dir='-').is_real:
        print("limx->0- => f(x) = ", lmPoNe, " => f(x) exists")
    else:
        print("limx->0- => f(x) = ", lmPoNe, " => f(x) doesn't exist")

    print("limx->0+ => f(x) = ", lmPoNe_right, " => f(x) exists")

    if lmPoNe != lmPoNe_right:
        print("limx->0- != limx->0+ f(x) (", f2, " != 0)",
              " => f(x) doesn't exist")



def ex5aexe():
    print("Bai 5a: ")

    fa = x**2 - 7
    lm = sp.limit(fa, x,  1)

    print("cau 5a")

    if fa.subs(x, 1) is None:
        print("function is not continuous at 1")
    else:
        if lm == fa.subs(x, 1):
            print("do limf(x)->1 = f(1) => True")
        else:
            print("do limf(x)->1 != f(1) => False")


def ex5bexe():
    print("Bai 5b: ")

    fb = (2*x - 3)**(1/2)
    lm = sp.limit(fb, x,  2)

    print("cau 5b")
    if fb.subs(x, 2) is None:
        print("function is not continuous at 2")
    else:
        if lm == fb.subs(x, 2):
            print("do limf(x)->1 = f(1) => True")
        else:
            print("do limf(x)->1 != f(1) => False")


def ex6aexe():
    print("Bai 6a: ")

    fa = (x**2 - x - 6) / (x - 3)

    y = []
    # At point 0
    lm_x_0 = sp.limit(fa, x, 0)

    if (lm_x_0 != 5):
        y.append(0)
    for c in np.arange(-100, 101, 1):
        if c != 0:
            if fa.subs(x, c) != sp.limit(fa, x, c):
                y.append(c)
    print("f(x) is continous for all x except: ", y)


def ex6bexe():
    print("Bai 6b: ")

    fb = (x**3 - 8) / (x**2 - 4)

    y = []
    # At point
    lm_x_2 = sp.limit(fb, x, 2)
    lm_x_ne2 = sp.limit(fb, x, -2)

    if (lm_x_2 != 3):
        y.append(2)
    if (lm_x_ne2 != 4):
        y.append(-2)
    for c in np.arange(-100, 101, 1):
        if c == 2 or c == -2:
            continue
        else:
            if fb.subs(x, c) != sp.limit(fb, x, c):
                y.append(c)

    print("f(x) is continous for all x except: ", y)


def ex6cexe():
    print("Bai 6c: ")

    fc = (x**2 - x - 2) / (x - 2)

    y = []
    # At point
    lm_x_2 = sp.limit(fc, x, 2)

    if (lm_x_2 != 1):
        y.append(2)

    for c in np.arange(-100, 101, 1):
        if c == 2:
            continue
        else:
            if fc.subs(x, c) != sp.limit(fc, x, c):
                y.append(c)

    print("f(x) is continous for all x except: ", y)


def ex6dexe():
    print("Bai 6d: ")

    fd = (x**2 - x - 2) / (x - 2)

    y = []
    # At point
    lm_x_0 = sp.limit(fd, x, 0)

    if (lm_x_0 != 1):
        y.append(0)

    for c in np.arange(-100, 101, 1):
        if c == 0:
            continue
        else:
            if fd.subs(x, c) != sp.limit(fd, x, c):
                y.append(c)

    print("f(x) is continous for all x except: ", y)


def ex7aexe():
    print("Bai 7a: ")

    fa = (x**2 - x - 2) / (x - 2)
    y = []
    for c in range(-100, 101, 1):
        if sp.limit(fa, x, c) != fa.subs(x, c):
            y.append(c)

    print("place that 7a functions discontinuous: ", y)


def ex7bexe():
    print("Bai 7b: ")

    fb = (x**2 - 2*x - 3) / (2*x - 6)
    y = []
    for c in range(-100, 101, 1):
        if sp.limit(fb, x, c) != fb.subs(x, c):
            y.append(c)

    print("place that 7b functions discontinuous: ", y)


def ex8fx(x):
    return 1 - (1-x**2)**(1/2)


def checkex8fx(a, b):
    if ex8fx(a) is None or ex8fx(b) is None:
        return False
    if abs(ex8fx(a + 0.000001) - ex8fx(a + 0.000001)) > 0.000001 or abs(ex8fx(b + 0.000001) - ex8fx(b-0.000001)) > 0.000001:
        return False

    return True


def ex8exe():
    print("Bai 8: ")

    if checkex8fx(-1, 1):
        print("the function is continuous ont the interval [-1,1]")
    else:
        print("the function is not continuous ont the interval [-1,1]")


def ex9fx(x):
    return sp.sin(10*(m.pi)) / x


def slopeOfPQ(x):
    return (ex9fx(x) - ex9fx(1)) / (x - 1)


def ex9exe():
    print("Bai 9: ")

    x = [2, 1.5, 1.4, 1.3, 1.2, 1.1, 0.5, 0.6, 0.7, 0.8, 0.9]
    for xi in x:
        print("slope of PQ with x = ", xi, ": ", slopeOfPQ(xi))



# ex1a()
# ex1b()
# ex1c()
# ex1d()
# ex1e()
# ex1f()
# ex1g()
# ex1h()
# ex1i()
# ex1j()
# ex1k()
# ex1l()
# ex1m()
# ex1n()

# ex2a()
# ex2b()
# ex2c()
# ex2d()
# ex2e()
# ex2f()
# ex2g()
# ex2h()
# ex2i()
# ex2j()
# ex2k()
# ex2l()
# ex2m()


ex3aexe()
ex3bexe()
# ex4exe()
# ex5aexe()
# ex5bexe()
# ex6aexe()
# ex6bexe()
# ex6cexe()
# ex6dexe()
# ex7aexe()
# ex7bexe()
# ex8exe()
# ex9exe()
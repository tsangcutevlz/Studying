import sympy as sp
import numpy as np
import math as m

x = sp.symbols('x')


def ex4a(order):
    result = 0
    for n in range(order + 1):
        term = ((-1) ** n) * (x ** (2 * n)) / sp.factorial(2 * n)
        result += term
    return result


def ex4b(order):
    result = 0
    for n in range(order + 1):
        term = x**n / sp.factorial(n)
        result += term
    return result


def ex4b(order):
    result = 0
    for n in range(order + 1):
        term = x**n / sp.factorial(n)
        result += term
    return result


def ex4c(order):
    result = 0
    for n in range(order + 1):
        term = x**n
        result += term
    return result


def ex4d(order):
    result = 0
    for n in range(order + 1):
        term = ((-1)**n) * (x**(2*n + 1)) / (2*n + 1)
    return result


def ex4():
    print("4a: ", ex4a(6))
    print("4b: ", ex4b(12))
    print("4c: ", ex4c(12))
    print("4d: ", ex4d(12))


def ex5():
    fx = (4*(x**2) + 1) / (3*(x**2) + 2)
    gx = (3*(5**x) - 2**x) / (4**x + 2*(5**x))

    limitfx = sp.limit(fx, x, sp.oo)
    limitgx = sp.limit(gx, x, sp.oo)
    print("5a: ", limitfx)
    print("5d: ", limitgx)


def ex6():
    fx = sp.exp(1/x)
    gx = sp.exp((x**3) / (x**3 + 1))
    limit = sp.limit(fx, x, sp.oo)
    limitt = sp.limit(gx, x, sp.oo)

    if (limit < 1000000 and limit > -100000):
        print("6e: Limit as x approaches infinity: ", limit)
    else:
        print("diverges")
    if (limitt < 1000000 and limit > -100000):
        print("6b: Limit as x approaches infinity: ", limit)
    else:
        print("diverges")


def ex7sub(n):
    sequence = [2]
    for _ in range(n - 1):
        fn = sequence[-1]
        fn_plus_1 = fn / (fn + 1)
        sequence.append(fn_plus_1)
    return sequence


def ex7():
    five = ex7sub(5)
    print("the first five terms: ")
    for i, term in enumerate(five, start=1):
        print(f"f{i} = {term}")


def ex9():
    fx = 5 / (2**x)
    limit = sp.limit(fx, x, 100)
    if (limit < 1000000 and limit > -100000):
        print("9b: convergent")
    else:
        print("9b: convergent")

ex9()

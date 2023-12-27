import sympy as sp
import numpy as np
import matplotlib.pyplot as plt

x = sp.symbols("x")

def intersectionPointsA(A):
    fx = x**2 - 2*A*x - A**2
    gx = -(x**2) + 4*A*x + A**3
    fakeFunction = sp.Eq(fx, gx)
    points = sp.solve((fakeFunction), x)
    return points

def intersectionPointsB(A):
    fx = (x**2 - 2*A*x - A**2) - 4*(A**3)
    gx = -(2*A*x) - A**2
    fakeFunction = sp.Eq(fx, gx)
    points = sp.solve((fakeFunction), x)
    return points

def ex1a(A):
    i = 1
    fx = x**2 - 2*A*x - A**2
    gx = -(x**2) + 4*A*x + A**3
    k = np.arange(-3000, 3001, 1)
    h = np.arange(-3000, 3001, 1)
    f = sp.lambdify(x, fx, 'numpy')
    g = sp.lambdify(x, gx, 'numpy')
    interPoints = intersectionPointsA(A)
    plt.plot(k, f(k), label='f(x)')
    plt.plot(h, g(h), label='g(x)')
    for point in interPoints:
        save = f(point)
        plt.scatter(point, save, color='black')
        print("Intersection point:",i,"(", point.evalf(), ",", save.evalf(), ")")
        i += 1
    plt.title('Question 1a')
    plt.legend()
    plt.show()

def ex1b(A):
    i = 1
    fx = x**2 - 2*A*x - A**2
    hx = (x**2 - 2*A*x - A**2) - 4*(A**3)
    fxprime = sp.diff(fx,x,1)
    tx = fxprime.subs(x, 0)*x - A**2 
    k = np.arange(-3000, 3001, 1)
    f = sp.lambdify(x, fx, 'numpy')
    h = sp.lambdify(x, hx, 'numpy')
    t = sp.lambdify(x, tx, 'numpy')
    plt.plot(k, f(k), label='f(x)')
    plt.plot(k, h(k), label='shifted f(x)')
    plt.plot(k, t(k), label='tangent line to f(x)')
    plt.scatter(0, f(0), color='green')
    print("Equation of the tangent line to the curve f(x) : -90*x - 2025")
    interPoints = intersectionPointsB(A)
    for point in interPoints:
        save = h(point)
        plt.scatter(point, save, color='black')
        print("Intersection point", i,
              ": (", point.evalf(), ",", save.evalf(), ")")
        i = i + 1
    plt.title('Question 1b')
    plt.legend()
    plt.show()

def ex1c(A):
    i = 0
    fx = x**2 - 2*A*x - A**2
    tx = sp.diff(fx, x, 1)*(-x) + fx + 4*(A**3)
    k = np.arange(-3000, 3001, 1)
    f = sp.lambdify(x, fx, 'numpy')
    fakeFunction = sp.Eq(tx, 0)
    points = sp.solve((fakeFunction), x)
    for point in points:
        line1x = sp.diff(fx,x,1).subs(x, point)*(x - point) + fx.subs(x, point)
        l1x = sp.lambdify(x, line1x, 'numpy')
        plt.scatter(point, f(point), color='green')
        print('1c. Equation of the tangent line', i + 1,'to the curve f(x): ', line1x.evalf())
        i = i + 1
        plt.plot(k, l1x(k))
    plt.scatter(0, -4*(A**3), color='green')
    plt.plot(k, f(k), label='f(x)')
    plt.title('Question 1c')
    plt.legend()
    plt.show()

A = 55

ex1a(A)
ex1b(A)
ex1c(A)

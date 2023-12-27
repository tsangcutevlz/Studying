import math as m
import matplotlib.pyplot as plt
import numpy as np
import sympy as sp

#######

x,y,t = sp.symbols('x y t')


#######


def draw3D(f, a, b, color, ax):
    x = np.arange(a, b+0.1, 0.1)
    y = x.copy()
    X, Y = np.meshgrid(x, y)
    Z = f(X, Y)
    if(type(Z) != type(f)):
        Z= np.array([[Z for i in range(len(x))] for i in range(len(y))])
    ax.plot_surface(X, Y, Z, cmap=color)


#######


def ex1():
    def fa(x, y): return x**2 + x*(y**3)
    def fb(x, y, z): return (x-y) / (y**2 + z**2)
    print("1a: f(0,0):", fa(0, 0))
    print("1a: f(-1,1):", fa(-1, 1))
    print("1a: f(2,3):", fa(2, 3))
    print("1a: f(-3,-2):", fa(-3, -2))
    print("1b: f(3,-1,2):", fb(3, -1, 2))
    print("1b: f(1,1/2,1/4):", fb(1, 1/2, 1/4))
    print("1b: f(0,-1/3,0):", fb(0, -1/3, 0))
    print("1b: f(2,2,100):", fb(2, 2, 100))


def ex2a():
    def fa(x, y): return np.cos(x)*np.cos(y) * \
        (np.e**(-((x**2 + y**2)**(1/2))/4))
    ax = plt.axes(projection='3d')
    draw3D(fa, -5, 5, 'twilight_shifted', ax)
    plt.show()


def ex2b():
    def fb(x, y): return -(x*(y**2))/(x**2 + y**2)
    ax = plt.axes(projection='3d')
    draw3D(fb, -5, 5, 'twilight_shifted', ax)
    plt.show()


def ex2c():
    def fc(x, y): return x*y*(x**2 - y**2)/(x**2 + y**2)
    ax = plt.axes(projection='3d')
    draw3D(fc, -5, 5, 'twilight_shifted', ax)
    plt.show()


def ex2d():
    def fd(x, y): return y**2 - y**4 - x**2
    ax = plt.axes(projection='3d')
    draw3D(fd, -5, 5, 'twilight_shifted', ax)
    plt.show()

def ex3n():
    fd = m.e**(-x)*sp.sin(x+y)
    fdxprime = sp.diff(fd, x)
    fdyprime = sp.diff(fd, y)
    fx1 = sp.lambdify((x,y), fdxprime, 'numpy')
    fx2 = sp.lambdify((x,y), fdyprime, 'numpy')
    ax = plt.axes(projection='3d')
    draw3D(fx1, -5, 5, 'twilight_shifted', ax)
    draw3D(fx2, -5, 5, 'twilight_shifted', ax)
    plt.show()

def ex3m():
    fd = (x*y - 1)**2
    fdxprime = sp.diff(fd, x)
    fdyprime = sp.diff(fd, y)
    fx1 = sp.lambdify((x,y), fdxprime, 'numpy')
    fx2 = sp.lambdify((x,y), fdyprime, 'numpy')
    ax = plt.axes(projection='3d')
    draw3D(fx1, -5, 5, 'twilight_shifted', ax)
    draw3D(fx2, -5, 5, 'twilight_shifted', ax)
    plt.show()

def ex4a():
    fd = sp.sin(x*y)
    fdx1prime = sp.diff(fd, x, 2)
    fdy1prime = sp.diff(fd, y, 2)
    fdxyprime = sp.diff(fdx1prime, y, 1)
    fx1 = sp.lambdify((x,y), fdx1prime, 'numpy')
    fx2 = sp.lambdify((x,y), fdy1prime, 'numpy')
    fx3 = sp.lambdify((x,y), fdxyprime, 'numpy')
    ax = plt.axes(projection='3d')
    draw3D(fx1, -5, 5, 'twilight_shifted', ax)
    draw3D(fx2, -5, 5, 'twilight_shifted', ax)
    draw3D(fx3, -5, 5, 'twilight_shifted', ax)
    plt.show()
def ex4b():
    fd = x + y +x*y
    fdx1prime = sp.diff(fd, x, 2)
    fdy1prime = sp.diff(fd, y, 2)
    fdxyprime = sp.diff(fdx1prime, y, 1)
    fx1 = sp.lambdify((x,y), fdx1prime, 'numpy')
    fx2 = sp.lambdify((x,y), fdy1prime, 'numpy')
    fx3 = sp.lambdify((x,y), fdxyprime, 'numpy')
    ax = plt.axes(projection='3d')
    draw3D(fx1, -5, 5, 'twilight_shifted', ax)
    draw3D(fx2, -5, 5, 'twilight_shifted', ax)
    draw3D(fx3, -5, 5, 'twilight_shifted', ax)
    plt.show()

def ex5a():
    fx = x*sp.sin(y) + y*sp.sin(x) + x*y
    fxprime1 = sp.diff(fx, x, 1)
    fxprime2 = sp.diff(fxprime1, y, 1)
    fxprime3 = sp.diff(fx, y, 1)
    fxprime4 = sp.diff(fxprime3, x, 1)

    print("cau 5a:")
    if fxprime2 == fxprime4:
        print("f''(x,y) = f''(y,x)")
    else:
        print("f''(x,y) != f''(y,x)")

def ex5c():
    fx = x*(y**2) + x**2*(y**3) + x**3*(y**4)
    fxprime1 = sp.diff(fx, x, 1)
    fxprime2 = sp.diff(fxprime1, y, 1)
    fxprime3 = sp.diff(fx, y, 1)
    fxprime4 = sp.diff(fxprime3, x, 1)
    print("cau 5c:")

    if fxprime2 == fxprime4:
        print("f''(x,y) = f''(y,x)")
    else:
        print("f''(x,y) != f''(y,x)")

def ex6a():
    fx = y**2*(x**4)*(m.e**x) + 2
    fxprime = sp.diff(fx,(x,2),(y,3))
    print("6a: ", fxprime)

def ex6b():
    fx = x**5 + 5*x*y + sp.sin(x) + 7*(m.e**x)
    fxprime = sp.diff(fx,(x,2),(y,3))
    print("6c: ", fxprime)

def ex7a():
    x = sp.cos(t)
    y = sp.sin(t)
    w = x**2 + y**2
    wprime = sp.diff(w, t, 1)
    k = 1
    print("7a: ", wprime.subs(wprime, k))

def ex7b():
    x = sp.cos(t) + sp.sin(t)
    y = sp.cos(t) - sp.sin(t)
    w = x**2 + y**2
    wprime = sp.diff(w, t, 1)
    k = 1
    print("7b: ", wprime.subs(wprime, k))

def ex9():
    fa = x**2 + x*(y**3)
    df_dx = sp.diff(fa, x)
    df_dy = sp.diff(fa, y)
    point = {x: 3, y: 2}
    slope_x = df_dx.subs(point)
    slope_y = df_dy.subs(point)
    ax = plt.axes(projection='3d')
    ax.scatter([3], [2], [slope_x, slope_y], color='r', s=100, label='Point (3, 2)')
    plt.show()
ex9()

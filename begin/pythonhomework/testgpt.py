import sympy as sp
import numpy as np
import matplotlib.pyplot as plt
x, y, z = sp.symbols('x y z')


def ve(start, stop, f, color, label):
    x1 = np.arange(start, stop, 0.5)
    for i in range(len(f)):
        func = f[i]
        y = [func(xi) for xi in x1]
        plt.plot(x1, y, color=color, label=label)
    plt.grid()
    plt.legend()
    plt.show()


def ex_01():
    def a():
        fxy = x**2+x*y**3
        f00 = fxy.subs({x: 0, y: 0})
        print(f00)
        f11 = fxy.subs({x: -1, y: 1})
        print(f11)
        f23 = fxy.subs({x: 2, y: 3})
        print(f23)
        f32 = fxy.subs({x: -3, y: -2})
        print(f32)

    def b():
        fxyz = (x-y)/(y**2+z**2)
        f312 = fxyz.subs({x: 3, y: -1, z: 2})
        print(f312)
        f11214 = fxyz.subs({x: 1, y: 1/2, z: 1/4})
        print(f11214)
        f0130 = fxyz.subs({x: 0, y: -1/3, z: 0})
        print(f0130)
        f22100 = fxyz.subs({x: 2, y: 2, z: 100})
        print(f22100)
    a()
    b()


ex_01()


def ex_02():
    def a():
        fxy = sp.cos(x) * sp.cos(y) * sp.exp(-sp.sqrt(x**2 + y**2) / 4)
        ve(-10, 10, fxy, "red", "cau a")

    def b():
        fxy = -(x*y**2)/(x**2 + y**2)
        ve(-10, 10, fxy, "red", "cau b")

    def c():
        fxy = x*y*(x**2 - y**2)/(x**2 + y**2)
        ve(-10, 10, fxy, "red", "cau c")

    def d():
        fxy = y**2 - y**4 - x**2
        ve(-10, 10, fxy, "red", "cau d")
    a()
    b()
    c()
    d()


ex_02()


def ex_03():
    def a():
        fxy = 2*x**2-3*y-4
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau a")

    def b():
        fxy = (x**2-1)*(y+2)
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau b")

    def c():
        fxy = x**2-x*y+y**2
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau c")

    def d():
        fxy = 5*x*y - 7*x**2 - y**2 + 3*x - 6*y + 2
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau d")

    def e():
        fxy = (x*y-1)**2
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau e")

    def f():
        fxy = (2*x-3*y)**3
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau f")

    def g():
        fxy = sp.sqrt(x**2+y**2)
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau g")

    def h():
        fxy = (x**3 + y/2)**(2/3)
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau h")

    def i():
        fxy = 1/(x+y)
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau i")

    def j():
        fxy = x/(x**2+y**2)
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau j")

    def k():
        fxy = (x+y)/(x*y-1)
        dh = sp.diff(fxy, x)
        dh1 = sp.diff(fxy, y)
        ve(-10, 10, [fxy, dh, dh1], "red", "cau k")

#    def l():
#         x = np.radians(x)
#         y = np.radians(y)
#         fxy = np.degrees(np.arctan(y/x))
#         dh = sp.diff(fxy, x)
#         dh1 = sp.diff(fxy, y)
#         ve(-10, 10, [fxy, dh, dh1], "red", "cau l")

    # def m():
    #     fxy = sp.exp(x+y+1)
    #     dh = sp.diff(fxy,x)
    #     dh1 = sp.diff(fxy,y)
    #     ve(-10, 10, [fxy, dh,dh1], "red", "cau m")

    # def n():
    #     x = np.radians(x)
    #     y = np.radians(y)
    #     fxy = sp.exp(-x)*np.degrees(np.sin(x+y))
    #     dh = sp.diff(fxy,x)
    #     dh1 = sp.diff(fxy,y)
    #     ve(-10, 10, [fxy, dh,dh1], "red", "cau n")

    # def o():
    #     fxy = sp.log(x+y)
    #     dh = sp.diff(fxy,x)
    #     dh1 = sp.diff(fxy,y)
    #     ve(-10, 10, [fxy, dh,dh1], "red", "cau o")
    k()
ex_03()
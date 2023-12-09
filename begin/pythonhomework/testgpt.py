import sympy as sp
import numpy as np
import matplotlib.pyplot as plt

def ex2c():
    # Khai báo biến
    x = sp.symbols('x')

    # Định nghĩa hàm số
    fx = 8 / sp.sqrt(x - 2)

    # Tính đạo hàm của hàm số
    fx_prime = sp.diff(fx, x, 1)

    # Tính giá trị của đạo hàm tại x = 6
    slope_at_x6 = fx_prime.subs(x, 6)

    # Tìm phương trình của đường tiếp tuyến
    tangent_equation = slope_at_x6 * (x - 6) + 4

    # Chuyển hàm số và đường tiếp tuyến thành hàm numpy
    f = sp.lambdify(x, fx, 'numpy')
    t = sp.lambdify(x, tangent_equation, 'numpy')

    # Tạo mảng giá trị x
    k = np.linspace(-6, 6, 1000)

    # Tính giá trị của hàm số và đường tiếp tuyến tương ứng
    func = np.piecewise(k, [k < 2, k >= 2], [lambda k: np.nan, lambda k: t(k)])
    original_func = f(k)

    # Vẽ đồ thị
    plt.plot(k, func, label='Tangent line')
    plt.plot(k, original_func, label='Original function')
    plt.scatter([6], [4], color='red', marker='o', label='Point of tangency (6, 4)')

    # Đặt tiêu đề và chú thích
    plt.title("2g")
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()

    # Hiển thị đồ thị
    plt.grid(True)
    plt.show()

# Gọi hàm để hiển thị đồ thị
ex2c()

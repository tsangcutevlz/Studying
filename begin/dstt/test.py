import numpy as np

# Hàm Gauss_3x3 sửa lại
def Gauss_3x3(C):
    temp_row_1 = C[1, 0] / C[0, 0]
    temp_row_2 = C[2, 0] / C[0, 0]
    C[1] = C[1] - temp_row_1 * C[0]
    C[2] = C[2] - temp_row_2 * C[0]
    temp_col_2 = C[2, 1] / C[1, 1]
    C[2] = C[2] - temp_col_2 * C[1]
    z = C[2, 2] / C[2, 2]
    y = (C[1, 3] - C[1, 2] * z) / C[1, 1]
    x = (C[0, 3] - C[0, 2] * z - C[0, 1] * y) / C[0, 0]
    return x, y, z

# Ma trận hệ số và vector hằng số
A = np.array([[1, 1, 2, 1],
              [3, 6, -5, -1],
              [2, 4, -3, 0]], dtype=float)

# Gọi hàm Gauss_3x3
x, y, z = Gauss_3x3(A.copy())

# So sánh kết quả với giá trị đã cho
expected_x, expected_y, expected_z = -9, 6, 2
print("Computed x, y, z:", x, y, z)
print("Expected x, y, z:", expected_x, expected_y, expected_z)

# Kiểm tra xem kết quả có khớp với giá trị đã cho không
if np.allclose((x, y, z), (expected_x, expected_y, expected_z)):
    print("Kết quả chính xác.")
else:
    print("Kết quả không chính xác.")

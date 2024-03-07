import numpy as np

T = np.array([[0.6, 0.7], [0.4, 0.3]])
p = np.array([0.5, 0.5])
k = np.array([1, 2, 10, 10, 100000])
print("cau 9: ")
for ki in k:
    print("For k =", ki, ", pk =", np.dot(
        np.linalg.matrix_power(T, ki), p))
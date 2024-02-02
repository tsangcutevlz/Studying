import numpy as np

# Assuming vector_x is your NumPy array
vector_x = np.array([3, 11, -9, -131, -1, 1, -11, 91, -6, 407, -12, -11, 12, 153, 371, 3, 91, -9])

# Find unique elements
unique_elements = np.unique(vector_x)

print("Original array:", vector_x)
print("Unique elements:", unique_elements)

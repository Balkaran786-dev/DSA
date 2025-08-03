import numpy as np
#Generate a random dataset 
np.random.seed(0)
X = np.random.rand(10, 3)  # 10 samples, 3 features

n = len(X)
#finding mean for both features
mean_vector = [sum([x[i] for x in X]) / n for i in range(2)]
X_centered = [[x[i] - mean_vector[i] for i in range(2)] for x in X]


#covariance matrix
cov_matrix = [[0, 0], [0, 0]]
for i in range(2):
    for j in range(2):
        cov_matrix[i][j] = sum(X_centered[k][i] * X_centered[k][j] for k in range(n)) / (n - 1)


#to find the unit eigen vector
def power_iteration(matrix, num_simulations=100):
    b_k = [1, 1]  # Start with a random vector
    for _ in range(num_simulations):
        # Calculate the matrix-by-vector product
        b_k1 = [sum(matrix[i][j] * b_k[j] for j in range(len(matrix))) for i in range(len(matrix))]
        
        # Normalize the vector
        norm = sum(x ** 2 for x in b_k1) ** 0.5
        b_k = [x / norm for x in b_k1]
    return b_k


principal_component = power_iteration(cov_matrix)


#PCA computation
X_reduced = [sum(x[i] * principal_component[i] for i in range(2)) for x in X_centered]

print("Original data:")
print(X)
print("Reduced data:")
print(X_reduced)

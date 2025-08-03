import matplotlib.pyplot as plt
import numpy as np

# Pie Chart
def draw_pie_chart():
    # Data for the pie chart
    labels = ['Category A', 'Category B', 'Category C', 'Category D']
    sizes = [25, 35, 20, 20]  # Percentages
    colors = ['gold', 'lightblue', 'lightgreen', 'salmon']
    explode = (0.1, 0, 0, 0)  # Highlight the first slice

    # Create pie chart
    plt.figure(figsize=(6, 6))
    plt.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%', startangle=140)
    plt.title('Pie Chart Example')
    plt.show()

# Scatter Plot
def draw_scatter_plot():
    # Data for scatter plot
    np.random.seed(42)
    x = np.random.rand(50) * 10  # Random x-coordinates
    y = np.random.rand(50) * 10  # Random y-coordinates
    colors = np.random.rand(50)  # Random color values
    sizes = np.random.rand(50) * 300  # Random sizes for markers

    # Create scatter plot
    plt.figure(figsize=(8, 6))
    plt.scatter(x, y, c=colors, s=sizes, alpha=0.6, cmap='viridis')
    plt.colorbar(label='Color Intensity')  # Add a color bar
    plt.title('Scatter Plot Example')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.grid(True)
    plt.show()

# Draw the charts
draw_pie_chart()
draw_scatter_plot()



import numpy as np

def pca(data, num_components):
    """
    Perform Principal Component Analysis (PCA) on the dataset.

    Parameters:
    - data: A 2D numpy array where each row is a data point, and each column is a feature.
    - num_components: Number of principal components to keep.

    Returns:
    - transformed_data: Data projected onto the principal components.
    - explained_variance: Variance explained by each principal component.
    """
    # Step 1: Standardize the dataset (zero mean for each feature)
    mean = np.mean(data, axis=0)
    centered_data = data - mean

    # Step 2: Compute the covariance matrix
    covariance_matrix = np.cov(centered_data, rowvar=False)

    # Step 3: Perform eigen decomposition of the covariance matrix
    eigenvalues, eigenvectors = np.linalg.eigh(covariance_matrix)

    # Step 4: Sort eigenvalues and eigenvectors in descending order
    sorted_indices = np.argsort(eigenvalues)[::-1]
    eigenvalues = eigenvalues[sorted_indices]
    eigenvectors = eigenvectors[:, sorted_indices]

    # Step 5: Select the top `num_components` eigenvectors
    principal_components = eigenvectors[:, :num_components]

    # Step 6: Transform the data
    transformed_data = np.dot(centered_data, principal_components)

    return transformed_data, eigenvalues[:num_components]

# Example Usage
if __name__ == "__main__":
    # Example dataset (rows are samples, columns are features)
    data = np.array([[2.5, 2.4],
                     [0.5, 0.7],
                     [2.2, 2.9],
                     [1.9, 2.2],
                     [3.1, 3.0],
                     [2.3, 2.7],
                     [2, 1.6],
                     [1, 1.1],
                     [1.5, 1.6],
                     [1.1, 0.9]])

    # Apply PCA to reduce to 1 dimension
    transformed_data, explained_variance = pca(data, num_components=1)

    print("Transformed Data:")
    print(transformed_data)
    print("\nExplained Variance:")
    print(explained_variance)


# # import numpy as np
# # import matplotlib.pyplot as plt

# # # Example dataset
# # # X: Independent variable
# # # Y: Dependent variable
# # X = np.array([1, 2, 3, 4, 5], dtype=float)
# # Y = np.array([2, 4, 5, 4, 5], dtype=float)

# # # Step 1: Calculate the mean of X and Y
# # X_mean = np.mean(X)
# # Y_mean = np.mean(Y)

# # # Step 2: Calculate the slope (m) and intercept (b)
# # numerator = np.sum((X - X_mean) * (Y - Y_mean))
# # denominator = np.sum((X - X_mean)**2)
# # m = numerator / denominator
# # b = Y_mean - m * X_mean

# # # Display the coefficients
# # print(f"Slope (m): {m}")
# # print(f"Intercept (b): {b}")

# # # Step 3: Define the regression line
# # def predict(x):
# #     return m * x + b

# # # Step 4: Make predictions for the dataset
# # Y_pred = predict(X)

# # # Step 5: Visualize the dataset and the regression line
# # plt.scatter(X, Y, color='blue', label='Data Points')
# # plt.plot(X, Y_pred, color='red', label='Regression Line')
# # plt.xlabel('X')
# # plt.ylabel('Y')
# # plt.legend()
# # plt.title('Linear Regression')
# # plt.show()


# import numpy as np
# import matplotlib.pyplot as plt

# X=np.array([1,2,3,4,5],dtype=float)
# Y=np.array([2,4,5,4,5],dtype=float)

# X_mean=np.mean(X)
# Y_mean=np.mean(Y)

# numerator=np.sum((X-X_mean)*(Y-Y_mean))
# denomerator=np.sum((X-X_mean)**2)

# m=numerator/denomerator

# b=Y_mean-m*X_mean

# print(f"slope (m):{m}")
# print(f"intercept (b):{b}")
# def pred(x):
#     return m*x+b

# Y_pred=pred(X)


# plt.scatter(X,Y,color="blue",label="datapoints")
# plt.plot(X,Y_pred,color="Red",label="Regression line")

# plt.xlabel('X')
# plt.ylabel('Y')

# plt.legend()

# plt.title('Regression line')
# plt.show()


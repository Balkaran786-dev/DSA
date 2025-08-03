# import pandas as pd
# import matplotlib.pyplot as plt

# file_path = "C:\\Users\\Balkaran\\Downloads\\UNSW_NB15 Dataset.csv" 
# data = pd.read_csv(file_path)

# print(data.columns) 
# print(data.head())   

# column_name = 'dur'  
# if column_name in data.columns:
   
#     category_counts = data[column_name].value_counts()

#     plt.figure(figsize=(8, 8))
#     plt.pie(category_counts, labels=category_counts.index, autopct='%1.1f%%', startangle=140)
#     plt.title(f"Distribution of {column_name} in UNSW_NB15 Dataset")
#     plt.axis('equal') 
#     plt.show()
# else:

#     print(f"Column '{column_name}' not found in the dataset.")


# import pandas as pd
# import numpy as np
# import matplotlib.pyplot as plt
# from sklearn.decomposition import PCA
# from sklearn.preprocessing import StandardScaler

# # Load the dataset
# file_path = "C:\\Users\\Balkaran\\Downloads\\UNSW_NB15 Dataset.csv"  # Update this with the correct file path
# data = pd.read_csv(file_path)

# column1 = 'sttl'  
# column2 = 'smean' 

# selected_data = data[[column1, column2]] 
# scaler = StandardScaler()
# standardized_data = scaler.fit_transform(selected_data)
# pca = PCA(n_components=2) 
# pca_result = pca.fit_transform(standardized_data)
# explained_variance = pca.explained_variance_ratio_

# plt.figure(figsize=(10, 6))

# plt.scatter(standardized_data[:, 0], standardized_data[:, 1], alpha=0.6, label='Original Data')

# plt.scatter(pca_result[:, 0], pca_result[:, 1], alpha=0.6, label='PCA Components')

# plt.title(f"PCA on Columns: {column1} & {column2}")
# plt.xlabel("Principal Component 1")
# plt.ylabel("Principal Component 2")
# plt.legend()
# plt.grid()
# plt.show()


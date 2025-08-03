import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from scipy.stats import skew

# Load the Iris dataset
iris = load_iris(as_frame=True)
data = iris['data']
data['species'] = iris['target']
data['species'] = data['species'].map({0: 'Setosa', 1: 'Versicolor', 2: 'Virginica'})

# Task 1: Probability of selecting a flower from each species
species_counts = data['species'].value_counts()
total_flowers = len(data)
probabilities = species_counts / total_flowers

print("Probabilities of each species:")
print(probabilities)

# Task 2: Distribution of petal and sepal lengths
summary_stats = data.groupby('species').agg(['mean', 'std', 'median'])
print("\nSummary statistics for petal and sepal lengths:")
print(summary_stats)

# Task 3: Conditional probability
def simple_conditional_probability(petal_length, sepal_width):
    results = {}
    for species in data['species'].unique():
        # Get the species-specific data
        species_data = data[data['species'] == species]
        
        # Calculate mean and standard deviation for petal length and sepal width
        petal_length_mean = species_data['petal length (cm)'].mean()
        sepal_width_mean = species_data['sepal width (cm)'].mean()
        
        # Use squared differences to estimate "closeness"
        petal_length_diff = abs(petal_length - petal_length_mean)
        sepal_width_diff = abs(sepal_width - sepal_width_mean)
        
        # Combine the differences (smaller differences mean higher probability)
        combined_score = 1 / (petal_length_diff + sepal_width_diff + 1e-5)  # Avoid division by zero
        
        results[species] = combined_score
    
    # Normalize the results so they sum to 1
    total_score = sum(results.values())
    probabilities = {species: score / total_score for species, score in results.items()}
    
    return probabilities

# Example dimensions
dimensions = {'petal_length': 5.5, 'sepal_width': 3.5}
probabilities = simple_conditional_probability(dimensions['petal_length'], dimensions['sepal_width'])

# Print results
print(f"Given Petal Length = {dimensions['petal_length']} cm and Sepal Width = {dimensions['sepal_width']} cm:")
for species, prob in probabilities.items():
    print(f"Probability of being {species}: {prob:.4f}")

# Task 4: Histograms
sns.histplot(data=data, x='petal length (cm)', hue='species', kde=True, bins=20)
plt.title('Petal Length Distribution')
plt.show()

sns.histplot(data=data, x='sepal width (cm)', hue='species', kde=True, bins=20)
plt.title('Sepal Width Distribution')
plt.show()

# Skewness analysis
print("\nSkewness of petal length:")
print(data.groupby('species')['petal length (cm)'].apply(skew))

print("\nSkewness of sepal width:")
print(data.groupby('species')['sepal width (cm)'].apply(skew))

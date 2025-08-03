import pandas as pd

# Load the dataset
df = pd.read_csv("C:\\Users\\Balkaran\\OneDrive\\Desktop\\aapl_stock_data.csv")

# Ensure the 'Date' column is in datetime format
df['Date'] = pd.to_datetime(df['Date'])

# Sort the data by Date to make sure the time series is ordered
df = df.sort_values('Date')

# Calculate daily returns using 'Close' column
df['Daily_Return'] = df['Close'].pct_change() * 100  # Convert to percentage

# Drop NaN values created by pct_change
df = df.dropna(subset=['Daily_Return'])

# Calculate mean, variance, and standard deviation
mean_return = df['Daily_Return'].mean()
variance_return = df['Daily_Return'].var()
std_dev_return = df['Daily_Return'].std()

# Print the results
print(f"Mean Daily Return: {mean_return}")
print(f"Variance of Daily Return: {variance_return}")
print(f"Standard Deviation of Daily Return: {std_dev_return}")



import matplotlib.pyplot as plt
import scipy.stats as stats
import numpy as np

# Plot the histogram of daily returns
plt.hist(df['Daily_Return'].dropna(), bins=50, density=True, alpha=0.6, color='b')

# Fit a normal distribution to the data
mu, std = stats.norm.fit(df['Daily_Return'].dropna())

# Plot the normal distribution curve
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = stats.norm.pdf(x, mu, std)
plt.plot(x, p, 'k', linewidth=2)

plt.title('Fit a Normal Distribution to Daily Returns')
plt.xlabel('Daily Return (%)')
plt.ylabel('Density')
plt.show()



sample_means = []
sample_sizes = [5, 10, 30, 50, 100]

for size in sample_sizes:
    # Take 1000 samples of the given size
    for _ in range(1000):
        sample = df['Daily_Return'].dropna().sample(size)
        sample_means.append(sample.mean())

# Plot the distribution of sample means
plt.hist(sample_means, bins=50, density=True, alpha=0.6, color='g')
plt.title('Central Limit Theorem: Distribution of Sample Means')
plt.xlabel('Sample Mean of Daily Returns')
plt.ylabel('Density')
plt.show()


skewness = df['Daily_Return'].skew()
kurtosis = df['Daily_Return'].kurt()

print(f"Skewness of Daily Returns: {skewness}")
print(f"Kurtosis of Daily Returns: {kurtosis}")

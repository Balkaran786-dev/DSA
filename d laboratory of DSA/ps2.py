import pandas as pd

# Load the dataset
data = pd.read_csv("C:\\Users\\Balkaran\\OneDrive\\Desktop\\online_retail_09_10.csv")  # Adjust the path to your dataset
data['InvoiceDate'] = pd.to_datetime(data['InvoiceDate'])

# Add a column for Total Purchase Amount
data['TotalAmount'] = data['Quantity'] * data['UnitPrice']

# Filter for two specific months
data['Month'] = data['InvoiceDate'].dt.month
month1 = data[data['Month'] == 5]  # Example: May
month2 = data[data['Month'] == 11]  # Example: November

from scipy.stats import ttest_ind

# Extract purchase amounts for the two months
purchase_month1 = month1['TotalAmount']
purchase_month2 = month2['TotalAmount']

# Perform the t-test
t_stat, p_value = ttest_ind(purchase_month1, purchase_month2, nan_policy='omit')

# Results
print(f"T-statistic: {t_stat:.4f}")
print(f"P-value: {p_value:.4f}")

# Significance level
alpha = 0.05
if p_value < alpha:
    print("Reject the null hypothesis: Significant difference in average purchase amounts.")
else:
    print("Fail to reject the null hypothesis: No significant difference in average purchase amounts.")

import numpy as np
from scipy.stats import sem, t

# Function to calculate confidence intervals
def confidence_interval(data, confidence=0.95):
    mean = np.mean(data)
    n = len(data)
    stderr = sem(data, nan_policy='omit')
    h = stderr * t.ppf((1 + confidence) / 2, n - 1)
    return mean - h, mean + h

# Confidence intervals for May and November
ci_month1 = confidence_interval(purchase_month1)
ci_month2 = confidence_interval(purchase_month2)

print(f"Confidence Interval for May: {ci_month1}")
print(f"Confidence Interval for November: {ci_month2}")


import matplotlib.pyplot as plt

# Group by month and calculate total purchase amounts
monthly_totals = data.groupby('Month')['TotalAmount'].sum()

# Plot
monthly_totals.plot(kind='bar', color='skyblue', figsize=(10, 6))
plt.title('Total Purchase Amount by Month')
plt.xlabel('Month')
plt.ylabel('Total Purchase Amount')
plt.xticks(range(12), labels=['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 
                              'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'], rotation=45)
plt.show()

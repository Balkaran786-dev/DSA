rom scipy.stats import ttest_ind

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

import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats as stats

# Load the data
df = pd.read_csv('../data/execution/combined_data.csv')

# Extract the column to analyze
data = df['avg_time_sec'].dropna()

# Shapiro-Wilk test for normality
stat, p = stats.shapiro(data)
print(f"Shapiro-Wilk test statistic: {stat:.4f}, p-value: {p:.4f}")
if p > 0.05:
    print("The data appears to be normally distributed (fail to reject H0).")
else:
    print("The data does NOT appear to be normally distributed (reject H0).")

# Plot histogram
plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
plt.hist(data, bins=30, edgecolor='k', alpha=0.7)
plt.title('Histogram of avg_time_sec')
plt.xlabel('avg_time_sec')
plt.ylabel('Frequency')

# Q-Q plot
plt.subplot(1, 2, 2)
stats.probplot(data, dist="norm", plot=plt)
plt.title('Q-Q Plot')

plt.tight_layout()
plt.show()
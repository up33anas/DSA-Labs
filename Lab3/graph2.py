import pandas as pd
import matplotlib.pyplot as plt

df_daily = pd.read_csv('dailyActivity_merged.csv')

df_daily['ActivityDate'] = pd.to_datetime(df_daily['ActivityDate'])

steps_per_day = df_daily.groupby('ActivityDate')['TotalSteps'].sum().reset_index()

plt.figure(figsize=(12,6))
plt.bar(df_daily['ActivityDate'], df_daily['TotalDistance'], color='green')
plt.title('Daily Distance Covered')
plt.xlabel('Date')
plt.ylabel('Distance (km or miles)')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()
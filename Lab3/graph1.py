import pandas as pd
import matplotlib.pyplot as plt

df_daily = pd.read_csv('dailyActivity_merged.csv')

df_daily['ActivityDate'] = pd.to_datetime(df_daily['ActivityDate'])

steps_per_day = df_daily.groupby('ActivityDate')['TotalSteps'].sum().reset_index()

plt.figure(figsize=(10,6))
plt.plot(steps_per_day['ActivityDate'], steps_per_day['TotalSteps'], marker='o', color='blue')
plt.title('Total Steps Per Day (Grouped)')
plt.xlabel('Date')
plt.ylabel('Total Steps')
plt.xticks(rotation=45)
plt.grid(True)
plt.tight_layout()
plt.show()

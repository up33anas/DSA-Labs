import pandas as pd
import matplotlib.pyplot as plt

# Fitbit Data
df_daily = pd.read_csv("dailyActivity_merged.csv")
df_sleep = pd.read_csv("sleepDay_merged.csv")
df_hourly = pd.read_csv("hourlySteps_merged.csv")

# Convert dates
df_daily["ActivityDate"] = pd.to_datetime(df_daily["ActivityDate"])
df_sleep["SleepDay"] = pd.to_datetime(df_sleep["SleepDay"])
df_hourly["ActivityHour"] = pd.to_datetime(df_hourly["ActivityHour"])

# Scatter chart for Total Time in Bed
plt.figure(figsize=(10,6))
plt.scatter(df_sleep["SleepDay"], df_sleep["TotalTimeInBed"], 
            color="purple", alpha=0.6)

plt.title("Scatter Chart of Total Time in Bed", fontsize=16)
plt.xlabel("Date", fontsize=14)
plt.ylabel("Total Time in Bed (minutes)", fontsize=14)
plt.grid(True, linestyle="--", alpha=0.6)
plt.tight_layout()
plt.show()

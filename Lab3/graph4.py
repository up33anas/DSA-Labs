import pandas as pd
import matplotlib.pyplot as plt

df_hourly = pd.read_csv("hourlySteps_merged.csv")

df_hourly["ActivityHour"] = pd.to_datetime(df_hourly["ActivityHour"])

date_filter = "2016-04-12"
df_april12 = df_hourly[df_hourly["ActivityHour"].dt.date == pd.to_datetime(date_filter).date()]
df_april12["Hour"] = df_april12["ActivityHour"].dt.hour
steps_by_hour = df_april12.groupby("Hour")["StepTotal"].sum()

# Pie chart
plt.figure(figsize=(8,8))
plt.pie(
    steps_by_hour,
    labels=steps_by_hour.index,
    autopct="%1.1f%%",
    startangle=0,
    textprops={'fontsize': 8},
    pctdistance=0.8
)

plt.title("Hourly Steps on 12th April 2016")
plt.show()

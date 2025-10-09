from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import csv
import time

# Setup driver
service = Service("D:/chromedriver-win64/chromedriver.exe")
driver = webdriver.Chrome(service=service)

# Step 1: Open the index page
driver.get("https://eduko.spikotech.com/Course/Index")

# Step 2: Wait until course cards appear
courses = WebDriverWait(driver, 10).until(
    EC.presence_of_all_elements_located((By.CSS_SELECTOR, "#courseData .card"))
)

# Step 3: Now load courses
courses = driver.find_elements(By.CSS_SELECTOR, "#courseData .card")

print(f"Found {len(courses)} courses")

data = []

# Loop through all the cards and extract required data
for course in courses:
    # Course title
    course_title = course.find_element(By.CSS_SELECTOR, ".card-title").text

    # Semester and instructor 
    h7_tags = course.find_elements(By.TAG_NAME, "h7")
    instructor = h7_tags[0].text.strip() if len(h7_tags) > 0 else "N/A"
    semester   = h7_tags[1].text.strip() if len(h7_tags) > 1 else "N/A"

    # Link to course details page
    course_link = course.find_element(By.TAG_NAME, "a").get_attribute("href")

    # Go to course details page
    driver.get(course_link)
    time.sleep(2)

    # Get course info
    course_code = driver.find_element(By.CSS_SELECTOR, "#CourseCode").text.strip()
    course_description = driver.find_element(By.CSS_SELECTOR, "#CourseDescription").text.strip()

    # CLOs
    clo_elements = driver.find_elements(By.CSS_SELECTOR, "#CourseClos li")
    CLOs = [clo.text.strip() for clo in clo_elements]
    CLO1 = CLOs[0] if len(CLOs) > 0 else "N/A"
    CLO2 = CLOs[1] if len(CLOs) > 1 else "N/A"
    CLO3 = CLOs[2] if len(CLOs) > 2 else "N/A"
    CLO4 = CLOs[3] if len(CLOs) > 3 else "N/A"

    # TextBooks
    book_elements = driver.find_elements(By.CSS_SELECTOR, "#CourseBooks li")
    books = [b.text.strip() for b in book_elements]
    book1 = books[0] if len(books) > 0 else "N/A"
    book2 = books[1] if len(books) > 1 else "N/A"   

    # Make a list of the course details
    row = [course_code, course_title, course_description, CLO1, CLO2, CLO3, CLO4, book1, book2, instructor, semester]

    # Append to the data to write to the csv file
    data.append(row)

    # GO BACK TO THE PREVIOUS LINK(Index page)
    driver.back()
    time.sleep(2)

print("Scraped rows:", len(data))

# Write data to csv file
with open("eduko_data.csv", "w", encoding="utf-8", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["CourseCode","Title","Description","CLO1","CLO2","CLO3","CLO4","TextBook1","TextBook2","Instructor","Semester"])
    writer.writerows(data)

# Exit/close the driver
driver.quit()
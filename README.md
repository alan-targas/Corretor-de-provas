# Exam Grader & Answer Key Manager

A lightweight, command-line application written in Standard C designed to automate exam grading and manage answer keys. 

Built specifically for office environments and shared computers, this tool requires zero installation and stores all data locally and securely. It's the perfect solution to eliminate manual grading and speed up productivity.

## 🚀 Features

- **Automated Grading:** Enter a student's answers and instantly get a side-by-side comparison with the correct answer key.
- **Dynamic Weighted Scoring:** Supports split-scoring logic. You can set different point values for the first half and the second half of the exam.
- **Detailed Reports:** Automatically calculates total points, hit/miss count, and the final percentage.
- **Manage Answer Keys (CRUD):** Easily Add, List, Alter, or Delete exam answer keys through a simple interactive menu.
- **Local Persistence:** All data is saved automatically in a lightweight binary file (`exams_data.bin`), ensuring data is never lost between sessions.

## 💻 How to Use (For Non-Programmers)

You don't need to install any programming tools to use this software.

1. Go to the **[Releases](../../releases)** tab on the right side of this GitHub page.
2. Download the latest `.exe` file.
3. Create a new folder on your computer (e.g., on your Desktop) and place the `.exe` inside it.
4. Double-click the `.exe` to run the program.

> **⚠️ Important Note:** The first time you run the program and add an answer key, it will automatically create a file called `exams_data.bin` in the same folder. This file is your local database. **Do not delete it**, or you will lose your saved exams!

## 🛠️ How to Compile (For Developers)

If you want to compile the code yourself or contribute to the project:

1. Clone this repository:
   ```bash
   git clone [https://github.com/your-username/your-repo-name.git](https://github.com/your-username/your-repo-name.git)
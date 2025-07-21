# 🧾 Resume Builder (C++)

A simple and interactive **Resume Builder** written in **C++**, designed for console use. It collects personal and professional details from the user and generates a well-formatted resume saved as a `.txt` file. Perfect for students and learners to understand file handling, string operations, and structured input/output in C++.

---

## 🚀 Features

- 📋 Collects Name, Email, Phone, Objective
- 🎓 Supports multiple Educational Qualifications
- 💼 Handles multiple Work Experiences
- 🛠️ Lists out Skills in bulleted format
- 💾 Saves output as a formatted `.txt` file
- 🕓 Filename includes timestamp to avoid overwrite
- 🖥️ Console-based interface (simple and clean)

---

## 📁 Folder Structure

```
Resume_creator_cpp/
├── main.cpp               # C++ source code
├── resume_YYYYMMDD_HHMMSS.txt  # Auto-generated resume file
├── README.md              # You are here
```

---
## Snapshots

<img width="1821" height="945" alt="image" src="https://github.com/user-attachments/assets/b8fea57b-2f4d-4ca7-a5c3-f10e90191515" />


https://github.com/user-attachments/assets/c49aadc7-f737-4ff3-a279-6b3e16b53e03


## 🛠️ How to Run

> 💡 Make sure you have a C++ compiler like g++ or MinGW installed.

1. Open your terminal and navigate to the project folder.
2. Compile the project:
   ```bash
   g++ main.cpp -o resume.exe
   ```
3. Run the executable:
   - On Windows:
     ```bash
     .\resume.exe
     ```
   - On Linux/Mac:
     ```bash
     ./resume
     ```

4. Follow the prompts to input your resume details.
5. Your resume will be saved as `resume_<timestamp>.txt` in the same folder.

---

## 💡 Example Use Case

```
=== Resume Builder ===
-------------------------
Enter your full name: Monis Sheikh
Enter your email: monis@example.com
Enter your phone number: 9876543210
Enter your career objective: Seeking a role in software development...

Enter number of education entries: 2
Enter qualification 1: B.Tech in CSE - ABC College - 2025
Enter qualification 2: HSC - XYZ School - 2021

Enter number of experiences: 1
Enter experience 1: Intern at OpenAI - 6 months

Enter number of skills: 3
Enter skill 1: C++
Enter skill 2: DSA
Enter skill 3: Problem Solving
```

---

## 🔮 Future Enhancements

- 🖨️ Export resume in PDF format using external libraries
- 🧑‍💼 Admin dashboard to manage multiple resumes
- 💬 Add validation for email and phone formats
- 🌐 GUI version using Qt or C++/CLI

---

## 🎯 Learning Concepts

This project demonstrates:
- Object-Oriented Programming
- File handling (`ofstream`)
- User input and loops
- String manipulation
- Console formatting

---

## 👨‍💻 Author

**Monis Sheikh**  
📫 [LinkedIn](https://linkedin.com/in/monissheikh1234)  
🔗 GitHub: [@monissheikh1234](https://github.com/monissheikh1234)

---

## 🌟 Give a ⭐ on GitHub if you found this helpful!

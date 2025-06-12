# Library-Management-System
A C++ GUI-based Library Management System with CSV persistence


## ✨ Features

- 👤 Add users and manage IDs
- 📘 Add, borrow, return books and other resources
- 🔍 Search by title , author or id
- 📂 Save/load data using CSV files
- ⚠️ Detect overdue loans
- 🗓️ Manage and display library events
- 🖼️ Visual UI built with VCL (`TButton`, `TStringGrid`, `TMemo`, etc.)


## 📁 File Structure

| File | Purpose |
|------|---------|
| `LibrarySystem.cpp/.h` | Core controller logic |
| `User.cpp/.h` | User model |
| `Book.cpp/.h`, `Article.cpp/.h`, etc. | Resource types |
| `Loan.cpp/.h`, `Reservation.cpp/.h` | Lending/reserving system |
| `FileManager.cpp/.h` | CSV file I/O |
| `EventManager.cpp/.h` | Event handling |
| `users.csv`, `resources.csv`, etc. | Stored data |
| `Unit3.cpp/.h` | GUI logic and VCL components |

## 📷 Screenshots
![Screenshot 2025-06-13 014838](https://github.com/user-attachments/assets/44c67c81-07b7-4aa8-b4fe-e403655da966)
![Screenshot 2025-06-13 014814](https://github.com/user-attachments/assets/cc8eb8f1-ecd3-4046-b566-4d3af247a3a0)
![Screenshot 2025-06-13 014800](https://github.com/user-attachments/assets/8ada6e65-a48d-418e-be48-8a1f68908358)
![Screenshot 2025-06-13 014711](https://github.com/user-attachments/assets/d9779a4f-7812-4d6d-aa7d-a304cfc80de2)
![Screenshot 2025-06-13 014649](https://github.com/user-attachments/assets/7fd10782-82d6-4970-8f22-bd0d53abe05c)
![Screenshot 2025-06-13 014624](https://github.com/user-attachments/assets/e88a5cd8-a15b-44f2-9f6e-0e8a0b62bbd0)

## 🛠 How to Run

1. Open `LibraryManagementSystem.cbproj` in RAD Studio / C++Builder
2. Build and Run
3. Use the interface buttons to interact
4. Data will be saved in `.csv` files automatically

## 👨‍💻 Author

- SOUILA MARWA
- C++ Project - 2025 / National Higher School Of Artificial Intelligence / Course: object oriented programming


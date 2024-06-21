# 🎓 CGPA Calculator (Cumulative Grade Point Average Calculator)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/datpham0412/CGPA_Calculator/blob/main/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/datpham0412/CGPA_Calculator)](https://github.com/datpham0412/CGPA_Calculator/issues)
[![GitHub stars](https://img.shields.io/github/stars/datpham0412/CGPA_Calculator)](https://github.com/datpham0412/CGPA_Calculator/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/datpham0412/CGPA_Calculator)](https://github.com/datpham0412/CGPA_Calculator/network/members)

## 📋 Project Description
The **CGPA Calculator** is a terminal-based application that allows students to manage and calculate their Cumulative Grade Point Average (CGPA). Students can input their personal details, course units, and grades, and the application will compute the GPA for each semester and the overall CGPA.

## 🛠 Technologies Used
- **C++**: Core programming language.
- **SQLite**: Database management.
- **Object-Oriented Programming**: Code organization and structure.
- **CMake**: Cross-platform build system.
- **Google Test**: Unit testing framework.

## 📚 Features
- Add student details: Name, Student ID, Current Year, and Current Semester.
- Add course units and grades for each semester.
- Calculate GPA for each semester.
- Calculate cumulative GPA (CGPA).

## 🚀 Installation and Running the Project
### Prerequisites
- Ensure you have `git` installed for cloning repositories.
- Ensure you have CMake installed and added to your system's PATH.

### Steps
1. **Clone the Repository**:
    ```sh
    git clone https://github.com/yourusername/CGPA_Calculator.git
    cd CGPA_Calculator
    ```

2. **Install CMake**:
    - Download CMake from [here](https://github.com/Kitware/CMake/releases/download/v3.30.0-rc3/cmake-3.30.0-rc3-windows-x86_64.msi)
    - Add the CMake binary path (e.g., `C:\Program Files\CMake\bin`) to your environment variables.

3. **Clone SQLiteCpp**:
    ```sh
    cd external
    git clone https://github.com/SRombauts/SQLiteCpp.git
    ```

4. **Modify SQLiteCpp CMakeLists.txt**:
    - Open `CMakeLists.txt` in the `external/SQLiteCpp` folder.
    - Change line 388 from:
      ```cmake
      option(SQLITECPP_RUN_CPPLINT "Run cpplint.py tool for Google C++ StyleGuide." ON)
      ```
      to:
      ```cmake
      option(SQLITECPP_RUN_CPPLINT "Run cpplint.py tool for Google C++ StyleGuide." OFF)
      ```

5. **Build the Project**:
    ```sh
    cd ..
    mkdir build
    cd build
    cmake ..
    cmake --build . --config Release
    ```

6. **Run the Application**:
    ```sh
    cd Release
    CGPA_Calculator_Main.exe
    ```

## 📷 Screenshots
![Screenshot 2024-06-21 111245](https://github.com/datpham0412/CGPA_Calculator/assets/100574389/c9de7ff3-2079-449d-b9fc-4c13c36a75f5)

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/datpham0412/CGPA_Calculator/blob/main/LICENSE) file for details.

## 📞 Contact
For any inquiries, please contact [tiendat041202@gmail.com](mailto:tiendat041202@gmail.com).

---

Made with ❤️ by [Dat Pham](https://github.com/datpham0412)

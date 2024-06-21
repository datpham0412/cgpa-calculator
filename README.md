# 🎓 CGPA Calculator (Cumulative Grade Point Average Calculator)

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
![Screenshot](path-to-screenshot.png)

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📞 Contact
For any inquiries, please contact [yourname@example.com](mailto:yourname@example.com).

---

Made with ❤️ by [Your Name](https://github.com/yourusername)

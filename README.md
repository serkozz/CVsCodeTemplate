# 🛠️ Native C/C++ Development Template

This project is configured for **Native Windows C development** using the **MSYS2 UCRT64** toolchain. This setup is specifically designed to bypass the MSYS2 console redirection, ensuring a stable and fast connection between **VS Code** and **GDB**.

---

## 🚀 Prerequisites

1.  **MSYS2**: Installed eveywhere you want.
2.  **UCRT64 Toolchain**: Run the following in your **MSYS2 UCRT64 Terminal**:
    ```bash
    pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja
    ```

---

## ⚙️ Step 1: System Environment (The "Secret Sauce")

For the **CMake Tools** extension to find your compilers without needing the MSYS2 console, you must add the binaries to your Windows System Path:

1.  Press `Win + S` and type **"Environment Variables"**.
2.  Select **"Edit the system environment variables"**.
3.  Click **Environment Variables** ➡️ Select **Path** (under System variables) ➡️ **Edit**.
4.  Add a new entry: `C:\msys64\ucrt64\bin` (or your specific drive path).

---

## 🛠️ Step 2: VS Code Setup

### 1️⃣ Install Extensions
Install the following from the VS Code Marketplace:
*   📦 **C/C++ Extension Pack**
*   📦 **CMake Tools**

### 2️⃣ Configure the Toolchain
1.  Open the Command Palette (`Ctrl + Shift + P`).
2.  Run **`CMake: Scan for Kits`** (The extension will now find `gcc.exe` natively).
3.  Run **`CMake: Select a Kit`**.
4.  Choose **`GCC x86_64-w64-mingw32 (ucrt64)`**.

### 3️⃣ Project Build
1.  Run **`CMake: Configure`** (Generates the `build.ninja` file).
2.  Press **`F7`** to build your executable.

---

## 🐞 Debugging & Workflow

*   **Build & Run**: Press **`F5`**. The `launch.json` is configured to run a `preLaunchTask` that rebuilds your code automatically.
*   **Debugger Settings**: 
    *   Uses **Intel Disassembly Flavor**.
    *   **GDB Index Caching** is enabled in `.gdb_cache` for instant startup.
    *   **Direct Pathing**: `miDebuggerPath` points directly to the `.exe` to prevent connection timeouts.

---

## 📂 Folder Structure

```text
├── .vscode/         # Native tasks and launch configs
├── build/           # Build artifacts (ignored by git)
│   └── bin/         # App.exe lives here
├── src/             # Source files (.c, .h)
├── CMakeLists.txt   # CMake project logic
└── README.md        # This file
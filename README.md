# 🔐 Secure Python Execution with C Launcher + PyArmor

This project demonstrates how to securely execute Python code using a C-based launcher and PyArmor-based encryption.

## 📁 Project Structure
```bash
.
├── main_launcher.c # Main entry point written in C
├── logic.py # Python function file (optionally encrypted via PyArmor)
└── .gitignore
```

## ✅ What This Project Does

- `main_launcher.c` uses the Python C API to import and run functions from `logic.py`
- `logic.py` is encrypted using **PyArmor 7.x** to prevent source code exposure
- `launcher.exe` is built using **gcc** and links to **Python 3.10**

## 🔐 Security Strategy

- **C-based launcher**: Execution starts in compiled C code, making the flow harder to reverse-engineer
- **PyArmor encryption**: Python code is AES-encrypted and decrypted only at runtime
- **Runtime isolation**: Logic and execution are split to maximize protection

## ⚙️ How to Build

```bash
gcc main_launcher.c -o launcher.exe -IC:/Path/To/Python310/include -LC:/Path/To/Python310/libs -lpython310

Example for my system:
gcc main_launcher.c -o launcher.exe -IC:\Users\BK\AppData\Local\Programs\Python\Python310\include -LC:\Users\BK\AppData\Local\Programs\Python\Python310\libs -lpython310
```

## 🔒 How to Protect logic.py
1. Use Python 3.10 virtual environment:
```bash
py -3.10 -m venv pyarmor-env
.\pyarmor-env\Scripts\activate
pip install "pyarmor<8"
```
2. Obfuscate:
```bash
pyarmor obfuscate logic.py
```
3. Move the following to the same folder as launcher.exe:
```bash
dist/logic.py
pytransform/
```
## 📦 Final Deployment Structure
```
📦 SecureApp/
├── launcher.exe
├── logic.py        # Encrypted
└── pytransform/    # Runtime
```
## 🧠 Author
Made by **Ellie Eunsung Roh** for secure on-device AI code distribution and reverse engineering resistance.

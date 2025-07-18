# STM32 Monorepo Test

- **CMake** + **Ninja** build system
- Shared **resources** (HAL, CMSIS, FreeRTOS, toolchains, Drivers)
- **pre-commit** hook enforcing **clang-format**

---

## 🚀 Quick Start

1. **Clone this repo**
    ```sh
    git clone https://github.com/justinlopez1/stm32-monorepo-test.git
    cd stm32-monorepo-test
    ```

2. **Install MSYS2**  
   Download: https://www.msys2.org/  
   Open an `MSYS2` terminal (Start menu).
   All the following commands need to be ran in an MSYS2 (Unix like) terminal

3. **Install build tools**
    ```sh
    pacman -Syu         # Update system, restart if prompted
    pacman -S --needed \
      arm-none-eabi-gcc \
      ninja \
      cmake \
      git \
      python-pip \
      clang
    ```

4. **Install Python deps**
    ```sh
    pip install --upgrade pip
    pip install pre-commit
    ```

5. **Install pre-commit hook**
    ```sh
    pre-commit install
    ```

6. **Build/Work on a firmware project**
    ```sh
    cd firmware/project1 # Example project, all projects are in firmware folder
    make              # Debug build (default)
    make clean        # Clean build folder
    make BUILD_TYPE=Release  # Release build
    ```

---

*All projects pull in sources/headers from `../../resources`.*

---

## 🛠️ Build & Run

- **From firmware subfolder** (`cd firmware/project1`):

    ```sh
    make                 # Build debug
    make clean           # Remove build
    make BUILD_TYPE=Release   # Build release
    ```

- **Manual CMake/Ninja**
    ```sh
    cmake -G Ninja -Bbuild \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_TOOLCHAIN_FILE='../../resources/cmake/gcc-arm-none-eabi.cmake'
    ninja -C build
    ```

- **Flash example** (OpenOCD, adjust paths as needed):
    ```sh
    openocd -f interface/stlink.cfg -f target/stm32l4x.cfg \
      -c "program build/project1.elf verify reset exit"
    ```

---

## 🧹 Clang-Format & Pre-commit

- **Install the hook** (from repo root, one-time per clone):
    ```sh
    pre-commit install
    ```

- **What it does**:  
    Every `git commit`, clang-format is auto-applied to C/C++ files (`.c`, `.cpp`, `.h`, `.hpp`).  
    If changes are made, the commit is **blocked** and you must re-add the formatted files.

    ```
    git add .
    git commit -m "Some message"
    # If "files were modified by this hook", re-add and commit again.
    ```

- **Format all files manually**:
    ```sh
    pre-commit run --all-files
    ```

- **Style config**:  
    See `.clang-format` in the repo root

---

## 🖥️ Recommended VS Code Settings

Add something like this to your vscode settings json file with ctrl+shift+p to use an msys2 teerminal inside of vscode
```json
{
    "terminal.integrated.profiles.windows": {
    "MSYS2": {
	"path": "C:\\msys64\\usr\\bin\\bash.exe",
	"args": [
		"--login",
		"-i"
	],
	"env": {
		"CHERE_INVOKING": "1"
	}
}
}

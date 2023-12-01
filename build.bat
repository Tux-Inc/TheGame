@echo off
set OUT_DIR=.\build
set BUILD_DIR=.\build
set SRC_DIR=.\

:: Check if OUT_DIR exists and create if it doesn't
if not exist %OUT_DIR% (
    mkdir %BUILD_DIR%
)

@REM "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
cmake -S %SRC_DIR% -G Ninja -B %BUILD_DIR% -DCMAKE_MAKE_PROGRAM="C:\Program Files\Ninja_Build\ninja.exe"

ninja -C %BUILD_DIR%

cmake --build %BUILD_DIR%

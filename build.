@echo off
REM build.bat - Bien dich module RF3 (Undo Stack, Benchmark, Automated Test)
REM Yeu cau: da cai dat MinGW-w64 va them g++ vao PATH.
REM Cach dung: Double click file build.bat hoac go build.bat trong cmd.

echo ============================================
echo    Dang bien dich module RF3 (C++11)...
echo ============================================

g++ -std=c++11 -O2 -Wall -Wextra -o rf3_app.exe src\main.cpp

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [LOI] Bien dich that bai. Kiem tra lai trinh bien dich g++.
    exit /b 1
)

echo.
echo ============================================
echo    BUILD THANH CONG: rf3_app.exe
echo    Chay bằng lenh:   rf3_app.exe
echo ============================================
pause

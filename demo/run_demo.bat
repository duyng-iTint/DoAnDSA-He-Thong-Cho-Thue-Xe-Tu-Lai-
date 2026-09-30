@echo off
REM run_demo.bat - Kich ban chay nhanh demo module RF3
cd ..
if not exist rf3_app.exe (
    echo Dang bien dich chuong trinh...
    call build.bat
)
echo.
echo Dang khoi chay Demo module RF3...
rf3_app.exe
pause

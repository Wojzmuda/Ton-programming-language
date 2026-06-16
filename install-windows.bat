@echo off
setlocal enabledelayedexpansion


set "DATA_DIR=data"
set "SF2_FILENAME=FluidR3_GM.sf2"
set "DOWNLOAD_URL=https://github.com/pianobooster/fluid-soundfont/releases/download/v3.1/FluidR3_GM.sf2"
set "USER_TON_DIR=%USERPROFILE%\.ton"
set "BIN_DIR=%USERPROFILE%\.ton\bin"

echo ^>^>^> [Ton Setup] Starting the installation...
echo ======================================================

:: 1. Safeguard 
if not exist "Ton.g4" (
    echo ^>^>^> [ERROR] Script must be run from Root Project directory!
    exit /b 1
)

echo ^>^>^> [1/6] SoundFont library setup
if not exist "%DATA_DIR%" mkdir "%DATA_DIR%"

if exist "%DATA_DIR%\%SF2_FILENAME%" (
    echo ^>^>^> [INFO] File %SF2_FILENAME% already exists. Skipping download.
) else (
    echo ^>^>^> [INFO] Downloading the SoundFont library ^(~142 MB^)...
    curl -L -# -o "%DATA_DIR%\%SF2_FILENAME%" "%DOWNLOAD_URL%"
    if %errorlevel% neq 0 (
        echo ^>^>^> [ERROR] Failed to download SoundFont.
        exit /b 1
    )
)

echo ^>^>^> [2/6] Installing SoundFont library globally in %USER_TON_DIR%.
if not exist "%USER_TON_DIR%" mkdir "%USER_TON_DIR%"
copy /Y "%DATA_DIR%\%SF2_FILENAME%" "%USER_TON_DIR%\%SF2_FILENAME%" >nul

echo ^>^>^> [3/6] Generating Parser and Lexer.
call antlr4 -Dlanguage=Cpp -visitor -listener -o antlr4_generated Ton.g4
if %errorlevel% neq 0 exit /b %errorlevel%

echo ^>^>^> [4/6] Configuring CMake environment.
cmake -B build
if %errorlevel% neq 0 exit /b %errorlevel%

echo ^>^>^> [5/6] Building Ton...
cmake --build build -j
if %errorlevel% neq 0 exit /b %errorlevel%

echo ^>^>^> [6/6] Adding the interpreter to the system PATH
if not exist "%BIN_DIR%" mkdir "%BIN_DIR%"

copy /Y "build\ton_app.exe" "%BIN_DIR%\ton.exe" >nul

powershell -NoProfile -Command "$userPath = [Environment]::GetEnvironmentVariable('Path', 'User'); if ($userPath -notmatch [regex]::Escape('%BIN_DIR%')) { [Environment]::SetEnvironmentVariable('Path', $userPath + ';%BIN_DIR%', 'User'); Write-Host '>>> [INFO] Successfully added %BIN_DIR% to User PATH.' } else { Write-Host '>>> [INFO] Directory already in User PATH. Skipping.' }"

echo ======================================================
echo ^>^>^> [SUCCESS] Ton language has been successfully compiled and installed on the system.
echo ^>^>^>
echo ^>^>^> IMPORTANT: Please restart your terminal/command prompt to apply PATH changes.
echo ^>^>^> From now on, you can use "ton" command from anywhere in your system.
echo ^>^>^> Just like that: ton example.ton
echo ^>^>^> Happy Toning!
echo ======================================================
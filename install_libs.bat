@echo off
set libs="ESP Mail Client@3.4.24"

for %%i in (%libs%) do (
    arduino-cli lib install %%i
)

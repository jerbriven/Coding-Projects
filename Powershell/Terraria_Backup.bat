@echo off

REM Copy files into staging location
echo d | xcopy /s "C:\Users\Jeremy\Documents\My Games\Terraria\Worlds" "C:\Users\Jeremy\Documents\My Games\Terraria\Staging"

REM set datetime
for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "YY=%dt:~2,2%" & set "YYYY=%dt:~0,4%" & set "MM=%dt:~4,2%" & set "DD=%dt:~6,2%"
set "HH=%dt:~8,2%" & set "Min=%dt:~10,2%" & set "Sec=%dt:~12,2%"

set "datestamp=%YYYY%%MM%%DD%" & set "timestamp=%HH%%Min%%Sec%"
set "fullstamp=%YYYY%-%MM%-%DD%_%HH%-%Min%-%Sec%"
echo datestamp: "%datestamp%"
echo timestamp: "%timestamp%"
echo fullstamp: "%fullstamp%"

REM Copy files into backup location
echo d | xcopy /s "C:\Users\Jeremy\Documents\My Games\Terraria\Staging" "C:\Users\Jeremy\Documents\My Games\Terraria\Backup_Worlds\"%fullstamp%

REM Delete Staging files and directory
del /q "C:\Users\Jeremy\Documents\My Games\Terraria\Staging\*"
for /d %%x in ("C:\Users\Jeremy\Documents\My Games\Terraria\Staging\*") do @rd /s /q "%%x"
rmdir "C:\Users\Jeremy\Documents\My Games\Terraria\Staging"
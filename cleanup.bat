@echo off
setlocal
SET /P AREYOUSURE=Are you sure, this action cannot be undone (Y/[N])? 
IF /I "%AREYOUSURE%" NEQ "Y" GOTO ABORT

:DELETE_FILES
echo Cleaning up project 'Brain Connections'
rmdir /s /q "FillInHack Console\Brain Connections\x64"
echo Cleaning up project 'encryptor'
rmdir /s /q "FillInHack Console\encryptor\x64"
echo Cleaning up project 'FillInHack Console Remaster'
rmdir /s /q "FillInHack Console\FillInHack Console Remaster\x64"
echo Cleaning up project 'FillInHack Console Updater'
rmdir /s /q "FillInHack Console\FillInHack Console Updater\obj"
echo Cleaning up project 'FillInHack_Header'
rmdir /s /q "FillInHack Console\FillInHack_Header\x64"
echo Cleaning up project 'help'
rmdir /s /q "FillInHack Console\help\x64"
rmdir /s /q "FillInHack Console\x64"
echo Finished cleaning up!
pause
exit

:ABORT
echo Action aborted. Quitting.
endlocal
pause
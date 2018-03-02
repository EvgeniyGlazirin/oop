rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1" 

echo Testing of number arguments
%PROGRAM% input.txt output.txt 
if ERRORLEVEL 1 goto err

echo Testing copying of empty file
%PROGRAM% empty.txt %TEMP%\empty.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\empty.txt empty.txt
if ERRORLEVEL 1 goto err

echo Testing copying not empty file
%PROGRAM% input.txt output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt input.txt
if ERRORLEVEL 1 goto err

echo Testing copying with input file is not exist
%PROGRAM% inputIsNotExist.txt output.txt
if not ERRORLEVEL 1 goto err


echo Sucsess testing
exit 0

:err
echo Program testing failed
exit 1
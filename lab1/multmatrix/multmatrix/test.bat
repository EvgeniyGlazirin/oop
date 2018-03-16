rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem Тесты корректности вводимых аргументов и их количества
echo Test1 - Testing launching without arguments
%PROGRAM% > nul
if not ERRORLEVEL 1 goto err

echo Test2 - Testing launching with right parameters count
%PROGRAM% matrix1.txt matrix2.txt >nul
if ERRORLEVEL 1 goto err

echo Test3 - Testing launching with wrong parameters count
%PROGRAM% matrix1.txt > nul
if not ERRORLEVEL 1 goto err


echo Test4 - Testing read from file is not exists
%PROGRAM% fileIsNotExists.txt matrix2.txt >nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt fileIsNotExists.txt >nul
if NOT ERRORLEVEL 1 goto err

echo Testing sucsessful!
exit 0

:err
echo Program testing failed
exit 1
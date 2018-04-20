rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem Тесты корректности вводимых аргументов и их количества
echo Test1 - Testing launching without arguments
%PROGRAM% > nul
if not ERRORLEVEL 1 goto err

echo Test2 - Testing launching with right parameters count
%PROGRAM% 1 >nul
if ERRORLEVEL 1 goto err

echo Test3 - Testing launching with wrong parameters count
%PROGRAM% 1 2 > nul
if not ERRORLEVEL 1 goto err

echo Test4 - Testing launching with right parameters count and wrong data(not digit)
%PROGRAM% notDigit >nul 
if not ERRORLEVEL 1 goto err

echo Test5 - Testing launching with wrong data (max value)
%PROGRAM% 256 > nul
if not ERRORLEVEL 1 goto err

echo Test6 - Testing launching with wrong data (min value)
%PROGRAM% -1 >nul
if not  ERRORLEVEL 1 goto err

rem Тесты сравнения ожидаемого результата с получившимся
echo Test7 - Testing result with expected result
%PROGRAM% 6 > "%TEMP%\result.txt"
fc.exe "%TEMP%\result.txt" expectedResult.txt >nul
if ERRORLEVEL 1 goto err

echo Test8 - Testing result with expected wrong result
%PROGRAM% 33 > "%TEMP%\result.txt"
fc.exe "%TEMP%\result.txt" expectedWrongResult.txt >nul
if not ERRORLEVEL 1 goto err

echo Testing sucsessful!
exit 0

:err
echo Program testing failed
exit 1
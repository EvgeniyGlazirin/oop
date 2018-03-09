rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
echo Test1 - Testing launching without arguments
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске c верным количеством параметров ожидается нулевой код возврата
echo Test2 - Testing of number arguments 
%PROGRAM% input.txt test > nul
if ERRORLEVEL 1 goto err

rem При попытке чтения из несуществующего файла ожидается ненулевой код возврата
echo Test3 - Testing read from file is not exists
%PROGRAM% fileIsNotExists.txt test >nul
if NOT ERRORLEVEL 1 goto err

rem При попытке поиска пустой строки ожидается ненулевой код возврата
echo Test4 - Testing search with empty string
%PROGRAM% input.txt "" > nul
if NOT ERRORLEVEL 1 goto err



echo Testing sucsessful!
exit 0

:err
echo Program testing failed
exit 1
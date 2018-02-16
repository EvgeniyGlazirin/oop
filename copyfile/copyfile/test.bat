rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
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
%PROGRAM% input.txt %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt input.txt
if ERRORLEVEL 1 goto err

echo Sucsess testing
exit 0

:err
echo Program testing failed
exit 1
rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
echo Test1 - Testing launching without arguments
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� c ������ ����������� ���������� ��������� ������� ��� ��������
echo Test2 - Testing of number arguments 
%PROGRAM% input.txt "never" > nul
if ERRORLEVEL 1 goto err

rem ��� ������� ������ �� ��������������� ����� ��������� ��������� ��� ��������
echo Test3 - Testing read from file is not exists
%PROGRAM% fileIsNotExists.txt test >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� ������ ������ ������ ��������� ��������� ��� ��������
echo Test4 - Testing search with empty string
%PROGRAM% input.txt "" > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� � �������, ������� �� ������� ��������� �� ������� ��� �������� 
echo Test5 - Testing with right parameters and string which not found
%PROGRAM% input.txt "stringNotFound" >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� � �������������� ����� ���������)
echo Test6 - Testing result with expected result 
%PROGRAM% test.txt "never" > "%TEMP%\result.txt" 
fc.exe "%TEMP%\result.txt" expectedResult.txt >nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(�������� � �������������� ����� �� ���������)
echo Test7 - Testing result with expected wrong result 
%PROGRAM% test.txt "now" > "%TEMP%\result.txt" 
fc.exe "%TEMP%\result.txt" expectedResult.txt  > nul
if NOT ERRORLEVEL 1 goto err


echo Testing sucsessful!
exit 0

:err
echo Program testing failed
exit 1
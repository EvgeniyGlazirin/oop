rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ����� ������������ �������� ���������� � �� ����������
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
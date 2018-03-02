rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� c ������ ����������� ���������� ��������� ������� ��� ��������
echo Testing of number arguments 
%PROGRAM% input.txt test >nul
if ERRORLEVEL 1 goto err

rem ��� ������� ������ �� ��������������� ����� ��������� ��������� ��� ��������
echo Testing read from file is not exists
%PROGRAM% fileIsNotExists.txt test >nul
if NOT ERRORLEVEL 1 goto err

echo Testing sucsessful!
exit 0

:err
echo Program testing failed
exit 1
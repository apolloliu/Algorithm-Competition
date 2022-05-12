g++ mkd.cpp   -o mkd -g
g++ D.cpp     -o std -g
g++ D_bl.cpp  -o bl  -g
:loop
	mkd.exe >1.txt
	std.exe <1.txt >2.txt
	bl.exe <1.txt >3.txt
	fc 2.txt 3.txt
if not errorlevel 1 goto loop
pause
goto loop
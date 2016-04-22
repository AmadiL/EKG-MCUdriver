
#include <stdio.h>

#include <windows.h>
#include <conio.h>
#include <math.h>
#include <winbase.h>


static DCB dcb;
static HANDLE hNumPort;
static char lpBuffor_read[33], lpBuffor_write[33];
static DWORD RS_ile;

int * myFunction(){
	hNumPort = CreateFile("COM3", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	int *p;
	p = &hNumPort;
	dcb.DCBlength = sizeof(dcb);

	dcb.BaudRate = CBR_9600;
	//dcb.fParity = TRUE;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;

	dcb.fDtrControl = DTR_CONTROL_ENABLE;
	dcb.fRtsControl = RTS_CONTROL_ENABLE;

	dcb.fOutxCtsFlow = FALSE;
	dcb.fOutxDsrFlow = FALSE;
	dcb.fDsrSensitivity = FALSE;
	dcb.fAbortOnError = FALSE;
	dcb.fOutX = FALSE;
	dcb.fInX = FALSE;
	dcb.fErrorChar = FALSE;
	dcb.fNull = FALSE;
	return p;
}

int main(){
	int *p = myFunction();
	
	
	SetCommState(*p, &dcb);
	strcpy(lpBuffor_write, "CLS 30\r\nLINE 100 100 600 400 0\r\n");// Niech to bêdzie przyk³adowe polecenie dla urz¹dzenia
	WriteFile(*p, lpBuffor_write, strlen(lpBuffor_write), &RS_ile, 0);
	
	ReadFile(*p, lpBuffor_read, 15, &RS_ile, 0);
	
	CloseHandle(*p);

	system("Pause");
	return 0;
}







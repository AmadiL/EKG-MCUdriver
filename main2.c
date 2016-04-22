
#include <stdio.h>

#include <windows.h>
#include <conio.h>
#include <math.h>
#include <winbase.h>


static DCB dcb;
//static HANDLE hNumPort;
static char lpBuffor_read[33], lpBuffor_write[33];
static DWORD RS_ile;

HANDLE * CreateHandler(char COM){
	HANDLE *hNumPort = CreateFile(COM, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	dcb.DCBlength = sizeof(dcb);

	dcb.BaudRate = CBR_9600;
	dcb.fParity = FALSE;
	//dcb.Parity = NOPARITY;
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
	return hNumPort;
}

int main(){
	HANDLE *hNumPort = CreateHandler("COM3");
	
	
	SetCommState(*hNumPort, &dcb);
	strcpy(lpBuffor_write, "CLS 30\r\nLINE 100 100 600 400 0\r\n");// Niech to bêdzie przyk³adowe polecenie dla urz¹dzenia
	WriteFile(*hNumPort, lpBuffor_write, strlen(lpBuffor_write), &RS_ile, 0);
	
	ReadFile(*hNumPort, lpBuffor_read, 15, &RS_ile, 0);
	
	CloseHandle(*hNumPort);

	//system("Pause");
	getchar();
	return 0;
}







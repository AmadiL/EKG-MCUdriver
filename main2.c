
#include <stdio.h>
#include <windows.h>
#include <winbase.h>


static DCB dcb;
//static HANDLE hNumPort;
static char lpBuffor_read[33], lpBuffor_write[33];
static DWORD RS_ile;

void WritetoCOM (HANDLE *hNumPort, char* MSG) {
	printf("2\n");
	strcpy(lpBuffor_write, &MSG);// Niech to bêdzie przyk³adowe polecenie dla urz¹dzenia
	printf("3\n");
	WriteFile(hNumPort, lpBuffor_write, strlen(lpBuffor_write), &RS_ile, 0);
	printf("4\n");	
}

HANDLE * CreateHandler(char* COM){
	printf("1\n");
	HANDLE *hNumPort = CreateFile(COM, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	printf("2\n");
	dcb.DCBlength = sizeof(dcb);
	printf("3\n");
	dcb.BaudRate = CBR_9600;
	printf("4\n");
	dcb.fParity = FALSE;
	printf("5\n");
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
	char* COM = "COM3";
	printf("dupa\n");
	HANDLE *hNumPort = CreateHandler(COM);
	printf("dupa2\n");
	char* MSG[30];
	
	SetCommState(hNumPort, &dcb);
	
	while(*MSG != "exit"){
		scanf("%s", &MSG);
		printf ("%s", MSG);
		WritetoCOM(hNumPort, *MSG);
		
		//memset(*MSG, 0, 30);
	}
	/*
	printf("2\n");
	strcpy(lpBuffor_write, "CLS 30\r\nLINE 100 100 600 400 0\r\n");// Niech to bêdzie przyk³adowe polecenie dla urz¹dzenia
	printf("3\n");
	WriteFile(hNumPort, lpBuffor_write, strlen(lpBuffor_write), &RS_ile, 0);
	printf("4\n");
	*/
	//ReadFile(hNumPort, lpBuffor_read, 15, &RS_ile, 0);
	printf("5\n");
	
	CloseHandle(hNumPort);

	getchar();
	return 0;
}







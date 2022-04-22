#include "Browser.h"

int main()
{
	// -kiosk 옵션의 경우 해당 브라우저가 하나도 실행중이지 않아야 키오스크 모드로 실행된다.
	MOONG::BROWSER::Browser::OpenURL("www.google.com");
	system("pause");
	MOONG::BROWSER::Browser::OpenURL("www.google.com", "edge");
	system("pause");
	MOONG::BROWSER::Browser::OpenURL("-kiosk www.google.com");
	system("pause");
	MOONG::BROWSER::Browser::OpenURLWithChrome("www.google.com");
	system("pause");
	MOONG::BROWSER::Browser::OpenURLWithChrome("-kiosk www.google.com");
	system("pause");
	MOONG::BROWSER::Browser::OpenURLWithIE("www.google.com");
	system("pause");
	MOONG::BROWSER::Browser::OpenURLWithMSEdge("www.google.com");
	system("pause");
	MOONG::BROWSER::Browser::OpenURLWithMSEdge("-kiosk www.google.com");

	return EXIT_SUCCESS;
}
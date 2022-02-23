#include "Browser.h"

int main()
{
	MOONG::BROWSER::Browser browser;

	// -kiosk 옵션의 경우 해당 브라우저가 하나도 실행중이지 않아야 키오스크 모드로 실행된다.
	browser.OpenURL("www.google.com", "edge");
	system("pause");
	browser.OpenURL("-kiosk www.google.com");
	system("pause");
	browser.OpenURLWithChrome("www.google.com");
	system("pause");
	browser.OpenURLWithChrome("-kiosk www.google.com");
	system("pause");
	browser.OpenURLWithIE("www.google.com");
	system("pause");
	browser.OpenURLWithMSEdge("www.google.com");
	system("pause");
	browser.OpenURLWithMSEdge("-kiosk www.google.com");

	return EXIT_SUCCESS;
}
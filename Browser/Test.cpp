#include "Browser.h"

int main()
{
	MOONG::BROWSER::Browser browser;

	// -kiosk �ɼ��� ��� �ش� �������� �ϳ��� ���������� �ʾƾ� Ű����ũ ���� ����ȴ�.
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
#include "Browser.h"

int main()
{
	// -kiosk �ɼ��� ��� �ش� �������� �ϳ��� ���������� �ʾƾ� Ű����ũ ���� ����ȴ�.
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
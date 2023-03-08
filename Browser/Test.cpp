#include "Browser.h"

int main()
{
	try
	{
		// -kiosk �ɼ��� ��� �ش� �������� �ϳ��� ���������� �ʾƾ� Ű����ũ ���� ����ȴ�.
		//MOONG::Browser::OpenURL("www.google.com");
		//system("pause");
		//MOONG::Browser::OpenURL("www.google.com", "edge");
		//system("pause");
		//MOONG::Browser::OpenURL("-kiosk www.google.com");
		//system("pause");
		//MOONG::Browser::OpenURLWithChrome("www.google.com");
		//system("pause");
		//MOONG::Browser::OpenURLWithChrome("-kiosk www.google.com");
		//system("pause");
		//MOONG::Browser::OpenURLWithIE("www.google.com");
		//system("pause");
		//MOONG::Browser::OpenURLWithMSEdge("www.google.com");
		//system("pause");
		//MOONG::Browser::OpenURLWithMSEdge("-kiosk www.google.com");

		std::string windows_default_browser;
		MOONG::Browser::get_windows_default_browser(windows_default_browser);
		std::cout << windows_default_browser << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
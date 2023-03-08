#include "Browser.h"

int main()
{
	try
	{
		// -kiosk 옵션의 경우 해당 브라우저가 하나도 실행중이지 않아야 키오스크 모드로 실행된다.
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
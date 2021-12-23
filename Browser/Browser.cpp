#include "Browser.h"

#include <algorithm>
#include <Windows.h>
#pragma comment(lib, "Shell32.lib")

MOONG::BROWSER::Browser::Browser() :
REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.html\\UserChoice"),
REG_VALUE_WINDOWS_DEFAULT_BROWSER("ProgID")
{

}

int MOONG::BROWSER::Browser::OpenURL(const std::string url, std::string browser)
{
	std::transform(browser.begin(), browser.end(), browser.begin(), ::tolower);
	
	if(browser == "default")
	{
		this->OpenURLWithWindowsDefaultBrowser(url);
	}
	else if(browser == "ie")
	{
		this->OpenURLWithIE(url);
	}
	else if(browser == "internet explorer")
	{
		this->OpenURLWithIE(url);
	}
	else if(browser == "chrome")
	{
		this->OpenURLWithChrome(url);
	}
	else if (browser == "edge")
	{
		this->OpenURLWithMSEdge(url);
	}
	else if (browser == "msedge")
	{
		this->OpenURLWithMSEdge(url);
	}
	else
	{
		this->OpenURLWithWindowsDefaultBrowser(url);
	}

	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithWindowsDefaultBrowser(const std::string url)
{
	std::string windows_default_browser;

	this->registry_.Read(HKEY_CURRENT_USER, this->REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER.c_str(), this->REG_VALUE_WINDOWS_DEFAULT_BROWSER.c_str(), windows_default_browser);

	std::transform(windows_default_browser.begin(), windows_default_browser.end(), windows_default_browser.begin(), ::tolower);

	// 파라미터 url 앞에 "-kiosk"가 붙어서 올 경우 크롬, 엣지는 정상 동작하지만,
	// 다른 브라우저의 경우 "-kiosk"가 아닐 경우 여기서 치환해준다.
	if (windows_default_browser.find("chrome") != std::string::npos)
	{
		this->OpenURLWithChrome(url);
	}
	else if (windows_default_browser.find("msedge") != std::string::npos)
	{
		this->OpenURLWithMSEdge(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", url.c_str(), "", "", SW_SHOW);	// 구현되지 않은 브라우저의 경우.
	}

	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithIE(const std::string url)
{
	ShellExecuteA(NULL, "open", "iexplore.exe", url.c_str(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithChrome(const std::string url)
{
	ShellExecuteA(NULL, "open", "chrome.exe", url.c_str(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithMSEdge(const std::string url)
{
	ShellExecuteA(NULL, "open", "msedge.exe", url.c_str(), "", SW_SHOW);

	return EXIT_SUCCESS;
}
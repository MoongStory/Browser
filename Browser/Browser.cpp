#include "Browser.h"

#include <algorithm>
#include <Windows.h>

#if _MSC_VER <= 1600
#include <shellapi.h>
#endif
#pragma comment(lib, "Shell32.lib")

const std::string MOONG::Browser::REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.htm\\UserChoice";
const std::string MOONG::Browser::REG_VALUE_WINDOWS_DEFAULT_BROWSER = "ProgID";

int MOONG::Browser::OpenURL(const std::string url, std::string browser/* = "Default"*/)
{
	std::transform(browser.begin(), browser.end(), browser.begin(), ::tolower);
	
	if(browser.compare("default") == 0)
	{
		MOONG::Browser::OpenURLWithWindowsDefaultBrowser(url);
	}
	else if(browser.compare("ie") == 0)
	{
		MOONG::Browser::OpenURLWithIE(url);
	}
	else if(browser.compare("internet explorer") == 0)
	{
		MOONG::Browser::OpenURLWithIE(url);
	}
	else if(browser.compare("chrome") == 0)
	{
		MOONG::Browser::OpenURLWithChrome(url);
	}
	else if (browser.compare("edge") == 0)
	{
		MOONG::Browser::OpenURLWithMSEdge(url);
	}
	else if (browser.compare("msedge") == 0)
	{
		MOONG::Browser::OpenURLWithMSEdge(url);
	}
	else
	{
		MOONG::Browser::OpenURLWithWindowsDefaultBrowser(url);
	}

	return EXIT_SUCCESS;
}

int MOONG::Browser::OpenURLWithWindowsDefaultBrowser(const std::string url)
{
	std::string windows_default_browser;

	MOONG::Browser::getWindowsDefaultBrowser(windows_default_browser);

	std::transform(windows_default_browser.begin(), windows_default_browser.end(), windows_default_browser.begin(), ::tolower);

	// 파라미터 url 앞에 "-kiosk"가 붙어서 올 경우 크롬, 엣지는 정상 동작하지만,
	// 다른 브라우저의 경우 "-kiosk"가 아닐 경우 여기서 치환해준다.
	if (windows_default_browser.find("chrome") != std::string::npos)
	{
		MOONG::Browser::OpenURLWithChrome(url);
	}
	else if (windows_default_browser.find("msedge") != std::string::npos)
	{
		MOONG::Browser::OpenURLWithMSEdge(url);
	}
	else if (windows_default_browser.find("htmlfile") != std::string::npos)
	{
		MOONG::Browser::OpenURLWithIE(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", url.c_str(), "", "", SW_SHOW);	// 구현되지 않은 브라우저의 경우.
	}

	return EXIT_SUCCESS;
}

int MOONG::Browser::OpenURLWithIE(const std::string url)
{
	ShellExecuteA(NULL, "open", "iexplore.exe", url.c_str(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::Browser::OpenURLWithChrome(const std::string url)
{
	ShellExecuteA(NULL, "open", "chrome.exe", url.c_str(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::Browser::OpenURLWithMSEdge(const std::string url)
{
	ShellExecuteA(NULL, "open", "msedge.exe", url.c_str(), "", SW_SHOW);

	return EXIT_SUCCESS;
}

LSTATUS MOONG::Browser::getWindowsDefaultBrowser(std::string& windows_default_browser)
{
	return MOONG::Registry::Read(HKEY_CURRENT_USER, MOONG::Browser::REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER.c_str(), MOONG::Browser::REG_VALUE_WINDOWS_DEFAULT_BROWSER.c_str(), windows_default_browser);
}

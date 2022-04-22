#include "Browser.h"

#include <algorithm>
#include <Windows.h>

#if _MSC_VER <= 1600
#include <shellapi.h>
#endif
#pragma comment(lib, "Shell32.lib")

const std::string MOONG::BROWSER::Browser::REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.htm\\UserChoice";
const std::string MOONG::BROWSER::Browser::REG_VALUE_WINDOWS_DEFAULT_BROWSER = "ProgID";

int MOONG::BROWSER::Browser::OpenURL(const std::string url, std::string browser/* = "Default"*/)
{
	std::transform(browser.begin(), browser.end(), browser.begin(), ::tolower);
	
	if(browser.compare("default") == 0)
	{
		MOONG::BROWSER::Browser::OpenURLWithWindowsDefaultBrowser(url);
	}
	else if(browser.compare("ie") == 0)
	{
		MOONG::BROWSER::Browser::OpenURLWithIE(url);
	}
	else if(browser.compare("internet explorer") == 0)
	{
		MOONG::BROWSER::Browser::OpenURLWithIE(url);
	}
	else if(browser.compare("chrome") == 0)
	{
		MOONG::BROWSER::Browser::OpenURLWithChrome(url);
	}
	else if (browser.compare("edge") == 0)
	{
		MOONG::BROWSER::Browser::OpenURLWithMSEdge(url);
	}
	else if (browser.compare("msedge") == 0)
	{
		MOONG::BROWSER::Browser::OpenURLWithMSEdge(url);
	}
	else
	{
		MOONG::BROWSER::Browser::OpenURLWithWindowsDefaultBrowser(url);
	}

	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithWindowsDefaultBrowser(const std::string url)
{
	std::string windows_default_browser;

	MOONG::BROWSER::Browser::getWindowsDefaultBrowser(windows_default_browser);

	std::transform(windows_default_browser.begin(), windows_default_browser.end(), windows_default_browser.begin(), ::tolower);

	// 파라미터 url 앞에 "-kiosk"가 붙어서 올 경우 크롬, 엣지는 정상 동작하지만,
	// 다른 브라우저의 경우 "-kiosk"가 아닐 경우 여기서 치환해준다.
	if (windows_default_browser.find("chrome") != std::string::npos)
	{
		MOONG::BROWSER::Browser::OpenURLWithChrome(url);
	}
	else if (windows_default_browser.find("msedge") != std::string::npos)
	{
		MOONG::BROWSER::Browser::OpenURLWithMSEdge(url);
	}
	else if (windows_default_browser.find("htmlfile") != std::string::npos)
	{
		MOONG::BROWSER::Browser::OpenURLWithIE(url);
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

LSTATUS MOONG::BROWSER::Browser::getWindowsDefaultBrowser(std::string& windows_default_browser)
{
	return MOONG::REGISTRY::Registry::Read(HKEY_CURRENT_USER, MOONG::BROWSER::Browser::REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER.c_str(), MOONG::BROWSER::Browser::REG_VALUE_WINDOWS_DEFAULT_BROWSER.c_str(), windows_default_browser);
}

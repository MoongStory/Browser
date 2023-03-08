#include "Browser.h"

#include "../../Registry/Registry/Registry.h"
#include "../../StringTool/StringTool/StringTool.h"

#include <algorithm>

#if _MSC_VER <= 1600
#include <shellapi.h>
#endif
#pragma comment(lib, "Shell32.lib")

// ��ǻ��\HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\Shell\Associations\UrlAssociations\https\UserChoice	ProgId
// ��ǻ��\HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FileExts\.html\UserChoice	ProgId
// ChromeHTML
// MSEdgeHTM
const std::string MOONG::Browser::REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER = "SOFTWARE\\Microsoft\\Windows\\Shell\\Associations\\UrlAssociations\\https\\UserChoice";
const std::string MOONG::Browser::REG_VALUE_WINDOWS_DEFAULT_BROWSER = "ProgID";

void MOONG::Browser::open_url(const std::string url, std::string browser/* = "Default"*/)
{
	try
	{
		MOONG::StringTool::tolower(browser);

		if (browser.compare("default") == 0)
		{
			MOONG::Browser::open_url_with_windows_default_browser(url);
		}
		else if (browser.compare("ie") == 0)
		{
			MOONG::Browser::open_url_with_internet_explorer(url);
		}
		else if (browser.compare("internet explorer") == 0)
		{
			MOONG::Browser::open_url_with_internet_explorer(url);
		}
		else if (browser.compare("chrome") == 0)
		{
			MOONG::Browser::open_url_with_chrome(url);
		}
		else if (browser.compare("edge") == 0)
		{
			MOONG::Browser::open_url_with_edge(url);
		}
		else if (browser.compare("msedge") == 0)
		{
			MOONG::Browser::open_url_with_edge(url);
		}
		else
		{
			MOONG::Browser::open_url_with_windows_default_browser(url);
		}
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

void MOONG::Browser::open_url_with_windows_default_browser(const std::string url)
{
	std::string windows_default_browser;

	try
	{
		MOONG::Browser::get_windows_default_browser(windows_default_browser);
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}

	MOONG::StringTool::tolower(windows_default_browser);

	// �Ķ���� url �տ� "-kiosk"�� �پ �� ��� ũ��, ������ ���� ����������,
	// �ٸ� �������� ��� "-kiosk"�� �ƴ� ��� ���⼭ ġȯ���ش�.
	if (windows_default_browser.find("chrome") != std::string::npos)
	{
		MOONG::Browser::open_url_with_chrome(url);
	}
	else if (windows_default_browser.find("msedge") != std::string::npos)
	{
		MOONG::Browser::open_url_with_edge(url);
	}
	else if (windows_default_browser.find("htmlfile") != std::string::npos)
	{
		MOONG::Browser::open_url_with_internet_explorer(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", url.c_str(), "", "", SW_SHOW);	// �������� ���� �������� ���.
	}
}

void MOONG::Browser::open_url_with_internet_explorer(const std::string url)
{
	ShellExecuteA(NULL, "open", "iexplore.exe", url.c_str(), "", SW_SHOW);
}

void MOONG::Browser::open_url_with_chrome(const std::string url)
{
	ShellExecuteA(NULL, "open", "chrome.exe", url.c_str(), "", SW_SHOW);
}

void MOONG::Browser::open_url_with_edge(const std::string url)
{
	ShellExecuteA(NULL, "open", "msedge.exe", url.c_str(), "", SW_SHOW);
}

LSTATUS MOONG::Browser::get_windows_default_browser(std::string& windows_default_browser)
{
	try
	{
		return MOONG::Registry::Read(HKEY_CURRENT_USER, MOONG::Browser::REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER.c_str(), MOONG::Browser::REG_VALUE_WINDOWS_DEFAULT_BROWSER.c_str(), windows_default_browser);
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

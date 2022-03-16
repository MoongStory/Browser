#include "Browser.h"

#include <algorithm>
#include <Windows.h>
#pragma comment(lib, "Shell32.lib")

MOONG::BROWSER::Browser::Browser() :
REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.htm\\UserChoice"),
REG_VALUE_WINDOWS_DEFAULT_BROWSER("ProgID")
{

}

int MOONG::BROWSER::Browser::OpenURL(const std::string url, std::string browser) const
{
	std::transform(browser.begin(), browser.end(), browser.begin(), ::tolower);
	
	if(browser.compare("default") == 0)
	{
		this->OpenURLWithWindowsDefaultBrowser(url);
	}
	else if(browser.compare("ie") == 0)
	{
		this->OpenURLWithIE(url);
	}
	else if(browser.compare("internet explorer") == 0)
	{
		this->OpenURLWithIE(url);
	}
	else if(browser.compare("chrome") == 0)
	{
		this->OpenURLWithChrome(url);
	}
	else if (browser.compare("edge") == 0)
	{
		this->OpenURLWithMSEdge(url);
	}
	else if (browser.compare("msedge") == 0)
	{
		this->OpenURLWithMSEdge(url);
	}
	else
	{
		this->OpenURLWithWindowsDefaultBrowser(url);
	}

	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithWindowsDefaultBrowser(const std::string url) const
{
	std::string windows_default_browser;

	this->getWindowsDefaultBrowser(windows_default_browser);

	std::transform(windows_default_browser.begin(), windows_default_browser.end(), windows_default_browser.begin(), ::tolower);

	// �Ķ���� url �տ� "-kiosk"�� �پ �� ��� ũ��, ������ ���� ����������,
	// �ٸ� �������� ��� "-kiosk"�� �ƴ� ��� ���⼭ ġȯ���ش�.
	if (windows_default_browser.find("chrome") != std::string::npos)
	{
		this->OpenURLWithChrome(url);
	}
	else if (windows_default_browser.find("msedge") != std::string::npos)
	{
		this->OpenURLWithMSEdge(url);
	}
	else if (windows_default_browser.find("htmlfile") != std::string::npos)
	{
		this->OpenURLWithIE(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", url.c_str(), "", "", SW_SHOW);	// �������� ���� �������� ���.
	}

	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithIE(const std::string url) const
{
	ShellExecuteA(NULL, "open", "iexplore.exe", url.c_str(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithChrome(const std::string url) const
{
	ShellExecuteA(NULL, "open", "chrome.exe", url.c_str(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithMSEdge(const std::string url) const
{
	ShellExecuteA(NULL, "open", "msedge.exe", url.c_str(), "", SW_SHOW);

	return EXIT_SUCCESS;
}

LSTATUS MOONG::BROWSER::Browser::getWindowsDefaultBrowser(std::string& windows_default_browser) const
{
	return this->registry_.Read(HKEY_CURRENT_USER, this->REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER.c_str(), this->REG_VALUE_WINDOWS_DEFAULT_BROWSER.c_str(), windows_default_browser);
}
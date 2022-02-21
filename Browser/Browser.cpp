#include "Browser.h"

#include <algorithm>
#include <Windows.h>
#pragma comment(lib, "Shell32.lib")

MOONG::BROWSER::Browser::Browser() :
REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.html\\UserChoice"),
REG_VALUE_WINDOWS_DEFAULT_BROWSER("ProgID")
{

}

int MOONG::BROWSER::Browser::OpenURL(const CStringA url, CStringA browser) const
{
	browser.MakeLower();
	
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

int MOONG::BROWSER::Browser::OpenURLWithWindowsDefaultBrowser(const CStringA url) const
{
	CStringA windows_default_browser;

	this->registry_.Read(HKEY_CURRENT_USER, this->REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER.GetString(), this->REG_VALUE_WINDOWS_DEFAULT_BROWSER.GetString(), windows_default_browser);

	windows_default_browser.MakeLower();

	// �Ķ���� url �տ� "-kiosk"�� �پ �� ��� ũ��, ������ ���� ����������,
	// �ٸ� �������� ��� "-kiosk"�� �ƴ� ��� ���⼭ ġȯ���ش�.
	if (windows_default_browser.Find("chrome") >= 0)
	{
		this->OpenURLWithChrome(url);
	}
	else if (windows_default_browser.Find("msedge") >= 0)
	{
		this->OpenURLWithMSEdge(url);
	}
	else if (windows_default_browser.Find("htmlfile") >= 0)
	{
		this->OpenURLWithIE(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", url.GetString(), "", "", SW_SHOW);	// �������� ���� �������� ���.
	}

	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithIE(const CStringA url) const
{
	ShellExecuteA(NULL, "open", "iexplore.exe", url.GetString(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithChrome(const CStringA url) const
{
	ShellExecuteA(NULL, "open", "chrome.exe", url.GetString(), "", SW_SHOW);
	
	return EXIT_SUCCESS;
}

int MOONG::BROWSER::Browser::OpenURLWithMSEdge(const CStringA url) const
{
	ShellExecuteA(NULL, "open", "msedge.exe", url.GetString(), "", SW_SHOW);

	return EXIT_SUCCESS;
}
#include "StdAfx.h"

#include "Browser.h"

#include <algorithm>
#include <Windows.h>
#pragma comment(lib, "Shell32.lib")

int BROWSER::Browser::OpenURL(const std::string url, std::string browser)
{
	std::transform(browser.begin(), browser.end(), browser.begin(), ::tolower);
	
	if(browser == "default")
	{
		ShellExecuteA(NULL, "open", url.c_str(), "", "", SW_SHOW);	// OS 기본 브라우저로 실행
	}
	else if(browser == "ie")
	{
		OpenURLWithIE(url);
	}
	else if(browser == "internet explorer")
	{
		OpenURLWithIE(url);
	}
	else if(browser == "chrome")
	{
		OpenURLWithChrome(url);
	}
	else if (browser == "edge")
	{
		OpenURLWithMSEdge(url);
	}
	else if (browser == "msedge")
	{
		OpenURLWithMSEdge(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", url.c_str(), "", "", SW_SHOW);	// OS 기본 브라우저로 실행
	}

	return S_OK;
}

int BROWSER::Browser::OpenURLWithIE(const std::string url)
{
	ShellExecuteA(NULL, "open", "iexplore.exe", url.c_str(), "", SW_SHOW);
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithChrome(const std::string url)
{
	ShellExecuteA(NULL, "open", "chrome.exe", url.c_str(), "", SW_SHOW);
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithMSEdge(const std::string url)
{
	ShellExecuteA(NULL, "open", "msedge.exe", url.c_str(), "", SW_SHOW);

	return S_OK;
}
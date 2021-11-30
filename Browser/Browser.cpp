#include "Browser.h"

#include <algorithm>
#include <Windows.h>
#pragma comment(lib, "Shell32.lib")

int BROWSER::Browser::OpenURL(const std::string url, const std::string browser)
{	
	std::string strURL = url;
	std::string strBrowser = browser;
	
	std::transform(strBrowser.begin(), strBrowser.end(), strBrowser.begin(), ::tolower);
	
	if(strBrowser == "default")
	{
		ShellExecuteA(NULL, "open", strURL.c_str(), "", "", SW_SHOW);	// OS 기본 브라우저로 실행
	}
	else if(strBrowser == "ie")
	{
		OpenURLWithIE(url);
	}
	else if(strBrowser == "internet explorer")
	{
		OpenURLWithIE(url);
	}
	else if(strBrowser == "chrome")
	{
		OpenURLWithChrome(url);
	}
	else if (strBrowser == "edge")
	{
		OpenURLWithMSEdge(url);
	}
	else if (strBrowser == "msedge")
	{
		OpenURLWithMSEdge(url);
	}
	else
	{
		ShellExecuteA(NULL, "open", strURL.c_str(), "", "", SW_SHOW);	// OS 기본 브라우저로 실행
	}
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithIE(const std::string url)
{
	std::string strURL = url;
	
	ShellExecuteA(NULL, "open", "iexplore.exe", strURL.c_str(), "", SW_SHOW);
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithChrome(const std::string url)
{
	std::string strURL = url;
	
	ShellExecuteA(NULL, "open", "chrome.exe", strURL.c_str(), "", SW_SHOW);
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithMSEdge(const std::string url)
{
	std::string strURL = url;
	
	ShellExecuteA(NULL, "open", "msedge.exe", strURL.c_str(), "", SW_SHOW);
	
	return S_OK;
}
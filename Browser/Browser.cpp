#include "StdAfx.h"

#include "Browser.h"

#include <algorithm>

extern CLoggerV4 logger;

int BROWSER::Browser::OpenURL(const std::string url, const std::string browser)
{
	logger.trace("OpenURL Start");
	
	std::string strURL = url;
	std::string strBrowser = browser;
	
	std::transform(strBrowser.begin(), strBrowser.end(), strBrowser.begin(), ::tolower);
	
	if(strBrowser == "default")
	{
		ShellExecute(NULL, "open", strURL.c_str(), "", "", SW_SHOW);	// OS 기본 브라우저로 실행
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
	else
	{
		logger.trace("OpenURL, unknown browser[%s] check the param, run as the OS default browser.", strBrowser.c_str());
		logger.debug("OpenURL param[%s]", strURL.c_str());
		ShellExecute(NULL, "open", strURL.c_str(), "", "", SW_SHOW);	// OS 기본 브라우저로 실행
	}
	
	logger.trace("OpenURL End");
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithIE(const std::string url)
{
	logger.trace("OpenURLWithIE Start");
	
	std::string strURL = url;
	
	logger.debug("OpenURLWithIE param[%s]", strURL.c_str());
	ShellExecute(NULL, "open", "iexplore.exe", strURL.c_str(), "", SW_SHOW);
	
	logger.trace("OpenURLWithIE End");
	
	return S_OK;
}

int BROWSER::Browser::OpenURLWithChrome(const std::string url)
{
	logger.trace("OpenURLWithChrome Start");
	
	std::string strURL = url;
	
	logger.debug("OpenURLWithChrome param[%s]", strURL.c_str());
	ShellExecute(NULL, "open", "chrome.exe", strURL.c_str(), "", SW_SHOW);
	
	logger.trace("OpenURLWithChrome End");
	
	return S_OK;
}
// https://github.com/MoongStory/Browser

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _BROWSER_H_
#define _BROWSER_H_

#include <iostream>

// https://github.com/MoongStory/Registry
#include "../../Registry/Registry/Registry.h"

// https://github.com/MoongStory/Exception
#include "../../Exception/Exception/Exception.h"

namespace MOONG
{
	class Browser
	{
	public:
	protected:
	private:
		static const std::string REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER;
		static const std::string REG_VALUE_WINDOWS_DEFAULT_BROWSER;
		
	public:
		static void OpenURL(const std::string url, std::string browser = "Default") noexcept(false);
		static void OpenURLWithWindowsDefaultBrowser(const std::string url) noexcept(false);
		static void OpenURLWithIE(const std::string url) noexcept(true);
		static void OpenURLWithChrome(const std::string url) noexcept(true);
		static void OpenURLWithMSEdge(const std::string url) noexcept(true);
		
		static LSTATUS getWindowsDefaultBrowser(std::string& windows_default_browser) noexcept(false);
	protected:
	private:
	};
}
#endif	// _BROWSER_H_
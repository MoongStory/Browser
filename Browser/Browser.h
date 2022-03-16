// https://github.com/MoongStory/Browser

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _BROWSER_H_
#define _BROWSER_H_

#include <iostream>

// https://github.com/MoongStory/Registry
#include "../../Registry/Registry/Registry.h"

namespace MOONG
{
	namespace BROWSER
	{
		class Browser
		{
		public:
			Browser();

			int OpenURL(const std::string url, std::string browser = "Default") const;
			int OpenURLWithWindowsDefaultBrowser(const std::string url) const;
			int OpenURLWithIE(const std::string url) const;
			int OpenURLWithChrome(const std::string url) const;
			int OpenURLWithMSEdge(const std::string url) const;

			LSTATUS getWindowsDefaultBrowser(std::string& windows_default_browser) const;

		private:
			const std::string REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER;
			const std::string REG_VALUE_WINDOWS_DEFAULT_BROWSER;

			MOONG::REGISTRY::Registry registry_;
		};
	}
}
#endif	// _BROWSER_H_
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
		protected:
		private:
			static const std::string REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER;
			static const std::string REG_VALUE_WINDOWS_DEFAULT_BROWSER;

		public:
			static int OpenURL(const std::string url, std::string browser = "Default");
			static int OpenURLWithWindowsDefaultBrowser(const std::string url);
			static int OpenURLWithIE(const std::string url);
			static int OpenURLWithChrome(const std::string url);
			static int OpenURLWithMSEdge(const std::string url);

			static LSTATUS getWindowsDefaultBrowser(std::string& windows_default_browser);
		protected:
		private:
		};
	}
}
#endif	// _BROWSER_H_
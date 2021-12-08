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
			int OpenURL(const std::string url, std::string browser = "Default");
			int OpenURLWithWindowsDefaultBrowser(const std::string url);
			int OpenURLWithIE(const std::string url);
			int OpenURLWithChrome(const std::string url);
			int OpenURLWithMSEdge(const std::string url);

		private:
			const std::string REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.html\\UserChoice";
			const std::string REG_VALUE_WINDOWS_DEFAULT_BROWSER = "ProgID";

			MOONG::REGISTRY::Registry registry_;
		};
	}
}
#endif	// _BROWSER_H_
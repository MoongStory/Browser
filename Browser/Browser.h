// https://github.com/MoongStory/Browser

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _BROWSER_H_
#define _BROWSER_H_

#include <atlstr.h>

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

			int OpenURL(const CStringA url, CStringA browser = "Default") const;
			int OpenURLWithWindowsDefaultBrowser(const CStringA url) const;
			int OpenURLWithIE(const CStringA url) const;
			int OpenURLWithChrome(const CStringA url) const;
			int OpenURLWithMSEdge(const CStringA url) const;

		private:
			const CStringA REG_SUB_KEY_WINDOWS_DEFAULT_BROWSER;
			const CStringA REG_VALUE_WINDOWS_DEFAULT_BROWSER;

			MOONG::REGISTRY::Registry registry_;
		};
	}
}
#endif	// _BROWSER_H_
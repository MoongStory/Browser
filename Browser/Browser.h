#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _BROWSER_H_
#define _BROWSER_H_

namespace BROWSER
{
	class Browser
	{
	public :
		int OpenURL(const std::string url, const std::string browser = "Default");
		int OpenURLWithIE(const std::string url);
		int OpenURLWithChrome(const std::string url);
	};
}

#endif	// _BROWSER_H_
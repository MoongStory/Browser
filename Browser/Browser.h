/*******************************************************************************
MIT License

Copyright (c) 2023 Moong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

// https://github.com/MoongStory/Browser

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _BROWSER_H_
#define _BROWSER_H_

#include <iostream>
#include <Windows.h>

#ifndef LSTATUS
	#define LSTATUS LONG
#endif

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
		static void open_url(const std::string url, std::string browser = "Default");
		static void open_url_with_windows_default_browser(const std::string url);
		static void open_url_with_internet_explorer(const std::string url);
		static void open_url_with_chrome(const std::string url);
		static void open_url_with_edge(const std::string url);
		
		static LSTATUS get_windows_default_browser(std::string& windows_default_browser);
	protected:
	private:
	};
}
#endif	// _BROWSER_H_
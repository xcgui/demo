#ifndef deelxtool_h__
#define deelxtool_h__
#pragma warning(disable:4786)

#include <windows.h>
#include <string>
#include <VECTOR>
#include <map>

BOOL MatchTextA(
			   const char* lpszText,
			   const char* lpszRegular, 
			   std::string & szOut);
BOOL MatchTextA(
			   const char* lpszText,
			   const char* lpszRegular,
			   std::vector<std::string> &VOut);

BOOL MatchTextA(
				 const char* lpszText,
				 const char* lpszRegular,
				 std::map<std::string,std::string> &VOut);

BOOL MatchTextW(const wchar_t* lpszText, 
				const wchar_t* lpszRegular, 
				std::wstring & szOut);

BOOL MatchTextW(
				const wchar_t* lpszText, 
				const wchar_t* lpszRegular, 
				std::vector<std::wstring> &VOut);
BOOL MatchTextW(
				const wchar_t* lpszText,
				const wchar_t* lpszRegular,
				 std::map<std::wstring,std::wstring> &VOut);

#endif // deelxtool_h__
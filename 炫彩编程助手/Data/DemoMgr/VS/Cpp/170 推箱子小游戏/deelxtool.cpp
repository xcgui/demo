#include "deelxtool.h"

#include "deelx.h"


BOOL MatchTextA(
			   const char* lpszText,
			   const char* lpszRegular, 
			   std::string & szOut)
{
	CRegexpT <char> regexp(lpszRegular);
	MatchResult result = regexp.Match(lpszText);
	if(!result.IsMatched())
		return FALSE;
	
	szOut.assign( &lpszText[result.GetStart()] , &lpszText[result.GetEnd()]  );
	return TRUE;
}


BOOL MatchTextA(
			   const char* lpszText,
			   const char* lpszRegular,
			   std::vector<std::string> &VOut)
{
	CRegexpT <char> regexp(lpszRegular);
	CContext * pContext = regexp.PrepareMatch(lpszText);
	
	std::string s; s.reserve(1024);
    MatchResult result = regexp.Match(pContext);
    while( result.IsMatched() )
    {
		s.assign(&lpszText[result.GetStart()] , &lpszText[result.GetEnd()]);

		VOut.push_back(s);
        result = regexp.Match(pContext);
    }
    regexp.ReleaseContext(pContext);

	return VOut.size() ? TRUE : FALSE;
}


BOOL MatchTextA(
				 const char* lpszText,
				 const char* lpszRegular,
				 std::map<std::string,std::string> &VOut)
{
	CRegexpT <char> regexp(lpszRegular);
	CContext * pContext = regexp.PrepareMatch(lpszText);
	
	std::string sK; sK.reserve(1024);
	std::string sV; sV.reserve(1024);

    MatchResult result = regexp.Match(pContext);
    while( result.IsMatched() )
    {
		if (result.MaxGroupNumber() == 2 )
		{
			sK.assign(&lpszText[result.GetGroupStart(1)] , &lpszText[result.GetGroupEnd(1)]);
			sV.assign(&lpszText[result.GetGroupStart(2)] , &lpszText[result.GetGroupEnd(2)]);
			VOut.insert(std::pair<std::string,std::string>(sK,sV));
		}
        result = regexp.Match(pContext);
    }
    regexp.ReleaseContext(pContext);
	
	return VOut.size() ? TRUE : FALSE;
}








BOOL MatchTextW(const wchar_t* lpszText, 
				const wchar_t* lpszRegular, 
				std::wstring & szOut)
{
	CRegexpT <wchar_t> regexp(lpszRegular);
	MatchResult result = regexp.Match(lpszText);
	if(!result.IsMatched())
		return FALSE;
	
	szOut.assign( &lpszText[result.GetStart()] , &lpszText[result.GetEnd()]  );
	return TRUE;
}


BOOL MatchTextW(
				const wchar_t* lpszText, 
				const wchar_t* lpszRegular, 
				std::vector<std::wstring> &VOut)
{
	CRegexpT <wchar_t> regexp(lpszRegular);
	CContext * pContext = regexp.PrepareMatch(lpszText);
	
	std::wstring s; s.reserve(1024);
    MatchResult result = regexp.Match(pContext);
    while( result.IsMatched() )
    {
		s.assign(&lpszText[result.GetStart()] , &lpszText[result.GetEnd()]);
		
		VOut.push_back(s);
        result = regexp.Match(pContext);
    }
    regexp.ReleaseContext(pContext);
	
	return VOut.size() ? TRUE : FALSE;
}


BOOL MatchTextW(
				 const wchar_t* lpszText,
				 const wchar_t* lpszRegular,
				 std::map<std::wstring,std::wstring> &VOut)
{
	CRegexpT <wchar_t> regexp(lpszRegular);
	CContext * pContext = regexp.PrepareMatch(lpszText);
	
	std::wstring sK; sK.reserve(1024);
	std::wstring sV; sV.reserve(1024);
	
    MatchResult result = regexp.Match(pContext);
    while( result.IsMatched() )
    {
		if (result.MaxGroupNumber() == 2 )
		{
			sK.assign(&lpszText[result.GetGroupStart(0)] , &lpszText[result.GetGroupEnd(0)]);
			sV.assign(&lpszText[result.GetGroupStart(1)] , &lpszText[result.GetGroupEnd(1)]);
			OutputDebugStringW(sK.c_str());
			OutputDebugStringW(sV.c_str());
			VOut.insert(std::pair<std::wstring,std::wstring>(sK,sV));
		}
        result = regexp.Match(pContext);
    }
    regexp.ReleaseContext(pContext);
	
	return VOut.size() ? TRUE : FALSE;
}
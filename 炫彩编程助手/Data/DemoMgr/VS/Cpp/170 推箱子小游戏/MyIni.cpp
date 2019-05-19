#include "MyIni.h"
#include "Directory.h"
#include <strsafe.h>

BOOL CIni::Open( const char* lpFileName )
{
	std::string szfileData;
	XC_ReadFileA(lpFileName,szfileData);
	return MatchTextA(szfileData.c_str(),"\\[\\s*(\\S+)\\s*=\\s*(\\S+)\\s*\\]",VOut);
}

BOOL CIni::Close( const char* lpFileName )
{
	std::string data;
	std::map<std::string,std::string>::iterator it = VOut.begin();
	while(it != VOut.end())
	{
		data =data+"["+it->first.c_str()+"="+it->second.c_str()+"]\r\n";
		++it;
	}
	return XC_WriteFileA(lpFileName,(VOID*)data.c_str(),data.size());
}

int CIni::GetValueInt( std::string strKey )
{
	return atoi(GetValue(strKey).c_str());
}

std::string CIni::GetValue( std::string strKey )
{
	std::string re;
	std::map<std::string,std::string>::iterator it = VOut.find(strKey);
	if (it == VOut.end())
		return "";
	
	return it->second;
}

VOID CIni::SetValueInt( std::string strKey,int nValue )
{
	char buff[MAX_PATH] = {0};
	StringCbPrintfA(buff,MAX_PATH,"%d",nValue);
	SetValue(strKey,buff);
}

VOID CIni::SetValue( std::string strKey,std::string strValue )
{
	std::map<std::string,std::string>::iterator it = VOut.find(strKey);
	if (it == VOut.end())
	{
		VOut.insert(std::pair<std::string,std::string>(strKey,strValue));
	}else
	{
		it->second = strValue;
	}
}

float CIni::GetValueFloat( std::string strKey )
{
	return atof(GetValue(strKey).c_str());
}

VOID CIni::SetValueFloat( std::string strKey,int nValue )
{
	char buff[MAX_PATH] = {0};
	StringCbPrintfA(buff,MAX_PATH,"%f",nValue);
	SetValue(strKey,buff);
}

#if 0


HINI Ini_Init()
{
	return new CIni;
}

VOID Ini_UnInit( HINI hIni )
{
	delete hIni;
	hIni = NULL;
}

BOOL Ini_Open(HINI hIni,const char* lpFileName )
{
	return hIni->Open(lpFileName);
}

BOOL Ini_Close( HINI hIni,const char* lpFileName )
{
	return hIni->Close(lpFileName);
}

int Ini_GetValueInt( HINI hIni,std::string strKey )
{
	return hIni->GetValueInt(strKey);
}

VOID Ini_SetValueInt( HINI hIni,std::string strKey,int nValue )
{
	hIni->SetValueInt(strKey,nValue);
}

VOID Ini_SetValueString( HINI hIni,std::string strKey,std::string strValue )
{
	hIni->SetValue(strKey,strValue);
}

std::string Ini_GetValueString( HINI hIni,std::string strKey )
{
	return hIni->GetValue(strKey);
}

#endif
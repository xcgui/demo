#ifndef MyIni_h__
#define MyIni_h__

#include "deelxtool.h"

// [cmd1=open]
// [cmd2=close]
// [cmd3=read]
// [cmd4=write]
class CIni
{
public:
	BOOL Open(const char* lpFileName);
	BOOL Close(const char* lpFileName);

	VOID SetValue(std::string strKey,std::string strValue);
	std::string GetValue(std::string strKey);

	VOID SetValueInt(std::string strKey,int nValue);
	int GetValueInt(std::string strKey);
	float GetValueFloat(std::string strKey);
	VOID SetValueFloat(std::string strKey,int nValue);

private:
	std::map<std::string,std::string> VOut;
};


#if 0

typedef CIni*  HINI;
HINI Ini_Init();
VOID Ini_UnInit(HINI hIni);
BOOL Ini_Open(HINI hIni,const char* lpFileName);
BOOL Ini_Close(HINI hIni,const char* lpFileName);
int Ini_GetValueInt(HINI hIni,std::string strKey);
VOID Ini_SetValueInt(HINI hIni,std::string strKey,int nValue);
VOID Ini_SetValueString(HINI hIni,std::string strKey,std::string strValue);
std::string Ini_GetValueString(HINI hIni,std::string strKey);

#endif




#endif // MyIni_h__
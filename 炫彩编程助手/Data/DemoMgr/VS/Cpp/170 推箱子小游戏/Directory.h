#ifndef DirectoryOption_h__
#define DirectoryOption_h__

#include <windows.h>

#pragma warning(disable:4786)
#include <wchar.h>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_PATH_XC    4096
#define ZeroMaxPathXC(pBuffer)  ZeroMemory(pBuffer,sizeof(wchar_t)*MAX_PATH_XC)


VOID XC_GetModuleFileDirectoryA(std::string& szOutDir);
VOID XC_GetModuleFileDirectoryW(std::wstring& szOutDir);

VOID MyGetDirectory(wchar_t* pDir, int size);
unsigned long XC_GetFileSize(wchar_t* pFile,unsigned long * pFileSizeHight);
VOID XC_OpenFloderW(const wchar_t* pDir);
VOID XC_OpenFloderA(const char* pDir);
int XC_CopyFile(const wchar_t* pSrc,const wchar_t* pDes);
BOOL XC_IsDirectory(wchar_t* lpFile);
BOOL XC_ReNameFolder(const wchar_t* lpszFromPath,const wchar_t* lpszToPath);
BOOL XC_DeleteFolderW(const wchar_t* lpszPath);
BOOL XC_DeleteFolderA(const char* lpszPath);
bool XC_IsFileExsit(const wchar_t* file);
BOOL XC_ReadFileA(const char* lpFileName,std::string& szOutData);
BOOL XC_ReadFileW(const wchar_t* lpFileName,std::wstring& szOutData);
BOOL XC_WriteFileA( const char* lpFileName,void* pData,int nSize );
BOOL XC_WriteFileW(const wchar_t* lpFileName,void* pData,int nSize);
BOOL XC_Exec(const wchar_t* lpFileName,PROCESS_INFORMATION* ppi);
BOOL XC_CMD(wchar_t* lpszCmd,const wchar_t* lpszCurDir,BOOL bWait,BOOL bShow = FALSE);




class CEnumPath
{
public:
	~CEnumPath();
	CEnumPath(const wchar_t* pPath,BOOL bDir = TRUE,BOOL bFullPath = FALSE);
	wchar_t* operator[](int n);
	
	int GetItemCount();
	
private:
	int m_nCount;
	wchar_t* m_Path[MAX_PATH_XC];
};

BOOL EnumPathFileW(const wchar_t* lpszDir,
				   const wchar_t* lpFilte /* *.txt *.rar */,
				   BOOL bFullPath,
				   std::vector<std::wstring>&  VOutData);
BOOL EnumPathFileA(
				   const char* lpszDir,
				   const char* lpFilte /* *.txt *.rar */,
				   BOOL bFullPath,
				   std::vector<std::string>&  VOutData);


BOOL EnumPathDirW(
				   const wchar_t* lpszDir,
				   BOOL bFullPath,
				   std::vector<std::wstring>&  VOutData);
BOOL EnumPathDirA(
				  const char* lpszDir,
				  BOOL bFullPath,
				  std::vector<std::string>&  VOutData);

BOOL GetFileNameFromFullPathNameW(const wchar_t* lpFullPathName,std::wstring& szOutData);
BOOL GetFileNameFromFullPathNameA(const char* lpFullPathName,std::string& szOutData);

#endif // DirectoryOption_h__
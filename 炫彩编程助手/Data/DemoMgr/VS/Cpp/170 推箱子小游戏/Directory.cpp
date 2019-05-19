#include "Directory.h"
#include <strsafe.h>
#include <Dbghelp.h>
#pragma comment(lib,"Dbghelp.lib")

#include "CCodec.h"

//例子 c:\abc\cde\ 
//c:\abc\cde\dasemimi.txt 

BOOL XC_MakeSureDirectoryPathExistsA(const char* lpszDir)
{
	return MakeSureDirectoryPathExists(lpszDir);
}

BOOL XC_MakeSureDirectoryPathExistsW(const wchar_t* lpszDir)
{
	return XC_MakeSureDirectoryPathExistsA(bm_utf16_to_ascii(lpszDir).c_str());
}

VOID XC_GetModuleFileDirectoryW( std::wstring& szOutDir )
{
	wchar_t pDir[MAX_PATH_XC] ={0};
	if(0!=GetModuleFileNameW(NULL,pDir,MAX_PATH_XC))
	{
		wchar_t *pFilePath=wcsrchr(pDir, L'\\' );
		if(pFilePath)
		{
			pFilePath[0]=L'\0';
			szOutDir = pDir;
		}
	}
}
VOID XC_GetModuleFileDirectoryA( std::string& szOutDir )
{
	char pDir[MAX_PATH_XC] ={0};
	if(0!=GetModuleFileNameA(NULL,pDir,MAX_PATH_XC))
	{
		char *pFilePath=strrchr(pDir, '\\' );
		if(pFilePath)
		{
			pFilePath[0]=L'\0';
			szOutDir = pDir;
		}
	}
}


void MyGetDirectory(wchar_t* pDir, int size)
{
	if(0!=GetModuleFileNameW(NULL,pDir,size))
	{
		wchar_t *pFilePath=wcsrchr(pDir, L'\\' );
		if(pFilePath)
		{
			pFilePath[0]=L'\0';
		}
	}
}


unsigned long XC_GetFileSize(wchar_t* pFile,unsigned long * pFileSizeHight)
{
	HANDLE hFile = CreateFileW(pFile,
		GENERIC_READ,FILE_SHARE_READ,
		NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return 0;
	}
	unsigned long nSize = GetFileSize(hFile,pFileSizeHight);
	CloseHandle(hFile);
	return nSize;
}


VOID XC_OpenFloderW(const wchar_t* pDir)
{
	wchar_t lpCmd[MAX_PATH_XC] = {0};
	StringCbPrintfW(lpCmd,MAX_PATH_XC*sizeof(wchar_t),L"%s\"%s\"",L"explorer.exe ",pDir);
	STARTUPINFOW si={0};
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);
	if (!CreateProcessW(NULL,lpCmd,NULL,NULL,NULL,0,NULL,NULL,&si,&pi))
	{
		StringCbPrintfW(lpCmd,MAX_PATH_XC*sizeof(wchar_t),L"start \"%s\"",pDir);
		if (!CreateProcessW(NULL,lpCmd,NULL,NULL,NULL,0,NULL,NULL,&si,&pi))
		{
			ShellExecuteW( NULL,L"open", L"explorer.exe", pDir, NULL, SW_SHOWNORMAL );
		}
	}else
	{
		CloseHandle(pi.hProcess);
	}
}
VOID XC_OpenFloderA(const char* pDir)
{
	char lpCmd[MAX_PATH_XC] = {0};
	StringCbPrintfA(lpCmd,MAX_PATH_XC,"%s\"%s\"","explorer.exe ",pDir);
	STARTUPINFOA si={0};
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);
	CreateProcessA(NULL,lpCmd,NULL,NULL,NULL,0,NULL,NULL,&si,&pi);
	CloseHandle(pi.hProcess);
}

class _SHFileOperationW
{
public:
	_SHFileOperationW(const wchar_t* pData)
	{
		int nSrcLen = wcslen(pData);
		SrcBuffer= new wchar_t[nSrcLen+2];
		CopyMemory(SrcBuffer,pData,nSrcLen*sizeof(wchar_t));
		SrcBuffer[nSrcLen] = L'\0';
		SrcBuffer[nSrcLen+1] = L'\0';
	}
	wchar_t* GetBuffer()
	{
		return SrcBuffer;
	}
	~_SHFileOperationW()
	{
		delete SrcBuffer;
	}
private:
	wchar_t* SrcBuffer;
};

class _SHFileOperationA
{
public:
	_SHFileOperationA(const char* pData)
	{
		int nSrcLen = strlen(pData);
		SrcBuffer= new char[nSrcLen+2];
		CopyMemory(SrcBuffer,pData,nSrcLen*sizeof(char));
		SrcBuffer[nSrcLen] = L'\0';
		SrcBuffer[nSrcLen+1] = L'\0';
	}
	char* GetBuffer()
	{
		return SrcBuffer;
	}
	~_SHFileOperationA()
	{
		delete SrcBuffer;
	}
private:
	char* SrcBuffer;
};

int XC_CopyFile(const wchar_t* pSrc,const wchar_t* pDes)
{
	_SHFileOperationW Src(pSrc);
	_SHFileOperationW Des(pDes);

	SHFILEOPSTRUCTW fileOp ={0};
	fileOp.fFlags = FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR ;
	fileOp.pFrom = Src.GetBuffer();
	fileOp.pTo   = Des.GetBuffer();
	fileOp.wFunc = FO_COPY;

	return SHFileOperationW(&fileOp);
}
BOOL XC_IsDirectory(wchar_t* lpFile)
{
	if (GetFileAttributesW(lpFile) == FILE_ATTRIBUTE_DIRECTORY)
		return TRUE;
	return FALSE;
}

BOOL XC_DeleteFolderW(const wchar_t* lpszPath) 
{ 
	_SHFileOperationW Src(lpszPath);

	SHFILEOPSTRUCTW FileOp; 
	ZeroMemory((void*)&FileOp,sizeof(SHFILEOPSTRUCTW));
	
	FileOp.fFlags = FOF_NOCONFIRMATION; 
	FileOp.hNameMappings = NULL; 
	FileOp.hwnd = NULL; 
	FileOp.lpszProgressTitle = NULL; 
	FileOp.pFrom = Src.GetBuffer(); 
	FileOp.pTo = NULL; 
	FileOp.wFunc = FO_DELETE; 
	
	return SHFileOperationW(&FileOp) == 0;
}
BOOL XC_DeleteFolderA(const char* lpszPath) 
{
	_SHFileOperationA Src(lpszPath);
	SHFILEOPSTRUCTA FileOp; 
	ZeroMemory((void*)&FileOp,sizeof(FileOp));
	
	FileOp.fFlags = FOF_NOCONFIRMATION; 
	FileOp.hNameMappings = NULL; 
	FileOp.hwnd = NULL; 
	FileOp.lpszProgressTitle = NULL; 
	FileOp.pFrom = Src.GetBuffer(); 
	FileOp.pTo = NULL; 
	FileOp.wFunc = FO_DELETE; 
	
	return SHFileOperationA(&FileOp) == 0;
}

/////////////////////////////////////
//ReNameFolder
//参数：lpszFromPath 源文件夹路径 。lpszToPath 目的文件夹路径
//作用：修改原文件夹的名字。
//
/////////////////////////////////////
BOOL XC_ReNameFolder(const wchar_t* lpszFromPath,const wchar_t* lpszToPath)
{
	_SHFileOperationW Src(lpszFromPath);
	_SHFileOperationW Des(lpszToPath);

    SHFILEOPSTRUCTW FileOp;
    ZeroMemory((void*)&FileOp,sizeof(SHFILEOPSTRUCTW));
    FileOp.fFlags = FOF_CONFIRMMOUSE;//FOF_NOCONFIRMATION ;
    FileOp.hNameMappings = NULL;
    FileOp.hwnd = NULL;
    FileOp.lpszProgressTitle = NULL;
    FileOp.pFrom = Src.GetBuffer();
    FileOp.pTo = Des.GetBuffer();
    FileOp.wFunc = FO_RENAME;
	
    return SHFileOperationW(&FileOp) == 0;
}
bool XC_IsFileExsit(const wchar_t* file)
{
	FILE* hFile = _wfopen(file,L"r");
	if (hFile != NULL)
	{
		fclose(hFile);
		return true;
	}
	return false;
}

BOOL XC_ReadFileA(const char* lpFileName,std::string& szOutData)
{
	FILE *fp = fopen(lpFileName, "r");
	if (fp == NULL)
		return FALSE;
    fseek( fp , 0 , SEEK_END );
    szOutData.resize(ftell( fp ));
    fseek( fp , 0 , SEEK_SET);
    fread( szOutData.begin() , szOutData.size() , sizeof(char) , fp);
	fclose(fp);
	return TRUE;
}

BOOL XC_ReadFileW(const wchar_t* lpFileName,std::wstring& szOutData)
{
	FILE *fp = _wfopen(lpFileName, L"r");
	if (fp == NULL)
		return FALSE;
    fseek( fp , 0 , SEEK_END );
    szOutData.resize(ftell( fp ));
    fseek( fp , 0 , SEEK_SET);
    fread( szOutData.begin() , szOutData.size() , sizeof(char) , fp);
	fclose(fp);
	return TRUE;
}

BOOL XC_WriteFileW( const wchar_t* lpFileName,void* pData,int nSize )
{
	FILE* hFile = _wfopen(lpFileName,L"wb");
	if (hFile == NULL)
		return FALSE;
	fwrite(pData,1,nSize,hFile);
	fclose(hFile);
	return TRUE;
}
BOOL XC_WriteFileA( const char* lpFileName,void* pData,int nSize )
{
	FILE* hFile = fopen(lpFileName,"wb");
	if (hFile == NULL)
		return FALSE;
	fwrite(pData,1,nSize,hFile);
	fclose(hFile);
	return TRUE;
}

BOOL XC_Exec( const wchar_t* lpFileName,PROCESS_INFORMATION* ppi )
{
	STARTUPINFOW si={0};
	si.cb = sizeof(si);
	BOOL bok= CreateProcessW(lpFileName,NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,ppi);
	CloseHandle(ppi->hProcess);
	return bok;
}

BOOL XC_CMD(wchar_t* lpszCmd,const wchar_t* lpszCurDir,BOOL bWait,BOOL bShow)
{
	PROCESS_INFORMATION pi;
	STARTUPINFOW si={0};
	si.cb = sizeof(si);
	if (bShow = TRUE)
		si.wShowWindow = SW_SHOW;
	BOOL bOk = CreateProcessW(NULL,lpszCmd,NULL,NULL,FALSE,0,NULL,lpszCurDir,&si,&pi);
	if (bWait == TRUE)
	{
		WaitForSingleObject(pi.hProcess,-1);
	}else
	{
		CloseHandle(pi.hProcess);
	}
	return bOk;
}


////////////////////////////////////////////////////////
CEnumPath::~CEnumPath()
{
	for (int i = 0; i < m_nCount; i++)
	{
		if (m_Path[i] != NULL)
		{
			delete [] m_Path[i];
			m_Path[i] = NULL;
		}
	}
	m_nCount = 0;
}

CEnumPath::CEnumPath(const wchar_t* pPath,BOOL bDir,BOOL bFullPath):m_nCount(0)
{
	ZeroMemory(m_Path,sizeof(wchar_t*)*MAX_PATH_XC);
	WIN32_FIND_DATAW FileData={0}; 
	wchar_t TempPath[MAX_PATH] = {0};
	StringCbCopyW(TempPath,sizeof(wchar_t*)*MAX_PATH_XC,pPath);
	if (TempPath[wcslen(pPath)] != L'\\')
	{
		StringCbCatW(TempPath,sizeof(wchar_t*)*MAX_PATH_XC,L"\\");
	}
	StringCbCatW(TempPath,sizeof(wchar_t*)*MAX_PATH_XC,L"*.*");
	HANDLE hSearch = FindFirstFileW(TempPath, &FileData); 
	
	if (hSearch == INVALID_HANDLE_VALUE) 
	{
		return;
	}
	BOOL fFinished = FALSE; 
	m_nCount = 0;
	while (!fFinished)
	{
		if ((wcscmp(FileData.cFileName,L".") != 0) && (wcscmp(FileData.cFileName,L"..") != 0))
		{
			if ( (FILE_ATTRIBUTE_DIRECTORY & FileData.dwFileAttributes) != 0 )
			{
				if (bDir == TRUE)
				{
					m_Path[m_nCount] = new wchar_t[MAX_PATH_XC];
					ZeroMaxPathXC(m_Path[m_nCount]);
					if (bFullPath == TRUE)
					{
						StringCbCatW(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC,pPath);
						StringCbCatW(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC,L"\\");
					}
					StringCbCatW(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC,FileData.cFileName);
					m_nCount++;
				}
			}else
			{
				if (bDir == FALSE)
				{
					m_Path[m_nCount] = new wchar_t[MAX_PATH_XC];
					ZeroMemory(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC);
					if (bFullPath == TRUE)
					{
						StringCbCatW(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC,pPath);
						StringCbCatW(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC,L"\\");
					}
					StringCbCatW(m_Path[m_nCount],sizeof(wchar_t)*MAX_PATH_XC,FileData.cFileName);
					m_nCount++;
				}
			}
		}
		ZeroMemory(&FileData,sizeof(FileData));
		if (!FindNextFileW(hSearch, &FileData)) 
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) 
			{ 
				fFinished = TRUE; 
			} 
			else 
			{ 
				FindClose(hSearch);
				return ;
			} 
		}
	}
	FindClose(hSearch);
}

wchar_t* CEnumPath::operator[](int n)
{
	return m_Path[n];
}

int CEnumPath::GetItemCount()
{
	return m_nCount;
}


BOOL EnumPathFileW(const wchar_t* lpszDir,const wchar_t* lpFilte /* *.txt *.rar */,BOOL bFullPath,std::vector<std::wstring>&  VOutData)
{

	WIN32_FIND_DATAW FileData={0}; 
	wchar_t TempPath[MAX_PATH_XC] = {0};
	StringCbCopyW(TempPath,sizeof(wchar_t)*MAX_PATH_XC,lpszDir);
	if (TempPath[wcslen(lpszDir)] != L'\\')
		StringCbCatW(TempPath,sizeof(wchar_t)*MAX_PATH_XC,L"\\");
	StringCbCatW(TempPath,sizeof(wchar_t)*MAX_PATH_XC,lpFilte);
	HANDLE hSearch = FindFirstFileW(TempPath, &FileData); 
	
	if (hSearch == INVALID_HANDLE_VALUE) 
		return FALSE;

	BOOL fFinished = FALSE; 
	wchar_t lpszFullFileName[MAX_PATH_XC] = {0};

	while (!fFinished)
	{
		ZeroMemory(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t));

		if (bFullPath == TRUE)
		{
			StringCbCatW(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t),lpszDir);
			StringCbCatW(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t),L"\\");
		}
		StringCbCatW(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t),FileData.cFileName);
		VOutData.push_back(lpszFullFileName);

		ZeroMemory(&FileData,sizeof(FileData));
		if (!FindNextFileW(hSearch, &FileData)) 
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) 
			{ 
				fFinished = TRUE; 
			} 
			else 
			{ 
				FindClose(hSearch);
				return FALSE;
			} 
		}
	}
	FindClose(hSearch);
	return TRUE;
}


BOOL EnumPathFileA(
				   const char* lpszDir,
				   const char* lpFilte /* *.txt *.rar */,
				   BOOL bFullPath,
				   std::vector<std::string>&  VOutData)
{
	
	WIN32_FIND_DATAA FileData={0}; 
	char TempPath[MAX_PATH_XC] = {0};
	StringCbCopyA(TempPath,MAX_PATH_XC,lpszDir);
	if (TempPath[strlen(lpszDir)] != '\\')
		StringCbCatA(TempPath,MAX_PATH_XC,"\\");

	StringCbCatA(TempPath,MAX_PATH_XC,lpFilte);
	HANDLE hSearch = FindFirstFileA(TempPath, &FileData); 
	
	if (hSearch == INVALID_HANDLE_VALUE) 
		return FALSE;
	
	BOOL fFinished = FALSE; 
	char lpszFullFileName[MAX_PATH_XC] = {0};
	
	while (!fFinished)
	{
		ZeroMemory(lpszFullFileName,MAX_PATH_XC);
		if ((strcmp(FileData.cFileName,".") != 0) && (strcmp(FileData.cFileName,"..") != 0))
		{
			if (bFullPath == TRUE)
			{
				StringCbCatA(lpszFullFileName,MAX_PATH_XC,lpszDir);
				StringCbCatA(lpszFullFileName,MAX_PATH_XC,"\\");
			}
			StringCbCatA(lpszFullFileName,MAX_PATH_XC,FileData.cFileName);
			VOutData.push_back(lpszFullFileName);
		}
		ZeroMemory(&FileData,sizeof(FileData));
		if (!FindNextFileA(hSearch, &FileData)) 
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) 
			{ 
				fFinished = TRUE; 
			} 
			else 
			{ 
				FindClose(hSearch);
				return FALSE;
			} 
		}
	}
	FindClose(hSearch);
	return TRUE;
}


BOOL EnumPathDirW(
				  const wchar_t* lpszDir,
				  BOOL bFullPath,
				  std::vector<std::wstring>&  VOutData)
{
	WIN32_FIND_DATAW FileData={0}; 
	wchar_t TempPath[MAX_PATH_XC] = {0};
	StringCbCopyW(TempPath,sizeof(wchar_t)*MAX_PATH_XC,lpszDir);
	if (TempPath[wcslen(lpszDir)-1] != L'\\')
		StringCbCatW(TempPath,sizeof(wchar_t)*MAX_PATH_XC,L"\\");
	StringCbCatW(TempPath,sizeof(wchar_t)*MAX_PATH_XC,L"*.*");
	HANDLE hSearch = FindFirstFileW(TempPath, &FileData); 
	
	if (hSearch == INVALID_HANDLE_VALUE) 
		return FALSE;
	
	BOOL fFinished = FALSE; 
	wchar_t lpszFullFileName[MAX_PATH_XC] = {0};
	
	while (!fFinished)
	{
		ZeroMemory(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t));
		if ((wcscmp(FileData.cFileName,L".") != 0) && (wcscmp(FileData.cFileName,L"..") != 0))
		{
			if ( (FILE_ATTRIBUTE_DIRECTORY & FileData.dwFileAttributes) != 0 )
			{
				if (bFullPath == TRUE)
				{
					StringCbCatW(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t),lpszDir);
					StringCbCatW(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t),L"\\");
				}
				StringCbCatW(lpszFullFileName,MAX_PATH_XC*sizeof(wchar_t),FileData.cFileName);
				VOutData.push_back(lpszFullFileName);
			}
		}
		ZeroMemory(&FileData,sizeof(FileData));
		if (!FindNextFileW(hSearch, &FileData)) 
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) 
			{ 
				fFinished = TRUE; 
			} 
			else
			{ 
				FindClose(hSearch);
				return FALSE;
			} 
		}
	}
	FindClose(hSearch);
	return TRUE;
}

BOOL EnumPathDirA(
				  const char* lpszDir,
				  BOOL bFullPath,
				  std::vector<std::string>&  VOutData)
{
	WIN32_FIND_DATAA FileData={0}; 
	char TempPath[MAX_PATH_XC] = {0};
	StringCbCopyA(TempPath,MAX_PATH_XC,lpszDir);
	if (TempPath[strlen(lpszDir)-1] != '\\')
		StringCbCatA(TempPath,MAX_PATH_XC,"\\");
	StringCbCatA(TempPath,MAX_PATH_XC,"*.*");
	HANDLE hSearch = FindFirstFileA(TempPath, &FileData); 
	
	if (hSearch == INVALID_HANDLE_VALUE) 
		return FALSE;
	
	BOOL fFinished = FALSE; 
	char lpszFullFileName[MAX_PATH_XC] = {0};
	
	while (!fFinished)
	{
		ZeroMemory(lpszFullFileName,MAX_PATH_XC);
		if ((strcmp(FileData.cFileName,".") != 0) && (strcmp(FileData.cFileName,"..") != 0))
		{
			if ( (FILE_ATTRIBUTE_DIRECTORY & FileData.dwFileAttributes) != 0 )
			{
				if (bFullPath == TRUE)
				{
					StringCbCatA(lpszFullFileName,MAX_PATH_XC,lpszDir);
					StringCbCatA(lpszFullFileName,MAX_PATH_XC,"\\");
				}
				StringCbCatA(lpszFullFileName,MAX_PATH_XC,FileData.cFileName);
				VOutData.push_back(lpszFullFileName);
			}
		}
		ZeroMemory(&FileData,sizeof(FileData));
		if (!FindNextFileA(hSearch, &FileData)) 
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) 
			{ 
				fFinished = TRUE; 
			} 
			else 
			{ 
				FindClose(hSearch);
				return FALSE;
			} 
		}
	}
	FindClose(hSearch);
	return TRUE;
}


BOOL GetFileNameFromFullPathNameW( const wchar_t* lpFullPathName,std::wstring& szOutData )
{
	for (int i = wcslen(lpFullPathName)-1; i > 0; i--)
	{
		if (lpFullPathName[i] == L'\\')
		{
			szOutData = lpFullPathName+i+1;
			return TRUE;
		}
	}
	return FALSE;
}

BOOL GetFileNameFromFullPathNameA(const char* lpFullPathName,std::string& szOutData)
{
	for (int i = strlen(lpFullPathName)-1; i > 0; i--)
	{
		if (lpFullPathName[i] == L'\\')
		{
			szOutData = lpFullPathName+i+1;
			return TRUE;
		}
	}
	return FALSE;
}
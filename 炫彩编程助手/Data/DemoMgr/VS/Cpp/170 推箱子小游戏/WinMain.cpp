#pragma warning(disable:4786)
#include "Common.h"
#include <strsafe.h>

#include "MyIni.h"
#include "CCodec.h"





// 1 地图设计
/*

0 什么都没有 
1 表示有墙
2 表示是地板
3 表示人
4 箱子
5 表示坐标位置

00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
*/

#define TYPE_NONE  0
#define TYPE_QIANG 1
#define TYPE_DIBAN 2
#define TYPE_MAN   3
#define TYPE_XIANGZI   4
#define TYPE_DES   5



#define MAX_ROW_COUNT 64
#define MAX_COL_COUNT 64
typedef struct _tagMapData
{
	int Array[MAX_ROW_COUNT][MAX_COL_COUNT];
	int Mark[MAX_ROW_COUNT][MAX_COL_COUNT];
}MapData,*PMapData;



BOOL Data_GetManXY(int nRowCount,int nColCount,MapData gInfo,int* pOutX,int* pOutY)
{
	for (int i = 0; i < nRowCount; i++)
	{
		for (int j = 0; j < nColCount; j++)
		{
			if (gInfo.Array[i][j] == TYPE_MAN)
			{
				*pOutX = j;
				*pOutY = i;
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL Data_HasManXY(int nRowCount,int nColCount,MapData gInfo)
{
	for (int i = 0; i < nRowCount; i++)
	{
		for (int j = 0; j < nColCount; j++)
		{
			if (gInfo.Array[i][j] == TYPE_MAN)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

VOID Data_StringToMapData(int nRowCount,int nColCount,const char* lpText,MapData& data)
{

	for (int i = 0; i < nRowCount; i++)
	{
		for (int j = 0; j < nColCount; j++)
		{

			char buff[2] = {0};
			buff[0] = lpText[i*nColCount+j];
			data.Array[i][j] = atoi(buff);
			if (data.Array[i][j] == TYPE_DES)
			{
				data.Mark[i][j] = TYPE_DES;
				data.Array[i][j] = TYPE_DIBAN;
			}else
			{
				data.Mark[i][j] = TYPE_NONE;
			}
			
		}
	}
	
}

//游戏控制器
class GControl
{
public:
	VOID Init(int nRowCount,int nColCount,MapData data)
	{
		m_RowCount = nRowCount;
		m_ColCount = nRowCount;
		Data_GetManXY(m_RowCount,m_ColCount,data,&m_ManX,&m_ManY);
		AddMap(data);
	}

	BOOL OnMove(int nVK)
	{
		int srcX = m_ManX;
		int srcY = m_ManY;
		int desX,desY;
		Fix1(nVK,srcX,srcY,&desX,&desY);
		
		//左边没路了
		if (!XY_IsInMap(desX,desY))
			return FALSE;
		MapData mpdt;
		GetMap(mpdt);

		int nType = XY_GetType(mpdt,desX,desY);
		//左边就是墙了
		if (nType == TYPE_QIANG || nType == TYPE_NONE)
			return FALSE;
		
		//左边一格是路
		if (nType == TYPE_DIBAN)
		{
			MapData data;
			GetMap(data);
			
			XY_SetType(data,desX,desY,TYPE_MAN);
			XY_SetType(data,srcX,srcY,TYPE_DIBAN);

			m_ManX = desX;
			m_ManY = desY;

			AddMap(data);
			return TRUE;
		}
		//左边一格是箱子
// 		if (XY_GetType(desX,desY) != TYPE_XIANGZI)
// 			return FALSE;
		
		int desX2,desY2;
		Fix1(nVK,desX,desY,&desX2,&desY2);
		
		//左边已经到底了。。。
		if (!XY_IsInMap(desX2,desY2))
			return FALSE;

		//左边就是墙了
		nType = XY_GetType(mpdt,desX2,desY2);
		if (nType == TYPE_QIANG || nType == TYPE_NONE)
			return FALSE;

		//左边也是箱子
		if (nType == TYPE_XIANGZI)
			return FALSE;
		
		if (nType != TYPE_DIBAN)
			return FALSE;

		//可以推
		MapData data;
		GetMap(data);

		XY_SetType(data,srcX,srcY,TYPE_DIBAN);
		XY_SetType(data,desX,desY,TYPE_MAN);
		XY_SetType(data,desX2,desY2,TYPE_XIANGZI);

		m_ManX = desX;
		m_ManY = desY;

		AddMap(data);
		return TRUE;
	}

	VOID Fix1(int vk,int srcX,int srcY,int* pX,int* pY)
	{
		*pX = srcX;
		*pY = srcY;
		if(vk == VK_LEFT)
			*pX = srcX-1;
		if(vk == VK_RIGHT)
			*pX = srcX+1;
		if(vk == VK_UP)
			*pY = srcY-1;
		if(vk == VK_DOWN)
			*pY = srcY+1;
	}

	BOOL XY_IsInMap(int x,int y)
	{
		if ( x >= 0 && x <= m_ColCount-1 && y >= 0 && y <= m_RowCount-1)
			return TRUE;
		return FALSE;
	}
	int XY_GetType(MapData& Data,int x,int y)
	{
		return Data.Array[y][x];
	}
	VOID XY_SetType(MapData& Data,int x,int y,int type)
	{
		Data.Array[y][x] = type;
	}

	void GetMap(MapData& Data)
	{
		Data = m_MapArrayData[m_DataIndex];
	}
	void SetMap(MapData& Data)
	{
		m_MapArrayData[m_DataIndex] = Data;
	}
	VOID AddMap(MapData Data)
	{
		m_MapArrayData.push_back(Data);
		m_DataIndex = m_MapArrayData.size()-1;
	}

	BOOL Data_IsSuccess()
	{
		MapData Des; 
		GetMap(Des);

		int nSrcCount = 0;
		int nDesCount = 0;
		BOOL bSuc = FALSE;
		for (int i = 0; i < m_RowCount; i++)
		{
			for (int j = 0; j < m_ColCount; j++)
			{
				if ( Des.Mark[i][j] == TYPE_DES)
				{
					nSrcCount++;
					if (Des.Array[i][j] == TYPE_XIANGZI)
						nDesCount++;

					bSuc = TRUE;
				}
			}
		}

		if (nSrcCount == nDesCount &&  bSuc == TRUE)
			return TRUE;

		return FALSE;
	}

	VOID RepareseManXY()
	{
		MapData mpdt;
		GetMap(mpdt);
		Data_GetManXY(m_RowCount,m_ColCount,mpdt,&m_ManX,&m_ManY);
	}

private:
	int m_ManX;
	int m_ManY;
	int m_ColCount;
	int m_RowCount;
	int m_DataIndex;
	std::vector<MapData> m_MapArrayData;
};

//////////////////////////////////////////////////////////////////////////

#define       ID_Window_Body_GameBoard       10 
#define       ID_Window_Left_Btn_NewGame       11 
#define       ID_Window_Left_Btn_SaveGame       12 
#define       ID_Window_Left_btn_PlayGame       19 
#define       ID_Window_Right_BackSpace       20 
#define       ID_Window_Right_Btn_Design       30 
#define       ID_Window_Right_Btn_NextLevel       24 
#define       ID_Window_Right_Btn_PrevLevel       25 
#define       ID_Window_Right_Edit_CurLevel       21 
#define       ID_Window_Right_Edit_MaxLevel       23 
#define       ID_Window_Right_Play       61 
#define       ID_Window_left_Design       60 






class CWindow_Demo
{
public:
    HWINDOW m_hWindow;

	int m_nCheckId;
	int nRowCount;
	int nColCount;
	HELE hBodyEleGameBoard;
	CIni m_Ini;


	HELE m_hEleLeftDesign;
	HELE m_hEleRightPlay;
	
	HELE m_hEditCurLevel;
	HELE m_hEditMaxLevel;

	HIMAGE m_Image[6];
	BOOL bDesignMode;


	HELE m_hBtnNextLevel;


    CWindow_Demo()
    {
		m_nCheckId = 0;
		nRowCount = 10;
		nColCount = 10;
		bDesignMode = FALSE;
        Init();
    }
	int OnBtnSaveClick(BOOL *pbHandled)
	{
		std::string MapInfo;
		int nCount  = XEle_GetChildCount(hBodyEleGameBoard);
		char Buffer[128]={0};
		for (int i = 0; i < nCount; i++)
		{
			HELE hBtn = XEle_GetChildByIndex(hBodyEleGameBoard,i);
			int nID = XEle_GetUserData(hBtn);
			StringCbPrintfA(Buffer,128,"%d",nID);
			MapInfo += Buffer;
		}


		wchar_t bufferText[MAX_PATH] ={0};
		XRichEdit_GetText(m_hEditCurLevel,bufferText,MAX_PATH);

		StringCbPrintfA(Buffer,MAX_PATH,"%d",_wtoi(bufferText));
		m_Ini.SetValue(Buffer,MapInfo);
		m_Ini.Close("Game.txt");

		MapData mptd;
		m_Control.GetMap(mptd);
		FlushButtonToMapData(mptd);
		m_Control.SetMap(mptd);

		m_Control.RepareseManXY();
		return 0;
	}

	int OnBtnBackSpaceClick(BOOL *pbHandled)
	{
		
		return 0;
	}

	int OnBtnNewGameClick(BOOL *pbHandled)
	{
		int nMaxLevelCount = Ini_GetMaxLevelCount();
		nMaxLevelCount+=1;

		std::string strMapData(nRowCount*nColCount,'2');//全部初始化为地板
		Ini_SetLevelString(nMaxLevelCount,strMapData);
		UI_LoadLevel(nMaxLevelCount);
		Init_SetMaxLevelCount(nMaxLevelCount);
		XRichEdit_SetTextInt(m_hEditMaxLevel,nMaxLevelCount);

		return 0;
	}
	int OnBtnDesignClick(BOOL *pbHandled)
	{
		XWnd_SetLayoutSize(m_hWindow,55,40,0,2);
		XWnd_AdjustLayout(m_hWindow);
		XWnd_RedrawWnd(m_hWindow);
		bDesignMode = TRUE;
		return 0;
	}
	int OnBtnPlayGameClick(BOOL *pbHandled)
	{
		//玩游戏，就要隐藏 设计面板	
		XWnd_SetLayoutSize(m_hWindow,0,40,55,2);
		XWnd_AdjustLayout(m_hWindow);
		XWnd_RedrawWnd(m_hWindow);
		bDesignMode = FALSE;
		return 0;
	}

    void Init()
    {
		XC_LoadResource(L"Game\\resource.xml",L"Game");
		m_hWindow = (HWINDOW)XC_LoadLayout(L"Game\\layout.xml");

		m_hEleLeftDesign = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_left_Design);
		m_hEleRightPlay  = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Play);
	
		HXCGUI hEleBtnSave = XC_GetObjectByID(m_hWindow,ID_Window_Left_Btn_SaveGame);		
		XEle_RegEventCPP(hEleBtnSave,XE_BNCLICK,&CWindow_Demo::OnBtnSaveClick);

		HELE hBtnNew = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Left_Btn_NewGame);		
		XEle_RegEventCPP(hBtnNew,XE_BNCLICK,&CWindow_Demo::OnBtnNewGameClick);

		RegCheck(1);
		RegCheck(2);
		RegCheck(3);
		RegCheck(4);
		RegCheck(5);
		RegCheck(6);


		m_hEditCurLevel = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Edit_CurLevel);
		m_hEditMaxLevel = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Edit_MaxLevel);

		HELE hBtnBackSpace = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_BackSpace);
		XEle_RegEventCPP(hBtnBackSpace,XE_BNCLICK,&CWindow_Demo::OnBtnBackSpaceClick);

		HELE hBtnPlay = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Left_btn_PlayGame);
		XEle_RegEventCPP(hBtnPlay,XE_BNCLICK,&CWindow_Demo::OnBtnPlayGameClick);
		
		HELE hBtnDesign = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Btn_Design);
		XEle_RegEventCPP(hBtnDesign,XE_BNCLICK,&CWindow_Demo::OnBtnDesignClick);

		HELE hEditMaxLevel = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Edit_MaxLevel);
		

		hBodyEleGameBoard = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Body_GameBoard);
		XEle_SetRectEx(hBodyEleGameBoard,0,0,33*nRowCount,33*nColCount);

		int x = 0;
		int y = 0;
		for (int i = 0; i < nRowCount; i++)
		{
			for (int j = 0; j < nColCount; j++)
			{
				HELE hBtn = XBtn_Create(x,y,33,33,NULL,hBodyEleGameBoard);
				XEle_EnableDrawFocus(hBtn,FALSE);
				XEle_EnableDrawBorder(hBtn,FALSE);
				XEle_RegEventCPP1(hBtn,XE_BNCLICK,&CWindow_Demo::OnBtnClick);
				x+=33;
			}
			x = 0;
			y += 33;
		}

		if (m_Ini.Open("Game.txt"))
		{
			//说明有游戏存在，直接打开play模式

			int GameCount = Ini_GetMaxLevelCount();
			if (GameCount > 0)
			{
				int nCurLevel = Ini_GetCurrentLevel_Int();
				if (nCurLevel == 0)
					nCurLevel = 1;
			
				UI_LoadLevel(nCurLevel);
			}

			XEle_PostEvent(hBtnPlay,hBtnPlay,XE_BNCLICK,NULL,NULL);
		}
		else
		{
			//说明没有游戏存在，打开设计模式
			XEle_PostEvent(hBtnDesign,hBtnDesign,XE_BNCLICK,NULL,NULL);
			XEle_PostEvent(hBtnNew,hBtnNew,XE_BNCLICK,NULL,NULL);
		}


		int nMaxLevelCount = Ini_GetMaxLevelCount();
		XRichEdit_SetTextInt(m_hEditMaxLevel,nMaxLevelCount);
	

		HELE hBtnPrevLevel = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Btn_PrevLevel);
		XEle_RegEventCPP(hBtnPrevLevel,XE_BNCLICK,&CWindow_Demo::OnBtnPrevLevelClick);

		m_hBtnNextLevel = (HELE)XC_GetObjectByID(m_hWindow,ID_Window_Right_Btn_NextLevel);
		XEle_RegEventCPP(m_hBtnNextLevel,XE_BNCLICK,&CWindow_Demo::OnBtnNextLevelClick);


		XWnd_RegEventCPP(m_hWindow,WM_KEYDOWN,&CWindow_Demo::OnEventKeyDown);
		XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CWindow_Demo::OnWndDestroy);

		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnWndDestroy(BOOL *pbHandled)
	{
		m_Ini.Close("Game.txt");
		return 0;
	}


	int OnBtnNextLevelClick(BOOL *pbHandled)
	{
		int nMaxCount = Ini_GetMaxLevelCount();
		int nCurLevel = Ini_GetCurrentLevel_Int();

		if (nCurLevel +1 > nMaxCount)
			return 0;

		nCurLevel += 1;
		UI_LoadLevel(nCurLevel);
		return 0;
	}
	int OnBtnPrevLevelClick(BOOL *pbHandled)
	{
		int nCurLevel = Ini_GetCurrentLevel_Int();
		if (nCurLevel < 2)
			return 0;
		nCurLevel-=1;
		UI_LoadLevel(nCurLevel);

		return 0;
	}

	VOID UI_LoadLevel(int nLevel)
	{
		std::string strGameInfo = Ini_GetMapInfoString(nLevel);
		MapData mpdt;
		Data_StringToMapData(nRowCount,nColCount,strGameInfo.c_str(),mpdt);
		m_Control.Init(nRowCount,nColCount,mpdt);
		FlushButtomItemImage(mpdt);

		XRichEdit_SetTextInt(m_hEditCurLevel,nLevel);
		Ini_SetCurrentLevel(nLevel);
		XEle_RedrawEle(hBodyEleGameBoard);
	}

	void Ini_SetLevelString(int nLevel,std::string strMapData)
	{
		char buff[MAX_PATH]={0};
		StringCbPrintfA(buff,MAX_PATH,"%d",nLevel);
		m_Ini.SetValue(buff,strMapData);
	}
	std::string Ini_GetMapInfoString(int nLevel)
	{
		char buff[MAX_PATH]={0};
		StringCbPrintfA(buff,MAX_PATH,"%d",nLevel);
 		return m_Ini.GetValue(buff);
	}
	VOID Init_SetMaxLevelCount(int nMaxLevelCount)
	{
		m_Ini.SetValueInt("Count",nMaxLevelCount);
	}
	int Ini_GetMaxLevelCount()
	{
		return m_Ini.GetValueInt("Count");
	}
	std::string Ini_GetCurrentLevel_string()
	{
		return m_Ini.GetValue("Current");
	}
	int Ini_GetCurrentLevel_Int()
	{
		return m_Ini.GetValueInt("Current");
	}
	VOID Ini_SetCurrentLevel(int nCurLevel)
	{
		m_Ini.SetValueInt("Current",nCurLevel);
	}

	VOID FlushButtonToMapData(MapData& mpdt)
	{
		for (int u = 0; u < XEle_GetChildCount(hBodyEleGameBoard); u++)
		{
			
			int r,c;
			c = u % nColCount;
			r = u / nColCount;
			HELE hBtn = XEle_GetChildByIndex(hBodyEleGameBoard,u);
			
			if (XEle_GetUserData(hBtn) == TYPE_DES)
			{
				mpdt.Mark[r][c] = TYPE_DES;
			}else
			{
				mpdt.Array[r][c] = XEle_GetUserData(hBtn);
			}
			
		}
	}

	VOID FlushButtomItemImage(MapData& mpdt)
	{

		for (int u = 0; u < XEle_GetChildCount(hBodyEleGameBoard); u++)
		{
			
			int r,c;
			c = u % nColCount;
			r = u / nColCount;
			
			HELE hBtn = XEle_GetChildByIndex(hBodyEleGameBoard,u);
			
			XEle_SetUserData(hBtn,mpdt.Array[r][c] );
			
			HBKM hBkInfoM = XEle_GetBkManager(hBtn);
			XBkM_Clear(hBkInfoM);
			XBkM_AddImage(hBkInfoM,element_state_flag_enable,m_Image[mpdt.Array[r][c]]);
			
			if (mpdt.Mark[r][c] == TYPE_DES)
			{
				XEle_SetUserData(hBtn,TYPE_DES);
				XBkM_AddImage(hBkInfoM,element_state_flag_enable,m_Image[mpdt.Mark[r][c]]);
			}
		}
	}

	int  OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{

		if (bDesignMode)
			return 0;

		MapData mpdt;
		m_Control.GetMap(mpdt);
		if (!Data_HasManXY(nRowCount,nColCount,mpdt))
			return FALSE;
		

		BOOL bDraw = FALSE;
		switch (wParam)
		{
		case VK_LEFT:
			bDraw = m_Control.OnMove(wParam);
			break;
		case VK_UP:
			bDraw = m_Control.OnMove(wParam);
			break;
		case VK_RIGHT:
			bDraw = m_Control.OnMove(wParam);
			break;
		case VK_DOWN:
			bDraw = m_Control.OnMove(wParam);
			break;
		}

		if (!bDraw)
			return 0;

		m_Control.GetMap(mpdt);
		FlushButtomItemImage(mpdt);
		XEle_RedrawEle(hBodyEleGameBoard);

		if (m_Control.Data_IsSuccess())
		{
			XEle_PostEvent(m_hBtnNextLevel,m_hBtnNextLevel,XE_BNCLICK,NULL,NULL);
//			MessageBoxA(NULL,"楼主，您已经推箱子成功","提示",MB_OK);
		}
		

		
		return 0;
	}
	int OnBtnClick(HELE hEventEle,BOOL *pbHandled)
	{
		if (!bDesignMode)
			return 0;


		BOOL bHasMan = FALSE;
		for (int u = 0; u < XEle_GetChildCount(hBodyEleGameBoard); u++)
		{
			HELE hEle = XEle_GetChildByIndex(hBodyEleGameBoard,u);
			if (XEle_GetUserData(hEle) == TYPE_MAN && m_nCheckId == TYPE_MAN)
			{

				MessageBoxA(NULL,"已经有一个猪脚了，不能再放一个了！","提示",MB_OK);
				bHasMan = TRUE;
				return 0;
			}
			
		}

 		HBKM hBkInfoM = XEle_GetBkManager(hEventEle);
 		XBkM_Clear(hBkInfoM);
 		XBkM_AddImage(hBkInfoM,element_state_flag_enable,m_Image[m_nCheckId]);
 		XEle_SetUserData(hEventEle,m_nCheckId);

		MapData mptd;
		m_Control.GetMap(mptd);
		FlushButtonToMapData(mptd);
//		FlushButtomItemImage(mptd);
//		m_Control.AddMap(mptd);
		m_Control.SetMap(mptd);
		XEle_RedrawEle(hBodyEleGameBoard);
		m_Control.RepareseManXY();

		return 0;
	}
	int OnButtonCheck(HELE hEventEle,BOOL bCheck,BOOL *pbHandled)
	{
		m_nCheckId = XEle_GetUserData(hEventEle);
		return 0;
	}
	VOID RegCheck(int nId)
	{
		wchar_t buffer[MAX_PATH] = {0};
		StringCbPrintfW(buffer,MAX_PATH,L"Game\\%d.png",nId-1);
		m_Image[nId-1] = XImage_LoadFile(buffer);
		XImage_EnableAutoDestroy(m_Image[nId-1],FALSE);

		HXCGUI hBtn = XC_GetObjectByID(m_hWindow,nId);
		XEle_RegEventCPP1(hBtn,XE_BUTTON_CHECK,&CWindow_Demo::OnButtonCheck);
		XEle_SetUserData((HELE)hBtn,nId-1);
	}

private:

	//游戏模式
	GControl m_Control;

};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
	XC_EnableDebugFile(FALSE);
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}






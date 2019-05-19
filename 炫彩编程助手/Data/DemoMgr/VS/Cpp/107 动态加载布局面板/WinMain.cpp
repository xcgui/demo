#include "Common.h"


HELE XC_GetEleByStr(HWINDOW hWindow,const wchar_t* res)
{
	return (HELE) XC_GetObjectByID(hWindow, XRes_GetIDValue(res) );
}

HXCGUI XC_GetLayoutByStr(HWINDOW hWindow,const wchar_t* res)
{
	return XC_GetObjectByID(hWindow, XRes_GetIDValue(res) );
}

class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton1; //按钮句柄
	HELE    m_hButton2; //按钮句柄

	HXCGUI  m_hLayoutObjectBody;

	HELE    m_hEleCurrentBody;

	
    BOOL Create() //创建窗口和按钮
    {
		m_hEleCurrentBody = NULL;

		XC_LoadResource(L"加载布局面板\\resource.xml",L"加载布局面板");
        m_hWindow =(HWINDOW)XC_LoadLayout(L"加载布局面板\\layout.xml");
        if(m_hWindow)
        {

			int nId = XRes_GetIDValue(L"ID_btn1");
			//从模板文件中获取按钮句柄
			m_hButton1 = XC_GetEleByStr(m_hWindow,L"ID_btn1");
			m_hButton2 = XC_GetEleByStr(m_hWindow,L"ID_btn2");

            XEle_RegEventCPP(m_hButton1,XE_BNCLICK,&CMyWnd::OnEventBtn1Click); //注册按钮点击事件
            XEle_RegEventCPP(m_hButton2,XE_BNCLICK,&CMyWnd::OnEventBtn2Click); //注册按钮点击事件

			m_hLayoutObjectBody = XC_GetLayoutByStr(m_hWindow,L"ID_LayoutBody");
			

			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtn1Click(BOOL *pBool) //按钮点击事件响应
    {
		DestoryBodyPane();

		HELE hLayoutPane1 = (HELE)XC_LoadLayout(L"加载布局面板\\面板1.xml",m_hWindow);
		XLayout_AddEle(m_hLayoutObjectBody,hLayoutPane1);
		
		XEle_SetLayoutHeight(hLayoutPane1,layout_size_type_fill,1);
		XEle_SetLayoutWidth(hLayoutPane1,layout_size_type_fill,1);	

		XWnd_AdjustLayout(m_hWindow);
		XWnd_RedrawWnd(m_hWindow);

		m_hEleCurrentBody = hLayoutPane1;
        return 0;    //事件的返回值
    }
	int OnEventBtn2Click(BOOL *pBool) //按钮点击事件响应
    {
		DestoryBodyPane();

		HELE hLayoutPane2 = (HELE)XC_LoadLayout(L"加载布局面板\\面板2.xml",m_hWindow);
		XLayout_AddEle(m_hLayoutObjectBody,hLayoutPane2);

		XEle_SetLayoutHeight(hLayoutPane2,layout_size_type_fill,1);
		XEle_SetLayoutWidth(hLayoutPane2,layout_size_type_fill,1);


		XWnd_AdjustLayout(m_hWindow);
		XWnd_RedrawWnd(m_hWindow);

		m_hEleCurrentBody = hLayoutPane2;
        return 0;    //事件的返回值
    }

	void DestoryBodyPane()
	{
		if (m_hEleCurrentBody)
		{
			XEle_Destroy(m_hEleCurrentBody);
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}





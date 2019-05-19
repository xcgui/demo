using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices;
using XCGUI;


class CWindow
{

    unsafe private int __OnWndMenuSelect(int nID, bool* pbHandled)
    {
        xc.MessageBoxA(0, "炫彩，我是大色", "你好", 0);
        return 0;
    }

    unsafe public void Create()
    {
        xc.XInitXCGUI("");

        int hWindow = xc.XWnd_Create(0, 0, 500, 300, "xcgui", 0, 15);



        xc.XBtn_SetType( xc.XBtn_Create(5, 3, 60, 20, "Close", hWindow),xcConst.button_type_close);

        int m_MenuBar = xc.XMenuBar_Create(20,40,260,28,hWindow);
        xc.XMenuBar_AddButton(m_MenuBar, "文件");
        xc.XMenuBar_AddButton(m_MenuBar, "编辑");
        xc.XMenuBar_AddButton(m_MenuBar, "视图");
        xc.XMenuBar_AddButton(m_MenuBar, "aaa");
        int hMenu=xc.XMenuBar_GetMenu(m_MenuBar,0);
        if(hMenu != 0)
        {
            xc.XMenu_AddItem(hMenu, 101, "101",xcConst.XC_ID_ROOT,0);
            xc.XMenu_AddItem(hMenu, 102, "102", xcConst.XC_ID_ROOT, 0);
            xc.XMenu_AddItem(hMenu, 103, "103", xcConst.XC_ID_ROOT, 0);
            //XMenu_AddItem(hMenu, 0, L"",XC_ID_ROOT,menu_item_flags_separator); //分隔栏
            xc.XMenu_AddItem(hMenu, 1031, "3-1",103,0);
        }
        hMenu=xc.XMenuBar_GetMenu(m_MenuBar,1);
        if(hMenu != 0)
        {
            xc.XMenu_AddItem(hMenu, 201, "201", xcConst.XC_ID_ROOT, 0);
            xc.XMenu_AddItem(hMenu, 202, "202", xcConst.XC_ID_ROOT, 0);
            xc.XMenu_AddItem(hMenu, 203, "203", xcConst.XC_ID_ROOT, 0);

        }
        hMenu=xc.XMenuBar_GetMenu(m_MenuBar,2);
        if( hMenu != 0)
        {
            xc.XMenu_AddItem(hMenu, 301, "301", xcConst.XC_ID_ROOT, 0);
        }

        xc.XEle_RegEventCPP(m_MenuBar, xcConst.XE_MENU_SELECT,new XE_MENU_SELECT_CPP(__OnWndMenuSelect));

        xc.XWnd_ShowWindow(hWindow, 5);

        xc.XRunXCGUI();
        xc.XExitXCGUI();
    }
}

namespace Project1
{
    class RunMain
    {
        static void Main()
        {
            CWindow pWindow = new CWindow();
            pWindow.Create();
        }

    }
}
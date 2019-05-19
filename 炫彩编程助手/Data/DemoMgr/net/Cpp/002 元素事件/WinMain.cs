using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices;
using XCGUI;

class CWindow
{
    unsafe private int OnBtnClick(bool* pbHandled)
    {
        xc.MessageBoxA(0, "炫彩，我是大色", "你好", 0);
        return 0;
    }
    unsafe public void Create()
    {
        xc.XInitXCGUI("");
        int hWindow = xc.XWnd_Create(0, 0, 500, 300, "xcgui", 0, 15);
        int hBtn = xc.XBtn_Create(0, 0, 100, 100, "按钮", hWindow);
        //  Marshal.AllocCoTaskMem(Marshal.SizeOf(pBtnClick))
        xc.XEle_RegEventCPP(hBtn, xcConst.XE_BNCLICK,new XE_BNCLICK_CPP(OnBtnClick));
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
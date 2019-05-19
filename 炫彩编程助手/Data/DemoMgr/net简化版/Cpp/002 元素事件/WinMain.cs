using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices;
using XCGUI;



class CWindow
{
    [DllImport("user32.dll")]
    public static extern int MessageBoxA(int hWnd, string pText, string pTitle, int nType);
    unsafe private int __OnBtnClick(bool* pbHandled)
    {
        MessageBoxA(0, "我是大色", "你好,炫彩", 0);
        return 0;
    }

    unsafe public void Create()
    {
        xc.XInitXCGUI("");
        int hWindow = XWnd.Create(0, 0, 500, 300, "xcgui", 0, xcConst.xc_window_style_default);
        int hBtn = XBtn.Create(0, 0, 100, 100, "按钮", hWindow);
        
        XEle.RegEventC(hBtn, xcConst.XE_BNCLICK, new XE_BNCLICK_C(__OnBtnClick));
        XWnd.ShowWindow(hWindow, 5);
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
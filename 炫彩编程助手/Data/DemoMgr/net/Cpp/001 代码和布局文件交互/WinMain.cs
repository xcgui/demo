using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices;
using XCGUI;


class CWindow
{
    unsafe public void Create()
    {
        xc.XInitXCGUI("");
        int hWindow = xc.XC_LoadLayout("..\\..\\Layout.xml", 0);

        int hBtn = xc.XC_GetObjectByID(hWindow, 10);


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

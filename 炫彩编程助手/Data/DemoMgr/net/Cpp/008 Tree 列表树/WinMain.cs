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
        int hWindow = xc.XWnd_Create(0, 0, 500, 300, "xcgui", 0, 15);

        int hTree = xc.XTree_Create(0,0, 200, 300, hWindow);
        xc.XTree_SetItemTemplateXML(hTree, "..\\..\\Tree_Item.xml");
        
        int hAdapter = xc.XAdTree_Create();
        xc.XTree_BindAdapter(hTree, hAdapter);
        xc.XAdTree_AddColumn(hAdapter, "name");

        int nID = xc.XAdTree_InsertItemText(hAdapter, "1", xcConst.XC_ID_ROOT, xcConst.XC_ID_LAST);
        xc.XAdTree_InsertItemText(hAdapter, "1.1", nID, xcConst.XC_ID_LAST);

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

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
        int hWindow = XWnd.Create(0, 0, 500, 300, "xcgui", 0, 15);

        int hTree = XTree.Create(0,0, 200, 300, hWindow);
        XTree.SetItemTemplateXML(hTree, "..\\..\\Tree_Item.xml");

        int hAdapter = XAdapterTree.Create();
        XTree.BindAdapter(hTree, hAdapter);
        XAdapterTree.AddColumn(hAdapter, "name");

        int nID = XAdapterTree.InsertItemText(hAdapter, "1", xcConst.XC_ID_ROOT, xcConst.XC_ID_LAST);
        XAdapterTree.InsertItemText(hAdapter, "1.1", nID, xcConst.XC_ID_LAST);

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

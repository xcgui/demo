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

        int hList = xc.XList_Create(0, 0, 300, 200, hWindow);
        xc.XList_SetItemTemplateXML(hList, "..\\..\\List_Item.xml");
        xc.XList_AddColumn(hList, 100);
        xc.XList_AddColumn(hList, 100);

        int hHead = xc.XAdMap_Create();
        xc.XList_BindAdapterHeader(hList, hHead);
        xc.XAdMap_AddItemText(hHead, "name", "第一列");
        xc.XAdMap_AddItemText(hHead, "name2", "第二列");


        int body = xc.XAdTable_Create();
        xc.XList_BindAdapter(hList, body);
        xc.XAdTable_AddColumn(body, "name");
        xc.XAdTable_AddColumn(body, "name2");

        int nItem = xc.XAdTable_AddItemText(body, "1.1");
        xc.XAdTable_SetItemText(body, nItem, 1, "1.2");


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

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

        int hList = XList.Create(0, 0, 300, 200, hWindow);
        XList.SetItemTemplateXML(hList, "..\\..\\List_Item.xml");
        XList.AddColumn(hList, 100);
        XList.AddColumn(hList, 100);

        int hHead = XAdapterMap.Create();
        XList.BindAdapterHeader(hList, hHead);
        XAdapterMap.AddItemText(hHead, "name", "第一列");
        XAdapterMap.AddItemText(hHead, "name2", "第二列");


        int body = XAdapterTable.Create();
        XList.BindAdapter(hList, body);
        XAdapterTable.AddColumn(body, "name");
        XAdapterTable.AddColumn(body, "name2");

        int nItem = XAdapterTable.AddItemText(body, "1.1");
        XAdapterTable.SetItemText(body, nItem, 1, "1.2");


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

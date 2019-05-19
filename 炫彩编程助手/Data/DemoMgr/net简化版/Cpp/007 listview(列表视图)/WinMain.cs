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

        int hListView = XListView.Create(0, 0, 400, 200, hWindow);
        XListView.SetItemTemplateXML(hListView, "..\\..\\ListView_Item.xml");

        int hAdapter = XAdapterListView.Create();
        XListView.BindAdapter(hListView, hAdapter);
        XAdapterListView.Group_AddColumn(hAdapter, "name3");

        int nGroup = XAdapterListView.Group_AddItemText(hAdapter, "dasemimi");


        XAdapterListView.Item_AddColumn(hAdapter, "name");
        XAdapterListView.Item_AddColumn(hAdapter, "name2");
        int hImage = XImage.LoadFile("..\\..\\2.png", false);
        int nItem = XAdapterListView.Item_AddItemImage(hAdapter, nGroup, hImage);
        XAdapterListView.Item_SetText(hAdapter, nGroup, nItem, 1, "哇咔咔");

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
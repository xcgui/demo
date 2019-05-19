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

        int hListView = xc.XListView_Create(0, 0, 400, 200, hWindow);
        xc.XListView_SetItemTemplateXML(hListView, "..\\..\\ListView_Item.xml");

        int hAdapter = xc.XAdListView_Create();
        xc.XListView_BindAdapter(hListView, hAdapter);
        xc.XAdListView_Group_AddColumn(hAdapter, "name3");

        int nGroup = xc.XAdListView_Group_AddItemText(hAdapter, "dasemimi");


        xc.XAdListView_Item_AddColumn(hAdapter, "name");
        xc.XAdListView_Item_AddColumn(hAdapter, "name2");
        int hImage = xc.XImage_LoadFile("..\\..\\2.png", false);
        int nItem = xc.XAdListView_Item_AddItemImage(hAdapter, nGroup, hImage);
        xc.XAdListView_Item_SetText(hAdapter, nGroup, nItem, 1, "哇咔咔");

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
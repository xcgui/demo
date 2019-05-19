using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices;
using XCGUI;


class CWindow
{
    int hListBox = 0;

    unsafe private int __OnBtnClick(int hEventEle,bool* pbHandled)
    {
        //获取当前点击的按钮所在列表项索引
        int nId = XListBox.GetItemIndexFromHXCGUI(hListBox,hEventEle);
        //int nId = xc.XEle_GetTemplateListItemID(hEventEle);

        return 0;
    }
    unsafe private int __OnListBoxTemplateCreateEnd(ref listBox_item_i pItem,bool *pbHandled)
    {
        int hBtn = XListBox.GetTemplateObject(hListBox,pItem.index,2);

        if (xc.IsHXCGUI(hBtn, xcConst.XC_BUTTON))
        {

            XEle.RegEventCPP1(hBtn, xcConst.XE_BNCLICK, new XE_BNCLICK_CPP1(__OnBtnClick));
        }


        return 0;
    }

    unsafe public void Create()
    {
        xc.XInitXCGUI("");
        int hWindow = XWnd.Create(0, 0, 500, 400, "xcgui", 0, 15);

        hListBox = XListBox.Create(0, 0, 300, 300, hWindow);
        XListBox.SetItemTemplateXML(hListBox, "..\\..\\ListBox_Item.xml");

        int hAdapter = XAdapterTable.Create();
        XListBox.BindAdapter(hListBox, hAdapter);
        XAdapterTable.AddColumn(hAdapter, "name");
        XAdapterTable.AddColumn(hAdapter, "name1");


        int nItem = XAdapterTable.AddItemText(hAdapter, "dasemimi");
        XAdapterTable.SetItemText(hAdapter, nItem, 1, "xiaosemimi");

        nItem = XAdapterTable.AddItemText(hAdapter, "dasemimi1");
        XAdapterTable.SetItemText(hAdapter, nItem, 1, "xiaosemimi1");

        XEle.RegEventCPP(hListBox, xcConst.XE_LISTBOX_TEMP_CREATE_END, new XE_LISTBOX_TEMP_CREATE_END_CPP(__OnListBoxTemplateCreateEnd));


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

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
        int nId = xc.XListBox_GetItemIndexFromHXCGUI(hListBox,hEventEle);
        //int nId = xc.XEle_GetTemplateListItemID(hEventEle);

        return 0;
    }
    unsafe private int __OnListBoxTemplateCreateEnd(ref listBox_item_i pItem,bool *pbHandled)
    {
        int hBtn = xc.XListBox_GetTemplateObject(hListBox,pItem.index,2);

        if (xc.XC_IsHXCGUI(hBtn, xcConst.XC_BUTTON))
        {

            xc.XEle_RegEventCPP1(hBtn, xcConst.XE_BNCLICK, new XE_BNCLICK_CPP1(__OnBtnClick));
        }


        return 0;
    }

    unsafe public void Create()
    {
        xc.XInitXCGUI("");
        int hWindow = xc.XWnd_Create(0, 0, 500, 400, "xcgui", 0, 15);

        hListBox = xc.XListBox_Create(0, 0, 300, 300, hWindow);
        xc.XListBox_SetItemTemplateXML(hListBox, "..\\..\\ListBox_Item.xml");

        int hAdapter = xc.XAdTable_Create();
        xc.XListBox_BindAdapter(hListBox, hAdapter);
        xc.XAdTable_AddColumn(hAdapter, "name");
        xc.XAdTable_AddColumn(hAdapter, "name1");


        int nItem = xc.XAdTable_AddItemText(hAdapter, "dasemimi");
        xc.XAdTable_SetItemText(hAdapter, nItem, 1, "xiaosemimi");

        nItem = xc.XAdTable_AddItemText(hAdapter, "dasemimi1");
        xc.XAdTable_SetItemText(hAdapter, nItem, 1, "xiaosemimi1");

        xc.XEle_RegEventCPP(hListBox, xcConst.XE_LISTBOX_TEMP_CREATE_END, new XE_LISTBOX_TEMP_CREATE_END_CPP(__OnListBoxTemplateCreateEnd));


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

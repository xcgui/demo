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

        int hComboBox = xc.XComboBox_Create(0, 0, 300, 20, hWindow);
        xc.XComboBox_SetItemTemplateXML(hComboBox, "..//..//ComboBox_ListBox_Item.xml");
      
        int hAdapterTable = xc.XAdTable_Create();
        xc.XComboBox_BindApapter(hComboBox,hAdapterTable);
        xc.XAdTable_AddColumn(hAdapterTable, "name");

        int nItem = xc.XAdTable_AddItemText(hAdapterTable, "1.1");

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

program WinMain;

{$APPTYPE GUI}

uses
  Windows,SysUtils,
  XCGUI in 'XCGUI.pas';


var
  hWindow : Integer ;
  hList : Integer ;
  hAdapterHeader : Integer;
  hAdapterBody   : Integer;
begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源
  hWindow := XWnd_Create(0,0,500,300,'大色秘密',0,15);  //创建窗口

  hList := XList_Create(0,0,500,300,hWindow);
  XList_SetItemTemplateXML(hList,'List_Item.xml');
  XList_AddColumn(hList,150);

  hAdapterHeader := XAdMap_Create();
  XList_BindAdapterHeader(hList,hAdapterHeader);
  XAdMap_AddItemText(hAdapterHeader,'name','aaaa');

  hAdapterBody := XAdTable_Create();
  XList_BindAdapter(hList,hAdapterBody);
  XAdTable_AddColumn(hAdapterBody,'name');
  XList_SetColumnWidth(hList,0,150);


  //XAdTable_InsertItemText()
  XAdTable_AddItemText(hAdapterBody,'dasemimi');


  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.





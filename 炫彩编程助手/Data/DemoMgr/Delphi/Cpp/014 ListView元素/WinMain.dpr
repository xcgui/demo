program WinMain;

{$APPTYPE GUI}

uses
  Windows,SysUtils,
  XCGUI in 'XCGUI.pas';


var
  hWindow : Integer ;
  hListView : Integer ;
  hAdpterListView : Integer;
  nGroup: Integer;
  nItem : Integer;
  hImage: Integer;

function OnBtnClick(pbHandle : PBoolean):Integer ;stdcall;
begin
  MessageBoxA(0,'dasemimi','good',MB_OK);
  Result := 0;
end;


function OnListViewTemplateCreateEnd(
          pItem:TlistView_item_i;
          pbHandle:PBoolean
          ):Integer ;stdcall;
var
  hEle : Integer;
begin

  hEle := XListView_GetTemplateObjectGroup(hListView,pItem.iGroup,1);
  if XC_IsHXCGUI(hEle,XC_BUTTON) then
    XEle_RegEventC(hEle,XE_BNCLICK,Integer(@OnBtnClick));

end;


begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源
  hWindow := XWnd_Create(0,0,500,300,'大色秘密',0,15);  //创建窗口

  hListView := XListView_Create(0,0,500,300,hWindow);
  XListView_SetItemTemplateXML(hListView,'ListView_Item.xml');
  hAdpterListView := XAdListView_Create();
  XListView_BindAdapter(hListView,hAdpterListView);

  //XAdListView_Group_AddColumn(hAdpterListView,'name4');
  XAdListView_Group_AddColumn(hAdpterListView,'name3');
  XAdListView_Item_AddColumn(hAdpterListView,'name');
  XAdListView_Item_AddColumn(hAdpterListView,'name2');




  nGroup := XAdListView_Group_AddItemText(hAdpterListView,'分组1');

  hImage := XImage_LoadFile('avatar_large.png',True);
  // nItem  := XAdListView_Item_AddItemImage(hAdpterListView,nGroup,hImage);
  nItem  := XAdListView_Item_AddItemImageEx(hAdpterListView,nGroup,'name',hImage);
  XAdListView_Item_SetText(hAdpterListView,nGroup,nItem,1,'ddddd');


  nGroup := XAdListView_Group_AddItemText(hAdpterListView,'分组2');
  nItem  := XAdListView_Item_AddItemImageEx(hAdpterListView,nGroup,'name',hImage);
  XAdListView_Item_SetText(hAdpterListView,nGroup,nItem,1,'aaaaa');

 // XEle_RegEventC(hListView,XE_LISTVIEW_TEMP_CREATE_END,Integer(@OnListViewTemplateCreateEnd));


  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.






program WinMain;

{$APPTYPE GUI}

uses
  Windows,
  XCGUI in 'XCGUI.pas';

var
hWindow:Integer ;
hBtn:Integer ;
hImageWnd:Integer ;
hBkInfoM:Integer;
begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源
  hWindow := XWnd_Create(0,0,500,300,'大色秘密',0,xc_window_style_default);  //创建窗口
  hBtn := XBtn_Create(0,0,50,50,'关闭',hWindow);
  XBtn_SetType(hBtn,button_type_close);
  hImageWnd := XImage_LoadFileAdaptive('j.JPG',18,21,72,65);
  //布局分整体布局 | 上 下 左 右 中 都在常量 window_state_开头的类型里面
  hBkInfoM := XWnd_GetBkInfoManager(hWindow);
  XBkInfoM_AddImage(hBkInfoM,window_state_body_leave,hImageWnd);


  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.

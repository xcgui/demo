program WinMain;

{$APPTYPE GUI}

uses
  Windows,
  XCGUI in 'XCGUI.pas';

var
hWindow:Integer ;
hBtn:Integer ;
//rt:RECT;
//pRt:TRECT;

function OnClick(pbHandle : PBoolean):Integer;stdcall ;
begin
  MessageBox(0,'炫彩','你好大色',MB_OK);
   Result := 0;
end;

begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源
  hWindow := XWnd_Create(0,0,500,300,'大色秘密',0,xc_window_style_default);  //创建窗口

  hBtn := XBtn_Create(0,0,50,50,'按钮',hWindow);
  //为按钮设置图标
  XBtn_SetIcon(hBtn,XImage_LoadFile('Zhong.png',False));
  //设置按钮图标在上面
  XBtn_SetIconAlign(hBtn,button_icon_align_top);


  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.

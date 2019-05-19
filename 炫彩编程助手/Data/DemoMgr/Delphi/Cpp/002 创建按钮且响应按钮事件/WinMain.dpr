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

  hBtn := XBtn_Create(0,0,50,50,'我是按钮',hWindow);
  XEle_RegEventC(hBtn,34,Integer(@OnClick) );

  
  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.

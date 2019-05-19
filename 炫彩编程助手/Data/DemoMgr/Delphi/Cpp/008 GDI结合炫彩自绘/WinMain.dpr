program WinMain;

{$APPTYPE GUI}

uses
  Windows,
  XCGUI in 'XCGUI.pas';

function OnPaint(hDraw:Integer ; pbHandled:PBoolean): Integer ;stdcall  ;
var
  pt :POINT;
  dc : Integer;
begin

  dc := XDraw_GetHDC(hDraw);
  SetTextColor(dc,255);
  TextOut(dc,0,0,'dasemimi',8);

  pbHandled^ := True;
  Result := 0;
end;

var
  hWindow:Integer ;
  hEle:Integer;
begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源
  hWindow := XWnd_Create(0,0,500,300,'大色秘密',0,15);  //创建窗口

  hEle := XEle_Create(0,0,100,100,hWindow);
  XEle_RegEventC(hEle,XE_PAINT,Integer(@OnPaint));

  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.

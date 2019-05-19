program WinMain;

{$APPTYPE GUI}

uses
  Windows,
  XCGUI in 'XCGUI.pas';

function OnPaint(hDraw:Integer ; pbHandled:PBoolean): Integer ;stdcall  ;
var
  pt :POINT;
begin

  XDraw_MoveToEx(hDraw, 0,0,@pt );
  XDraw_LineTo(hDraw ,100,100);

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

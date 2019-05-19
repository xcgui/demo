program WinMain;

{$APPTYPE GUI}

uses
  Windows,
  XCGUI in 'XCGUI.pas';


var
  hWindow:Integer ;
begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源

  XC_LoadResource('QQTest\\resource.xml','QQTest');
  hWindow := XC_LoadLayout('QQTest\\Layout.xml',0);

  XWnd_AdjustLayout(hWindow);
  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.

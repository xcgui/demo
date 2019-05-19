program WinMain;

{$APPTYPE GUI}

uses
  Windows,SysUtils,
  XCGUI in 'XCGUI.pas';


var
  hWindow : Integer ;
  hEle : Integer ;
  hImageList: array[0..9] of  Integer;
  i : Integer ;
  buff : WideString;

function OnPaint(hDraw:Integer ; pbHandled:PBoolean): Integer ;stdcall  ;
begin

   if i <> -1 then
    XDraw_Image(hDraw, hImagelist[i],0,0);
  pbHandled^ := True;
  Result := 0;
end;



function OnPaintEnd(hDraw:Integer ; pbHandled:PBoolean): Integer ;stdcall  ;
var
  pt :POINT;
  dc : Integer;
begin

  if i <> -1 then
    XDraw_Image(hDraw, hImagelist[i],0,0);

  pbHandled^ := True;
  Result := 0;
end;

procedure OnTimer(hWnd,nMsg,idEvent,dwTime: Integer );stdcall  ;
begin
   inc(i);
   if i > 8 then
      i := 0;
   FillChar(buff,SizeOf(buff),0);
   WideFmtStr(buff,'floatpanel.acc.%d.png',[i]);
   hImageList[i] := XImage_LoadFile(PWideChar(buff),False);
   XEle_RedrawEle(hEle,False);

end;

begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //初始化资源
  hWindow := XWnd_Create(0,0,500,300,'大色秘密',0,15);  //创建窗口

  hEle := XEle_Create(0,0,100,100,hWindow);
  XEle_EnableBkTransparent(hEle,True );
  //XEle_EnableEvent_XE_PAINT_END(hEle ,True );
  XEle_RegEventC(hEle,XE_PAINT,Integer(@OnPaint));
  //XEle_RegEventC(hEle,XE_PAINT_END,Integer(@OnPaintEnd));

  i := -1;
  SetTimer(0,0,800,@OnTimer);


  XWnd_AdjustLayout(hWindow);
  XWnd_ShowWindow(hWindow,5);      //显示窗口
  XRunXCGUI();                     //运行程序
  XExitXCGUI();                    //销毁资源
end.




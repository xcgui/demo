unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes,Graphics,
  Controls, Forms, Dialogs, ExtCtrls, StdCtrls;

type
  TForm1 = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    Memo1: TMemo;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    FXCHandle:Integer;


    procedure DoCreateXcForm;
 //   class  procedure BtnCloseOnClick;
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  bok : LongBool;
implementation
  uses XCGUI;
{$R *.dfm}



procedure TForm1.FormCreate(Sender: TObject);
begin
  DoCreateXcForm;
end;


procedure BtnCloseOnClick;
begin
  Form1.close;
end;

procedure TForm1.DoCreateXcForm;
begin
 // FXCHandle := XWnd_Create(0,0,600,480,'Hello world',0, xc_window_style_default);
  bok := XC_LoadResource('.\res\resource.xml', '.\res');
  FXCHandle:= XC_LoadLayout('.\res\Layout.xml', 0);
  XWnd_AdjustLayout(FXCHandle);
  XEle_RegEventC(XC_GetObjectByID(FXCHandle,1001),34,Integer(Addr(BtnCloseOnClick)) );
  WindowS.SetParent(XWnd_GetHWND(FXCHandle ),Panel1.handle);
  MoveWindow(XWnd_GetHWND(FXCHandle ),-2,-1,604,52,true );
  XWnd_ShowWindow(FXCHandle,SW_SHOWNORMAL );
end;






end.

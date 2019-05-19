unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, XCGUI;

type
  TForm2 = class(TForm)
    procedure FormCreate(Sender: TObject);
    procedure FormResize(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  hWindow: Integer;
  hBtnClose: Integer;

implementation

{$R *.dfm}

function OnBtnCloseClick(pbhandle:PBoolean):Integer;stdcall ;
begin
    MessageBox(0,'关闭按钮被点击','提示',MB_OK);
    PostMessage(Form2.Handle,WM_CLOSE,0,0);
end;


procedure TForm2.FormCreate(Sender: TObject);
  var
    ClientRc : TRECT;
begin
       hWindow := XWnd_CreateEx(0,'','炫彩作为子窗口',WS_CHILD,0,0,500,300,form2.Handle,xc_window_style_default);
       hBtnClose := XBtn_Create(0,0,100,20,'关闭按钮',hWindow);
       XEle_RegEventC(hBtnClose,XE_BNCLICK,Integer(@OnBtnCloseClick));
       XWnd_ShowWindow(hWindow,SW_SHOW);
end;


procedure TForm2.FormResize(Sender: TObject);
begin
  MoveWindow(XWnd_GetHWND(hWindow),0,0,ClientWidth,ClientHeight,False);
end;

end.

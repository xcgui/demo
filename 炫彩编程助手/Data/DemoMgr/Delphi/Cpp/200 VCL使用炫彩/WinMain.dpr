program WinMain;

uses
  Forms, Xcgui,
  Unit1 in 'Unit1.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  XInitXCGUI('');
//  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);

  

  Application.Run;
  //XRunXCGUI;
 // XExitXCGUI;

end.

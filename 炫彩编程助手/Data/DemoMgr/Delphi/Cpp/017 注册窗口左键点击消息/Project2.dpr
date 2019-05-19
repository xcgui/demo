program Project2;

{$APPTYPE GUI}

uses
  SysUtils,
  Forms,
  Xcgui,
  Unit2 in 'Unit2.pas' {Form2};

begin
  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI('');
  Application.Initialize;
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.

program prjPrduto;

uses
  Forms,
  uProduto in 'uProduto.pas' {fProduto};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfProduto, fProduto);
  Application.Run;
end.

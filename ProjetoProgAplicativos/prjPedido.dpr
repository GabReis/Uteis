program prjPedido;

uses
  Forms,
  uPedido in 'uPedido.pas' {fProduto};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfProduto, fProduto);
  Application.Run;
end.

unit uPedido;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, DBCtrls;

type
  TfProduto = class(TForm)
    edNome: TEdit;
    edDescricao: TEdit;
    edTipo: TEdit;
    edDataCadastro: TEdit;
    edSituacao: TEdit;
    edAlqIPI: TEdit;
    edPrecoCompra: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    edMargemLucro: TEdit;
    edPrecoVenda: TEdit;
    Label9: TLabel;
    Label10: TLabel;
    edUnidade: TEdit;
    btSalvar: TButton;
    DBImgFoto: TDBImage;
    btInserir: TButton;
    btEditar: TButton;
    btDeletar: TButton;
    btCancelar: TButton;
    procedure btSalvarClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  fProduto: TfProduto;

implementation

{$R *.dfm}

procedure TfProduto.btSalvarClick(Sender: TObject);
begin
if( (edTipo.Text <> 'Embalagens') And (edTipo.Text <> 'Informática') And (edTipo.Text <> 'Material Escritório') And (edTipo.Text <> 'Móveis') ) then
                  ShowMessage('No campo tipo, digite exatamente: Embalagens, Informática, Material Escritório ou Móveis');
if( (edSituacao.Text <> 'Ativo') And (edSituacao.Text <> 'Inativo') )then
                  ShowMessage('No campo situacao, digite exatamente: Ativou ou Inativo');
end;

procedure TfProduto.FormCreate(Sender: TObject);
begin
btSalvar.Visible:=false;
btCancelar.Visible:=false;
end;

end.

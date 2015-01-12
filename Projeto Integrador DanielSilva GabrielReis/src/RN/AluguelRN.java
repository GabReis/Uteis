/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.*;
import Pers.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;




/**
 *
 * @author Silva
 */
public class AluguelRN {

    public Aluguel buscarUmAluguelSemDataDevolucao(Veiculo veiculo) {
        if (veiculo==null)
            return null;
        
            
        List aluguelList = new ArrayList();
        AluguelPERS aluguelPERS = new AluguelPERS();
        aluguelList = aluguelPERS.buscarUmAluguelSemDataDevolucao(veiculo.getCodveiculo());//passa somente o Id do veiculo pra persistência
        
        if (aluguelList == null)
            return null;
        if (aluguelList.isEmpty())//alguel nao encontrado
           return null;
        
        
        return (Aluguel)aluguelList.get(0); //retorna o aluguel relacionado ao veiculo recebido e que nao possui data de devolução
    }

    public String atualizarDataDevolucao(Date dataDevolucao, Aluguel aluguel) {
        String mensagem = "atualizou";//se atualizou com sucesso, 
        if (aluguel == null)
            return "Erro ao atualizar Data de Devolucao, aluguel == null";
        //tratar data aqui
        
        aluguel.setDatadevolucao(dataDevolucao);
        AluguelPERS aluguelPERS = new AluguelPERS();
        mensagem = aluguelPERS.atualizarAluguel(aluguel);
        return mensagem;
    }
    public String calcularAluguel(Aluguel aluguel, float kmAntiga){//kmAntida ja validada
        if (aluguel == null)
            return "Erro: Aluguel Null";
        if (aluguel.getCodaluguel() < 0)
            return "Id Aluguel Invalido";
       
       float valorTotalTaxa=0, valorTotalManutencao=0;
       float kilometragem=0 , valorPorKm=0, percentualDescontoKm100=0;
       float valorTaxaPorDia=0, percentualDescontoNaTaxaAluguel=0;
       int qtdeDiasAluguel=0;
       String seguro="";   
       AluguelPERS aluguelPERS = new AluguelPERS();
       ResultSet valores = aluguelPERS.calcularAluguel(aluguel.getCodaluguel());
              
       if(valores == null)
           return "ResultSet Null\n Dados não encontrados ou Erro ao acessar o banco\n ";
        try {
            if (valores.next()){
                    valorTotalTaxa = valores.getFloat("VALORTOTALTAXA");
                    valorTotalManutencao = valores.getFloat("VALORTOTALMANUTENCAO");
                    kilometragem = valores.getFloat("KILOMETRAGEM");
                    valorPorKm = valores.getFloat("VALORPORKM");
                    percentualDescontoKm100 = valores.getFloat("PERCENTUALDESCONTOKM100");
                    valorTaxaPorDia = valores.getFloat("VALORTAXAPORDIA");
                    percentualDescontoNaTaxaAluguel = valores.getFloat("PERCENTUALDESCONTONATAXAALUGUEL");
                    qtdeDiasAluguel = valores.getInt("QTDEDIASALUGUEL");
                    seguro = valores.getString("SEGURO");
            }
        } catch (SQLException ex) {
            return "Erro ao extrair dados para o cálculo: "+ex.getMessage();
        }
        float resultado=0;
        float kmRodado = kilometragem - kmAntiga; //onde kilometragem é a atual
        
        if(seguro != null){
             if (seguro.equals("SEGURO"))//se tiver seguro nao paga manutencao
                valorTotalManutencao = 0;
        }
        resultado = valorTotalTaxa+(qtdeDiasAluguel*valorTaxaPorDia) + (valorPorKm*kmRodado) + valorTotalManutencao;
        
        if (kmRodado <= 100)//promocao se foi rodado até 100 entao há um desconto na taxa de aluguel
            resultado = resultado - (resultado*percentualDescontoKm100); 
        
        
        resultado = resultado - (resultado*percentualDescontoNaTaxaAluguel);//caso haja desconto na taxa do aluguel será descontado
        
        
      return Float.toString(resultado);  
    }

    public String darBaixa(Aluguel aluguel) {
       if (aluguel == null)
            return "Erro aluguel == null";
       if (aluguel.getFormapagamento() == null || aluguel.getFormapagamento().equals(""))
           return "Insira corretamente a forma de pagamento";
       AluguelPERS aluguelPERS = new AluguelPERS();
       String mensagem = aluguelPERS.atualizarAluguel(aluguel);
       return mensagem;
    }

    public String cadastrarAluguel(Aluguel aluguel) {
       String mensagem = null;
       if (aluguel == null)
           return "Erro aluguel igual a NULL";
       
       
       
       AluguelPERS aluguelPERS = new AluguelPERS();
       
       mensagem= aluguelPERS.cadastrarAluguel(aluguel);
       
       return mensagem;
    }
   
    
}

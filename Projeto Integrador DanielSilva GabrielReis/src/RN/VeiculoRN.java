/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.*;
import Pers.*;
import java.math.BigDecimal;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Silva
 */
public class VeiculoRN {

    public VeiculoRN() {
    }
    
    public Veiculo buscarVeiculo(String placa) {
        if (placa.equals("")){//nao foi informado a placa
            return null;
        }
        
        List objeto = new ArrayList();
        placa = placa.toUpperCase();//deixa maúscula a placa
        
        VeiculoPERS veiculoPERS = new VeiculoPERS();
        objeto = veiculoPERS.buscarVeiculo(placa);
        if (objeto.isEmpty()){
            return null;
        }
        Veiculo veiculo = (Veiculo)objeto.get(0);//pega o único veiculo retonado pelo ArrayList
        
        return veiculo;
    }

    public String atualizarVeiculo(Veiculo veiculo) {
        String mensagem="";
        if (veiculo == null)
            return "Erro: Veiculo é NULL";
        if (veiculo.getChassi().equals("") || veiculo.getCombustivel().equals("") || veiculo.getPlaca().equals("") || veiculo.getCor().equals(""))
            return "Erro: preencha correntamente os campos";
        VeiculoPERS veiculoPERS = new VeiculoPERS();
        
        mensagem = veiculoPERS.atualizarVeiculo(veiculo);
        return mensagem;
    }
    

    public String atualizarVeiculo(Veiculo veiculo, String kilometragem) {
       String mensagem="atualizou";
       if (veiculo == null)
           return "Erro RN Veiculo null";
       if (kilometragem == null || kilometragem.equals(""))
           return "Erro na kilometragem Atual";
        
      BigDecimal kmAtual = new BigDecimal(kilometragem);
       
       if (kmAtual.compareTo(veiculo.getKilometragem()) >=0 ){//kilometragem >= veiculo.getKilometragem
           veiculo.setKilometragem(kmAtual);//veiculo recebe a nova kilometragem

           VeiculoPERS veiculoPERS = new VeiculoPERS();
           mensagem = veiculoPERS.atualizarVeiculo(veiculo);
           return mensagem;
       }else
           return "Erro: Kilometragem menor do que a atual";
       
    }

    public String cadastrarVeiculo(Veiculo veiculo) {
        String mensagem =null;
        if (veiculo==null)
            return "O veiculo nao foi cadastrado" ;
        
        veiculo.setStatus("DISPONIVEL");
        veiculo.setVenda(null);
        
        if (veiculo.getAno() == 0 || veiculo.getChassi().equals("") || veiculo.getCombustivel().equals("")|| 
            veiculo.getCor().equals("")|| veiculo.getModelo().equals("") || veiculo.getPlaca().equals(""))
            return "Erro nos dados do veiculo";
        if (veiculo.getKilometragem() == null)
            return "Erro km";
        
        if (veiculo.getTipoveiculo() == null)
           return "TIPO VEICULO NULL";
        if (veiculo.getCompra() == null)
            return "COMPRA NULL";
        
        
        
        VeiculoPERS veiculoPers = new VeiculoPERS();
        mensagem = veiculoPers.cadastrarVeiculo(veiculo);
        return mensagem;
    }
   
}

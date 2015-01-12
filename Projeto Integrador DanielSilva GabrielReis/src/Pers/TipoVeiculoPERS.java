/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.*;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.*;

/**
 *
 * @author Silva
 */
public class TipoVeiculoPERS {

    public List buscarTipoVeiculo(String tipo) {
        
        List tipoVeiculoList = new ArrayList();
        Conexao conexao;
        
        try {
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("buscarTipoVeiculoPorTipo");// "bucarVeiculoPelaPlaca" é o nome da HQL a ser executado no .hbm.xml do veículo
            selecao.setString("tipoRecebido",tipo);
            tipoVeiculoList = selecao.list();
            conexao.fecharSessao();
        } catch (Exception ex) {
            return null;
        }
        return tipoVeiculoList;
    }
    
    public String cadastrarTipoVeiculo(Tipoveiculo tipoVeiculo){
        String mensagem;
        Transaction transaction = null;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.save(tipoVeiculo);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Tipo de veículo cadastrado com sucesso";
        }catch(Exception e){
            transaction.rollback();
            return "Erro! "+e.getMessage();
        }
        return mensagem;
    }
    
}

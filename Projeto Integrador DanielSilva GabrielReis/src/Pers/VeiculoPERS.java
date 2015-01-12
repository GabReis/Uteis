/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import org.hibernate.*;
import PacotePrincipal.*;
import PacotePrincipal.*;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author Silva
 */
public class VeiculoPERS {

    public VeiculoPERS() {
    }
    
    public List buscarVeiculo(String placa) {
        List objeto = new ArrayList();
        Conexao conexao=null;
        
        try {
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("buscarVeiculoPelaPlaca");// "bucarVeiculoPelaPlaca" é o nome da HQL a ser executado no .hbm.xml do veículo
            selecao.setString("placaRecebida",placa);
            objeto = selecao.list();
            conexao.fecharSessao();
        } catch (Exception ex) {
            try{
                conexao.fecharSessao();
            }catch(Exception e){
                return null;
            }
            return null;
        }
        return objeto;
    }

    public String atualizarVeiculo(Veiculo veiculo) {
        String mensagem="atualizou";
        Conexao conexao = null;
        Transaction transaction = null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(veiculo);
            
            transaction.commit();
            session.flush();
            conexao.fecharSessao();
           
        }catch(Exception e){
            try{
                transaction.rollback();
                conexao.fecharSessao();
            }catch(Exception ex){
                return "Erro no acesso ao banco";
            }
            return "Erro na persistencia: "+e.getMessage();
        }
        return mensagem;
        
    }

    public String cadastrarVeiculo(Veiculo veiculo) {
        
        Conexao conexao=null;
        Transaction transaction=null;
        try {
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction= conexao.criarTransacao();
            session.save(veiculo);
            transaction.commit();
            conexao.fecharSessao();
        } catch (Exception ex) {
            try{
                transaction.rollback();
                conexao.fecharSessao();
            }catch(Exception e){
                return "Erro no acesso ao banco: "+e.getMessage();
            }
            return "Errr: "+ex.getMessage();
        }
        return "OK";
    }
    
    
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import org.hibernate.*;
import PacotePrincipal.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
/**
 *
 * @author cliente
 */
public class PromocaoPERS {

    public PromocaoPERS() {
    }
    
   String mensagem;
        
    public String cadastrarPromocao(Promocao promocao) {
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            Transaction transaction = conexao.criarTransacao();
            session.save(promocao);
            transaction.commit();
            session.flush();
            session.close();
            mensagem = "Cadastrado com sucesso";
        }catch(Exception e){
            mensagem = "Erro "+e.getMessage();
            
        }
        return mensagem;
    }
    
    
    public List buscarPromocao(Date data){
        List listPromocao = new ArrayList();
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaPromocaoPorData");
            selecao.setDate("dataRecebida", data);
            listPromocao = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            return null;
            
        }
        return listPromocao;
    }
    public String atualizarPromocao(Promocao promocao) {
        Transaction transaction = null;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(promocao);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Promomoção atualizada com sucesso";
        }catch(Exception e){
            transaction.rollback();
            mensagem = "Erro "+e.getMessage();
            
        }
        return mensagem;
    }
    
}

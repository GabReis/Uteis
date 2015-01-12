/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.*;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author cliente
 */
public class EnderecoPers {

    public String cadastrarEndereco(Endereco endereco) {
        String mensagem;
        Conexao conexao=null;
         Transaction transaction=null;
        try{
            conexao= new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.save(endereco);
            transaction.commit();
            session.flush();
            session.close();
            mensagem = "CADASTROU";
        }catch(Exception e){
            transaction.rollback();
            conexao.fecharSessao();
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }
    public List buscarEndereco(String cidade, String rua){
        List listEndereco = new ArrayList();
        Conexao conexao=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaEnderecoPorCidadeRua");
            selecao.setString("cidadeRecebida", cidade).setString("ruaRecebida", rua);
            listEndereco = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            conexao.fecharSessao();
            return null;
            
        }
        return listEndereco;
    }
    public String atualizarEndereco(Endereco endereco) {
        String mensagem;
        Transaction transaction = null;
        Conexao conexao=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(endereco);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Endereço atualizado com sucesso";
        }catch(Exception e){
            transaction.rollback();
            conexao.fecharSessao();
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }
}

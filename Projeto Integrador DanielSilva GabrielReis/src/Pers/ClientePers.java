/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.Cliente;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author cliente
 */
public class ClientePers {

    public String cadastrarCliente(Cliente cliente) {
        String mensagem;
        Conexao conexao=null;
        Transaction transaction=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.save(cliente);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Cliente cadastrado com sucesso";
        }catch(Exception e){
            try{
                transaction.rollback();
                conexao.fecharSessao();
            }catch(Exception ex){
                return "Erro: "+ex.getMessage();
            }
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }
     public List buscarCliente(String cpfOuCnpj){
        List listCliente = new ArrayList();
        Conexao conexao=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaClientePorDocumento");
            selecao.setString("documentoRecebido", cpfOuCnpj);
            listCliente = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            conexao.fecharSessao();
            return null;
        }
        return listCliente;
    }
     public String atualizarCliente(Cliente cliente){
        String mensagem;
        Transaction transaction =null;
        Conexao conexao= null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(cliente);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Cliente atualizado com sucesso";
        }catch(Exception e){
            try{
                transaction.rollback();
                conexao.fecharSessao();
            }catch(Exception er){
                   mensagem = "Erro "+er.getMessage();
            }
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }

    public List buscarEmailCliente(int codaluguel) {
        List listCliente = new ArrayList();
        Conexao conexao = null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaEmailCliente");
            selecao.setInteger("codAluguelRecebido", codaluguel);
            listCliente = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            try{
                conexao.fecharSessao();
            }catch(Exception er){
                   return null;
            }
            return null;
            
        }
        return listCliente;
    }

    
}

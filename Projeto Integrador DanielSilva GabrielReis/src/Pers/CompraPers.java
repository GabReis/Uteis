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
public class CompraPers {
    public String cadastrarCompra(Compra compra){
        String mensagem;
        Transaction transaction = null;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.save(compra);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "OK";
        }catch(Exception e){
            transaction.rollback();
            mensagem = "Erro! "+e.getMessage();
        }
        return mensagem;
    }
    public List buscarCompra(int codCompra){
        List listCompra = new ArrayList();
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaCompraPorCodCompra");
            selecao.setInteger("codCompraRecebido", codCompra);
            listCompra = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            return null;
        }
        return listCompra;
    }
    public String atualizarCompra(Compra compra){
        String mensagem;
        Transaction transaction = null;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(compra);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Compra alterada com sucesso";
        }catch(Exception e){
            transaction.rollback();
            mensagem = "Erro! "+e.getMessage();
        }
        return mensagem;
    }
}
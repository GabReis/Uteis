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
 * @author a1257072
 */
public class FornecedorPers {
    public String cadastrarFornecedor(Fornecedor fornecedor) {
        String mensagem;
        Conexao conexao=null;
        Transaction transaction=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.save(fornecedor);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "SALVOU";
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
     

    public List buscarFornecedor(String documento) {
      
        List listFornecedor = new ArrayList();
        Conexao conexao=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaFornecedorPorDocumento");
            selecao.setString("documentoRecebido", documento);
            listFornecedor = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            conexao.fecharSessao();
            return null;  
        }
        return listFornecedor;
    }
    public String atualizarFornecedor(Fornecedor fornecedor) {
        String mensagem;
        Transaction transaction = null;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(fornecedor);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Fornecedor atualizado com sucesso";
        }catch(Exception e){
            transaction.rollback();
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }
}

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
 * @author Silva
 */
public class VendaPers {
    public String cadastrarVenda(Venda venda){
            String mensagem;
            Transaction transaction = null;
            try{
                Conexao conexao = new Conexao();
                Session session = conexao.criarSessao();
                transaction = conexao.criarTransacao();
                session.save(venda);
                transaction.commit();
                conexao.fecharSessao();
                mensagem = "Venda realizada com sucesso";
            }catch(Exception e){
                transaction.rollback();
                mensagem = "Erro! "+e.getMessage();
            }
        return mensagem;
        }
               
        public List buscarVenda(int codVenda){
            List listVenda = new ArrayList();
            try{
                Conexao conexao = new Conexao();
                Session session = conexao.criarSessao();
                Query selecao = session.getNamedQuery("BuscaVendaPorCodVenda");
                selecao.setInteger("codVendaRecebido", codVenda);
                listVenda = selecao.list();
                conexao.fecharSessao();
            }catch(Exception e){
                return null;
            }
            return listVenda;
        }
        
        public String atualizarVenda(Venda venda){
            String mensagem;
            Transaction transaction = null;
            try{ 
                Conexao conexao = new Conexao();
                Session session = conexao.criarSessao();
                transaction = conexao.criarTransacao();
                session.update(venda);
                transaction.commit();
                conexao.fecharSessao();
                mensagem = "Venda alterada com sucesso";
            }catch(Exception e){
                transaction.rollback();
                mensagem = "Erro! "+e.getMessage();
            }
        return mensagem;
        }
}

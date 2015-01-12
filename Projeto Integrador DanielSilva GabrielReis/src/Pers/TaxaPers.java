/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.Taxa;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author cliente
 */
public class TaxaPers {
    public TaxaPers(){}
        public String cadastrarTaxa(Taxa taxa){
            String mensagem;
            Conexao conexao=null;
            Transaction transaction = null;
            try{
                conexao = new Conexao();
                Session session = conexao.criarSessao();
                transaction = conexao.criarTransacao();
                session.save(taxa);
                transaction.commit();
                conexao.fecharSessao();
                mensagem = "Taxa cadastrada com sucesso";
            }catch(Exception e){
                try{
                    transaction.rollback();
                    conexao.fecharSessao();
                }catch(Exception er){
                    return "Erro persistencia: "+er.getMessage();
                }
                mensagem = "Erro!"+e.getMessage();
            }
            return mensagem;
        }
        
        public List buscarTaxa(String placa){
            List listTaxa = new ArrayList();
            try{
                Conexao conexao = new Conexao();
                Session session = conexao.criarSessao();
                Query selecao = session.getNamedQuery("buscarTaxa");
                selecao.setString("placa", placa);
                listTaxa = selecao.list();
                conexao.fecharSessao();
            }catch(Exception e){
                return null;
            }
            return listTaxa;
        }

   
    
}

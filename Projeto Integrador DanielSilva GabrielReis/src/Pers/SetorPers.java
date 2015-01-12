/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.*;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Query;
import org.hibernate.Transaction;
import org.hibernate.Session;

/**
 *
 * @author Silva
 */
public class SetorPers {
    public String passandoSetorAoFuncionario(Setor setor){
            Transaction transaction = null;
            String mensagem;
            try{
                Conexao conexao = new Conexao();
                Session session = conexao.criarSessao();
                transaction =  conexao.criarTransacao();
                session.save(setor);
                transaction.commit();
                conexao.fecharSessao();
                mensagem = "Setor salvo com sucesso";
            }catch(Exception e){
                try{
                    transaction.rollback();
                }catch(Exception ex){
                    return "erro: "+ex.getMessage();
                }
                mensagem = "Erro! "+e.getMessage();
            }
        return mensagem;
        }
        
        public List buscarSetor(String setor){
            List listSetor = new ArrayList();
            try{
                    Conexao conexao = new Conexao();
                    Session session = conexao.criarSessao();
                    Query selecao = session.getNamedQuery("BuscaSetorPeloNome");
                    selecao.setString("setorRecebido", setor);
                    listSetor = selecao.list();
                    conexao.fecharSessao();
            }catch(Exception e){
                    return null;
            }
            return listSetor;
        }
        public String atualizandoSetorDoFuncionario(Setor setor){
            String mensagem;
            Transaction transaction = null;
            try{
                Conexao conexao = new Conexao();
                Session session = conexao.criarSessao();
                transaction = conexao.criarTransacao();
                session.update(setor);
                transaction.commit();
                conexao.fecharSessao();
                mensagem = "Setor alterado com sucesso";
            }catch(Exception e){
                transaction.rollback();
                mensagem = "Erro! "+e.getMessage();
            }
        return mensagem;
        }
}

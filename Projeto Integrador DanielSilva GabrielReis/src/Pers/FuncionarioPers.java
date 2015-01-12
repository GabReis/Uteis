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
public class FuncionarioPers {

    public String cadastrarFuncionario(Funcionario funcionario) {
         String mensagem;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            Transaction transaction = conexao.criarTransacao();
            session.save(funcionario);
            transaction.commit();
            session.flush();
            session.close();
            mensagem = "Funcionário cadastrado com sucesso";
        }catch(Exception e){
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }
    public List buscarFuncionario(String cpf) {
        List listFuncionario = new ArrayList();
        Conexao conexao=null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            Query selecao = session.getNamedQuery("BuscaFuncionarioPorCpf");
            selecao.setString("cpfRecebido", cpf);
            listFuncionario = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            conexao.fecharSessao();
            return null;
        }
        return listFuncionario;
    }
    public String atualizarFuncionario(Funcionario funcionario) {
         String mensagem;
         Transaction transaction = null;
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            session.update(funcionario);
            transaction.commit();
            conexao.fecharSessao();
            mensagem = "Funcionário atualizado com sucesso";
        }catch(Exception e){
            transaction.rollback();
            mensagem = "Erro "+e.getMessage();
        }
        return mensagem;
    }
}

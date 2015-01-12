/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.Aluguel;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.hibernate.*;

/**
 *
 * @author Silva
 */
public class AluguelPERS {

    public AluguelPERS() {
    }

    public List buscarUmAluguelSemDataDevolucao(int codveiculo) {
        List aluguelList = new ArrayList();
        Conexao conexao = null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            
            Query selecao = session.getNamedQuery("buscarAluguelSemDataDevolucao");
            selecao.setInteger("pCodVeiculo", codveiculo);
            
            aluguelList = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            try{
                conexao.fecharSessao();
            }catch(Exception ex){
                return null;
            }
            return null;
        }
        return aluguelList;
    }

    public String atualizarAluguel(Aluguel aluguel) {
        String mensagem="";
        Conexao conexao=null;
        Transaction transaction = null;
        try{
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction = conexao.criarTransacao();
            
            session.update(aluguel);
            
            transaction.commit();
            conexao.fecharSessao();
            mensagem="OK";
        }catch(Exception e){
            try{
                transaction.rollback();
                conexao.fecharSessao();
            }catch(Exception ex){
                return "Erro na persistencia: "+e.getMessage();
            }
            return "Erro na persistencia: "+e.getMessage();
        }
        return mensagem;
    }
    public ResultSet calcularAluguel(int codAluguel){
            Connection conexao=null;
            ResultSet resultado=null;
            try {
                // registra e carrega o driver JDBC do Firebird
                Class.forName("org.firebirdsql.jdbc.FBDriver");

                // estabelecendo conexÃ£o com o BD
                conexao = DriverManager.getConnection("jdbc:firebirdsql:localhost:d:/LOCADORA.fdb","sysdba", "masterkey");
                CallableStatement procedure = conexao.prepareCall("{call PROCEDURECALCULARALUGUEL(?)}");
                procedure.setInt(1, codAluguel);
                resultado = procedure.executeQuery();
                conexao.close();
            } catch (Exception e) {
                try {
                    conexao.close();
                } catch (SQLException ex) {
                    return null;
                }
                return null;
            } 
        return resultado;
    }
    public String cadastrarAluguel(Aluguel aluguel){
        Conexao conexao=null;
        Transaction transaction=null;
        try {
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction= conexao.criarTransacao();
            session.save(aluguel);
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

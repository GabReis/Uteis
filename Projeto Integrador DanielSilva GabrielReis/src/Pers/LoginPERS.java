/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import java.util.ArrayList;
import java.util.List;
import org.hibernate.*;

/**
 *
 * @author Silva
 */
public class LoginPERS {
    //se estiver correto o usuario e a senha o banco retorna um funcionario 
    public List autenticar(String login, String senha) {
        List loginList= new ArrayList();
        try{
            Conexao conexao = new Conexao();
            Session session = conexao.criarSessao();
            
            Query selecao = session.getNamedQuery("fazerLogin");//a query está na classe funcionario
            selecao.setString("login", login).setString("senha", senha);
            
            
            loginList = selecao.list();
            conexao.fecharSessao();
        }catch(Exception e){
            return null;
        }
        return loginList;
    }
}

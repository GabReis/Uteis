/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.Funcionario;
import PacotePrincipal.Login;
import Pers.LoginPERS;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Silva
 */
public class LoginRN {
    
    public Funcionario autenticar(Login login) {
        List loginList= new ArrayList();
        String mensagem;
        if (login.getLogin().equals(" ") || login.getSenha().equals(" "))
            return null;
        LoginPERS loginPERS = new LoginPERS();
        loginList = loginPERS.autenticar(login.getLogin().toUpperCase(), login.getSenha());
        
        if (loginList == null || loginList.isEmpty())
            return null;
        Funcionario funcionario = (Funcionario)loginList.get(0);
        
        return funcionario;
    }
    public boolean solicitarAcessoDiretor(Funcionario funcionario){
        if (funcionario.getTipo().equals("DIRETOR"))
            return true;
        else
            return false;
    }
    
}

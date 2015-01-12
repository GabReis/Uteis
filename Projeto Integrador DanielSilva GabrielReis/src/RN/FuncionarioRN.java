/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.Funcionario;
import Pers.FuncionarioPers;
import java.util.List;

/**
 *
 * @author cliente
 */
public class FuncionarioRN {
    String mensagem;
    /**
     *
     * @param funcionario
     * @return
     */
    public String cadastrarFuncionario(Funcionario funcionario) {
         if( (funcionario.getNome().equals("")) ||  (funcionario.getCpf().equals("")) ||
            (funcionario.getTipo().equals("")) || (funcionario.getLogin().equals("") ) ||
            (funcionario.getTelefone().equals("")) || (funcionario.getSenha().equals("")) ) {
                    mensagem = "Erro! Preencha todos os campos antes de prosseguir";
                    return mensagem;
    }   
         if(funcionario.getNumendereco()==0)//para validar o funcionario sem numero de endereco na tela de cadastro de funcionario
             return "Erro: Insira outro numero para a casa";
         if (funcionario.getEndereco() == null)
             return "Erro no endereco";
         funcionario.setTipo(funcionario.getTipo().toUpperCase());
         FuncionarioPers funcionarioPers = new FuncionarioPers();
         mensagem=funcionarioPers.cadastrarFuncionario(funcionario);
         return mensagem;
    }
    public Funcionario buscarFuncionario(String documento){
        if (documento.equals(""))
            return null;
        
        FuncionarioPers funcionarioPers = new FuncionarioPers();
        List listFuncionario= funcionarioPers.buscarFuncionario(documento);
        if (listFuncionario == null || listFuncionario.isEmpty())
            return null;
        return (Funcionario)listFuncionario.get(0);
    }
    public String atualizarFuncionario(Funcionario funcionario){
        FuncionarioPers funcionarioPers = new FuncionarioPers();
        funcionarioPers.atualizarFuncionario(funcionario);
        return mensagem;
    }
    
}

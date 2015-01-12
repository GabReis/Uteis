/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.Endereco;
import Pers.EnderecoPers;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
/**
 *
 * @author cliente
 */
public class EnderecoRN {
    String mensagem;
    public String cadastrarEndereco(Endereco endereco) {
        if( (endereco.getBairro().equals("")) || (endereco.getCep() == null) || 
            (endereco.getCidade() == null) || (endereco.getRua()== null ) ||
            (endereco.getComplemento() == null) || (endereco.getUf()==null) ) {
                    mensagem = "Erro! Preencha todos os campos antes------ de prosseguir";
                    return mensagem;
    }   
        EnderecoPers enderecoPers = new EnderecoPers();
        mensagem = enderecoPers.cadastrarEndereco(endereco);
        return mensagem;
    }

    public Endereco buscarEndereco(String cidade, String rua) {
        List enderecoList = new ArrayList();
        
        if (cidade == null || rua ==null)
            return null;
        if(cidade.equals("") || rua.equals(""))
            return null;
        EnderecoPers enderecoPERS = new EnderecoPers();
        
        enderecoList = enderecoPERS.buscarEndereco(cidade, rua);
        if (enderecoList == null)
            return null;
        if (enderecoList.isEmpty())
            return null;
        return (Endereco)enderecoList.get(0);
    }
    public String atualizarEndereco(Endereco endereco){
        EnderecoPers enderecoPers = new EnderecoPers();
        enderecoPers.atualizarEndereco(endereco);
        return mensagem;
    }
}
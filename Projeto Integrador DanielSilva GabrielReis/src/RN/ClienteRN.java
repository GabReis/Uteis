/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;


import PacotePrincipal.*;
import Pers.*;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author cliente
 */
public class ClienteRN {
    
    public String cadastrarCliente(Cliente cliente) {
        String mensagem;
        if( (cliente.getNome() == null) ||   
            (cliente.getNumcnh() == null) || (cliente.getEmail()== null ) || 
            (cliente.getTelefone() == null) || (cliente.getTipocnh()==null) ) {
                    mensagem = "Erro! Preencha todos os campos antes de prosseguir";
                    return mensagem;
        }          
        if(cliente.getNumendereco()==0)
                         return "OK";            
        ClientePers clientePers = new ClientePers();
        mensagem=clientePers.cadastrarCliente(cliente);
        return mensagem;
    }
    public String cadastrarCliente(Cliente cliente, String pessoa) {
        String mensagem;
        if (pessoa == null){
            return "Erro cnpj/cpj nao informado";
        }
        
        if( (cliente.getNome().equals("")) ||   
            cliente.getNumcnh().equals("")  || cliente.getEmail().equals("") || 
            cliente.getTelefone().equals("") || cliente.getTipocnh().equals("") || cliente.getNumendereco() == 0) {
                    mensagem = "Erro! Preencha todos os campos antes de prosseguir";
                    return mensagem;
        }          
                  
       if (pessoa.equals("FISICA"))
           cliente.setCpf(pessoa);
       else
           cliente.setCpf(pessoa);
       
        ClientePers clientePers = new ClientePers();
        mensagem=clientePers.cadastrarCliente(cliente);
        
        return mensagem;
    }
    public Cliente buscarEmailCliente(Aluguel aluguel){
        List listCliente = new ArrayList();
        if(aluguel == null)
            return null;
        ClientePers clientePers = new ClientePers();
        listCliente = clientePers.buscarEmailCliente(aluguel.getCodaluguel());
        if (listCliente == null)
            return null;
        if (listCliente.isEmpty())
            return null;
        return  (Cliente)listCliente.get(0);
    }
    
    public Cliente buscarCliente(String documento) {
       List clienteList = new ArrayList();
       if (documento == null)
           return null;
       if (documento.equals(""))
           return null;
       ClientePers clientePERS = new ClientePers();
       clienteList = clientePERS.buscarCliente(documento);
       
       if (clienteList == null)
           return null;
      if (clienteList.isEmpty())
          return null;
       
       return (Cliente)clienteList.get(0);
    }
    public String atualizarCliente(Cliente cliente){
        String mensagem=null;
        ClientePers clientePers = new ClientePers();
        clientePers.atualizarCliente(cliente);
        return mensagem;
    }
    
}

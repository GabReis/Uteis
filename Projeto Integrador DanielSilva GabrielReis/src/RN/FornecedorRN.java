/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.Fornecedor;
import Pers.FornecedorPers;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author cliente
 */
public class FornecedorRN {
        String mensagem;
        public String cadastrarFornecedor(Fornecedor fornecedor, String tipoPessoa, String doc){
            if (doc == null || doc.equals(""))
                return "documento invalido";
            if (tipoPessoa.equals("SELECIONE"))
                    return "Selecione um tipo de pessoa";
            if(tipoPessoa.toUpperCase().equals("FISICA") ){
                    fornecedor.setCnpj(null);
                    fornecedor.setCpf(doc);
            }
            else if(tipoPessoa.toUpperCase().equals("JURIDICA") ){
                    fornecedor.setCpf(null);
                    fornecedor.setCnpj(doc);
            }
            //( fornecedor.getCpf().equals("") && fornecedor.getCnpj().equals(""))
            if( fornecedor.getNome().equals("") ||  fornecedor.getTelefone().equals("") ||
                     fornecedor.getNumendereco() == 0 ){
                    mensagem = "Erro! Preencha todos os campos antes de prosseguir";
                    return mensagem;
            }  
            if (fornecedor.getEndereco()==null)
                return "FK NULL";
                   
        FornecedorPers fornecedorPers = new FornecedorPers();
        mensagem=fornecedorPers.cadastrarFornecedor(fornecedor);
        return mensagem;
    }

    public Fornecedor buscarFornecedor(String documento) {
       List fornecedorList = new ArrayList();
       if (documento == null)
           return null;
       if (documento.equals(""))
           return null;
       FornecedorPers fornecedorPERS = new FornecedorPers();
       fornecedorList = fornecedorPERS.buscarFornecedor(documento);
       
       if (fornecedorList == null)
           return null;
      if (fornecedorList.isEmpty())
          return null;
       
       return (Fornecedor)fornecedorList.get(0);
    }
    
    public String atualizarFornecedor(Fornecedor fornecedor){
        FornecedorPers fornecedorPers = new FornecedorPers();
        fornecedorPers.atualizarFornecedor(fornecedor);
        return mensagem;
    }
    public String cadastrarFornecedor(Fornecedor fornecedor) {
            FornecedorPers fornecedorPers = new FornecedorPers();
            
            mensagem=fornecedorPers.cadastrarFornecedor(fornecedor);
            return mensagem;
      
    }
    
}

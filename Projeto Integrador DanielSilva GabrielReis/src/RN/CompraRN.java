/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.*;
import Pers.*;

/**
 *
 * @author Silva
 */
public class CompraRN {

    public String cadastrarCompra(Compra compra) {
        /*if (funcionario == null)
            return null;
        if (!funcionario.getTipo().equals("DIRETOR"))
            return "SOMENTE DIRETOR";*/
        String mensagem="OK";
        if (compra == null)
            return "Compra Null em RN";
        if (compra.getFornecedor() == null || compra.getFuncionario() == null)
            return "Fk null";
        CompraPers compraPERS = new CompraPers();
        mensagem = compraPERS.cadastrarCompra(compra);
        if (!mensagem.equals("OK"))//mensagem != OK
            return mensagem;
        
        return mensagem;//retorna o OK
    }
    
    
}

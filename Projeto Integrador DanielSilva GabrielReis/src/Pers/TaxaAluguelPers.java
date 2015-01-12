/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

import PacotePrincipal.Taxaaluguel;
import org.hibernate.*;

/**
 *
 * @author Silva
 */
public class TaxaAluguelPers {

    public String cadastrarTaxaAluguel(Taxaaluguel taxaAluguel) {
       Conexao conexao=null;
       Transaction transaction=null;
        try {
            conexao = new Conexao();
            Session session = conexao.criarSessao();
            transaction= conexao.criarTransacao();
            session.save(taxaAluguel);
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

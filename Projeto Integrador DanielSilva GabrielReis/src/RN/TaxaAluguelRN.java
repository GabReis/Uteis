/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;

import PacotePrincipal.Taxaaluguel;
import Pers.TaxaAluguelPers;

/**
 *
 * @author Silva
 */
public class TaxaAluguelRN {

    public String cadastrarTaxaAluguel(Taxaaluguel taxaAluguel) {
        String mensagem=null;
       if (taxaAluguel == null)
           return "Erro taxaAluguel null";
       TaxaAluguelPers taxaAluguelPers = new TaxaAluguelPers();
       mensagem = taxaAluguelPers.cadastrarTaxaAluguel(taxaAluguel);
       return mensagem;
    }
    
}

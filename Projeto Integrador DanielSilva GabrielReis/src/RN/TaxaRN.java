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
 * @author Silva
 */
public class TaxaRN {
    public TaxaRN(){}
    public List buscarTaxa(Veiculo veiculo) {
        List listTaxa = new ArrayList();
        if (veiculo == null)
            return null;
        TaxaPers taxaPers = new TaxaPers();
        listTaxa = taxaPers.buscarTaxa(veiculo.getPlaca());
        if (listTaxa == null || listTaxa.isEmpty())
            return null;
        
        
        
        return listTaxa;
    }
    public boolean verificaDia(String teste){
            if(!("").equals(teste))
                return false;
            return true;
            
        }
        public String cadastrarTaxa(Taxa taxa){
            if (taxa == null)
                return "Erro taxa null";
            TaxaPers taxaPers = new TaxaPers();
            String mensagem = taxaPers.cadastrarTaxa(taxa);
            return mensagem;
        }
    
}

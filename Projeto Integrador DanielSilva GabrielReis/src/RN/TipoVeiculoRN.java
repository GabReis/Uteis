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
public class TipoVeiculoRN {

    public Tipoveiculo buscarVeiculo(String tipo) {
        List tipoVeiculoList = new ArrayList();
        
        if (tipo == null || tipo.equals(""))
            return null;
        TipoVeiculoPERS tipoVeiculoPERS = new TipoVeiculoPERS();
        tipoVeiculoList = tipoVeiculoPERS.buscarTipoVeiculo(tipo);
        
        if (tipoVeiculoList == null)
            return null;
        if (tipoVeiculoList.isEmpty())
            return null;
        
        return (Tipoveiculo)tipoVeiculoList.get(0);
    }
    
        public String cadastrarTipoVeiculo(Tipoveiculo tipoVeiculo){
            String mensagem;
            TipoVeiculoPERS tipoVeiculoPers = new TipoVeiculoPERS();
            mensagem = tipoVeiculoPers.cadastrarTipoVeiculo(tipoVeiculo);
            return mensagem;
        }
    
}

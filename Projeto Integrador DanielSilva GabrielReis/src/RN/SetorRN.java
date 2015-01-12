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
public class SetorRN {
    
        public String cadastrarSetor(Setor setor){
            String mensagem=null;
            SetorPers setorPers = new SetorPers();
            setorPers.passandoSetorAoFuncionario(setor);
            return mensagem;
        }
        public String atualizarSetor(Setor setor){
            String mensagem=null;
            SetorPers setorPers = new SetorPers();
            setorPers.atualizandoSetorDoFuncionario(setor);
            return mensagem;
        }
}

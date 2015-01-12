/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RN;
import Pers.*;
import PacotePrincipal.*;
import java.math.BigDecimal;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import javax.swing.JOptionPane;
/**
 *
 * @author cliente  Tratar a data!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *                  Ver oque passar no Set, tratar strings nos text fields  
 */                                       
public class PromocaoRN {
    private String mensagem;   
    public String cadastrarPromocao(Promocao promocao) {
        //JOptionPane.showMessageDialog(null, ""+promocao.getDatafimpromocao()+" "+promocao.getPercentualdesconto()+" "+promocao.getCodpromocao()+" "+promocao.getTipopromocao());
        if(promocao.getTipopromocao()!=1&&promocao.getTipopromocao()!=2){
            mensagem="Promoção inválida";
            return mensagem;
        }   
        
        PromocaoPERS promocaoPERS = new PromocaoPERS();
        mensagem = promocaoPERS.cadastrarPromocao(promocao);
        return mensagem;
    }
    public String atualizarPromocao(Promocao promocao){
            PromocaoPERS promocaoPers = new PromocaoPERS();
            mensagem=promocaoPers.atualizarPromocao(promocao);
            return mensagem;
    }
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Pers;

/**
 *
 * @author Silva
 */

import org.hibernate.cfg.Configuration;
import org.hibernate.*;

public class Conexao {
   
    SessionFactory factory = null;
    Session session = null;
    Transaction transaction = null;
    
    public Conexao() throws Exception{//lança exception pra quem chama
        
            //---conexão com o banco de dados------------
            factory = new Configuration().configure("Pers/hibernate.cfg.xml").buildSessionFactory();
            //---cria uma sessão do hibernate na conexao ativa----- 
            session = factory.openSession();
            //---inicia uma transação -----------
            transaction = session.beginTransaction();
    }
    public Session criarSessao(){
        return session;
    }
    public Transaction criarTransacao(){
        return transaction;
    }
    public void fecharSessao(){
        session.flush();
        session.close();
    }
}


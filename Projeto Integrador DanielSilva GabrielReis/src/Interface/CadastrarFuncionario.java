/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Interface;

import PacotePrincipal.*;
import RN.FuncionarioRN;
import RN.SetorRN;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.JOptionPane;

/**
 *
 * @author cliente
 */
public class CadastrarFuncionario extends javax.swing.JFrame {
    private Funcionario funcionarioLogado;
    private Funcionario funcionario=null;
    /**
     * Creates new form CadastrarFuncionario
     */
    public CadastrarFuncionario(Funcionario funcionarioLogado){
        this.funcionarioLogado=funcionarioLogado;
        initComponents();
    }
    
    public CadastrarFuncionario(){
       
        initComponents();
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        nome = new javax.swing.JTextField();
        jLabel17 = new javax.swing.JLabel();
        cpf = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        telefone = new javax.swing.JTextField();
        botaoConfirmar = new javax.swing.JButton();
        botaoCancelar = new javax.swing.JButton();
        jLabel10 = new javax.swing.JLabel();
        dataNasc = new javax.swing.JTextField();
        jLabel18 = new javax.swing.JLabel();
        tipo = new javax.swing.JTextField();
        jLabel12 = new javax.swing.JLabel();
        login = new javax.swing.JTextField();
        jLabel11 = new javax.swing.JLabel();
        senha = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        setor = new javax.swing.JTextField();
        jLabel8 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel2.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel1.setText("Nome");
        jPanel2.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 44, -1, -1));
        jPanel2.add(nome, new org.netbeans.lib.awtextra.AbsoluteConstraints(125, 41, 240, -1));

        jLabel17.setText("CPF");
        jPanel2.add(jLabel17, new org.netbeans.lib.awtextra.AbsoluteConstraints(470, 44, -1, -1));

        cpf.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cpfActionPerformed(evt);
            }
        });
        cpf.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                cpfFocusLost(evt);
            }
        });
        jPanel2.add(cpf, new org.netbeans.lib.awtextra.AbsoluteConstraints(537, 41, 170, -1));

        jLabel9.setText("Telefone");
        jPanel2.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 140, -1, -1));
        jPanel2.add(telefone, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 130, 162, -1));

        botaoConfirmar.setText("Confirmar");
        botaoConfirmar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoConfirmarActionPerformed(evt);
            }
        });
        jPanel2.add(botaoConfirmar, new org.netbeans.lib.awtextra.AbsoluteConstraints(224, 288, -1, 33));

        botaoCancelar.setText("Cancelar");
        botaoCancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoCancelarActionPerformed(evt);
            }
        });
        jPanel2.add(botaoCancelar, new org.netbeans.lib.awtextra.AbsoluteConstraints(423, 285, -1, 39));

        jLabel10.setText("Data de nascimento");
        jPanel2.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(12, 82, -1, -1));
        jPanel2.add(dataNasc, new org.netbeans.lib.awtextra.AbsoluteConstraints(125, 79, 253, -1));

        jLabel18.setText("TIpo de funcionário");
        jPanel2.add(jLabel18, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 179, -1, -1));
        jPanel2.add(tipo, new org.netbeans.lib.awtextra.AbsoluteConstraints(121, 176, 196, -1));

        jLabel12.setText("Login");
        jPanel2.add(jLabel12, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 220, -1, -1));
        jPanel2.add(login, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 220, 220, -1));

        jLabel11.setText("Senha");
        jPanel2.add(jLabel11, new org.netbeans.lib.awtextra.AbsoluteConstraints(443, 226, -1, -1));
        jPanel2.add(senha, new org.netbeans.lib.awtextra.AbsoluteConstraints(545, 223, 162, -1));

        jLabel2.setText("Setor");
        jPanel2.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(440, 180, -1, -1));
        jPanel2.add(setor, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 170, 150, -1));

        jLabel8.setText("Cadastrar funcionário");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(19, Short.MAX_VALUE)
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(14, 14, 14))
            .addGroup(layout.createSequentialGroup()
                .addGap(362, 362, 362)
                .addComponent(jLabel8)
                .addContainerGap(274, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel8)
                .addGap(18, 18, 18)
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(21, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cpfActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cpfActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cpfActionPerformed

    private void botaoConfirmarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoConfirmarActionPerformed
            if (this.funcionario!=null){//funcionario ja cadastrado
                JOptionPane.showMessageDialog(null, "Funcionario Ja cadastrado");
                return;
            }
                
            Funcionario funcionario = new Funcionario();
            Setor setor1 = new Setor();
            funcionario.setNome(nome.getText());
            try{    
                Date data1 = new SimpleDateFormat("dd/MM/yyyy").parse(dataNasc.getText()); 
                funcionario.setDatanascimento(data1);
            }catch(ParseException erroData){
                JOptionPane.showMessageDialog(null,"Formato de data inválido");
                return ;
            }
            funcionario.setCpf(cpf.getText());        
            funcionario.setTelefone(telefone.getText());
            funcionario.setTipo(tipo.getText());
            funcionario.setLogin(login.getText());
            funcionario.setSenha(senha.getText());
            
            setor1.setSetor(setor.getText());
            SetorRN setorRN = new SetorRN();
            String mensagem = setorRN.cadastrarSetor(setor1);
      
            funcionario.setSetor(setor1);

            FuncionarioRN funcionarioRN = new FuncionarioRN();
            mensagem = funcionarioRN.cadastrarFuncionario(funcionario);//nao cadastra aqui, é só para validar os dados
            if(! mensagem.equals("Erro: Insira outro numero para a casa")){
                        JOptionPane.showMessageDialog(null, mensagem);
            }else{
                CadastroEnderecos cadastroEnderecos = new CadastroEnderecos(funcionarioLogado, funcionario);
                cadastroEnderecos.setVisible(true);
                this.setVisible(false);
            }
                  
    }//GEN-LAST:event_botaoConfirmarActionPerformed

    private void cpfFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_cpfFocusLost
        FuncionarioRN funcionarioRN = new FuncionarioRN();
         funcionario = funcionarioRN.buscarFuncionario(this.cpf.getText());
         if (funcionario != null){
             JOptionPane.showMessageDialog(null, "Funcionario Ja cadastrado");
             
         }
    }//GEN-LAST:event_cpfFocusLost

    private void botaoCancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoCancelarActionPerformed
        if (JOptionPane.showConfirmDialog(null, "Tela Inicial") == 0 ){ //0 é o sim
            TelaInicial telaInicial = new TelaInicial(this.funcionarioLogado);
            telaInicial.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_botaoCancelarActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(CadastrarFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(CadastrarFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(CadastrarFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(CadastrarFuncionario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new CadastrarFuncionario().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoCancelar;
    private javax.swing.JButton botaoConfirmar;
    private javax.swing.JTextField cpf;
    private javax.swing.JTextField dataNasc;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JTextField login;
    private javax.swing.JTextField nome;
    private javax.swing.JTextField senha;
    private javax.swing.JTextField setor;
    private javax.swing.JTextField telefone;
    private javax.swing.JTextField tipo;
    // End of variables declaration//GEN-END:variables
}

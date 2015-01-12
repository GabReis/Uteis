/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Interface;

import PacotePrincipal.*;
import RN.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.JOptionPane;

/**
 *
 * @author cliente
 */
public class SetorLocacao extends javax.swing.JFrame {
    private Funcionario funcionario;
    private Veiculo veiculo;
    
    /**
     * Creates new form SetorLocacao
     */
    public SetorLocacao() {
        initComponents();
    }
    public SetorLocacao(Funcionario funcionario) {
        this.funcionario = funcionario;
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

        buttonGroup1 = new javax.swing.ButtonGroup();
        buttonGroup2 = new javax.swing.ButtonGroup();
        jLabel4 = new javax.swing.JLabel();
        tFPlaca = new javax.swing.JTextField();
        jBConfirmar = new javax.swing.JButton();
        LBTCancelar = new javax.swing.JButton();
        jBOK = new javax.swing.JButton();
        jLabel8 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTMostrarVeiculo = new javax.swing.JTextPane();
        jLabel2 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jCTipoLocacao = new javax.swing.JComboBox();
        tFDataLocacao = new javax.swing.JTextField();
        jLabel12 = new javax.swing.JLabel();
        jCSeguro = new javax.swing.JComboBox();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel4.setText("Placa");
        getContentPane().add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 50, -1, -1));

        tFPlaca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tFPlacaActionPerformed(evt);
            }
        });
        getContentPane().add(tFPlaca, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 50, 310, -1));

        jBConfirmar.setText("Confirmar");
        jBConfirmar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBConfirmarActionPerformed(evt);
            }
        });
        getContentPane().add(jBConfirmar, new org.netbeans.lib.awtextra.AbsoluteConstraints(108, 548, -1, 31));

        LBTCancelar.setText("Cancelar");
        LBTCancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LBTCancelarActionPerformed(evt);
            }
        });
        getContentPane().add(LBTCancelar, new org.netbeans.lib.awtextra.AbsoluteConstraints(305, 548, 86, 31));

        jBOK.setText("OK");
        jBOK.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBOKActionPerformed(evt);
            }
        });
        getContentPane().add(jBOK, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 40, -1, -1));

        jLabel8.setText("seguro");
        getContentPane().add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(280, 310, -1, -1));

        jScrollPane1.setViewportView(jTMostrarVeiculo);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(66, 85, 348, 192));

        jLabel2.setText("Setor de Locação");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(219, 11, -1, -1));

        jLabel10.setText("Tipo de Aluguel");
        getContentPane().add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 310, -1, -1));

        jCTipoLocacao.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "DIARIO", "SEMANAL", "MENSAL" }));
        getContentPane().add(jCTipoLocacao, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 340, -1, -1));
        getContentPane().add(tFDataLocacao, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 450, 209, -1));

        jLabel12.setText("Data Locação");
        getContentPane().add(jLabel12, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 450, -1, -1));

        jCSeguro.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "SIM", "NAO", " " }));
        getContentPane().add(jCSeguro, new org.netbeans.lib.awtextra.AbsoluteConstraints(280, 340, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents
        
    private void tFPlacaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tFPlacaActionPerformed
        
    }//GEN-LAST:event_tFPlacaActionPerformed

    private void jBOKActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBOKActionPerformed
        String placa = tFPlaca.getText();
        VeiculoRN veiculoRN = new VeiculoRN();
        this.veiculo = veiculoRN.buscarVeiculo(placa);
        
        if (this.veiculo == null){
            this.jTMostrarVeiculo.setText("Veículo não encontrado");  
            return;
        }else    
            this.jBConfirmar.setEnabled(true);
            String mostrarVeiculo = 
                    "Placa: "+this.veiculo.getPlaca()+"\nStatus: "+this.veiculo.getStatus()+
                    "\nChassi: "+this.veiculo.getChassi()+"\nCombustivel: "+this.veiculo.getCombustivel()+"\nCor: "+this.veiculo.getCor()+
                    "\nModelo: "+this.veiculo.getModelo()+"\nAno: "+this.veiculo.getAno()+
                    "\nKilometragem: "+this.veiculo.getKilometragem();
            this.jTMostrarVeiculo.setText(mostrarVeiculo); 
            if (!veiculo.getStatus().toUpperCase().equals("DISPONIVEL")){
                this.jBConfirmar.setEnabled(false);
                JOptionPane.showMessageDialog(null,"Veiculo indisponivel");
            }
    }//GEN-LAST:event_jBOKActionPerformed

    private void jBConfirmarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBConfirmarActionPerformed
        //quando esse botao é clicado é porque ja tem um veiculo escolhido 
        float seguro = 0;
        if (jCSeguro.getSelectedItem().toString().equals("SIM")){
            try{
                seguro = Float.parseFloat( JOptionPane.showInputDialog("Digite o Seguro"));
            }catch(Exception e){
                JOptionPane.showMessageDialog(null,"Seguo inválido: "+e.getMessage());
                return;
            }
        }
        
        Aluguel aluguel = new Aluguel();
        Date dataLocacao=null;
        try{    //Formato data do VO é do tipo Date 
           dataLocacao = new SimpleDateFormat("dd/MM/yyyy").parse(tFDataLocacao.getText()); 
        }catch(Exception erro){
            JOptionPane.showMessageDialog(null,"Erro na data: "+erro.getMessage());
            return;
        }
        aluguel.setDataaluguel(dataLocacao);
        aluguel.setTipoaluguel(this.jCTipoLocacao.getSelectedItem().toString());
        
        CadastrarCliente cadastrarCliente = new CadastrarCliente(this.funcionario, this.veiculo, aluguel, seguro);
        cadastrarCliente.setVisible(true);
        this.setVisible(false);
            
    }//GEN-LAST:event_jBConfirmarActionPerformed

    private void LBTCancelarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LBTCancelarActionPerformed
        if (JOptionPane.showConfirmDialog(null, "Tela Inicial") == 0 ){ //0 é o sim
            TelaInicial telaInicial = new TelaInicial(this.funcionario);
            telaInicial.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_LBTCancelarActionPerformed

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
            java.util.logging.Logger.getLogger(SetorLocacao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(SetorLocacao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(SetorLocacao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(SetorLocacao.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new SetorLocacao().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton LBTCancelar;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.ButtonGroup buttonGroup2;
    private javax.swing.JButton jBConfirmar;
    private javax.swing.JButton jBOK;
    private javax.swing.JComboBox jCSeguro;
    private javax.swing.JComboBox jCTipoLocacao;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextPane jTMostrarVeiculo;
    private javax.swing.JTextField tFDataLocacao;
    private javax.swing.JTextField tFPlaca;
    // End of variables declaration//GEN-END:variables
}
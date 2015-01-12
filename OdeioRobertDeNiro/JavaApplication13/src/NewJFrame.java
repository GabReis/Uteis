import java.awt.*;
import java.awt.image.*;
import java.io.*;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.*;

public class NewJFrame extends javax.swing.JFrame {
    private int[] arrayCelulas = new int[8];
    BufferedImage imagem1;
    int flag=0;
   
    public NewJFrame() {
        initComponents();
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenuItem3 = new javax.swing.JMenuItem();
        Afinamento = new javax.swing.JMenu();
        jMenuItem4 = new javax.swing.JMenuItem();
        jMenuItem5 = new javax.swing.JMenuItem();
        jMenuItem6 = new javax.swing.JMenuItem();
        jMenuItem7 = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        jMenu1.setText("Arquivo");

        jMenuItem1.setLabel("Abrir...");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem1);

        jMenuItem2.setLabel("Salvar...");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem2);

        jMenuItem3.setLabel("Sair");
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem3);

        jMenuBar1.add(jMenu1);

        Afinamento.setText("Imagem");
        Afinamento.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AfinamentoActionPerformed(evt);
            }
        });

        jMenuItem4.setLabel("Negativo");
        jMenuItem4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem4ActionPerformed(evt);
            }
        });
        Afinamento.add(jMenuItem4);

        jMenuItem5.setText("Afinamento");
        jMenuItem5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem5ActionPerformed(evt);
            }
        });
        Afinamento.add(jMenuItem5);

        jMenuItem6.setText("Operador Roberts");
        jMenuItem6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem6ActionPerformed(evt);
            }
        });
        Afinamento.add(jMenuItem6);

        jMenuItem7.setText("Contraste");
        jMenuItem7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem7ActionPerformed(evt);
            }
        });
        Afinamento.add(jMenuItem7);

        jMenuBar1.add(Afinamento);

        setJMenuBar(jMenuBar1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter("JPG, PNG & GIF Images", "jpg", "png", "gif");
        chooser.setFileFilter(filter);
        chooser.setDialogTitle("Abrir Imagem");
        int op = chooser.showOpenDialog(this);
        if(op == JFileChooser.APPROVE_OPTION){  
            File arq = chooser.getSelectedFile();  
            String path = arq.toString();  
            try { 
                  imagem1 = ImageIO.read(new File(path));
                  System.out.println("Arquivo aberto com sucesso!");
                  ImageIcon icon = new ImageIcon(imagem1);
                  if (flag==0) {
                      jLabel1.setIcon(icon);
                      Container contentPane = getContentPane();
                      contentPane.setLayout(new GridLayout());
                      contentPane.add(new JScrollPane(jLabel1));
                      flag=1;
                  }
                  else jLabel1.setIcon(icon);
                  setSize(imagem1.getWidth()+25, imagem1.getHeight()+70);
	    }
	    catch(IOException e){
		System.out.println("Erro IO Exception! Verifique se o arquivo especificado existe e tente novamente.");
	    }
	    catch(Exception e){
		System.out.println("Erro Exception! " + e.getMessage());
	    }                   
        }  
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem3ActionPerformed
        System.exit(1);
    }//GEN-LAST:event_jMenuItem3ActionPerformed
    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter("JPG Images", "jpg");
        chooser.setFileFilter(filter);
        chooser.setDialogTitle("Salvar Imagem");
        int op = chooser.showSaveDialog(this);
        if(op == JFileChooser.APPROVE_OPTION){  
            File arq = chooser.getSelectedFile();  
            String path = arq.toString();  
            try {
		ImageIO.write(imagem1,"jpg",new File(path));
		System.out.println("Arquivo salvo com sucesso!");
		}
		catch(IOException e){
			System.out.println("Erro IO Exception! Verifique se o arquivo especificado existe e tente novamente.");
		}
		catch(Exception e){
			System.out.println("Erro Exception! " + e.getMessage());
		}
        }
    }//GEN-LAST:event_jMenuItem2ActionPerformed
    private void jMenuItem4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem4ActionPerformed
        int width = imagem1.getWidth();
	int height = imagem1.getHeight();
	for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) { 				
                int rgb = imagem1.getRGB(i, j); 				
                int r = 255 - (int)((rgb&0x00FF0000)>>>16);
		int g = 255 - (int)((rgb&0x0000FF00)>>>8);
		int b = 255 - (int) (rgb&0x000000FF);
		Color color = new Color(r, g, b);
		imagem1.setRGB(i, j, color.getRGB());
	    }
        }
        this.imageUpdate(imagem1, ALLBITS, 0, 0, width, height);

    }//GEN-LAST:event_jMenuItem4ActionPerformed

    private void jMenuItem5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem5ActionPerformed
        calculaTonsDeCinza(0);
        JOptionPane.showMessageDialog(null, "Imagem pronta para Afinamento!");
        int width = imagem1.getWidth();
	int height = imagem1.getHeight();
        BufferedImage imageAux = new BufferedImage(imagem1.getWidth(), imagem1.getHeight(),BufferedImage.TYPE_INT_RGB);
	float[] masc1 = new float[] {0.0f, 0.0f, 0.0f,
                                    1.0f, 0.0f, 1.0f,
                                    255.0f, 255.0f, 255.0f};
        
        float[] masc2 = new float[] {1.0f, 255.0f, 255.0f,
                                    0.0f, 0.0f, 255.0f,
                                    0.0f, 0.0f, 1.0f};
        
        float[] masc3 = new float[] {255.0f, 1.0f, 0.0f,
                                     255.0f, 0.0f, 0.0f,
                                     255.0f, 1.0f, 0.0f};
        
        float[] masc4 = new float[] {0.0f, 0.0f, 1.0f,
                                    0.0f, 0.0f, 255.0f,
                                    1.0f, 255.0f, 255.0f};
        
        float[] masc5 = new float[] {255.0f, 255.0f, 255.0f,
                                     1.0f, 0.0f, 1.0f,
                                     0.0f, 0.0f, 0.0f};
        
        float[] masc6 = new float[] {1.0f, 0.0f, 0.0f,
                                    255.0f, 0.0f, 0.0f,
                                    255.0f, 255.0f, 1.0f};
                
        float[] masc7 = new float[] {0.0f, 1.0f, 255.0f,
                                    0.0f, 0.0f, 255.0f,
                                    0.0f, 1.0f, 255.0f};
        
        float[] masc8 = new float[]{255.0f, 255.0f, 1.0f,
                                    255.0f, 0.0f, 0.0f,
                                    1.0f, 0.0f, 0.0f};
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imagem1.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imagem1.getRGB(i-1, j-1));
                            if(cor.getRed() != masc1[0])
                                if(masc1[0]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i-1, j));
                            if(cor.getRed() != masc1[1])
                                if(masc1[1]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i-1, j+1));
                            if(cor.getRed() != masc1[2])
                                if(masc1[2]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i, j-1));
                            if(cor.getRed() != masc1[3])
                                 if(masc1[3]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i, j+1));
                            if(cor.getRed() != masc1[5])
                                if(masc1[5]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i+1, j-1));
                            if(cor.getRed() != masc1[6])
                                if(masc1[6]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i+1, j));
                            if(cor.getRed() != masc1[7])
                                if(masc1[7]!=1)
                                    break;
                            
                            cor = new Color(imagem1.getRGB(i+1, j+1));
                            if(cor.getRed() != masc1[8])
                                if(masc1[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
              
        
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc2[0])
                                if(masc2[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc2[1])
                                if(masc2[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc2[2])
                                if(masc2[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc2[3])
                                 if(masc2[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc2[5])
                                if(masc2[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc2[6])
                                if(masc2[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc2[7])
                                if(masc2[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc2[8])
                                if(masc2[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc3[0])
                                if(masc3[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc3[1])
                                if(masc3[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc3[2])
                                if(masc3[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc3[3])
                                 if(masc3[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc3[5])
                                if(masc3[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc3[6])
                                if(masc3[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc3[7])
                                if(masc3[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc3[8])
                                if(masc3[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc4[0])
                                if(masc4[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc4[1])
                                if(masc4[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc4[2])
                                if(masc4[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc4[3])
                                 if(masc4[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc4[5])
                                if(masc4[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc4[6])
                                if(masc4[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc4[7])
                                if(masc4[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc4[8])
                                if(masc4[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        
        
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc5[0])
                                if(masc5[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc5[1])
                                if(masc5[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc5[2])
                                if(masc5[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc5[3])
                                 if(masc5[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc5[5])
                                if(masc5[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc5[6])
                                if(masc5[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc5[7])
                                if(masc5[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc5[8])
                                if(masc5[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc6[0])
                                if(masc6[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc6[1])
                                if(masc6[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc6[2])
                                if(masc6[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc6[3])
                                 if(masc6[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc6[5])
                                if(masc6[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc6[6])
                                if(masc6[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc6[7])
                                if(masc6[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc6[8])
                                if(masc6[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc7[0])
                                if(masc7[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc7[1])
                                if(masc7[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc7[2])
                                if(masc7[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc7[3])
                                 if(masc7[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc7[5])
                                if(masc7[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc7[6])
                                if(masc7[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc7[7])
                                if(masc7[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc7[8])
                                if(masc7[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        
        for (int i = 1; i <width-1; i++) {
            for (int j = 1; j < height-1; j++){ 	
                 Color cor = new Color(imageAux.getRGB(i, j));
                 if(cor.getRed() == 0){
                       while(true){
                           imageAux.setRGB(i, j, cor.getRGB());
                            cor = new Color(imageAux.getRGB(i-1, j-1));
                            if(cor.getRed() != masc8[0])
                                if(masc8[0]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j));
                            if(cor.getRed() != masc8[1])
                                if(masc8[1]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i-1, j+1));
                            if(cor.getRed() != masc8[2])
                                if(masc8[2]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j-1));
                            if(cor.getRed() != masc8[3])
                                 if(masc8[3]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i, j+1));
                            if(cor.getRed() != masc8[5])
                                if(masc8[5]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j-1));
                            if(cor.getRed() != masc8[6])
                                if(masc8[6]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j));
                            if(cor.getRed() != masc8[7])
                                if(masc8[7]!=1)
                                    break;
                            
                            cor = new Color(imageAux.getRGB(i+1, j+1));
                            if(cor.getRed() != masc8[8])
                                if(masc8[8]!=1)
                                    break;
                            cor = new Color (255,255,255);
                            imageAux.setRGB(i, j, cor.getRGB());
                            break;
                        }
                 }
                 else
                          imageAux.setRGB(i, j, cor.getRGB());
                
            }
        }	
        imagem1 = imageAux;
        ImageIcon icon = new ImageIcon(imagem1);
        jLabel1.setIcon(icon);
        this.imageUpdate(imagem1, ALLBITS, 0, 0, width, height);
        System.out.println("Processo finalizado!");
    }//GEN-LAST:event_jMenuItem5ActionPerformed
    private void AfinamentoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AfinamentoActionPerformed
    }//GEN-LAST:event_AfinamentoActionPerformed

    private void jMenuItem6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem6ActionPerformed
        int width = imagem1.getWidth();
	int height = imagem1.getHeight();
        BufferedImage imageAux = new BufferedImage(imagem1.getWidth(), imagem1.getHeight(),BufferedImage.TYPE_INT_RGB);
	
        double res1,res2;int setaPixel;
        calculaTonsDeCinza(1);
        for (int i = 1; i < width-1; i++) {
            for (int j = 1; j < height-1; j++) { 				
                    Color cor1 = new Color(imagem1.getRGB(i, j));
                    Color cor2 = new Color(imagem1.getRGB(i-1, j+1));
                    Color cor3 = new Color(imagem1.getRGB(i-1, j-1));
                    res1 =  (cor1.getRed()-cor2.getRed())*(cor1.getRed()-cor2.getRed());
                    res2 = (cor1.getRed()-cor3.getRed())*(cor1.getRed()-cor3.getRed());
                    res1 = res1+res2;
                    res1 = Math.pow(res1,0.5);
                    setaPixel = (int)res1;
                    if(setaPixel>255)setaPixel=255;
                    if(setaPixel<0)setaPixel=0;
                    Color color = new Color(setaPixel, setaPixel, setaPixel);
                    imageAux.setRGB(i, j, color.getRGB());
            }
        }
        imagem1 = imageAux;
        ImageIcon icon = new ImageIcon(imagem1);
        jLabel1.setIcon(icon);
        this.imageUpdate(imagem1, ALLBITS, 0, 0, width, height);
    }//GEN-LAST:event_jMenuItem6ActionPerformed

    private void jMenuItem7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem7ActionPerformed
         int width = imagem1.getWidth();
	int height = imagem1.getHeight(),red,green,blue;
	for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) { 				
                Color cor = new Color(imagem1.getRGB(i, j));
		red = cor.getRed()-10;
                if(red <0) red =0;
                green = cor.getGreen()-10;
                if(green <0) green = 0;
                blue = cor.getBlue()-10;
                if(blue<0)blue=0;
                Color color = new Color(red, green, blue);
                    
		imagem1.setRGB(i, j, color.getRGB());
	    }
        }
        this.imageUpdate(imagem1, ALLBITS, 0, 0, width, height);
    }//GEN-LAST:event_jMenuItem7ActionPerformed
    private void calculaTonsDeCinza(int modo){
        int width = imagem1.getWidth();
	int height = imagem1.getHeight();
        int y;
	for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) { 				
                Color cor = new Color(imagem1.getRGB(i, j)); 				//a cor inversa é dado por 255 menos o valor de cada canal 				
                y = (int) (0.299 * (int)(cor.getRed()) + 
                        0.587 * (int)(cor.getGreen()) +  
                        0.114 * (int) (cor.getBlue()) );
                if(modo == 0){
                    if(y<128)y=0;
                    else y=255;
                }
		Color color = new Color(y, y, y);
		imagem1.setRGB(i, j, color.getRGB());
	    }
        }
        this.imageUpdate(imagem1, ALLBITS, 0, 0, width, height);
    }
   
        
    
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
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new NewJFrame().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenu Afinamento;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JMenuItem jMenuItem4;
    private javax.swing.JMenuItem jMenuItem5;
    private javax.swing.JMenuItem jMenuItem6;
    private javax.swing.JMenuItem jMenuItem7;
    // End of variables declaration//GEN-END:variables
}

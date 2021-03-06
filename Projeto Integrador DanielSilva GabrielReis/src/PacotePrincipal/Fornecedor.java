package PacotePrincipal;
// Generated 03/04/2013 16:45:21 by Hibernate Tools 3.2.1.GA


import java.util.HashSet;
import java.util.Set;

/**
 * Fornecedor generated by hbm2java
 */
public class Fornecedor  implements java.io.Serializable {


     private int codfornecedor;
     private Endereco endereco;
     private String nome;
     private String cpf;
     private String cnpj;
     private int numendereco;
     private String telefone;
     private Set compras = new HashSet(0);

    public Fornecedor() {
    }

	
    public Fornecedor(int codfornecedor, Endereco endereco, String nome, int numendereco) {
        this.codfornecedor = codfornecedor;
        this.endereco = endereco;
        this.nome = nome;
        this.numendereco = numendereco;
    }
    public Fornecedor(int codfornecedor, Endereco endereco, String nome, String cpf, String cnpj, int numendereco, String telefone, Set compras) {
       this.codfornecedor = codfornecedor;
       this.endereco = endereco;
       this.nome = nome;
       this.cpf = cpf;
       this.cnpj = cnpj;
       this.numendereco = numendereco;
       this.telefone = telefone;
       this.compras = compras;
    }
   
    public int getCodfornecedor() {
        return this.codfornecedor;
    }
    
    public void setCodfornecedor(int codfornecedor) {
        this.codfornecedor = codfornecedor;
    }
    public Endereco getEndereco() {
        return this.endereco;
    }
    
    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }
    public String getNome() {
        return this.nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCpf() {
        return this.cpf;
    }
    
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public String getCnpj() {
        return this.cnpj;
    }
    
    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }
    public int getNumendereco() {
        return this.numendereco;
    }
    
    public void setNumendereco(int numendereco) {
        this.numendereco = numendereco;
    }
    public String getTelefone() {
        return this.telefone;
    }
    
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    public Set getCompras() {
        return this.compras;
    }
    
    public void setCompras(Set compras) {
        this.compras = compras;
    }




}



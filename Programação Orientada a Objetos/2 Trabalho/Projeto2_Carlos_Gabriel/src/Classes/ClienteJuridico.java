/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

import java.util.Calendar;
import java.util.Date;


/**
 *
 * @author Carlos Gabriel Silva Stedile
 */
public class ClienteJuridico extends Cliente
{
    private String cnpjCli;
    private float limiteCredito;
    private int statusCliente;
    private Date clienteDesde;
    //Construtor
    public ClienteJuridico(int codigo, String nome, String cnpj, float limCred, int sttsCl, Date clDesde) 
    {
        super(codigo, nome);
        cnpjCli = cnpj;
        limiteCredito = limCred;
        statusCliente = sttsCl;
        clienteDesde = clDesde;
    }
    
    /*--- Getters e Setters ---*/
    public String getCnpjCli() {
        return cnpjCli;
    }
    
    public void setCnpjCli(String cnpjCli) {
        this.cnpjCli = cnpjCli;
    }

    public float getLimiteCredito() {
        return limiteCredito;
    }

    public void setLimiteCredito(float limiteCredito) {
        this.limiteCredito = limiteCredito;
    }

    public int getStatusCliente() {
        return statusCliente;
    }

    public void setStatusCliente(int statusCliente) {
        this.statusCliente = statusCliente;
    }

    public Date getClienteDesde() {
        return clienteDesde;
    }

    public void setClienteDesde(Date clienteDesde) {
        this.clienteDesde = clienteDesde;
    }
    /*--- Getters e Setters ---*/
    
    @Override
    public String toString()
    {
        Calendar cal = Calendar.getInstance();
        cal.setTime(clienteDesde);
        int ano = cal.get(Calendar.YEAR);
        int mes = cal.get(Calendar.MONTH);
        int dia = cal.get(Calendar.DAY_OF_MONTH);
        return "Cliente: " + super.getNomeCli() + "\n\tCodigo:" + super.getCodigoCli() +
                "\tTipo:" + statusCliente + "\tCNPJ:" + cnpjCli + "\tLimite de Credito:" + limiteCredito + "\t Cliente desde:" + dia + "/" + (mes + 1) + "/" + ano;
    }
}

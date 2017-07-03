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
public class ClienteFisico extends Cliente
{
    private String cpfCli;
    private float limiteCredito;
    private int statusCliente;
    private Date clienteDesde;
    
    //Construtor
    public ClienteFisico(int codigo, String nome, String cpf, float limCred, int sttsCl, Date clDesde)
    {
        super(codigo, nome);
        cpfCli = cpf;
        limiteCredito = limCred;
        statusCliente = sttsCl;
        clienteDesde = clDesde;
    }

    /*--- Getters e Setters ---*/
    public String getCpfCli() {
        return cpfCli;
    }

    public void setCpfCli(String cpfCli) {
        this.cpfCli = cpfCli;
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
                "\tTipo:" + statusCliente + "\tCPF:" + cpfCli + "\tLimite de Credito:" + limiteCredito + "\t Cliente desde:" + dia + "/" + (mes + 1) + "/" + ano;
    }
}

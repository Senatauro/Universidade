/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

/**
 *
 * @author Carlos Gabriel Silva Stedile
 */
public abstract class Cliente 
{
    private int codigoCli;
    private String nomeCli;
    Endereco end;
    
    Cliente(int codigo, String nome)
    {
        codigoCli = codigo;
        nomeCli = nome;
    }
    
    @Override
    public String toString()
    {
        return "Nome do Cliente:" + getNomeCli() + "   codigo: " + getCodigoCli(); 
    }
    
    /*--- Getters ---*/
    public int getCodigoCli() {
        return codigoCli;
    }

    public String getNomeCli() {
        return nomeCli;
    }
    /*--- Getters ---*/
}

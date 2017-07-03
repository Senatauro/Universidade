/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Classes;

import java.util.ArrayList;
import java.util.Date;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author Carlos Gabriel Silva Stedile
 */
public class Cadastro 
{
    private static ArrayList<ClienteJuridico> listaClJur = new ArrayList<ClienteJuridico>();
    private static ArrayList<ClienteFisico> listaClFis = new ArrayList<ClienteFisico>();
    
    //Adiciona o cadastro na lista declarada acima
    //Retorno atual void, colocar para retornar bool, true se deu certo, false se deu errado
    public static void AdicionarCadastro(int tipo, int cod, String nome, String CP, float limCredito, int statusCliente, Date clienteDesde)
    {
        if(tipo == 1)
        {
            ClienteFisico clFis = new ClienteFisico(cod, nome, CP, limCredito, statusCliente, clienteDesde);
            for(ClienteFisico fi : listaClFis)
            {
                if(fi.getCodigoCli() == cod)
                {
                    JOptionPane.showMessageDialog(new JFrame(), "Já existe usuario cadastrado com esse código", "Cadastros",JOptionPane.WARNING_MESSAGE);
                    return;
                }
            }
            listaClFis.add(clFis);
            //System.out.println(clFis.toString());
        }
        else if(tipo == 2)
        {
            ClienteJuridico clJur = new ClienteJuridico(cod, nome, CP, limCredito, statusCliente, clienteDesde);
            for(ClienteJuridico ju : listaClJur)
            {
                if(ju.getCodigoCli() == cod)
                {
                    JOptionPane.showMessageDialog(new JFrame(), "Já existe usuario cadastrado com esse código", "Cadastros",JOptionPane.WARNING_MESSAGE);
                    return;
                }
            }
            listaClJur.add(clJur);
        }
    }
    
    public static String ListarCadastros(int tipo)
    {
        String cadastros = "";
        if(tipo == 1)
        {
            for(ClienteFisico cad : listaClFis)
            {
                cadastros += cad.toString() + "\n";
                System.out.println(cadastros);
            }
        }
        else if(tipo == 2)
        {
            for(ClienteJuridico cad : listaClJur)
            {
                cadastros += cad.toString() + "\n";
            }
        }
        if(cadastros != "")
            return cadastros;
        else
            return "Nenhum usuario cadastrado";
    }
    public static Object ListarCadastros(int tipo, int codCl)
    {
        Object cadastro = null;
        if(tipo == 1)
        {
            for(ClienteFisico cad : listaClFis)
            {
                if(cad.getCodigoCli() == codCl)
                {
                    cadastro = cad;
                    break;
                }
            }
        }
        else if(tipo == 2)
        {
            for(ClienteJuridico cad : listaClJur)
            {
                if(cad.getCodigoCli() == codCl)
                {
                    cadastro = cad;
                    break;
                }
            }
        }
        if(cadastro != null)
            return cadastro;
        else
            return null;
    }
    
    public static boolean ExcluirCadastro(int tipo, int codigo)
    {
        if(tipo == 1)
            for(int i = 0; i < listaClFis.size(); i++)
            {
                if(listaClFis.get(i).getCodigoCli() == codigo)
                {
                    listaClFis.remove(i);
                    return true;
                }
            }
        else if(tipo == 2)
            for(int i = 0; i < listaClJur.size(); i++)
            {
                if(listaClJur.get(i).getCodigoCli() == codigo)
                {
                    listaClJur.remove(i);
                    return true;
                }
            }
        return false;
    }
    
    public static Object ProximoCadastroOuAnterior(int tipo, int codigo, boolean anterior)
    {
        if(tipo == 1)   //Checa o tipo de cliente
            for(int i = 0; i < listaClFis.size(); i++)//Faz o for
            {
                if(listaClFis.get(i).getCodigoCli() == codigo)  //Checa o cliente na posição i se possui o mesmo codigo que o do parametro
                    if(!anterior)   //Caso sim checa se o parametro anterior é verdade
                        if(listaClFis.size() > (i + 1))   //Caso não seja checa se a posição i + 1 ainda existe dentro da lista
                            return listaClFis.get(i+1); //Retorna a posição i + 1
                        else                            //Caso não exista
                            return listaClFis.get(0);   //Retorna a posição inicial
                    else            //Caso o parametro anterior seja verdade
                        if(0 <= (i - 1))                  // Checa se a posição i - 1 existe dentro da lista
                            return listaClFis.get(i-1); //retorna a posição i - 1
                        else                            //Caso não exista
                            return listaClFis.get(listaClFis.size() - 1);   //retorna a ultima posição da lista
            }
        else if(tipo == 2) // Mesma coisa que explicado em cima, só que agora é pro cliente juridico
            for(int i = 0; i < listaClJur.size(); i++)//Faz o for
            {
                if(listaClJur.get(i).getCodigoCli() == codigo)  //Checa o cliente na posição i se possui o mesmo codigo que o do parametro
                    if(!anterior)   //Caso sim checa se o parametro anterior é verdade
                        if(listaClJur.size() > (i + 1))   //Caso não seja checa se a posição i + 1 ainda existe dentro da lista
                            return listaClJur.get(i+1); //Retorna a posição i + 1
                        else                            //Caso não exista
                            return listaClJur.get(0);   //Retorna a posição inicial
                    else            //Caso o parametro anterior seja verdade
                        if(0 <= (i - 1))                  // Checa se a posição i - 1 existe dentro da lista
                            return listaClJur.get(i-1); //retorna a posição i - 1
                        else                            //Caso não exista
                            return listaClJur.get(listaClJur.size() - 1);   //retorna a ultima posição da lista
            }
        return null;
    }
}

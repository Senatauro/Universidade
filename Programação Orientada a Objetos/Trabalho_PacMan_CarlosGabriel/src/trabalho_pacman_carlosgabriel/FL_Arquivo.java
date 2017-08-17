/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author gabriel
 */

//Script para mexer com arquivos
class FL_Arquivo 
{
    String endereco;
    PrintWriter saida;
    BufferedReader entrada;
    
    //Cria algo para manipular arquivo
    public FL_Arquivo(String endereco) throws IOException
    {
        this.endereco = endereco;
        File arquivo = new File(endereco);
        System.out.println(endereco);
        if(!arquivo.exists())
        {
            arquivo.createNewFile();
            System.out.println("entrou na craicao de arquivo");
        }
        this.entrada = new BufferedReader(new FileReader(endereco));
        this.saida = new PrintWriter(new BufferedWriter(new FileWriter(endereco, true)));
    }
    
    //Usar o objeto criado para ler uma linha no arquivo
    public String LeLinha() throws IOException
    {
        String linha = entrada.readLine();
        if(linha == null)
            return "";
        return linha;
    }
    
    //Usar o objeto criado para ler uma linha especifica no arquivo
    public String LeLinha(int numeroDaLinha) throws IOException
    {
        entrada.close();
        this.entrada = new BufferedReader(new FileReader(endereco));
        String linha = null;
        int i;
        for(i = 0; i < numeroDaLinha; i++)
        {
            linha = entrada.readLine();
        }
        return linha;
    }
    
    //Usar o objeto criado para escrever no arquivo
    public void Escreve(String texto) throws IOException
    {
        if(saida == null)
            this.saida = new PrintWriter(new BufferedWriter(new FileWriter(endereco, true)));
        saida.print(texto + "\n");
    }
    
    //Usar o objeto criado para salvar arquivo
    public void Salvar() throws IOException
    {
        saida.close();
        this.saida = new PrintWriter(new BufferedWriter(new FileWriter(endereco, true)));
    }
    
    //Fechar os streams
    public void Fechar() throws IOException
    {
        saida.close();
        entrada.close();
    }
}

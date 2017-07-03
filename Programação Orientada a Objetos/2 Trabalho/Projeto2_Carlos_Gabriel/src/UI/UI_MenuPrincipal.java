/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package UI;

import java.awt.ComponentOrientation;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;

/**
 *
 * @author cgsste
 */
public class UI_MenuPrincipal extends JFrame
{
    //Referencia a janelinha aberta
    public static UI_Cadastro ui;
    JPanel painel;
    JMenuBar barraMenu;
    JMenu menu_cadastro, menu_consultas, menu_relatorios, menu_sobre, menu_ajuda;
    JMenuItem menCad_endereco, menCad_clFis, menCad_clJur, menCad_sair;
    Action ac_endereco, ac_clientesFis, ac_clientesJur, ac_sair, ac_sobre;
    
    public UI_MenuPrincipal()
    {
        /*--- Criação do Menu ---*/
        barraMenu = new JMenuBar();
        menu_cadastro = new JMenu("Cadastro");
        menu_consultas = new JMenu("Consultas");
        menu_relatorios = new JMenu("Relatorios");
        menu_sobre = new JMenu("Sobre");
        menu_ajuda = new JMenu("Ajuda");
        /*--- Criação do Menu ---*/
        
        /*--- Criação das opções do menu ---*/
        menCad_endereco = new JMenuItem("Endereço");
        menCad_clFis = new JMenuItem("Clientes - Física");
        menCad_clJur = new JMenuItem("Clientes - Juridica");
        menCad_sair = new JMenuItem("Sair");
        /*--- Criação das opções do menu ---*/
        
        /*--- Criação das ações ---*/
        ac_endereco = new AbstractAction() 
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                System.out.println("Ainda não faz nada");
            }
        };
        ac_clientesFis = new AbstractAction() 
        {
            //Caso tenha outra janela aberta, fecha aquela janela e abre essa
            //Caso tenha uma janela do mesmo tipo, não faz nada
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(ui == null)
                    ui = new UI_Cadastro("Física", "CPF");
                else if(ui.getTitle().endsWith("Juridica"))
                {
                    ui.FecharJanela();
                    ui = new UI_Cadastro("Física", "CPF");
                }
            }
        };
        ac_clientesJur = new AbstractAction()
        {
            //Caso tenha outra janela aberta, fecha aquela janela e abre essa
            //Caso tenha uma janela do mesmo tipo, não faz nada
            @Override
            public void actionPerformed(ActionEvent ae)
            {
                if(ui == null)
                    ui = new UI_Cadastro("Jurídica", "CNPJ");
                else if(ui.getTitle().endsWith("Física"))
                {
                    ui.FecharJanela();
                    ui = new UI_Cadastro("Jurídica", "CNPJ");
                }
            }
        };
        ac_sair = new AbstractAction() 
        {
            @Override
            public void actionPerformed(ActionEvent e) 
            {
                FecharJanela();
            }
        };
        /*--- Criação das ações ---*/
        
        
        /*--- Adicionando os botões nas opções menu ---*/
        menu_cadastro.add(menCad_endereco);
        menu_cadastro.add(menCad_clFis);
        menu_cadastro.add(menCad_clJur);
        menu_cadastro.add(menCad_sair);
        /*--- Adicionando os botões nas opções menu ---*/
        
        /*--- Adicionando as ações nas opções do menu ---*/
        menCad_clFis.addActionListener(ac_clientesFis);
        menCad_clJur.addActionListener(ac_clientesJur);
        menCad_sair.addActionListener(ac_sair);
        /*--- Adicionando as ações nas opções do menu ---*/
        
        /*--- Colocando menu ---*/
        super.setJMenuBar(barraMenu);        
        barraMenu.add(menu_ajuda);
        barraMenu.add(menu_sobre);
        barraMenu.add(menu_relatorios);
        barraMenu.add(menu_consultas);
        barraMenu.add(menu_cadastro);
        barraMenu.setComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);
        /*--- Colocando menu ---*/
        
        //Criação do painel
        painel = new JPanel();
        
        super.add(painel);
        
        /*--- Pegando tamanho da tela ---*/
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int width = (int)screenSize.getWidth();
        int height = (int)screenSize.getHeight();
        /*--- Pegando tamanho da tela ---*/
        
        //Configurações finais
        super.setTitle("Sistema de Controle de Clientes");
        super.setSize(width, height);
        super.setLocationRelativeTo(null);
        super.setDefaultCloseOperation(EXIT_ON_CLOSE);
        super.setVisible(true);
        
    }
    
    void FecharJanela()
    {
        this.dispose();
    }
}

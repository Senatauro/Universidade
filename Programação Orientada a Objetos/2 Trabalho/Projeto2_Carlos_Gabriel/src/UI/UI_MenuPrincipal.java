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
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 *
 * @author Carlos Gabriel Silva Stedile
 */
public class UI_MenuPrincipal extends JFrame
{
    //Referencia a janelinha aberta
    public static UI_Cadastro ui;
    JPanel painel;
    JMenuBar barraMenu;
    JMenu menu_cadastro, menu_consultas, menu_relatorios, menu_sobre, menu_ajuda;
    JMenuItem menCad_endereco, menCad_clFis, menCad_clJur, menCad_sair, menSob_info;
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
        
        /*--- Adicionando hotkeys nas opções principais ---*/
        menu_cadastro.setMnemonic('C');
        menu_consultas.setMnemonic('O');
        menu_relatorios.setMnemonic('R');
        menu_sobre.setMnemonic('S');
        menu_ajuda.setMnemonic('A');
        /*--- Adicionando hotkeys nas opções principais ---*/
                
        /*--- Criação das opções do menu ---*/
        menCad_endereco = new JMenuItem("Endereço", new ImageIcon("Imagens/1-incluir.png"));
        menCad_clFis = new JMenuItem("Clientes - Física", new ImageIcon("Imagens/17-historico.png"));
        menCad_clJur = new JMenuItem("Clientes - Juridica", new ImageIcon("Imagens/12-informacao.png"));
        menCad_sair = new JMenuItem("Sair", new ImageIcon("Imagens/20-sair.png"));
        menSob_info = new JMenuItem("Informações");
        /*--- Criação das opções do menu ---*/
        
        /*--- Adicionando hotkeys nas opções do menu de cadastro ---*/
        menCad_endereco.setMnemonic('E');
        menCad_clFis.setMnemonic('F');
        menCad_clJur.setMnemonic('J');
        menCad_sair.setMnemonic('S');
        /*--- Adicionando hotkeys nas opções do menu de cadastro ---*/
        
        /*--- Criação das ações ---*/
        ac_endereco = new AbstractAction() 
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                JOptionPane.showMessageDialog(new JFrame(), "Em desenvolvimento", "Mensagem", JOptionPane.INFORMATION_MESSAGE);
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
        
        ac_sobre = new AbstractAction() 
        {
            @Override
            public void actionPerformed(ActionEvent e) 
            {
                JOptionPane.showMessageDialog(null, "Segundo Trabalho de POO\n\nDesenvolvedor: Carlos Gabriel Silva Stédile", "Sobre", JOptionPane.INFORMATION_MESSAGE, new ImageIcon("Imagens/16-hm.png"));
            }
        };
        /*--- Criação das ações ---*/
        
        
        /*--- Adicionando os botões nas opções menu ---*/
        menu_cadastro.add(menCad_endereco);
        menu_cadastro.add(menCad_clFis);
        menu_cadastro.add(menCad_clJur);
        menu_cadastro.add(menCad_sair);
        
        menu_sobre.add(menSob_info);
        /*--- Adicionando os botões nas opções menu ---*/
        
        /*--- Adicionando as ações nas opções do menu ---*/
        menCad_clFis.addActionListener(ac_clientesFis);
        menCad_clJur.addActionListener(ac_clientesJur);
        menCad_sair.addActionListener(ac_sair);
        /*--- Adicionando as ações nas opções do menu ---*/
        
        //Adicionando as ações no sobre
        menSob_info.addActionListener(ac_sobre);
        
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

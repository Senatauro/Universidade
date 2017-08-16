/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package UI;

import Classes.Cadastro;
import Classes.ClienteFisico;
import Classes.ClienteJuridico;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

/**
 *
 * @author Carlos Gabriel Silva Stedile
 */
public class UI_Cadastro extends JFrame
{
    //Referencia ao JFrame
    JFrame ref;
    //Label
    private JLabel lab_codCl, lab_nomeCl, lab_cpCL, lab_limCredCl, lab_statusCl, lab_tempoCl;
    //Campos de texto
    private JTextField txtF_codCl, txtF_nomeCl, txtF_cpCl, txtF_limCredCl, txtF_tempoCl;
    //Combo box
    private JComboBox comb_statusCl;
    //Botoes
    private JButton bt_incluir, bt_listar, bt_excluir, bt_anterior, bt_proximo, bt_sair;
    //Barra de menu
    private JMenuBar barraMenu;
    //Menu
    private JMenu menu;
    //Itens do menu
    private JMenuItem men_incluir, men_listar, men_excluir, men_anterior, men_proximo, men_sair;
    //Paineis
    private JPanel painel1, painel2;
    //Ações
    private Action incluir, listar, excluir, anterior, proximo, sair;
    
    private KeyListener aga;
    
    public UI_Cadastro(String tipoDePessoa, String tipoDePessoa2)
    {
        ref = this;
        /*--- Criação dos Labels ---*/
        lab_codCl = new JLabel("Código:", SwingConstants.RIGHT);
        lab_nomeCl = new JLabel("Nome do Cliente:", SwingConstants.RIGHT);
        lab_cpCL = new JLabel(tipoDePessoa2 + ":", SwingConstants.RIGHT);
        lab_limCredCl = new JLabel("Limite de Crédito:", SwingConstants.RIGHT);
        lab_statusCl = new JLabel("Status:", SwingConstants.RIGHT);
        lab_tempoCl = new JLabel("Cliente desde:", SwingConstants.RIGHT);
        /*--- Criação dos Labels ---*/

        /*--- Criação dos TextField ---*/
        txtF_codCl = new JTextField();
        txtF_nomeCl = new JTextField();
        txtF_cpCl = new JTextField();
        txtF_limCredCl = new JTextField();
        txtF_tempoCl = new JTextField();
        /*--- Criação dos TextField ---*/
        
        /*--- Criação do comboBox ---*/
        String[] jota = {"Preferencial", "Ouro", "Prata", "Bronze"};
        comb_statusCl = new JComboBox(jota);
        /*--- Criação do comboBox ---*/
        
        /*--- Criação dos botoes ---*/
        bt_incluir = new JButton("Incluir", new ImageIcon("./Imagens/5-gravar.png"));
        bt_listar = new JButton("Listar", new ImageIcon("./Imagens/4-buscar.png"));
        bt_excluir = new JButton("Excluir", new ImageIcon("./Imagens/3-excluir.png"));
        bt_anterior = new JButton("Anterior", new ImageIcon("./Imagens/7-anterior.gif"));
        bt_proximo = new JButton("Proximo", new ImageIcon("./Imagens/8-proximo.gif"));
        bt_sair = new JButton("Sair", new ImageIcon("./Imagens/20-sair.png"));
        /*--- Criação dos botoes ---*/
        
        /*--- Criação do menu ---*/
        barraMenu = new JMenuBar();
        menu = new JMenu("Opções");
        men_incluir = new JMenuItem("Incluir", new ImageIcon("./Imagens/5-gravar.png"));
        men_listar = new JMenuItem("Listar", new ImageIcon("./Imagens/4-buscar.png"));
        men_excluir = new JMenuItem("Excluir", new ImageIcon("./Imagens/3-excluir.png"));
        men_anterior = new JMenuItem("Anterior", new ImageIcon("./Imagens/7-anterior.gif"));
        men_proximo = new JMenuItem("Proximo", new ImageIcon("./Imagens/8-proximo.gif"));
        men_sair = new JMenuItem("Sair", new ImageIcon("./Imagens/20-sair.png"));
        /*--- Criação do menu ---*/
        
        /*--- Criação dos Paineis ---*/
        painel1 = new JPanel();
        painel2 = new JPanel();
        /*--- Criação dos Paineis ---*/
        
        /*--- Definição das Ações ---*/
        incluir = new AbstractAction() 
        {
            /*--- Codigo de incluir
                  Pega todos os dados dos campos de textos
                  E manda adicionar para a função de adicionar cadastos
                  Baseado no nome do titulo ---*/
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                try 
                {
                    DateFormat formatter = new SimpleDateFormat("dd/MM/yy");
                    Date data = FormataData(txtF_tempoCl.getText());
                    int codigo = Integer.parseInt(txtF_codCl.getText());
                    float limiteCredito = Float.parseFloat(txtF_limCredCl.getText());
                    System.out.println(comb_statusCl.getSelectedIndex());
                    Cadastro.AdicionarCadastro(ref.getTitle().endsWith("Física") ? 1 : 2, codigo, txtF_nomeCl.getText(), txtF_cpCl.getText(), limiteCredito, comb_statusCl.getSelectedIndex(), data);
                }
                catch (Exception ex)
                {
                    Logger.getLogger(UI_Cadastro.class.getName()).log(Level.SEVERE, null, ex);
                }
                ZerarCampos();
            }
        };
        listar = new AbstractAction() 
        {
            /*--- Função de listar os cadastros
                  Pode listar todos os cadastros de um tipo(Fisico ou Juridico)
                  Ou pode carregar somente um cadastro e mostrado na propria janela 
                  Depende se o campo de codigo esta preenchido ou não ---*/
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(txtF_codCl.getText().length() == 0)
                {
                    String cadastros = "";
                    if(ref.getTitle().endsWith("Física"))
                        cadastros = Cadastro.ListarCadastros(1);
                    else if(ref.getTitle().endsWith("Jurídica"))
                        cadastros = Cadastro.ListarCadastros(2);
                    JFrame cadastrosFeitos = new JFrame();
                    JTextArea aga = new JTextArea(cadastros);
                    aga.setEditable(false);
                    JScrollPane sp = new JScrollPane(aga);
                    cadastrosFeitos.setSize(800, 400);
                    cadastrosFeitos.add(sp);
                    cadastrosFeitos.setTitle("Clientes Cadastrados");
                    cadastrosFeitos.setLocationRelativeTo(null);
                    cadastrosFeitos.setDefaultCloseOperation(DISPOSE_ON_CLOSE);                //JOptionPane.showMessageDialog(teste, sp, "Cadastros",JOptionPane.INFORMATION_MESSAGE);
                    cadastrosFeitos.setVisible(enabled);
                }
                //Caso a caixa de texto do codigo não esteja vazia, colocar o cadastro exato na tela
                else
                {
                    int codigo = Integer.parseInt(txtF_codCl.getText());
                    if(ref.getTitle().endsWith("Física"))
                    {
                        ClienteFisico cadastro = (ClienteFisico)Cadastro.ListarCadastros(1, codigo);
                        if(cadastro == null)
                        {
                            JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                            return;
                        }
                        txtF_cpCl.setText(cadastro.getCpfCli().toString());
                        comb_statusCl.setSelectedIndex(cadastro.getStatusCliente());
                        txtF_limCredCl.setText(Float.toString(cadastro.getLimiteCredito()));
                        txtF_nomeCl.setText(cadastro.getNomeCli());
                        Calendar cal = Calendar.getInstance();
                        cal.setTime(cadastro.getClienteDesde());
                        int ano = cal.get(Calendar.YEAR);
                        int mes = cal.get(Calendar.MONTH);
                        int dia = cal.get(Calendar.DAY_OF_MONTH);
                        txtF_tempoCl.setText(Integer.toString(dia) + "/" + Integer.toString(mes + 1) + "/" + Integer.toString(ano));
                    }
                    else
                    {
                        System.out.println("entrou aqui");
                        ClienteJuridico cadastro = (ClienteJuridico)Cadastro.ListarCadastros(2, codigo);
                        if(cadastro == null)
                        {
                            JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                            return;
                        }
                        txtF_cpCl.setText(cadastro.getCnpjCli());
                        comb_statusCl.setSelectedIndex(cadastro.getStatusCliente());
                        txtF_limCredCl.setText(Float.toString(cadastro.getLimiteCredito()));
                        txtF_nomeCl.setText(cadastro.getNomeCli());
                        Calendar cal = Calendar.getInstance();
                        cal.setTime(cadastro.getClienteDesde());
                        int ano = cal.get(Calendar.YEAR);
                        int mes = cal.get(Calendar.MONTH);
                        int dia = cal.get(Calendar.DAY_OF_MONTH);
                        txtF_tempoCl.setText(Integer.toString(dia) + "/" + Integer.toString(mes + 1) + "/" + Integer.toString(ano));
                    }
                }
            }
        };
        
        excluir = new AbstractAction() 
        {
            /*--- Função de excluir o cadastro
                  Exclui um cadastro especifico dependendo do tipo da janela(Fisica ou Juridica)
                  Caso cadastro exista, é deletado e informa que a operação deu certo
                  Caso contrario fala que o cadastro nao existe ou que não foi informado codigo ---*/
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(txtF_codCl.getText().length() > 0)
                {
                    if(Cadastro.ExcluirCadastro( ref.getTitle().endsWith("Física") ? 1 : 2, Integer.parseInt(txtF_codCl.getText())))
                        JOptionPane.showMessageDialog(new JFrame(), "Cadastro Excluido com sucesso", "Cadastros",JOptionPane.INFORMATION_MESSAGE);
                    else
                        JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                }
                else
                    JOptionPane.showMessageDialog(new JFrame(), "Impossivel excluir vazio\nPor favor declare um codigo", "Cadastros",JOptionPane.ERROR_MESSAGE);
            }
        };
        
        anterior = new AbstractAction() 
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(txtF_codCl.getText().length() > 0)
                    if(ref.getTitle().endsWith("Física"))
                    {
                        ClienteFisico cadastro = (ClienteFisico)Cadastro.ProximoCadastroOuAnterior(1, Integer.parseInt(txtF_codCl.getText()), true);
                        if(cadastro == null)
                        {
                            JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                            return;
                        }
                        txtF_codCl.setText(Integer.toString(cadastro.getCodigoCli()));
                        txtF_cpCl.setText(cadastro.getCpfCli());
                        txtF_limCredCl.setText(Float.toString(cadastro.getLimiteCredito()));
                        txtF_nomeCl.setText(cadastro.getNomeCli());
                        comb_statusCl.setSelectedIndex(cadastro.getStatusCliente());
                        Calendar cal = Calendar.getInstance();
                        cal.setTime(cadastro.getClienteDesde());
                        int ano = cal.get(Calendar.YEAR);
                        int mes = cal.get(Calendar.MONTH);
                        int dia = cal.get(Calendar.DAY_OF_MONTH);
                        txtF_tempoCl.setText(Integer.toString(dia) + "/" + Integer.toString(mes + 1) + "/" + Integer.toString(ano));                    
                    }
                    else if(ref.getTitle().endsWith("Jurídica"))
                    {
                        ClienteJuridico cadastro = (ClienteJuridico)Cadastro.ProximoCadastroOuAnterior(2, Integer.parseInt(txtF_codCl.getText()), true);
                        if(cadastro == null)
                        {
                            JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                            return;
                        }
                        txtF_codCl.setText(Integer.toString(cadastro.getCodigoCli()));
                        txtF_cpCl.setText(cadastro.getCnpjCli());
                        txtF_limCredCl.setText(Float.toString(cadastro.getLimiteCredito()));
                        txtF_nomeCl.setText(cadastro.getNomeCli());
                        comb_statusCl.setSelectedIndex(cadastro.getStatusCliente());
                        Calendar cal = Calendar.getInstance();
                        cal.setTime(cadastro.getClienteDesde());
                        int ano = cal.get(Calendar.YEAR);
                        int mes = cal.get(Calendar.MONTH);
                        int dia = cal.get(Calendar.DAY_OF_MONTH);
                        txtF_tempoCl.setText(Integer.toString(dia) + "/" + Integer.toString(mes + 1) + "/" + Integer.toString(ano));                    
                    }    
            }
        };
        
        proximo = new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(txtF_codCl.getText().length() > 0)
                    if(ref.getTitle().endsWith("Física"))
                    {
                        ClienteFisico cadastro = (ClienteFisico)Cadastro.ProximoCadastroOuAnterior(1, Integer.parseInt(txtF_codCl.getText()), false);
                        if(cadastro == null)
                        {
                            JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                            return;
                        }
                        txtF_codCl.setText(Integer.toString(cadastro.getCodigoCli()));
                        txtF_cpCl.setText(cadastro.getCpfCli());
                        txtF_limCredCl.setText(Float.toString(cadastro.getLimiteCredito()));
                        txtF_nomeCl.setText(cadastro.getNomeCli());
                        comb_statusCl.setSelectedIndex(cadastro.getStatusCliente());
                        Calendar cal = Calendar.getInstance();
                        cal.setTime(cadastro.getClienteDesde());
                        int ano = cal.get(Calendar.YEAR);
                        int mes = cal.get(Calendar.MONTH);
                        int dia = cal.get(Calendar.DAY_OF_MONTH);
                        txtF_tempoCl.setText(Integer.toString(dia) + "/" + Integer.toString(mes + 1) + "/" + Integer.toString(ano));                    
                    }
                    else if(ref.getTitle().endsWith("Jurídica"))
                    {
                        ClienteJuridico cadastro = (ClienteJuridico)Cadastro.ProximoCadastroOuAnterior(2, Integer.parseInt(txtF_codCl.getText()), false);
                        if(cadastro == null)
                        {
                            JOptionPane.showMessageDialog(new JFrame(), "Cadastro não existe", "Cadastros",JOptionPane.WARNING_MESSAGE);
                            return;
                        }
                        txtF_codCl.setText(Integer.toString(cadastro.getCodigoCli()));
                        txtF_cpCl.setText(cadastro.getCnpjCli());
                        txtF_limCredCl.setText(Float.toString(cadastro.getLimiteCredito()));
                        txtF_nomeCl.setText(cadastro.getNomeCli());
                        comb_statusCl.setSelectedIndex(cadastro.getStatusCliente());
                        Calendar cal = Calendar.getInstance();
                        cal.setTime(cadastro.getClienteDesde());
                        int ano = cal.get(Calendar.YEAR);
                        int mes = cal.get(Calendar.MONTH);
                        int dia = cal.get(Calendar.DAY_OF_MONTH);
                        txtF_tempoCl.setText(Integer.toString(dia) + "/" + Integer.toString(mes + 1) + "/" + Integer.toString(ano));                    
                    }    
            }
        };
        
        sair = new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                FecharJanela();
            }
        };
        /*--- Definição das Ações ---*/
        
        /*--- Listeners dos botões ---*/
        bt_incluir.addActionListener(incluir);
        
        bt_listar.addActionListener(listar);
        
        bt_excluir.addActionListener(excluir);
        
        bt_anterior.addActionListener(anterior);
                
        bt_proximo.addActionListener(proximo);
        
        bt_sair.addActionListener(sair);
        /*--- Listeners dos botões ---*/
        
        /*--- Listeners dos botões do menu ---*/
        /*bt_incluir.addActionListener(incluir);
        bt_listar.addActionListener(listar);
        bt_excluir.addActionListener(excluir);
        bt_anterior.addActionListener(anterior);
        bt_proximo.addActionListener(proximo);
        bt_sair.addActionListener(sair);*/
        /*--- Listeners dos botões do menu ---*/
        
        //Coloca o painel1 como grid de 6 linhas por 2 colunas
        painel1.setLayout(new GridLayout(6,2));
        
        //Coloca o painel2 como grid de 1 linha por 6 colunas
        painel2.setLayout(new GridLayout(1,6));
        
        /*--- Adicionando os labels e textbox ao painel1 ---*/
        painel1.add(this.lab_codCl);
        painel1.add(this.txtF_codCl);
        painel1.add(this.lab_nomeCl);
        painel1.add(this.txtF_nomeCl);
        painel1.add(this.lab_cpCL);
        painel1.add(this.txtF_cpCl);
        painel1.add(this.lab_limCredCl);
        painel1.add(this.txtF_limCredCl);
        painel1.add(this.lab_statusCl);
        painel1.add(this.comb_statusCl);
        painel1.add(this.lab_tempoCl);
        painel1.add(this.txtF_tempoCl);
        /*--- Adicionando os labels e textbox ao painel1 ---*/
        
        /*--- Adicionando os menus ---*/
        super.setJMenuBar(this.barraMenu);
        barraMenu.add(this.menu);
        /*--- Adicionando os menus ---*/
        
        /*--- Adicionando os botões no menu ---*/
        menu.add(men_incluir);
        menu.add(men_listar);
        menu.add(men_excluir);
        menu.add(men_anterior);
        menu.add(men_proximo);
        menu.add(men_sair);
        /*--- Adicionando os botões no menu ---*/
        
        /*--- Adicioando botões ao painel2 ---*/
        painel2.add(this.bt_incluir);
        painel2.add(this.bt_listar);
        painel2.add(this.bt_excluir);
        painel2.add(this.bt_anterior);
        painel2.add(this.bt_proximo);
        painel2.add(this.bt_sair);        
        /*--- Adicioando botões ao painel2 ---*/
        
        /*--- Adicionando os paineis ao programa ---*/
        super.add(painel1, BorderLayout.CENTER);
        super.add(painel2, BorderLayout.SOUTH);
        /*--- Adicionando os paineis ao programa ---*/
        
        
        super.addWindowListener(new WindowAdapter()
        {
            @Override
            public void windowClosing(WindowEvent e)
            {
                UI_MenuPrincipal.ui = null;
            }
        });
        
        
        //Colocando painel principal como azul
        painel1.setBackground(Color.yellow);
        
        /*--- Configurações finais ---*/
        super.setTitle("Cadastro de Clientes - Pessoa " + tipoDePessoa);
        super.setSize(840, 240);
        super.setLocationRelativeTo(null);
        super.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        super.setVisible(true);
        /*--- Configurações finais ---*/
    }
    
    
    //Funções de ajuda
    void FecharJanela()
    {
        this.dispose();
    }
    
    Date FormataData(String data) throws Exception 
    {
        if (data == null || data.equals(""))
            return null;
        Date date = null;
        try 
        {
            DateFormat formatter = new SimpleDateFormat("dd/MM/yy");
            date = (Date)formatter.parse(data);
        } 
        catch (ParseException e) 
        {
            JOptionPane.showMessageDialog(new JFrame(), "Ensira a data nesse formato:\nDD/MM/AA", "Cadastros",JOptionPane.ERROR_MESSAGE);
            throw e;
        }
        return date;
	}
    
    void ZerarCampos()
    {
        txtF_codCl.setText("");
        txtF_nomeCl.setText("");
        txtF_cpCl.setText("");
        txtF_limCredCl.setText("");
        txtF_tempoCl.setText("");
    }
}

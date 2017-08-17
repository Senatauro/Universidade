/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import javax.swing.JFrame;

/**
 *
 * @author gabriel
 */
public class UI_Interface extends JFrame
{
    public UI_Interface()
    {
        this.add(new UI_Grafico());
        this.setLocationRelativeTo(null);
        this.setSize(1020,400);
        this.setResizable(false);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setTitle("Jogo Pacman");
        this.setVisible(true);
    }
}

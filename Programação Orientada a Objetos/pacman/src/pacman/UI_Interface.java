/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pacman;

import java.io.IOException;
import javax.swing.JFrame;

/**
 *
 * @author cgsste
 */
public class UI_Interface extends JFrame
{
    public UI_Interface() throws IOException
    {
		this.add(new UI_Grafico());
		this.setTitle("PacMan");
		this.setSize(504,540);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setResizable(false);
		this.setVisible(true);
    }
}

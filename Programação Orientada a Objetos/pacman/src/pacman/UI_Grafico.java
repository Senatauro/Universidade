/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pacman;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import javax.swing.JComponent;

/**
 *
 * @author cgsste
 */
public class UI_Grafico extends JComponent implements Runnable, KeyListener
{
    int[][] mat = new int[32][32];

    @SuppressWarnings("empty-statement")
    public UI_Grafico() throws IOException
    {
        int j = 0;
        BufferedReader br = new BufferedReader(new FileReader("teste.txt"));
        for(int i = 0; br.ready(); i++)
        {
            char linha = (char)br.read();
            System.out.print(linha);
            if(linha == '1')
                mat[i][j] = 1;
            if(linha == '\n' && j < 32)
            {
                j++;
                i = -1;
            }
//System.out.print(linha);
        }
        br.close();
    }
    @Override
    public void run() 
    {
        repaint();
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyTyped(KeyEvent ke) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyPressed(KeyEvent ke) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void keyReleased(KeyEvent ke) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
    public void paint(Graphics g)
    {
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, 528,528);
        g.setColor(Color.BLUE);
        for(int x = 0; x < 32; x++)
        {
            for(int y = 0; y < 32; y++)
            {
                if(mat[x][y] == 1)
                {
                    g.fillRect(x * 16, y * 16 , 16, 16);
                }
            }
        }
    }
}

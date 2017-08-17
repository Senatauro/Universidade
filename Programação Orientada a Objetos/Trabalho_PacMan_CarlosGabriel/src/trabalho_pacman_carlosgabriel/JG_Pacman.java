/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import java.awt.Color;
import java.awt.event.KeyEvent;

/**
 *
 * @author gabriel
 */

//Classe do pacman que extende da animação para dar vida ao pacman
public class JG_Pacman extends JG_Animacao
{
    private int velocidade;
    public boolean cima, baixo, direita, esquerda;
    private int pontos;
    
    public JG_Pacman(int x, int y)
    {
        super(x, y, Color.YELLOW);  //Posição aonde o pacman vai começar e a cor dele
        super.setBase(50);          //Tamanho da base
        super.setAltura(50);        //Tamanho da altura
        this.velocidade = 2;
        this.baixo = true;
        this.pontos = 0;
    }
    
    public void Reset()
    {
        this.pontos = 0;
    }
    
    public void setVelocidade(int vel)
    {
        this.velocidade = vel;
    }
    
    public void AdicionarPontos(int pontos)
    {
        this.pontos += pontos;
    }
    
    public int getPontos()
    {
        return this.pontos;
    }
    
    public void keyPressed(KeyEvent e)
    {
        int direcao = e.getKeyCode();
        if(direcao == KeyEvent.VK_LEFT)
	{
            setVelY(0);
            setVelX(-velocidade);
            cima = false;
            direita = false;
            baixo = false;
            esquerda = true;
        }
	else if(direcao == KeyEvent.VK_RIGHT)
	{
            if(mapa.getPermissao(getPosX(), getPosY()))
            {
		setVelY(0);
		setVelX(velocidade);
		cima = false;
		direita =true;
		baixo = false;
		esquerda = false;
            }
	}
        else if(direcao == KeyEvent.VK_UP)
	{
            setVelX(0);
            setVelY(-velocidade);
            cima = true;
            direita = false;
            baixo = false;
            esquerda = false;
	}
        else if(direcao == KeyEvent.VK_DOWN)
	{
            setVelX(0);
            setVelY(velocidade);
            cima = false;
            direita =false;
            baixo = true;
            esquerda = false;
        }
    }
}

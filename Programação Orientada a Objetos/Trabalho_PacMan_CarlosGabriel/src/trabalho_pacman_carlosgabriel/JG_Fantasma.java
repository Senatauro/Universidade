/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author gabriel
 */

//Controla o fantasminha
public class JG_Fantasma extends JG_Animacao
{
	private int velocidade;
	public int vertices;
	public int[] verticesX;
	public int[] verticesY;
	private JG_Movimento movimento;
        
	public JG_Fantasma(int x, int y, Color cor)
	{
		super(x, y, cor);
		verticesX = new int[9];
		verticesY = new int[9];
		setBase(50);
		setAltura(50);
		this.vertices = 9;
		atualizaVertices();
		movimento = new JG_Movimento(0);
		movimento.start();
		setVelX(movimento.getVelX());
		setVelY(movimento.getVelY());
	}

	public void setVelocidade(int x)
	{
		this.velocidade = x;
		movimento.setVelocidade(velocidade, velocidade);
	}

	public boolean getColisao(int px, int py)
	{
		if(px >= this.getPosX() && px <= (this.getPosX() + getBase()) && py >= this.getPosY() && py <=(this.getPosY() + this.getAltura()))
		{
				return true;
		}
		return false;
	}

        //O fantasma foi criado a mão por um macaco
        //Esses vertices são para pintar a parte de baixo do fantasma
	public void atualizaVertices()
	{
		verticesX[0] = getPosX();
		verticesY[0] = getPosY() + getBase()/2;
		verticesX[1] = 10 +getPosX();
		verticesY[1] = (this.getAltura()) + getPosY();
		verticesX[2] = 18 +getPosX();
		verticesY[2] = (this.getAltura()/2) + 10 +getPosY();
		verticesX[3] = 25 +getPosX();
		verticesY[3] = this.getAltura() +getPosY();
		verticesX[4] = 32 +getPosX();
		verticesY[4] = (this.getAltura()/2) + 10 +getPosY();
		verticesX[5] = 40 +getPosX();
		verticesY[5] = this.getAltura() +getPosY();
                verticesX[6] = 45 +getPosX();
		verticesY[6] = (this.getAltura()/2) + 10 +getPosY();
                verticesX[7] = 50 +getPosX();
		verticesY[7] = this.getAltura() +getPosY();
		verticesX[8] = this.getBase() +getPosX();
		verticesY[8] = (this.getAltura()/2 )+getPosY();
	}

        //Ele "randomiza" pra onde o fantasma vai andar
        //É chamado por uma thread pra redefinir movimento
        //Le os dados que a thread de movimento fornece e atualiza aqui
	public void atualizaMovimento()
	{
		setVelX(movimento.getVelX());
		setVelY(movimento.getVelY());
	}

}

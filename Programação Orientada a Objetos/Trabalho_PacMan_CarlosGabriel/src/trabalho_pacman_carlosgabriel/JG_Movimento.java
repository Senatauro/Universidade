/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;
import java.util.Random;
/**
 *
 * @author gabriel
 */

//Codigo usado para gerar o movimento aleatorio dos fantasmas
public class JG_Movimento extends Thread
{
	private int aleatorio;
	public int velocidadeX;
	public int velocidadeY;
	private int auxX;
	private int auxY;

	public JG_Movimento(int velocidade)
	{
		super();
		this.velocidadeX = velocidade;
		this.velocidadeY = velocidade;
	}

	public void setVelocidade(int velocidadeX, int velocidadeY)
	{
		this.velocidadeX = velocidadeX;
		this.auxX = velocidadeX;
		this.auxY = velocidadeY;
		this.velocidadeY = velocidadeY;
	}

	public int getVelX()
	{
		return this.velocidadeX;
	}

	public int getVelY()
	{
		return this.velocidadeY;
	}

	@Override
	public void run()
	{
		while(true)
		{
			try
			{
				Thread.sleep(500);
				aleatorio = new Random().nextInt(4);    //Totalmente aleatorio :D
				if(aleatorio == 0)
				{
					this.velocidadeY = 0;
					this.velocidadeX = -auxX;
				}
				else if(aleatorio == 1)
				{
					this.velocidadeX = 0;
					this.velocidadeY = -auxY;
				}
				else if(aleatorio ==2)
				{
					this.velocidadeY = auxY;
					this.velocidadeX = 0;
				}
				else if(aleatorio ==3)
				{
					this.velocidadeX = auxX;
					this.velocidadeY = 0;
				}
			}
			catch(InterruptedException ex)
			{
			}
		}
	}
}

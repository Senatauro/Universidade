/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import java.awt.Color;

/**
 *
 * @author gabriel
 */

//Codigo geral para todas as animações
public class JG_Animacao extends Thread 
{

    private int posX;
    private int posY;
    private int velX;
    private int velY;
    private int base;
    private int altura;
    private int limiteX = 1010 - base;
    private int limiteY = 310 - altura;
    private int inicioX = 10;
    private int inicioY = 10;
    private Color cor;
    public JG_Mapa mapa;

    public JG_Animacao(int px, int py, Color cor)
    {
        super("movimento"); //Nomeia a thead para movimento
        this.posX = px;
        this.posY = py;
        this.base = 10;
        this.altura = 10;
        this.cor = cor;
        this.start();       //Inicia a thread
        mapa = new JG_Mapa();
    }

    //Define os limites do mapa baseados nos valores (1010 -base) e (310 - altura)
    private void atualizaLimites() 
    {
        limiteX = 1010 - base;
        limiteY = 310 - altura;
        inicioX = 10;
        inicioY = 10;
    }

    public int getPosX() {
        return this.posX;
    }

    public int getPosY() {
        return this.posY;
    }

    public Color getCor() {
        return this.cor;
    }

    public int getBase() {
        return this.base;
    }

    public int getAltura() {
        return this.altura;
    }

    public void setCor(Color cor) {
        this.cor = cor;
    }

    public void setBase(int x) {
        this.base = x;
        atualizaLimites();
    }

    public void setAltura(int y) {
        this.altura = y;
        atualizaLimites();
    }

    public void setVelX(int x) {
        this.velX = x;
    }

    public void setVelY(int y) {
        this.velY = y;
    }

    public void setPos(int x, int y) {
        this.posX = x;
        this.posY = y;
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(50);
                moveX(velX);    //Move o treco na direção X com a velocidade velX
                moveY(velY);    //Move o treco na direção Y com a velocidade velY
            } catch (InterruptedException ex) {
            }
        }
    }

    
    public void atualizaMapa(JG_Mapa mapa) {
        this.mapa = mapa;
    }
    
    //Função para mover o objeto filho deste
    //Ex: Mover o fantasma(extendido dessa classe)
    public void moveX(int numero) {
        if (!((this.posX - 5 + numero > this.limiteX) || (this.posX + numero < this.inicioX))) {
            if (mapa.getPermissao(this.posX + numero, this.posY)) {
                this.posX += numero;
            }
        }
    }

    //Função para mover o objeto filho deste
    //Ex: Mover o fantasma(extendido dessa classe)
    public void moveY(int numero) {
        if (!(((this.posY - 5) + numero > this.limiteY) || (this.posY + numero < this.inicioY))) {
            if (mapa.getPermissao(this.posX, this.posY + numero)) {
                this.posY += numero;
            }
        }
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import javax.swing.JComponent;
import javax.swing.JOptionPane;

import java.awt.Graphics;
import java.awt.Color;
import java.awt.Font;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import java.io.IOException;

/**
 *
 * @author gabriel
 */
//Cuida de todo o grafico
public class UI_Grafico extends JComponent implements Runnable, KeyListener {

    Graphics g;
    private Font fonte;
    private JG_Pacman pacman;
    private JG_Abertura abertura;
    private JG_Mapa mapa;
    private TipoBloco superponto;
    private JG_Fantasma fantasma;
    private JG_Fantasma fantasma1;
    private JG_Fantasma fantasma2;
    private boolean jogando;
    private boolean ganhou;
    private Color corBloco;

    UI_Grafico() {

        mapa = new JG_Mapa();
        abertura = new JG_Abertura();
        abertura.start();
        corBloco = Color.GREEN;

        /*--- Cria pacman ---*/
        pacman = new JG_Pacman(mapa.getPosicaoXPacMan(), mapa.getPosicaoYPacMan());
        pacman.setVelocidade(10);
        /*--- Cria pacman ---*/

 /*--- Cria fantasmas ---*/
        fantasma = new JG_Fantasma(mapa.getPosicaoXFantasma(), mapa.getPosicaoYFantasma(), Color.WHITE);
        fantasma.setVelocidade(10);

        fantasma1 = new JG_Fantasma(mapa.getPosicaoXFantasma(), mapa.getPosicaoYFantasma(), Color.BLUE);
        fantasma1.setVelocidade(10);

        fantasma2 = new JG_Fantasma(mapa.getPosicaoXFantasma(), mapa.getPosicaoYFantasma(), Color.RED);
        fantasma2.setVelocidade(10);
        /*--- Cria fantasmas ---*/

        //Seta referencia do mapa para a instancia dos objetos criados
        pacman.atualizaMapa(mapa);  //Serve para saber se o pacman pode andar naquela parte do mapa e se esta em cima de um ponto
        fantasma.atualizaMapa(mapa); //Serve para saber se o pacman pode andar naquela parte do mapa 

        fantasma1.atualizaMapa(mapa);
        fantasma2.atualizaMapa(mapa);

        fonte = new Font("TimesRoman", Font.PLAIN, 20); //Define a fonte utilizada
        new Thread(this).start();   //Cria uma thread para esse codigo manter o mapa atualizado
        addKeyListener(this);
        setFocusable(true);
        jogando = true;
        ganhou = false;
    }

    //Quando a thread é inicializada, essa funcao paint é chamada a cada iteracao
    public void paint(Graphics g) {
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, 1020, 400);//preenche a tela com a cor preta
        g.setColor(Color.BLUE);
        g.drawRoundRect(10, 10, 1000, 300, 20, 20);//Desenha quadrado limitador na tela 
        desenhaPacMan(g);
        desenhaMapa(g);
        desenhaFantasma(g);
        desenhaPontos(g);
        if (!jogando && ganhou)//Se o jogador ganhou
        {
            g.setColor(Color.GREEN);
            g.setFont(fonte);
            g.drawString("Parabéns, Você Ganhou !!!", 400, 160);
            pacman.Reset();
            try {
                mapa.getDados();
            } catch (IOException x) {
            }
            mapa.getXY();
            pacman.setVelY(0);
            pacman.setVelX(0);
            pacman.setPos(mapa.getPosicaoXPacMan(), mapa.getPosicaoYPacMan());  //Atualiza a posição do pacman de acordo com o novo mapa
            fantasma.setPos(mapa.getPosicaoXFantasma(), mapa.getPosicaoYFantasma());
            fantasma1.setPos(mapa.getPosicaoXFantasma(), mapa.getPosicaoYFantasma());
            fantasma2.setPos(mapa.getPosicaoXFantasma(), mapa.getPosicaoYFantasma());

        } else if (!jogando && !ganhou) {
            g.setColor(Color.RED);
            g.setFont(fonte);
            g.drawString("Que pena... você perdeu.", 400, 160);
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(20);

                if (jogando) {//Atualiza o movimento dos fantasmas
                    fantasma.atualizaMovimento();
                    fantasma1.atualizaMovimento();
                    fantasma2.atualizaMovimento();
                    checaColisao();
                } else {
                    Thread.sleep(5000);
                    jogando = true;
                    ganhou = false;
                    pacman.setVelY(0);
                    pacman.setVelX(0);
                    pacman.setPos(mapa.getPosicaoXPacMan(), mapa.getPosicaoYPacMan());
                }
                repaint();

            } catch (InterruptedException ex) {

            }
        }
    }
    
    //Checa a colisão do pacman com os fantasmas
    private void checaColisao() {
        if (fantasma1.getColisao(pacman.getPosX(), pacman.getPosY())) {
            ganhou = false;
            jogando = false;
        } else if (fantasma2.getColisao(pacman.getPosX(), pacman.getPosY())) {
            ganhou = false;
            jogando = false;
        } else if (fantasma.getColisao(pacman.getPosX(), pacman.getPosY())) {
            ganhou = false;
            jogando = false;
        }
    }

    private void finalizaJogo() {
        jogando = false;
        ganhou = true;
    }

    //Desenha as bolinhas do mapa
    private void desenhaPontos(Graphics g) {
        g.setFont(fonte);
        g.setColor(Color.ORANGE);
        g.drawString("Score: " + pacman.getPontos(), 10, 330);
    }

    //Desenha o pacman com arcos e circulos
    private void desenhaPacMan(Graphics g) {
        g.setColor(pacman.getCor());
        g.fillOval(pacman.getPosX(), pacman.getPosY(), pacman.getBase(), pacman.getAltura());
        if (abertura.aberto) {
            g.setColor(Color.BLACK);
            if (pacman.cima) {
                g.fillArc(pacman.getPosX(), pacman.getPosY(), pacman.getBase(), pacman.getAltura(), 45, 90);
//				g.setColor(Color.BLACK);
//				g.fillOval(pacman.getX() + 10, pacman.getY() + 20, 10, 10);
            } else if (pacman.baixo) {
                g.fillArc(pacman.getPosX(), pacman.getPosY(), pacman.getBase(), pacman.getAltura(), 225, 90);
            } else if (pacman.direita) {
                g.fillArc(pacman.getPosX(), pacman.getPosY(), pacman.getBase(), pacman.getAltura(), 315, 90);
            } else if (pacman.esquerda) {
                g.fillArc(pacman.getPosX(), pacman.getPosY(), pacman.getBase(), pacman.getAltura(), 135, 90);
            }
        }
    }
    
    //Desenha o fantasma
    private void desenhaFantasma(Graphics g) {
        g.setColor(fantasma.getCor());
        g.fillArc(fantasma.getPosX(), fantasma.getPosY(), fantasma.getBase(), fantasma.getAltura(), 0, 180);
        fantasma.atualizaVertices();
        g.fillPolygon(fantasma.verticesX, fantasma.verticesY, fantasma.vertices);

        g.setColor(fantasma1.getCor());
        g.fillArc(fantasma1.getPosX(), fantasma1.getPosY(), fantasma1.getBase(), fantasma1.getAltura(), 0, 180);
        fantasma1.atualizaVertices();
        g.fillPolygon(fantasma1.verticesX, fantasma1.verticesY, fantasma1.vertices);

        g.setColor(fantasma2.getCor());
        g.fillArc(fantasma2.getPosX(), fantasma2.getPosY(), fantasma2.getBase(), fantasma2.getAltura(), 0, 180);
        fantasma2.atualizaVertices();
        g.fillPolygon(fantasma2.verticesX, fantasma2.verticesY, fantasma2.vertices);
    }

    //Desenha o mapa baseado nos pontos escaneados do arquivo txt do mapa
    public void desenhaMapa(Graphics g) {
        int posX, posY, i, j;
        int addX, addY;
        addX = (mapa.getBase() / 2) - 5;
        addY = (mapa.getAltura() / 2) - 5;

        for (i = 0; i < 18; i++) {
            for (j = 0; j < 5; j++) {
                posX = 10 + (mapa.getBase() * i);
                posY = 10 + (mapa.getAltura() * j);
                if (mapa.pos[i][j] == TipoBloco.PONTO) {
                    g.setColor(Color.WHITE);
                    g.fillOval(posX + addX, posY + addY, 10, 10);
                } else if (mapa.pos[i][j] == TipoBloco.SUPER_PONTO) {
                    g.setColor(Color.RED);
                    g.fillOval(posX + addX - 5, posY + addY - 5, 15, 15);
                } else if (mapa.pos[i][j] == TipoBloco.BLOCO_HORIZONTAL) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX + mapa.getBase(), posY);
                    g.drawLine(posX, posY + mapa.getAltura(), posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.BLOCO_VERTICAL) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX, posY + mapa.getAltura());
                    g.drawLine(posX + mapa.getBase(), posY, posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.CANTO_INF_ESQUERDO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX, posY + mapa.getAltura());
                    g.drawLine(posX, posY + mapa.getAltura(), posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.CANTO_SUP_DIREITO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX + mapa.getBase(), posY);
                    g.drawLine(posX + mapa.getBase(), posY, posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.CANTO_SUP_ESQUERDO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX + mapa.getBase(), posY);
                    g.drawLine(posX, posY, posX, posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.CANTO_INF_DIREITO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY + mapa.getAltura(), posX + mapa.getBase(), posY + mapa.getAltura());
                    g.drawLine(posX + mapa.getBase(), posY, posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.FIM_HORIZONTAL_DIREITO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX + mapa.getBase(), posY);
                    g.drawLine(posX, posY + mapa.getAltura(), posX + mapa.getBase(), posY + mapa.getAltura());
                    g.drawLine(posX + mapa.getBase(), posY, posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.FIM_HORIZONTAL_ESQUERDO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX + mapa.getBase(), posY);
                    g.drawLine(posX, posY + mapa.getAltura(), posX + mapa.getBase(), posY + mapa.getAltura());
                    g.drawLine(posX, posY, posX, posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.FIM_VERTICAL_BAIXO) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX, posY + mapa.getAltura());
                    g.drawLine(posX + mapa.getBase(), posY, posX + mapa.getBase(), posY + mapa.getAltura());
                    g.drawLine(posX, posY + mapa.getAltura(), posX + mapa.getBase(), posY + mapa.getAltura());
                } else if (mapa.pos[i][j] == TipoBloco.FIM_VERTICAL_CIMA) {
                    g.setColor(corBloco);
                    g.drawLine(posX, posY, posX, posY + mapa.getAltura());
                    g.drawLine(posX + mapa.getBase(), posY, posX + mapa.getBase(), posY + mapa.getAltura());
                    g.drawLine(posX, posY, posX + mapa.getBase(), posY);
                }
            }
        }
        //PONTOS
        //Descobre se o pacman comeu um ponto ou não
        superponto = mapa.comePontos(pacman.getPosX(), pacman.getPosY());
        if (superponto == TipoBloco.SUPER_PONTO) {
            pacman.AdicionarPontos(100);
            if (pacman.getPontos() == mapa.getPontos()) {
                finalizaJogo();
            }
        } else if (superponto == TipoBloco.PONTO) {
            pacman.AdicionarPontos(10);
            if (pacman.getPontos() == mapa.getPontos()) {
                finalizaJogo();
            }
        }
    }
    
    //Manda a tecla apertada para a instancia do pacman controlar
    public void keyPressed(KeyEvent e) {
        pacman.keyPressed(e);
    }

    public void keyReleased(KeyEvent e) {
    }

    public void keyTyped(KeyEvent e) {
    }
}

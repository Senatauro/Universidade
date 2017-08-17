/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

import java.io.IOException;

/**
 *
 * @author gabriel
 */
public class JG_Mapa 
{
    public TipoBloco[][] pos;
    private int pontos;
    private int base;
    private int altura;
    private int contador;
    private int pacX, pacY;
    private int fantX, fantY;
    
    //Instancia o mapa, e define o tamanho do mapa
    public JG_Mapa() {
        pos = new TipoBloco[18][5];
        base = 1000 / 18; //tamanho de cada bloco no mapa
        altura = 300 / 5;

        pontos = 0;
        contador = 0;
        try {
            getDados();
        } catch (IOException ex) {
        }
        getXY();
    }
    
    //Le o arquivo do mapa
    public void getDados() throws IOException {
        this.pontos = 0;
        FL_Arquivo arq = new FL_Arquivo("mapa.txt");
        int i;
        for (i = 0; i < 5; i++) {
            setLinha(i, arq.LeLinha(i + 1));
        }
        arq.Fechar();
        contador++;
    }

    public int getPosicaoXPacMan() {
        return this.pacX;
    }

    public int getPosicaoYPacMan() {
        return this.pacY;
    }

    public int getPosicaoXFantasma() {
        return this.fantX;
    }

    public int getPosicaoYFantasma() {
        return this.fantY;
    }

    //Coloca as bolinhas aonde tem a bolinha no mapa
    public void completaPontos() {
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 5; j++) {
                pos[i][j] = TipoBloco.PONTO;
            }
        }
    }
    
    //O colisor
    //O fantasma e o pacman "solicitam" uma permissão para poder andar no mapa
    public boolean getPermissao(int posX, int posY) {
        int i, j;
        for (i = 0; i < 18; i++) {
            for (j = 0; j < 5; j++) {
                if (pos[i][j] == TipoBloco.BLOCO_HORIZONTAL || pos[i][j] == TipoBloco.BLOCO_VERTICAL 
                        || pos[i][j] == TipoBloco.CANTO_INF_DIREITO || pos[i][j] == TipoBloco.CANTO_INF_ESQUERDO 
                        || pos[i][j] == TipoBloco.CANTO_SUP_DIREITO || pos[i][j] == TipoBloco.CANTO_SUP_ESQUERDO 
                        || pos[i][j] == TipoBloco.FIM_VERTICAL_CIMA || pos[i][j] == TipoBloco.FIM_VERTICAL_BAIXO 
                        || pos[i][j] == TipoBloco.FIM_HORIZONTAL_DIREITO || pos[i][j] == TipoBloco.FIM_HORIZONTAL_ESQUERDO) {
                    if ((posX + 40 >= (10 + getBase() * i) && posX + 40 <= (10 + (getBase() * i) + getBase())) || (posX + 10 <= (10 + getBase() * (i + 1)) && posX + 10 >= (10 + getBase() * i))) {
                        if (posY + 40 >= (10 + getAltura() * j) && posY + 40 <= (10 + (getAltura() * j) + getAltura())) {
                            return false;
                        } else if (posY + 5 <= (10 + getAltura() * (j + 1)) && posY + 5 >= (10 + getAltura() * j)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    //Come a bolinha de ponto
    public TipoBloco comePontos(int px, int py)
    {
        int i, j;
        for (i = 0; i < 18; i++) {
            for (j = 0; j < 5; j++) {
                if (pos[i][j] == TipoBloco.PONTO || pos[i][j] == TipoBloco.SUPER_PONTO) {//Colisor do eixo X
                    if ((px + 20 >= (10 + getBase() * i) && px + 20 <= (10 + (getBase() * i) + getBase())) || (px + 20 <= (10 + getBase() * (i + 1)) && px + 20 >= (10 + getBase() * i))) {
                        //Colisor do eixo Y
                        //Checa para ver se o pacman e a bolinha estão no mesmo ponto
                        if (py + 10 >= (10 + getAltura() * j) && py + 10 <= (10 + (getAltura() * j) + getAltura())) {
                            if (pos[i][j] == TipoBloco.PONTO) {
                                pos[i][j] = TipoBloco.NADA;
                                return TipoBloco.PONTO;
                            } else {
                                pos[i][j] = TipoBloco.NADA;
                                return TipoBloco.SUPER_PONTO;
                            }
                        } else if (py + 20 <= (10 + getAltura() * (j + 1)) && py + 20 >= (10 + getAltura() * j)) {
                            if (pos[i][j] == TipoBloco.PONTO) {
                                pos[i][j] = TipoBloco.NADA;
                                return TipoBloco.PONTO;
                            } else {
                                pos[i][j] = TipoBloco.NADA;
                                return TipoBloco.SUPER_PONTO;
                            }
                        }
                    }
                }
            }
        }
        return TipoBloco.NADA;
    }

    //Faz algo
    public void getXY()
    {
        int i, j;
        for (i = 0; i < 18; i++) {
            for (j = 0; j < 5; j++) {
                if (pos[i][j] == TipoBloco.PACMAN) {
                    pacX = i * this.getBase() + 10;
                    pacY = j * this.getAltura() + 10;
                } else if (pos[i][j] == TipoBloco.FANTASMA) {
                    fantX = i * this.getBase() + 10;
                    fantY = j * this.getAltura() + 10;
                }
            }
        }
    }

    //"Mapeia" o mapa para definir cada ponto da matriz
    public void setLinha(int linha, String desenho) {
        int i;
        char tipoDesenho;
        System.out.println(desenho);
        for (i = 0; i < 18; i++) {
            tipoDesenho = desenho.charAt(i);
            if (tipoDesenho == '.') {
                this.pos[i][linha] = TipoBloco.PONTO;
                this.pontos += 10;
            } else if (tipoDesenho == '@') {
                this.pos[i][linha] = TipoBloco.SUPER_PONTO;
                this.pontos += 100;
            } else if (tipoDesenho == '|') {
                this.pos[i][linha] = TipoBloco.BLOCO_VERTICAL;
            } else if (tipoDesenho == '-') {
                this.pos[i][linha] = TipoBloco.BLOCO_HORIZONTAL;
            } else if (tipoDesenho == ' ') {
                this.pos[i][linha] = TipoBloco.NADA;
            } else if (tipoDesenho == ']') {
                this.pos[i][linha] = TipoBloco.CANTO_INF_DIREITO;
            } else if (tipoDesenho == '[') {
                this.pos[i][linha] = TipoBloco.CANTO_INF_ESQUERDO;
            } else if (tipoDesenho == '{') {
                this.pos[i][linha] = TipoBloco.CANTO_SUP_ESQUERDO;
            } else if (tipoDesenho == '}') {
                this.pos[i][linha] = TipoBloco.CANTO_SUP_DIREITO;
            } else if (tipoDesenho == '<') {
                this.pos[i][linha] = TipoBloco.FIM_HORIZONTAL_ESQUERDO;
            } else if (tipoDesenho == '>') {
                this.pos[i][linha] = TipoBloco.FIM_HORIZONTAL_DIREITO;
            } else if (tipoDesenho == '^') {
                this.pos[i][linha] = TipoBloco.FIM_VERTICAL_CIMA;
            } else if (tipoDesenho == 'v' || tipoDesenho == 'V') {
                this.pos[i][linha] = TipoBloco.FIM_VERTICAL_BAIXO;
            } else if (tipoDesenho == 'F' || tipoDesenho == 'f') {
                this.pos[i][linha] = TipoBloco.FANTASMA;
            } else if (tipoDesenho == 'P' || tipoDesenho == 'P') {
                this.pos[i][linha] = TipoBloco.PACMAN;
            }
        }
    }

    public int getBase() {
        return this.base;
    }

    public int getAltura() {
        return this.altura;
    }

    public int getPontos() {
        return this.pontos;
    }
}


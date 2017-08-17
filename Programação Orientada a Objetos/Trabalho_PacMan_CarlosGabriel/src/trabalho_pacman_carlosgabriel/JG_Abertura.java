/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho_pacman_carlosgabriel;

/**
 *
 * @author gabriel
 */

//Usado para abrir e fechar e abrir a boca do pacman
public class JG_Abertura extends Thread {

    public boolean aberto;

    public JG_Abertura() {
        super();
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(200);
                this.aberto = !this.aberto;
            } catch (InterruptedException ex) {
            }
        }
    }
}

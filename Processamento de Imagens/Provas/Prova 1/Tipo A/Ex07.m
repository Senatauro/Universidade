function [intIndice, intValorMatriz]= exercicio4 (intPosicaoX, intPosicaoY, matriz);
  [intTamanhoLinhaMatriz, intTamanhoColunaMatriz] = size(matriz);
  intIndice = (intTamanhoLinhaMatriz*(intPosicaoY-1)) + intPosicaoX;
  intValorMatriz = matriz(intPosicaoX, intPosicaoY);
end
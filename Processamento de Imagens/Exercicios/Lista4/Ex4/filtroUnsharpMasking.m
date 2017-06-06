function f = filtroUnsharpMasking(Matriz, k)
  
  ImagemSuavizada = correlacaoEConvolucao(Matriz, [1 1 1; 1 1 1; 1 1 1], 9);
  Mascara = Matriz - ImagemSuavizada;
  imshow(Mascara);
  ImagemFinal = Matriz + k * Mascara;
  figure, imshow(ImagemFinal), title("Imagem final");
  
endfunction
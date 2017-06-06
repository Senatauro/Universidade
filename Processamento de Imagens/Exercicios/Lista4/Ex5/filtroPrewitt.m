function f = filtroPrewitt(Mostrar)

  Im = imread("lena_gray.bmp");
  Imagem1 = correlacaoEConvolucao(Im, [-1 -1 -1; 0 0 0; 1 1 1], 1);
  Imagem2 = correlacaoEConvolucao(Im, [-1 0 1; -1 0 1; -1 0 1], 1);
  Imagem3 = sqrt( (Imagem1 .* Imagem1) + (Imagem2 .* Imagem2) );
  ImagemFinal = Imagem3 ./ max(Imagem3);
  f = ImagemFinal;
  if(Mostrar == true)
    imshow(ImagemFinal);
  endif
endfunction
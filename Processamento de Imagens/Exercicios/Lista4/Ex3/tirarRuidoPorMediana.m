function f = tirarRuidoPorMediana()
  
  ImagemComRuido = imread("lena_ruido.bmp");
  linha = 1;
  coluna = 1;
  while linha < size(ImagemComRuido)(1)
    while coluna < size(ImagemComRuido)(2)
      parte = ImagemComRuido(linha : linha + 2, coluna : coluna+2);
      mediana = sort(parte(:)')(5);
      ImagemSemRuido(linha : linha + 2, coluna : coluna + 2) = mediana;
      if size(ImagemComRuido)(2) > coluna + 2
        coluna = coluna + 2;
      else
        break;
      endif
    endwhile
    coluna = 1;
    if size(ImagemComRuido)(1) > linha + 2
      linha = linha + 2;
    else
      break;
    endif
  endwhile
  figure, imshow(ImagemSemRuido)
  figure, imshow([ImagemSemRuido  zeros(size(ImagemComRuido)(1), 30)  ImagemComRuido]);
  imwrite(ImagemSemRuido, "Imagem com filtro de mediana.png");
  %f = ImagemSemRuido;
  %ImagemSemRuido = zeros(size(ImagemComRuido)(1) + 4, size(ImagemComRuido)(2) + 4);
  %filtro = [1 2 1; 1 1 0; 1 2 1];
  %for linha = 1:size(ImagemComRuido)(1)
  %  for coluna = 1:size(ImagemComRuido)(2)
  %    ImagemSemRuido(linha + 2, coluna + 2) = ImagemComRuido(linha, coluna);
  %  end
  %end
  
  
endfunction
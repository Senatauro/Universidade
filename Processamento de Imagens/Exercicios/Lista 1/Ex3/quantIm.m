%Faça um outro script similar para ler a mesma imagem e quantizá-la em 6 bits, 5 bits, 4 bits, 3 bits,
%2 bits, e 1 bit através de multiplicação por um valor real (dica: use a função imadjust). Neste caso
%você pode usar a função image para visualizar o resultado.
%Analise o que ocorre quando a imagem é amostrada e quantizada. Qual a diferença entre as funções
%image e imshow?

function a = quantIm(bits)
  Im = imread("lenna.jpg");
  Im = double(Im)/255; 
  NIm = imadjust(Im,[min(Im(:)); max(Im(:))],[0.0; bits]);
  a = NIm;
endfunction
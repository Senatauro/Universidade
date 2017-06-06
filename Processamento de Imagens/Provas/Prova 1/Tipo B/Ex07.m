
  k = 1;
  i = imread('cameraman.png');
  i = double(i); % converto para double para realizar operações matematicas sem ter problema com a imagem
  maiorValor = max(i(:)); % obtenho o maior valor de intensidade da imagem
  i = i ./ maiorValor; % normalizo os valores para ficar de 0 até 1
  i = i .* k;% Coloco os valores no intervalo de 0 até k
  i = round(i); % arredondo
  i = (i .* maiorValor) ./ k; % volto para o intervalo de 0 a 255
  i = round(i); % arredondo novamente
  i = uint8(i); % retorno a matriz i para o tipo imagem uint8
  imshow(i)
    

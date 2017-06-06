
im = imread('lena_ruido.bmp');


mask = ones(3,3) / 9;

im2 = mediana(im);


figure;
imshow(im);
title('Original');

figure;
imshow(im1);
title('Convolução');

figure;
imshow(im2);
title('Mediana');


function imagem_nova = mediana(image)
    [l_imagem,c_imagem]= size(image);
    linhas = l_imagem - 2;
    colunas = c_imagem - 2;
        
    imagem_nova = zeros(linhas,colunas);

    for l = 1:linhas
        for c = 1:colunas
            temp = image(l:l+2,c:c+2);
            temp = sort(temp(:));
            imagem_nova(l,c) = temp(5);
        end
    end

    imagem_nova = uint8(imagem_nova);
end

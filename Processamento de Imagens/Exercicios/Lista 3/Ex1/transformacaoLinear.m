function transformacaoLinear(b, c)
  Im = imread("lena_gray.bmp");
  g = c * Im + b
  figure, imshow(g)
  g = c * log2 (Im + 1)
  figure, imshow(g)
  g = c * exp(Im + 1)
  figure, imshow(g)
endfunction
function f = melhorarBranco()
  
  Im = imread("esqueleto.png");
  NIm = imcomplement(Im);
  NNIm = max(NIm, Im);
  NNNIm = imadjust(NNIm);
  K = imadjust(NIm , [0,1] , [0, 0.7]);
  figure, imshow(K)

  
endfunction
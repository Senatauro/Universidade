function f = filtroLaplace(Matriz, filtro)
  
  f = correlacaoEConvolucao(Matriz, filtro, 1);

endfunction
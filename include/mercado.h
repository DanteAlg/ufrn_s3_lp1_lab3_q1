#ifndef MERCADO_H_
#define MERCADO_H_

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>

#include "produto.h"
#include "roupa.h"
#include "fruta.h"
#include "bebida.h"

class Mercado {
  public:
    Mercado();
    ~Mercado();

  private:
    std::vector<std::shared_ptr<Produto>> produtos;

  public:
    void abrir();
    void adicionarProduto(const std::shared_ptr<Produto> &p);
    void listarProdutos();
    void somarProdutos();
    void subtrairProdutos();
};

#endif

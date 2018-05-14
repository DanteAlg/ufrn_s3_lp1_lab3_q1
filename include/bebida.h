#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"
#include <iostream>

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, short _preco, 
			int _teor_alcoolico);
	~Bebida();
private:
	int m_teor_alcoolico;
public:
	// getters
	int getTeorAlcoolico();
	// setters
	void setTeorAlcoolico(int _teor_alcoolico);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif

#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"
#include <iostream>

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, short _preco, 
			std::string _marca, char _sexo, char _tamanho);
	~Roupa();
private:
	std::string m_marca;
	char m_sexo;
	char m_tamanho;
public:
	// getters
	std::string getMarca();
	char getSexo();
	char getTamanho();
	// setters
	void setMarca(std::string _marca);
	void setSexo(char _sexo);
	void setTamanho(char _tamanho);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif

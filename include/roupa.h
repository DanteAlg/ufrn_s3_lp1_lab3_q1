#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"
#include <iostream>

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, short _preco, 
			std::string _marca, std::string _sexo, std::string _tamanho);
	~Roupa();
private:
	std::string m_marca;
	std::string m_sexo;
	std::string m_tamanho;
public:
	// getters
	std::string getMarca();
	std::string getSexo();
	std::string getTamanho();
	// setters
	void setMarca(std::string _marca);
	void setSexo(std::string _sexo);
	void setTamanho(std::string _tamanho);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif

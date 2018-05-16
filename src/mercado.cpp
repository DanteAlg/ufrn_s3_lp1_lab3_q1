#include "mercado.h"

Mercado::Mercado() {}

Mercado::~Mercado() {}

void Mercado::abrir() {
	// No macbook não consegui pegar o arquivo no mesmo diretório, só dessa forma
	std::fstream file("src/produtos.dat");

	// Caso não encontre da forma acima tento no mesmo diretório
	if (!file) {
		file.open("produtos.dat");
	}

	std::string tipo;
	
	std::string cod, desc, data, marca, tam, sex;
	int aux = 0;
	double preco, grau_alcoolico;
	short validade;

	if (file) {
		while(!file.eof()) {
			file.seekg(aux);
			std::getline(file, tipo, ',');

			std::getline(file, cod, ',');
			std::getline(file, desc, ',');
			file >> preco;
			aux = file.tellg();
			file.seekg(aux + 1);

			if (tipo.compare("BEBIDA") == 0) {
				file >> grau_alcoolico;
				adicionarProduto(std::make_shared<Bebida>(cod, desc, preco, grau_alcoolico));
			}
			else if (tipo.compare("FRUTA") == 0) {
				std::getline(file, data, ',');
				file >> validade;
				adicionarProduto(std::make_shared<Fruta>(cod, desc, preco, data, validade));
			}
			else if (tipo.compare("ROUPA") == 0) {
				std::getline(file, marca, ',');
				std::getline(file, sex, ',');
				std::getline(file, tam, ',');
				adicionarProduto(std::make_shared<Roupa>(cod, desc, preco, marca, tam, sex));
			}

			aux = file.tellg();
			aux++;
		}
	}

	// Produto com erro, mesmo codigo de uma fruta que tem no .dat
	adicionarProduto(std::make_shared<Fruta>("001002003-24", "Maca importada", 9.0, "01/10/2017", 18));
	
	// testes
	listarProdutos();
	somarProdutos();
	subtrairProdutos();
}

void Mercado::adicionarProduto(const std::shared_ptr<Produto> &p) {
	for(int i = 0; i < produtos.size(); i++) {
		if (*produtos[i] == *p) {
			std::cout << "Produto já existe!" << std::endl;
			return;
		}
	}

	produtos.push_back(p);
};

void Mercado::listarProdutos() {
	for (auto i = produtos.begin(); i != produtos.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}
}

void Mercado::somarProdutos() {
	// Somar e subtrair o valor de dois produtos
	// Somar 8.7 + 4.75 = 13.45
	std::cout << "Valor total da Maca verde com Laranja: " << *produtos[0] + *produtos[1] << std::endl;
}

void Mercado::subtrairProdutos() {
	// Subtrair 8.7 - 4.75 = 3.95
	std::cout << "Subtrair valor da Laranja na Maca verde: " << *produtos[0] - *produtos[1] << std::endl;
}

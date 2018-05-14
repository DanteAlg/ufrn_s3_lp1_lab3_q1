#include <iostream>
#include <vector>
#include <memory>
#include "produto.h"
#include "fruta.h"
#include "bebida.h"
#include "roupa.h"

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<shared_ptr<Produto>> lista;

	// TODO: puxar os produtos a partir de um .dat
	// TODO: validar entrada de produtos com mesmo código de barra

	// Adiciona frutas	
	lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	lista.push_back(make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));

	// Adiciona Bebidas
	lista.push_back(make_shared<Bebida>("001002003-50","Bacati",8.70,10));
	lista.push_back(make_shared<Bebida>("001002004-51","Cerveja",4.75,20));
	lista.push_back(make_shared<Bebida>("001002005-52","Vinho",2.30,8));

	// Adiciona Roupas
	lista.push_back(make_shared<Roupa>("001002003-54","Camisa de marca",8.70,"Riachuelo",'M','S'));
	lista.push_back(make_shared<Roupa>("001002004-66","Camisa do alecrim",4.75,"Seu zé",'M','M'));
	lista.push_back(make_shared<Roupa>("001002005-67","Jeans usado",2.30,"Boteco",'F','P'));

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}

	// Somar e subtrair o valor de dois produtos
	// Somar 8.7 + 4.75 = 13.45
	std::cout << "Valor total da Maca verde com Laranja: " << *lista[0] + *lista[1] << std::endl;

	// Subtrair 8.7 - 4.75 = 3.95
	std::cout << "Subtrair valor da Laranja na Maca verde: " << *lista[0] - *lista[1] << std::endl;

	// Erro ao tentar adicionar um objeto com mesmo código
	lista.push_back(make_shared<Fruta>("001002003-45","Maca importada",9.0,"01/10/2017",18));

	return 0;
}

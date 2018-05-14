##########################################
# MENSAGEM DO TEOBALDO
##########################################

Caro amigo, nem sei por onde começar. Soube do desastre que foi a avaliação, mas eu realmente tive que viajar e não deu tempo de completar as implementações.

A propósito, acabo de notar que estou atrasado para outra viagem...

Hey! Posso te pedir mais um GRANDE favor? Completa esse código para mim?!

Não se esqueça de:
* Completar a implementação das classes :white_check_mark:
* Documentar o código usando Doxygen :white_check_mark:
* Criar um makefile apropiado :white_check_mark:
* Alterar o main para testar toda a implementação :white_check_mark:

IMPORTANTE:
* Não permita incluir na lista produtos com o mesmo código
* Confesso que apenas reproduzi a sobrecarga do operador de inserção na classe Produto, mas não sei bem o que fiz. O que eu realmente não entendi foi como, mesmo eu não tendo sobrecarregado o operador de inserção na classe Fruta, ainda consigo imprimir os dados de um objeto desta classe usando este operador! Que loucura! Por isso, preciso que você explique isso em um ou dois parágrafos para eu enviar ao professor. :white_check_mark:
```
A sobrecarga do operador << feita em "produto.cpp" é herdada pelas classes Fruta, Bebida e Roupa, sendo necessário apenas alterar o método virtual "print()" que é prototipado em "produto.h:28", segundo a implementação da sobrecarca, o operador << executa o método "print()" de cada classe descendente.
```
* Outra parte que eu fiz, mas não sei bem a razão, foi declarar o método destrutor da classe Produto como virtual. Advinha?! Eu também preciso explicar isso ao professor. Conto com sua ajuda! :white_check_mark:
```
Para evitar que seja chamado o destrutor da classe base caso exista um destrutor nas classes descendentes. O virtual cria uma preferencia pelo uso dos métodos sobreescritos, ou seja a classe base não controla a forma de destruir um objeto que ela não conheceria, neste caso o que vai herdar Produto.
```

Fico te devendo mais esta!

Tenho que ir.

Teobaldo

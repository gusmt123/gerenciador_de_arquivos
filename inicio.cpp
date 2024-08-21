#include <iostream>
#include "Arquivo.h"

using namespace std;

int main()
{
    // Declara a variável que controla se o input do usuário é válido e atribui o valor false a ela
    bool opcao_valida = false;
    char opcao;
    string nome_arquivo;

    // Loop até o usuário digitar uma opção válida
    while (!opcao_valida)
    {
        // Menu com as opções principais
        std::cout << "Digite uma das opções a seguir: " << std::endl;
        std::cout << "1. Criar arquivo" << std::endl;
        std::cout << "2. Apagar arquivo" << std::endl;
        
        // Armazena input do usuário na variável opcao
        std::cin >> opcao;

        // Verifica se a opção digitada foi válida
        if(opcao == '1' || opcao == '2')
        {
            opcao_valida = true; // Marca a opção como válida

            std::cout << "Digite o nome do arquivo:" << std::endl;
            
            // Armazena nome do arquivo na variável nome_arquivo
            std::cin >> nome_arquivo;

            // Cria instância da classe Arquivo
            Arquivo arquivo_selecionado(nome_arquivo); 

            switch(opcao)
            {
                case '1':
                    arquivo_selecionado.criar_arquivo();
                    break;
                
                case '2':
                    arquivo_selecionado.apagar_arquivo();
                    break;
            }
        }
        else
        {
            std::cout << "Opção inválida. Saindo..." << std::endl;
            exit(0); // Encerra o programa se a opção for inválida
        }
    }

    return 0;
}

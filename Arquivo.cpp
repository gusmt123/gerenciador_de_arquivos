//inclui arquivos e bibliotecas usados nesse código
#include "Arquivo.h"
#include <iostream>
#include <fstream>
#include <filesystem>


using namespace std;

//construtor da classe arquivo, recebe como parametro uma constante que é uma refencia
Arquivo::Arquivo(const std::string& nome_arquivo) : nome_arquivo(nome_arquivo){}

//cria o arquivo ou pasta
void Arquivo::criar_arquivo()
{
    std::fstream arquivo(nome_arquivo, std::ios::out);
    if (!arquivo)
    {
        std::cerr << "Erro ao criar o arquivo: " << nome_arquivo << std::endl;
    }
    else
    {
        arquivo << "Arquivo criado com sucesso!";
        arquivo.close();
    }
}

//apaga o arquivo ou pasta
void Arquivo::apagar_arquivo()
{
    try
    {
        //verifica s eo arquivo ou pasta existe
        if (filesystem::exists(nome_arquivo))
        {
            //verifica se é um arquivo
            if (filesystem::is_regular_file(nome_arquivo))
            {
                // Remove o arquivo
                filesystem::remove(nome_arquivo);
                std::cout << "Arquivo apagado com sucesso." << std::endl;
            }
            //verifica se é uma pasta
            else if (filesystem::is_directory(nome_arquivo))
            {
                // Remove o diretório e seu conteúdo
                filesystem::remove_all(nome_arquivo);
                std::cout << "Diretório apagado com sucesso." << std::endl;
            }
            else
            {
                std::cerr << "O caminho especificado não é um arquivo nem um diretório." << std::endl;
            }
        }
        else
        {
            std::cerr << "O arquivo ou diretório não existe." << std::endl;
        }
    }
    //tratamento de erros
    catch (const filesystem::filesystem_error& erro)
    {
        //mostra mensagem de erro ao apagar arquivo ou diretório
        std::cerr << "Erro ao apagar o arquivo ou diretório!" << std::endl;
    }
}

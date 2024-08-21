#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <filesystem>

class Arquivo
{
private:
    std::string nome_arquivo;

public:
    Arquivo(const std::string& nome_arquivo);

    void criar_arquivo();
    void apagar_arquivo();
};

#endif // ARQUIVO_H

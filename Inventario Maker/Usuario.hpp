#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

using namespace std;

enum TipoUsuario {
     ALUNO, DOCENTE 
};

class Usuario {
private:
    string cpf;
    string nome;
    string matricula;
    TipoUsuario tipo;

public:
    Usuario();
    Usuario(const string& cpf, const string& nome, const string& matricula, TipoUsuario tipo);
    string getCPF() const;
    string getNome() const;
    string getMatricula() const;
    TipoUsuario getTipo() const;
    string getTipoString() const;
};

#endif
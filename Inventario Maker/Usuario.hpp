#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <iostream>

using namespace std;

class Usuario {
public:
   
    enum class TipoUsuario {
        ALUNO,
        DOCENTE
    };

private:
    string cpf;
    string nome;
    string matricula;
    TipoUsuario tipo;
    
public:
  
    Usuario(const string& cpf, const string& nome, 
           const string& matricula, TipoUsuario tipo);

    string getCPF() const;
    string getNome() const;
    string getMatricula() const;
    TipoUsuario getTipo() const;
    string getTipoString() const;
    

    void setCPF(const string& novoCPF);
    void setNome(const string& novoNome);
    void setMatricula(const string& novaMatricula);
    void setTipo(TipoUsuario novoTipo);

};

#endif 

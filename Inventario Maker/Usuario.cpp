#include "Usuario.hpp"

Usuario::Usuario(const string& cpf, const string& nome, const string& matricula, TipoUsuario tipo)
    : cpf(cpf), nome(nome), matricula(matricula), tipo(tipo) {}

string Usuario::getCPF() const { return cpf; }
string Usuario::getNome() const { return nome; }
string Usuario::getMatricula() const { return matricula; }
TipoUsuario Usuario::getTipo() const { return tipo; }

string Usuario::getTipoString() const {
    return (tipo == ALUNO) ? "Aluno" : "Docente";
}
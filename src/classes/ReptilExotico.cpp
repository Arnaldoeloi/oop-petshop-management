#include "../../include/ReptilExotico.h"
#include <string>

ReptilExotico::ReptilExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
    m_id=id;
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;
    
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;

    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;
}

ReptilExotico::ReptilExotico(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;
    
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;

    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;
}
        

ReptilExotico::ReptilExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
    m_classe="Reptilia";
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;
    
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;

    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;
}
        



std::string ReptilExotico::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
    }
    std::string s = ss.str();
    return s;
}

std::ostream& ReptilExotico::print(std::ostream& os) const{
    return os<<std::endl
        <<"Réptil Exótico: "           <<m_nome<<std::endl
        <<"   => id: "                 <<m_id<<std::endl
        <<"   => Classe: "             <<m_classe<<std::endl
        <<"   => Nome: "               <<m_nome_batismo<<std::endl
        <<"   => Nome Científico: "    <<m_nome_cientifico<<std::endl
        <<"   => Sexo: "               <<m_sexo<<std::endl
        <<"   => Tamanho: "            <<m_tamanho<<std::endl
        <<"   => Dieta: "              <<m_dieta<<std::endl
        <<"   => Veterinário: "        <<m_veterinario->getNome()<<" / "<<m_veterinario->getId()<<std::endl
        <<"   => Veterinário: "        <<m_veterinario->getNome()<<" / "<<m_veterinario->getId()<<std::endl
        <<std::endl;


        /* <<"Tratador: "                <<m_nome<<std::endl
        <<"   => CPF: "               <<m_cpf<<std::endl
        <<"   => Idade: "             <<m_idade<<std::endl
        <<"   => Típo Sanguíneo: "    <<m_tipo_sanguineo<<std::endl
        <<"   => Fator RH: "          <<m_fator_rh<<std::endl
        <<"   => Especialidade: "     <<m_especialidade<<std::endl
        <<"   => Nível de Segurança: "<<m_nivel_de_seguranca<<std::endl
        <<std::endl; */
}
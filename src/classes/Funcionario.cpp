#include "Funcionario.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "CSVparser.hpp"

std::string Funcionario::filePath = "./storage/funcionarios.csv";
Funcionario::Funcionario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade){
    m_id = id;
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
}

std::multimap<std::string,Funcionario*> Funcionario::all(){
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    std::multimap<std::string,Funcionario*> funcionarios;
    int n_rows = file.rowCount();
    std::cout<<"N_rows: "<<n_rows<<std::endl;
    int n_columns = file.columnCount();
    std::cout<<"N_columns: "<<n_columns<<std::endl;


    for(int i = 0; i<n_rows; i++){
        
        /* Recupera os campos do arquivo csv*/
        int id = std::stoi(file[i][0]);
        std::string nome = file[i][2];
        std::string cpf = file[i][3];
        short idade = std::stoi(file[i][4]);
        short tipo_sanguineo = std::stoi(file[i][5]);
        char fator_rh = file[i][6][0];
        std::string especialidade = file[i][7];
        /* Estancia dinamicamente um novo funcionario */
        Funcionario* funcionario = new Funcionario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);
        
        /* faz o downcasting para tratador ou veterinario */
        
        std::cout<<"chamou"<<std::endl;
        if(file[i][1] == "Tratador"){
            // so funciona se funcionario tiver um metodo virtual
            //Tratador* tratador = dynamic_cast<Tratador*>(func);
            Tratador* tratador = static_cast<Tratador*>(funcionario); 
            tratador->setNivelDeSeguranca(stoi(file[i][9]));
            
            // faz o upcasting de volta para funcionario
            funcionarios.insert(std::pair<std::string, Funcionario*>("tratador", tratador));
        }else{
            // so funciona se funcionario tiver um metodo virtual
            //Veterinario* veterinario = dynamic_cast<Veterinario*>(func);

            Veterinario* veterinario = static_cast<Veterinario*>(funcionario);
            veterinario->setCrmv(file[i][7]);

            // faz o upcasting de volta para funcionario
            funcionarios.insert(std::pair<std::string, Funcionario*>("veterinario", veterinario));
        }     

    }

    return funcionarios;
}

std::string Funcionario::getNome(){
    return m_nome;
}
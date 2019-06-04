#include "Funcionario.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "CSVparser.hpp"

std::string Funcionario::filePath = "./storage/funcionarios.csv";
std::string Funcionario::tableName = "funcionarios";
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
    //std::cout<<"N_rows: "<<n_rows<<std::endl;
    //int n_columns = file.columnCount();
    //std::cout<<"N_columns: "<<n_columns<<std::endl;


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
        
        
        /* faz o downcasting para tratador ou veterinario */
        if(file[i][1] == "Tratador"){

            //Método construtor de tratador + upcasting para funcionário
            Funcionario* funcionario;
            Tratador* tratador = new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, stoi(file[i][9]));
            funcionario = tratador;

            funcionarios.insert(std::pair<std::string, Funcionario*>("tratador", funcionario));

        }else if(file[i][1] == "Veterinario"){
            // Oitava coluna representa o código cnmv
            std::string cnmv = file[i][8];


            //Método construtor de veterinário + upcasting para funcionário
            Funcionario* funcionario;
            Veterinario* veterinario = new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, file[i][8]);
            funcionario = veterinario;

            funcionarios.insert(std::pair<std::string, Funcionario*>("veterinario", funcionario));
        }     

    }

    return funcionarios;
}

Funcionario* Funcionario::buildFuncionarioFromFile(csv::Row* file){
    int id = std::stoi((*file)[0]);
    std::string nome = (*file)[2];
    std::string cpf = (*file)[3];
    short idade = std::stoi((*file)[4]);
    short tipo_sanguineo = std::stoi((*file)[5]);
    char fator_rh = (*file)[6][0];
    std::string especialidade = (*file)[7];
    /* Estancia dinamicamente um novo funcionario */
    
    
    /* faz o downcasting para tratador ou veterinario */
    if((*file)[1] == "Tratador"){

        //Método construtor de tratador + upcasting para funcionário
        Funcionario* funcionario;
        Tratador* tratador = new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, stoi((*file)[9]));
        funcionario = tratador;
        return funcionario;

    }else if((*file)[1] == "Veterinario"){
        // Oitava coluna representa o código cnmv
        std::string cnmv = (*file)[8];


        //Método construtor de veterinário + upcasting para funcionário
        Funcionario* funcionario;
        Veterinario* veterinario = new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, (*file)[8]);
        funcionario = veterinario;

        return funcionario;
    }
    Funcionario* f = NULL;
    return f;
}

// procura por id
Funcionario* Funcionario::find(int id){
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    int n_rows = file.rowCount();
    for (int i = 0; i < n_rows; i++)
    {
        if(id == std::stoi(file[i][0])){
            /* Recupera os campos do arquivo csv*/
            return buildFuncionarioFromFile(&file[i]);
        }
    }
    Funcionario* f = NULL;
    return f;
}

std::string Funcionario::getNome(){
    return m_nome;
}
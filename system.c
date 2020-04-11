#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <string.h>

typedef struct aluno{
    int codigo_alu;
    char nome_alu[15];
    char cpf[12];
    //disciplina disciplina[15];

}aluno;

typedef struct disciplina{
    int codigo_dis;
    char professor[15];
    char nome_dis[15];
    int creditos;
    aluno aluno[15];
}disciplina;

typedef struct periodo{
    char nome_periodo[10];
    aluno aluno[15];
    disciplina disciplina[15];
}periodo;

int main(){
    periodo periodo[10];
    char periodo_escolhido[10], periodo_digitado[10], disciplina_digitada[10], disciplina_escolhida[10], aluno_escolhido[15], disciplina_escolhida2[10], aluno_digitado[15];
    int escolha, aluno_existe, aluno_esta_disciplina, aluno_esta_matriculado, aux2, periodo_controle, periodo_existe, i, salva_periodo, salva_disciplina, cont_aluno, cont_disc, aux, j, esta_matriculado, disciplina_existe;
    periodo_controle = cont_aluno = cont_disc = i = 0;
    while(1){
        printf("O que você deseja?\n1-Inserir um período\n2-Fazer consultas em um período\n0-Sair\n");
        scanf("%d", &escolha);
        if(escolha == 0){
            break;
        }
        switch (escolha)
        {
        case 1:
            printf("Qual periodo você deseja inserir?\n");
            //DEVE VERIFICAR SE O PERIODO JA NAO EXISTE
            scanf("%s", periodo_digitado);
            for(i=0; i < 10; i++){
                if(strcmp(periodo[i].nome_periodo, periodo_digitado)==0){
                    printf("Esse período já existe\n");
                    break;
                }
            }
            strcpy(periodo[periodo_controle].nome_periodo, periodo_digitado);
            periodo_controle++;
            break;

        case 2:
            periodo_existe = 0;
            printf("Insira o período que se deseja realizar a consulta:\n");
            //DEVE VERIFICAR SE O PERIODO EXISTE
            scanf("%s", periodo_escolhido);
            for(i=0; i<10; i++){
                if(strcmp(periodo_escolhido, periodo[i].nome_periodo)==0){
                    salva_periodo = i;
                    periodo_existe = 1;
                }
            }
            if(periodo_existe == 1){
                for(i=0; i<10; i++){
                    for(j=0; j<15; j++){
                        strcpy(periodo[salva_periodo].disciplina[i].aluno[j].nome_alu,"0");
                        strcpy(periodo[salva_periodo].aluno[j].nome_alu, "0");
                    }
                }
                while(1){
                    printf("Diga o que deseja realizar:\n1-Inserir aluno\n2-Remover aluno\n3-Inserir Disciplina\n4-Remover Disciplina\n5-Verificar disciplinas de um aluno\n6-Verificar quais alunos estão em uma disciplina\n0-Voltar ao menu anterior\n");
                    scanf("%d", &escolha);
                    if(escolha == 0){
                        break;
                    }
                    switch (escolha)
                    {
                    case 1:
                        esta_matriculado = 0;
                        disciplina_existe = 0;
                        printf("Para inserir um aluno será necessário a inserção de alguns dados\n");
                        printf("Nome: ");
                        scanf("%s", aluno_digitado);
                        for(i=0; i<10; i++){
                            if(strcmp(periodo[salva_periodo].aluno[i].nome_alu, aluno_digitado) == 0){
                                esta_matriculado = 1;
                                aux = i;
                            }
                        }
                        if(esta_matriculado == 1){
                            printf("Esse aluno já está matriculado no período\nEntre com uma nova disciplina para ele:  ");
                            scanf("%s", disciplina_escolhida);
                            for(i=0; i<15; i++){
                                if(strcmp(periodo[salva_periodo].disciplina[i].nome_dis, disciplina_escolhida)==0){
                                    salva_disciplina = i;
                                    disciplina_existe = 1;
                                }
                            }
                            if(disciplina_existe == 1){
                                aluno_esta_disciplina = 0;
                                for(i=0; i<10; i++){
                                    if(strcmp(periodo[salva_periodo].disciplina[salva_disciplina].aluno[i].nome_alu, aluno_digitado)==0){
                                        aluno_esta_disciplina = 1;
                                        break;
                                    }
                                }
                                for(i=0; i<15; i++){
                                    if(strcmp(periodo[salva_periodo].disciplina[salva_disciplina].aluno[i].nome_alu, "0") == 0){
                                        cont_aluno = i;
                                        break;
                                    }
                                }
                                if(aluno_esta_disciplina == 0){
                                    strcpy(periodo[salva_periodo].disciplina[salva_disciplina].aluno[cont_aluno].nome_alu, periodo[salva_periodo].aluno[aux].nome_alu);
                                }else{
                                    printf("Estre aluno já está matriculado nesta disciplina\n");
                                }
                            }else{
                                printf("Essa disciplina não existe\n");
                            }
                        }else{
                            for(i=0; i<15; i++){
                                    if(strcmp(periodo[salva_periodo].aluno[i].nome_alu, "0") == 0){
                                        cont_aluno = i;
                                        break;
                                    }
                                }
                            strcpy(periodo[salva_periodo].aluno[cont_aluno].nome_alu, aluno_digitado);
                            printf("CPF: ");
                            scanf("%s", periodo[salva_periodo].aluno[cont_aluno].cpf);
                            printf("Código: ");
                            scanf("%d", &periodo[salva_periodo].aluno[cont_aluno].codigo_alu);
                            printf("Disciplina: ");
                            scanf("%s", disciplina_escolhida);
                            for(i=0; i<15; i++){
                                if(strcmp(periodo[salva_periodo].disciplina[i].nome_dis, disciplina_escolhida)==0){
                                    salva_disciplina = i;
                                    disciplina_existe = 1;
                                }
                            }
                            if(disciplina_existe == 1){
                                for(i=0; i<15; i++){
                                    if(strcmp(periodo[salva_periodo].disciplina[salva_disciplina].aluno[i].nome_alu, "0") == 0){
                                        aux2 = i;
                                        break;
                                    }
                                }
                                strcpy(periodo[salva_periodo].disciplina[salva_disciplina].aluno[aux2].cpf, periodo[salva_periodo].aluno[cont_aluno].cpf);
                                strcpy(periodo[salva_periodo].disciplina[salva_disciplina].aluno[aux2].nome_alu, periodo[salva_periodo].aluno[cont_aluno].nome_alu);
                                periodo[salva_periodo].disciplina[salva_disciplina].aluno[aux2].codigo_alu = periodo[salva_periodo].aluno[cont_aluno].codigo_alu;
                                //cont_aluno++;
                            }else{
                                printf("Essa disciplina não existe");
                            }
                        }
                        break;
                    
                    case 2:
                        aluno_existe = 0;
                        aluno_esta_matriculado = 0;
                        disciplina_existe = 0;
                        printf("Diga o que deseja:\n1-Remover aluno de uma disciplina\n2-Remover aluno do periodo\n");
                        scanf("%d", &escolha);
                        if(escolha == 1){
                            printf("Entre com o nome do aluno que deseja remover: ");
                            scanf("%s", aluno_digitado);
                            for(i=0; i< 10; i++){
                                if(strcmp(aluno_digitado, periodo[salva_periodo].aluno[i].nome_alu)== 0){
                                    aluno_existe = 1;
                                }
                            }
                            if(aluno_existe == 1){
                                printf("Entre com a disciplina que deseja remover o aluno: ");
                                scanf("%s", disciplina_digitada);
                                for(i = 0; i < 10; i++){
                                    if(strcmp(disciplina_digitada, periodo[salva_periodo].disciplina[i].nome_dis)==0){
                                        disciplina_existe = 1;
                                        aux = i;
                                    }
                                }
                                if(disciplina_existe == 1){
                                    for(i=0; i<10; i++){
                                        if(strcmp(periodo[salva_periodo].disciplina[aux].aluno[i].nome_alu, aluno_digitado) == 0){
                                            aluno_esta_matriculado = 1;
                                            aux2 = i;
                                        }
                                    }
                                    if(aluno_esta_matriculado == 1){
                                        for(i=aux2; i<10; i++){
                                            periodo[salva_periodo].disciplina[aux].aluno[i].codigo_alu = periodo[salva_periodo].disciplina[aux].aluno[i+1].codigo_alu;
                                            strcpy(periodo[salva_periodo].disciplina[aux].aluno[i].nome_alu, periodo[salva_periodo].disciplina[aux].aluno[i+1].nome_alu);
                                            strcpy(periodo[salva_periodo].disciplina[aux].aluno[i].cpf, periodo[salva_periodo].disciplina[aux].aluno[i+1].cpf);
                                        }
                                    }else{
                                        printf("Esse aluno não está matriculado\n");
                                    }
                                }else{
                                    printf("Essa disciplina não existe\n");
                                }                        
                            }else{
                                printf("Esse aluno não existe\n");
                            }
                        }
                        if(escolha == 2){
                            aluno_existe = 0;
                            printf("Entre com o nome do aluno que deseja remover do período: ");
                            scanf("%s", aluno_digitado);
                            for(i=0; i<10; i++){
                                if(strcmp(periodo[salva_periodo].aluno[i].nome_alu, aluno_digitado)==0){
                                    aux = i;
                                    aluno_existe = 1;
                                }
                            }
                            if(aluno_existe == 1){
                                for(i=aux; i<10; i++){
                                    periodo[salva_periodo].aluno[i].codigo_alu = periodo[salva_periodo].aluno[i+1].codigo_alu;
                                    strcpy(periodo[salva_periodo].aluno[i].nome_alu, periodo[salva_periodo].aluno[i+1].nome_alu);
                                    strcpy(periodo[salva_periodo].aluno[i].cpf, periodo[salva_periodo].aluno[i+1].cpf);
                                }
                                for(i=0; i<10; i++){
                                    for(j=0; j<10; j++){
                                        if(strcmp(periodo[salva_periodo].disciplina[i].aluno[j].nome_alu, aluno_digitado)==0){
                                            for(int k=j; k<10; k++){
                                                periodo[salva_periodo].disciplina[i].aluno[k].codigo_alu = periodo[salva_periodo].disciplina[i].aluno[k+1].codigo_alu;
                                                strcpy(periodo[salva_periodo].disciplina[i].aluno[k].nome_alu, periodo[salva_periodo].disciplina[i].aluno[k+1].nome_alu);
                                                strcpy(periodo[salva_periodo].disciplina[i].aluno[k].cpf, periodo[salva_periodo].disciplina[i].aluno[k+1].cpf);
                                            }
                                        }
                                    }
                                    
                                }
                            }else{
                                printf("Esse aluno não existe\n");
                            }
                        }
                        break;

                    case 3:
                        disciplina_existe = 0;
                        printf("Digite a disciplina que deseja inserir: ");
                        scanf("%s", disciplina_digitada);
                        for(i=0; i<10; i++){
                            if(strcmp(periodo[salva_periodo].disciplina[i].nome_dis, disciplina_digitada)==0){
                                disciplina_existe = 1;
                            }
                        }
                        if(disciplina_existe != 1){
                            strcpy(periodo[salva_periodo].disciplina[cont_disc].nome_dis, disciplina_digitada);
                            printf("Digite o código da disciplina: ");
                            scanf("%d", &periodo[salva_periodo].disciplina[cont_disc].codigo_dis);
                            printf("Digite o nome do professor da disciplina: ");
                            scanf("%s", periodo[salva_periodo].disciplina[cont_disc].professor);
                            printf("Digite a quantidade de créditos que essa disciplina terá: ");
                            scanf("%d", &periodo[salva_periodo].disciplina[cont_disc].creditos);
                            cont_disc++;
                        }else{
                            printf("Essa disciplina ja existe\n");
                        }
                        break;
                    
                    case 4:
                        disciplina_existe = 0;
                        printf("Entre com o nome da disciplina que deseja remover: ");
                        scanf("%s", disciplina_digitada);
                        for(i=0; i<10; i++){
                            if(strcmp(periodo[salva_periodo].disciplina[i].nome_dis, disciplina_digitada)==0){
                                disciplina_existe = 1;
                                aux = i;
                            }
                        }
                        if(disciplina_existe == 1){
                            for(i=aux; i<10; i++){
                                periodo[salva_periodo].disciplina[i].codigo_dis = periodo[salva_periodo].disciplina[i+1].codigo_dis;
                                periodo[salva_periodo].disciplina[i].creditos = periodo[salva_periodo].disciplina[i+1].creditos;
                                strcpy(periodo[salva_periodo].disciplina[i].nome_dis, periodo[salva_periodo].disciplina[i+1].nome_dis);
                                strcpy(periodo[salva_periodo].disciplina[i].professor, periodo[salva_periodo].disciplina[i+1].professor);
                                for(j=0; j<10; j++){
                                    periodo[salva_periodo].disciplina[i].aluno[j].codigo_alu = periodo[salva_periodo].disciplina[i+1].aluno[j].codigo_alu;
                                    strcpy(periodo[salva_periodo].disciplina[i].aluno[j].cpf, periodo[salva_periodo].disciplina[i+1].aluno[j].cpf);
                                    strcpy(periodo[salva_periodo].disciplina[i].aluno[j].nome_alu, periodo[salva_periodo].disciplina[i+1].aluno[j].nome_alu);
                                }
                            }
                        }else{
                            printf("Esta disciplina não existe\n");
                        }
                        break;

                    case 5:
                        aluno_existe = 0;
                        printf("Diga o nome do aluno que deseja verificar as disciplinas: ");
                        scanf("%s", aluno_escolhido);
                        //printf("%d\n", strcmp(aluno_escolhido, periodo[salva_periodo].disciplina[0].aluno[0].nome_alu));
                        for(i=0; i<10; i++){
                            for(j=0; j<10; j++){
                                if(strcmp(aluno_escolhido, periodo[salva_periodo].disciplina[i].aluno[j].nome_alu) == 0){
                                    aux = i;
                                    aluno_existe = 1;
                                    printf("%s\n", periodo[salva_periodo].disciplina[i].nome_dis);
                                }
                            }
                        }/*
                        if(aluno_existe == 1){
                            printf("%s\n", periodo[salva_periodo].disciplina[aux].nome_dis);
                        }else{
                            printf("O aluno não existe\n");
                        }*/
                        break;

                    case 6:
                        disciplina_existe = 0;
                        printf("Diga qual disciplina deseja verificar os alunos: ");
                        scanf("%s", disciplina_escolhida2);
                        for(i=0; i<10; i++){
                            if(strcmp(periodo[salva_periodo].disciplina[i].nome_dis, disciplina_escolhida2) == 0){
                                aux = i;
                                disciplina_existe = 1;

                            }
                        }
                        if(disciplina_existe == 1){
                            for(i=0; i<10; i++){
                                if(strcmp(periodo[salva_periodo].disciplina[aux].aluno[i].nome_alu, "0") != 0){
                                    printf("%s\n", periodo[salva_periodo].disciplina[aux].aluno[i].nome_alu);
                                }
                            }
                        }else{
                            printf("Essa disciplina não existe\n");
                        }
                        break;
                    }
                }
            }else{
                printf("Esse período não existe, tente novamente\n");
            }
            break;
        }
    }
}

//AS VARIAVEIS QUE CONTAM ALUNO E CONTAM DISCIPLINA PRECISAM SER INICIALIZADAS COMO O ULTIMO ELEMENTO DO ARQUIVO

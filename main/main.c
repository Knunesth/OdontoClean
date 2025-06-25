#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar_funcionarios() {
    FILE *fp = fopen("../dados/funcionarios.txt", "a");
    
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    limpar_buffer();

    char nomeF[30], emailF[100], senhaF[20];

    printf("Digite o nome: ");
    fgets(nomeF, sizeof(nomeF), stdin);
    nomeF[strcspn(nomeF, " \n")] = 0;

    printf("Digite o email: ");
    fgets(emailF, sizeof(emailF), stdin);
    emailF[strcspn(emailF, " \n")] = 0;

    printf("Digite a senha: ");
    fgets(senhaF, sizeof(senhaF), stdin);
    senhaF[strcspn(senhaF, " \n")] = 0;

    fprintf(fp, "====================\nNome: %s\nEmail: %s\nSenha: %s\n====================\n", nomeF, emailF, senhaF);
    fclose(fp);

    printf("Cadastrado com sucesso");
}


void cadastrar_cliente() {
    FILE *fp = fopen("../dados/cliente.txt", "a");
    
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    limpar_buffer();

    char nomeC[30], emailC[100], senhaC[20];

    printf("Digite o nome: ");
    fgets(nomeC, sizeof(nomeC), stdin);
    nomeC[strcspn(nomeC, " \n")] = 0;

    printf("Digite o email: ");
    fgets(emailC, sizeof(emailC), stdin);
    emailC[strcspn(emailC, " \n")] = 0;

    printf("Digite a senha: ");
    fgets(senhaC, sizeof(senhaC), stdin);
    senhaC[strcspn(senhaC, " \n")] = 0;

    fprintf(fp, "====================\nNome: %s\nEmail: %s\nSenha: %s\n====================\n", nomeC, emailC, senhaC);
    fclose(fp);

    printf("Cadastrado com sucesso");
}

int main(){
    setlocale(LC_ALL, "");
    system("chcp 65001");

    printf("\n\n ====================================================================================\n");
    printf(" *       ____      _             _         _____ _                                 *\n");
    printf(" *      / __ \\    | |           | |       / ____| |                                *\n");
    printf(" *     | |  | | __| | ___  _ __ | |_ ___ | |    | | ___  __ _ _ __                 *\n");
    printf(" *     | |  | |/ _` |/ _ \\| '_ \\| __/ _ \\| |    | |/ _ \\/ _` | '_ \\                *\n");
    printf(" *     | |__| | (_| | (_) | | | | || (_) | |____| |  __/ (_| | | | |               *\n");
    printf(" *      \\____/ \\__,_|\\___/|_| |_|\\__\\___/ \\_____|_|\\___|\\__,_|_| |_|               *\n");
    printf(" *                                                                                 *\n");
    printf(" ====================================================================================\n");

    char enter;

    printf("   | Seja bem-vindo(a) à OdontoClean, onde cuidar do seu sorriso é a nossa |\n");
    printf("   | prioridade!                                                             |\n");
    printf("   |                                                                         |\n");
    printf("   | Somos uma clínica odontológica comprometida com a excelência no      |\n");
    printf("   | atendimento, unindo tecnologia de ponta, profissionais especializados   |\n");
    printf("   | e um ambiente acolhedor para proporcionar a você a melhor experiência |\n");
    printf("   | em saúde bucal.                                                        |\n");
    printf("   |                                                                         |\n");
    printf("   | Na OdontoClean, acreditamos que cada sorriso é único. E por isso      |\n");
    printf("   | oferecemos um atendimento personalizado, focado em conforto, segurança |\n");
    printf("   | e resultados duradouros. Do check-up à estética, estamos prontos para |\n");
    printf("   | transformar a sua relação com o dentista.                             |\n");
    printf("    =========================================================================\n");
    printf("Pressione 'ENTER' para prosseguir.");
    enter = getchar();
    
    system("cls");

    int opcao1, opcao2, opcaoFun1, opcaoC_1; //escolhas
    int senhaADM; //senha ADM
    
    while (1) {
        printf("\n---------------------------------\n");
        printf("|Bem vindo ao menu OdontoClean\n|");
        printf("---------------------------------\n");
        printf("1 - Painel do Cliente\n");     
        printf("2 - Painel do Funcionario\n");     
        printf("3 - Ajuda\n");    
        printf("0 - Sair\n"); 
        printf("Escolha uma opcao:\n");
        scanf(" %d", &opcao1);

        switch (opcao1){
        case 0:
            printf("\nSaindo do sistema...\n");
            return 0;

        case 1: 
            printf(" Painel cliente\n"); 
            printf("1- Cadastar\n"); 
            printf("2- Login\n"); 
            printf("3- Prefiro nao realizar login\n"); 
            printf("0- Sair\n"); 
            scanf(" %i", &opcao2);
            switch (opcao2){
                case 0:
                    printf("\nSaindo do sistema...\n");
                    break;

                case 1: 
                    while (1) { 
                        printf("1 - Cadastro ");
                        printf("0 - Sair  "); 
                        if (opcaoC_1 == 1 ){ 
                            printf("Cadastro Cliente\n"); 
                            cadastrar_cliente();
                        } else if( opcaoC_1 == 0){ 
                            printf("Saindo do menu cadastro\n");
                            break;
                        }else{
                            printf("Escolha um opcao valida\n"); 
                        }
                    }
                    
                    break;
                    
                case 2:
                    
                    break;

                case 3:
                
                    break;
                
                default:
                    system("cls");
                    printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 
                    break;
                }//fim da opcao 2  
            break;    
            

        case 2: 

            printf("Painel Funcionario\n");
            printf("1-Cadastro do Funcionario\n");
            printf("2-Insira seu ID e Senha\n"); 
            printf("0- Sair\n"); 
            scanf(" %d", &opcaoFun1);
            switch (opcaoFun1){
                case 0:
                    printf("\nSaindo do sistema...\n");
                    break;
                case 1:
                    printf("Cadastro do funcionario: ");
                    scanf(" %i", &senhaADM);
                    while (senhaADM != 102938){
                        printf("Senha incorreta!. Tente novamente pressionando 'ENTER'\n");
                        enter = getchar();
                        system("cls");
                        printf("0- Sair: \n");
                        printf("Cadastro do funcionario: ");
                        scanf(" %i", &senhaADM);
                        if (senhaADM == 0){
                            printf("Saindo...");
                            break;
                        }
                    }
                    printf("Cadastro do funcionario\n");
                    cadastrar_funcionarios();
                    
                    break;

                case 2:

                    break;
                
                default:
                    system("cls");
                    printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 
                    break;
                }
            break;
            
        case 3: 
             printf(" Ajuda\n"); 
             printf("1- Chat bot\n"); 
             printf("2- Conversar com o atendente\n"); 
             printf("0- Sair\n"); 
            break;
             
        default:
            system("cls");
            printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 
            break;
             //fim da opcao 1     
        }   
    }

}
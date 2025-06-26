#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 256

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//cadastrar funcionarios
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

    fprintf(fp, "==========================\n Nome: %s\n Email: %s\n Senha: %s\n==========================\n", nomeF, emailF, senhaF);
    fclose(fp);

    printf("Cadastrado com sucesso");
}

//cadastrar clientes
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

    printf("Cadastrado com sucesso\n");
}

//login funcionarios
int loginF(const char *arquivo_db, const char *email_entra, const char *senha_entra) {
    FILE *arquivo = fopen(arquivo_db, "r");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.");
        return 0;
    }

    char linha[MAX_LINHA];
    char nome[100], email[100], senha[100];
    int encontrou = 0;
    char teste;

    while (fgets(linha, MAX_LINHA, arquivo)) {
        if (strncmp(linha, " Nome:", 6) == 0) {
            sscanf(linha, " Nome: %[^\n]", nome);
        } else if (strncmp(linha, " Email:", 7) == 0) {
            sscanf(linha, " Email: %[^\n]", email);
        } else if(strncmp(linha, " Senha:", 7) == 0) {
            sscanf(linha, " Senha: %[^\n]", senha);

            if (strcmp(email_entra, email) == 0) {
                if (strcmp(senha_entra, senha) == 0) {
                    printf("Login bem sucedido. Bem vindo: %s.\n", nome); //Colocar as funcionalidades quando entrar no funcionario
                    scanf(" %c", &teste);
                    encontrou = 1;


                    break;
                } else {
                    printf("Email encontrado, mas a senha está errada para o email: %s\n", email);
                    encontrou = 1;
                    break;
                }
            }
        }
    }

    fclose(arquivo);

    if (encontrou != 1) {
        printf("Email nao encontrado. \n");
        return 0;
    }

    return 1;
}

//login clientes
int loginC(const char *arquivo_db, const char *email_entra, const char *senha_entra) {
    FILE *arquivo = fopen(arquivo_db, "r");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.");
        return 0;
    }

    char linha[MAX_LINHA];
    char nome[100], email[100], senha[100];
    int encontrou = 0;
    char teste;

    while (fgets(linha, MAX_LINHA, arquivo)) {
        if (strncmp(linha, "Nome:", 5) == 0) {
            sscanf(linha, "Nome: %[^\n]", nome);
        } else if (strncmp(linha, "Email:", 6) == 0) {
            sscanf(linha, "Email: %[^\n]", email);
        } else if(strncmp(linha, "Senha:", 6) == 0) {
            sscanf(linha, "Senha: %[^\n]", senha);

            if (strcmp(email_entra, email) == 0) {
                if (strcmp(senha_entra, senha) == 0) {
                    printf("Login bem sucedido. Bem vindo: %s.\n", nome); //Colocar as funcionalidades quando entrar no funcionario
                    scanf(" %c", &teste);
                    encontrou = 1;


                    break;
                } else {
                    printf("Email encontrado, mas a senha está errada para o email: %s\n", email);
                    encontrou = 1;
                    break;
                }
            }
        }
    }

    fclose(arquivo);

    if (encontrou != 1) {
        printf("Email nao encontrado. \n");
        return 0;
    }

    return 1;
}

int main(){
    setlocale(LC_ALL, "");
    system("chcp 65001");

    char enter;

    printf("\n\n ====================================================================================\n");
    printf(" *       ____      _             _         _____ _                                 *\n");
    printf(" *      / __ \\    | |           | |       / ____| |                                *\n");
    printf(" *     | |  | | __| | ___  _ __ | |_ ___ | |    | | ___  __ _ _ __                 *\n");
    printf(" *     | |  | |/ _` |/ _ \\| '_ \\| __/ _ \\| |    | |/ _ \\/ _` | '_ \\                *\n");
    printf(" *     | |__| | (_| | (_) | | | | || (_) | |____| |  __/ (_| | | | |               *\n");
    printf(" *      \\____/ \\__,_|\\___/|_| |_|\\__\\___/ \\_____|_|\\___|\\__,_|_| |_|               *\n");
    printf(" *                                                                                 *\n");
    printf(" ====================================================================================\n");
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

    int opcao1, opcao2, opcaoFun1, opcaoC_1, opcaoC_2, opcaoC_3, opcaoMC_1, opcaoA_1; //escolhas
    int senhaADM; //senha ADM
    char opcaoCB_1;
    char emailF[100], senha[100], emailC[100], senhaC[100];//funcionairo
    
    while (1) {
        //system("cls");
        printf("========== Bem vindo ao menu OdontoClean ==========\n");
        printf("---------------------------------------------------\n");
        printf("| 1 - Painel do Cliente                            |\n");     
        printf("| 2 - Painel do Funcionario                        |\n");     
        printf("| 3 - Ajuda                                        |\n");    
        printf("| 0 - Sair                                         |\n"); 
        printf("---------------------------------------------------\n");
        printf("==================================================\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao1);

        switch (opcao1){
        case 0:
            printf("\nSaindo do sistema...\n");
            return 0;

        case 1: 
            system("cls");

            printf("================ PAINEL DO CLIENTE ================\n"); 
            printf("---------------------------------------------------\n");
            printf("| 1- Cadastar                                      |\n"); 
            printf("| 2- Login                                         |\n"); 
            printf("| 3- Prefiro nao realizar login                    |\n"); 
            printf("| 0- Sair                                          |\n");
            printf("---------------------------------------------------\n"); 
            printf("===================================================\n"); 
            printf("Escolha uma opcao: ");
            scanf(" %i", &opcao2);
            switch (opcao2){
                case 0:
                    printf("\nSaindo do sistema...\n");
                    break;

                case 1: 
                    while (1) { 
                        system("cls");
                        printf("\n========= Cadastro =========\n"); 
                        printf("| 1 - Cadastro             |\n");
                        printf("| 0 - Sair                 |\n"); 
                        printf("============================\n"); 
                        printf("Escolha uma opcao: ");
                        scanf(" %d", &opcaoC_1);

                        if(opcaoC_1 == 1 ){ 
                            printf("Cadastro Cliente\n"); 
                             cadastrar_cliente();//void clientes
                             break;

                        } else if( opcaoC_1 == 0){ 
                            printf("Saindo do menu cadastro...\n");
                            break;
                        }else{
                            printf("Escolha uma opcao valida\n"); 
                        }
                    }
                    
                    break;
                    
                case 2:
                    printf("\n========= Login =========\n"); 
                    printf("| 0- voltar               |\n");
                    printf("| 1- login                |\n");
                    printf("\n========================\n");
                    scanf(" %i", &opcaoC_2);
                    if(opcaoC_2 == 1){
                        limpar_buffer();
                        //Login funcionario
                        printf("Login do usuario\n");
                        printf("Email: ");
                        fgets(emailC, sizeof(emailC), stdin);
                        emailC[strcspn(emailC, "\n")] = 0;

                        printf("Senha: ");
                        fgets(senhaC, sizeof(senhaC), stdin);
                        senhaC[strcspn(senhaC, "\n")] = 0;

                        // Chama a função de login passando os dados e o nome do arquivo
                        loginC("../dados/cliente.txt", emailC, senhaC);
                        break;
                        
                    }else if (opcaoC_2 == 0){
                        printf("\n Saindo do sistema...\n");
                        break;
                    }else{
                        printf("opcao invalida!");
                    }

                    break;

                case 3:
                    printf("\n Seja bem vindo. Como desejaria realizar seu procedimento? \n");
                    printf(" 1- Marcar Consulta\n");
                    printf(" 2- Consulta ja marcada\n");
                    printf(" 0- Sair\n");
                    scanf(" %i", &opcaoC_3);
                        switch (opcaoC_3){
                            case 1:
                                printf("\n========= Marcar Consulta =========\n");
                                printf("| 1- 08/07 - 14:30\n");
                                printf("| 2- 09/07 - 15:00\n");
                                printf("| 3- 10/07 - 08:30\n");
                                printf("| 0- sair\n");
                                scanf(" %i", &opcaoMC_1);
                                    if(opcaoMC_1 == 0){
                                        printf("\nSaindo da Aréa de Marcação\n");
                                        //void 
                                    }
                        
                                break;
                                
                            default:
                                system("cls");
                                printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 
                                break;
                        }
                
                    break;
                
                default:
                    system("cls");
                    printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 
                    break;
                }//fim da opcao 2  
            break;    
            

        case 2:
            system("cls");

            printf("============== PAINEL DO FUNCIONARIO ==============\n");
            printf("---------------------------------------------------\n");
            printf("| 1- Cadastro do Funcionario                        |\n");
            printf("| 2- Login                                         |\n"); 
            printf("| 0- Sair                                          |\n"); 
            printf("---------------------------------------------------\n");
            printf("===================================================\n");
            printf("Escolha uma opcao: "); 
            scanf(" %d", &opcaoFun1);
            switch (opcaoFun1){
                case 0:
                    printf("\nSaindo do sistema...\n");
                    break;
                case 1:
                    printf("========= Cadastro do funcionario =========\n");

                    int tentativas = 3;
                    do {
                        printf("Digite a senha do ADM para prosseguir ('0' para sair): ");
                        scanf(" %i", &senhaADM);

                        if (senhaADM == 0) {
                            printf("Saindo do cadastro de funcionário...\n");
                            break;
                        }

                        if (senhaADM != 102938) {
                            tentativas--;
                            if (tentativas > 0) {
                                printf("Senha incorreta!!! Você tem %d tentativa(s) restante(s).\n\n", tentativas);
                            } else {
                                break;
                            }
                        }
                    } while (senhaADM != 102938 && tentativas > 0);

                    if (senhaADM == 102938) {
                        cadastrar_funcionarios();
                    }

                    break;

                case 2:
                    limpar_buffer();
                    //Login funcionario
                    printf("Login do funcionario\n");
                    printf("Email: ");
                    fgets(emailF, sizeof(emailF), stdin);
                    emailF[strcspn(emailF, "\n")] = 0;

                    printf("Senha: ");
                    fgets(senha, sizeof(senha), stdin);
                    senha[strcspn(senha, "\n")] = 0;

                    // Chama a função de login passando os dados e o nome do arquivo
                    loginF("../dados/funcionarios.txt", emailF, senha);
                    break;
                
                default:
                    system("cls");
                    printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 

                break;
            }
               
        case 3:
            while (1) {
                system("cls");

                printf("======= COMO PODERIAMOS TE AJUDAR? =======\n"); 
                printf("------------------------------------------\n");
                printf("| 1- Chat bot                             |\n"); 
                printf("| 2- Conversar com o atendente            |\n"); 
                printf("| 0- Sair                                 |\n");
                printf("------------------------------------------\n");
                printf("==========================================\n"); 
                printf("Escolha uma opcao: ");
                scanf(" %i", &opcaoA_1); 
                    switch (opcaoA_1){
                        case 0:
                            break;
                            
                        case 1:
                            system("cls");
                            printf("\n========== CHAT BOT ==========\n");
                            printf("Quer saber os horarios de atendimento? (S/N): ");
                            
                            scanf(" %c", &opcaoCB_1);

                            if (opcaoCB_1 == 'S' || opcaoCB_1 == 's') {
                                printf("\nNosso horário de atendimento é de segunda a sexta, das 8h às 18h.\n");
                            } else if (opcaoCB_1 == 'N' || opcaoCB_1 == 'n') {
                                printf("\nNão temos uma solução atualmente!\n");
                                printf("Tente contatar um atendente para solucionar o problema.");
                            } else {
                                printf("\nResposta inválida. Por favor, digite S ou N.\n");
                            }
                            break;
                        
                        case 2:
                            printf("\n===== BEM-VINDO AO ATENDIMENTO =====\n");
                            printf("Para conversar com um atendente:\n> Voce pode entrar em contato com nossos funcionarios: (61)9 9999-9999 ou (61)8 8888-8888\n");
                            printf("> Via E-mail: OdontoClean@gmaim.com \n");
                            printf("> Via Insta: @odontoclean_ofc\n");
                            printf("> Nosso grupo do Whatsapp: 'https://chat.whatsapp.com/JAXdRCX4T6EIDtKBfBfCZG'\n\n");
                            break;

                        default:
                            system("cls");
                            printf("\n OPCAO INVALIDA. TENTE NOVAMENTE!!! \n"); 
                            break;
                    }
                    break;
            }
        }   
    
    }
}
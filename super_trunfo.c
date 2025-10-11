#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função utilitária para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    // Introdução ao jogo
    printf("========================================\n");
    printf("          JOGO SUPER TRUNFO            \n");
    printf("========================================\n\n");
    printf("Bem-vindo ao Super Trunfo!\n\n");
    printf("Pressione Enter para iniciar o jogo...\n");
    getchar();

    int tela_atual = 0; // 0 = Menu inicial, 1 = Seleção de modo de jogo, 2 = Regras, 3 = Sair

    // 0 - String para o menu inicial
    char texto_menu_inicial[] = "\n========================================\n"
           "                MENU                   \n"
           "\n"
           "1. Iniciar Jogo\n"
           "2. Ver regras\n"
           "3. Sair\n"
           "\n"
           "Escolha uma opção digitando o número correspondente(1-3): \n";
    //1 - String para o menu de jogo
    char texto_jogo[] = "\n========================================\n"
            "Vamos começar!\n\n"
            "Escolha o modo de entrada de dados:\n"
            "0 - Entrada de dados pela CPU (modo demonstrativo)\n"
            "1 - Entrada de dados pelos usuários com atributo aleátorio\n"
            "2 - Entrada de dados pelos usuários com escolha do atributo\n"
            "3 - Voltar ao menu inicial\n"
            "========================================\n";
    //2 - Regras
    char texto_regras[] = "\n========================================\n"
        "                REGRAS                 \n"
        "1. Cada jogador escolhe ou cria uma carta com atributos de uma cidade.\n"
        "2. No modo demonstrativo a CPU escolhe um atributo aleatório para comparar.\n"
        "3. No modo usuário, cada jogador escolhe dois atributos.\n"
        "4. A carta com o maior valor no atributo (modo demonstrativo) ou soma dos atributos (modo usuário) ganha.\n"
        "========================================\n"
        "Digite 1 e clique Enter para voltar ao menu inicial:\n";
    
    //3 - Sair
    char texto_sair[] = "\n========================================\n"
           "          SAINDO DO JOGO               \n"
           "========================================\n";

    // Variáveis dos jogadores
    char str_cidade_jogador_A[33], str_cidade_jogador_B[33];
    int int_populacao_jogador_A = 0, int_populacao_jogador_B = 0;
    float float_area_jogador_A = 0, float_area_jogador_B = 0;
    float float_pib_jogador_A = 0, float_pib_jogador_B = 0;
    int qtde_pontos_turisticos_jogador_A = 0, qtde_pontos_turisticos_jogador_B = 0;

    while (1) {
        switch (tela_atual) {
        // 0 = Menu inicial, 1 = Seleção de modo de jogo, 2 = Regras, 3 = Sair
        case 0: /*Menu Inicial {1-Iniciar jogo / 2-Ver regras / 3-Sair}*/{
            printf("%s", texto_menu_inicial);
            char opcao[10];
            while (1) {
                fgets(opcao, sizeof(opcao), stdin);
                // switch para tratar escolha_menu
                switch (opcao[0]) {
                case '1': tela_atual = 1; limpar_buffer(); break;
                case '2': tela_atual = 2; limpar_buffer(); break;
                case '3': tela_atual = 3; limpar_buffer(); break;
                default: printf("Opção inválida. Por favor, escolha 1, 2 ou 3:\n"); continue;
            }
                break;  // sai do while interno
            }
            break; // sai do case 0
        case 1: {
            printf("%s", texto_jogo);
            int escolha_jogo = -1;
            while (1) {
                if (scanf("%d", &escolha_jogo) != 1) {
                    //limpar_buffer();
                    printf("Opção inválida. Por favor, escolha 0, 1, 2 ou 3: \n");
                    continue;
                }
                //limpar_buffer();
                if (escolha_jogo >= 0 && escolha_jogo <= 3) break;
                printf("Opção inválida. Por favor, escolha 0, 1, 2 ou 3: \n");
            }
            if (escolha_jogo == 0) {
                // CPU modo demonstrativo
                snprintf(str_cidade_jogador_A, sizeof(str_cidade_jogador_A), "Manaus");
                int_populacao_jogador_A = 2;
                float_area_jogador_A = 11401.0;
                float_pib_jogador_A = 74.0;
                qtde_pontos_turisticos_jogador_A = 8;

                snprintf(str_cidade_jogador_B, sizeof(str_cidade_jogador_B), "Sao Paulo");
                int_populacao_jogador_B = 12;
                float_area_jogador_B = 1521.0;
                float_pib_jogador_B = 443.0;
                qtde_pontos_turisticos_jogador_B = 15;
            } else if (escolha_jogo == 1) {
                printf("Modo usuário selecionado.\n");
                printf("\n========================================\n");
                printf("          CRIAÇÃO DAS CARTAS           \n");
                printf("========================================\n\n");
                // Jogador A
                while (1) {
                    printf("Primeiro vamos aos dados do jogador A.\n");
                    // Cidade
                    while (1) {
                        printf("Jogador A, pode me dizer qual a cidade da sua carta (máx 32 caracteres): \n");
                        if (fgets(str_cidade_jogador_A, sizeof(str_cidade_jogador_A), stdin) == NULL) {
                            printf("Erro ao ler o nome da cidade.\n");
                            continue;
                        }
                        size_t len = strlen(str_cidade_jogador_A);
                        if (len > 0 && str_cidade_jogador_A[len - 1] == '\n') {
                            str_cidade_jogador_A[len - 1] = '\0';
                            len--;
                        }
                        if (len == 0) {
                            printf("O nome da cidade não pode ser vazio.\n");
                            continue;
                        }
                        if (len == sizeof(str_cidade_jogador_A) - 1 && str_cidade_jogador_A[len - 1] != '\0') {
                            printf("Limite de caracteres excedido! Use até 32 caracteres.\n\n");
                            //limpar_buffer();
                            continue;
                        }
                        break;
                    }
                    // População
                    char buffer[64];
                    while (1) {
                        printf("Jogador A, pode me dizer qual a população da sua cidade em milhões (exemplo: se sua cidade tiver 300.000.000 digite 300): \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &int_populacao_jogador_A) != 1) {
                            printf("Valor inválido! Digite apenas números inteiros.\n");
                            continue;
                        }
                        break;
                    }
                    // Área
                    while (1) {
                        printf("Jogador A, pode me dizer qual a área da sua cidade em km²: \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%f", &float_area_jogador_A) != 1) {
                            printf("Valor inválido! Digite apenas números (pode usar ponto para decimais).\n");
                            continue;
                        }
                        break;
                    }
                    // PIB
                    while (1) {
                        printf("Jogador A, pode me dizer qual o PIB da sua cidade em bilhões: \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%f", &float_pib_jogador_A) != 1) {
                            printf("Valor inválido! Digite apenas números (pode usar ponto para decimais).\n");
                            continue;
                        }
                        break;
                    }
                    // Pontos turísticos
                    while (1) {
                        printf("Jogador A, pode me dizer quantos pontos turísticos a sua cidade tem: \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &qtde_pontos_turisticos_jogador_A) != 1) {
                            printf("Valor inválido! Digite apenas números inteiros.\n");
                            continue;
                        }
                        break;
                    }
                    printf("\nDados informados para Jogador A:\n");
                    printf("Cidade: %s\n", str_cidade_jogador_A);
                    printf("População: %d milhões\n", int_populacao_jogador_A);
                    printf("Área: %.2f km²\n", float_area_jogador_A);
                    printf("PIB: %.2f bilhões\n", float_pib_jogador_A);
                    printf("Pontos turísticos: %d\n", qtde_pontos_turisticos_jogador_A);
                    printf("Esses são os dados que você quer usar? (s para sim, n para não):\n");
                    char confirma_A;
                    //limpar_buffer();
                    scanf(" %c", &confirma_A);
                    //limpar_buffer();
                    if (confirma_A == 's' || confirma_A == 'S') break;
                    printf("Vamos começar novamente o cadastro do Jogador A!\n\n");
                }
                // Jogador B
                while (1) {
                    printf("\nAgora vamos aos dados do jogador B.\n");
                    // Cidade
                    while (1) {
                        printf("Jogador B, pode me dizer qual a cidade da sua carta (máx 32 caracteres): \n");
                        if (fgets(str_cidade_jogador_B, sizeof(str_cidade_jogador_B), stdin) == NULL) {
                            printf("Erro ao ler o nome da cidade.\n");
                            continue;
                        }
                        size_t len = strlen(str_cidade_jogador_B);
                        if (len > 0 && str_cidade_jogador_B[len - 1] == '\n') {
                            str_cidade_jogador_B[len - 1] = '\0';
                            len--;
                        }
                        if (len == 0) {
                            printf("O nome da cidade não pode ser vazio.\n");
                            continue;
                        }
                        if (len == sizeof(str_cidade_jogador_B) - 1 && str_cidade_jogador_B[len - 1] != '\0') {
                            printf("Limite de caracteres excedido! Use até 32 caracteres.\n\n");
                            //limpar_buffer();
                            continue;
                        }
                        break;
                    }
                    // População
                    char buffer[64];
                    while (1) {
                        printf("Jogador B, pode me dizer qual a população da sua cidade em milhões (exemplo: se sua cidade tiver 300.000.000 digite 300):\n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &int_populacao_jogador_B) != 1) {
                            printf("Valor inválido! Digite apenas números inteiros.\n");
                            continue;
                        }
                        break;
                    }
                    // Área
                    while (1) {
                        printf("Jogador B, pode me dizer qual a área da sua cidade em km²: \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%f", &float_area_jogador_B) != 1) {
                            printf("Valor inválido! Digite apenas números (pode usar ponto para decimais).\n");
                            continue;
                        }
                        break;
                    }
                    // PIB
                    while (1) {
                        printf("Jogador B, pode me dizer qual o PIB da sua cidade em bilhões: \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%f", &float_pib_jogador_B) != 1) {
                            printf("Valor inválido! Digite apenas números (pode usar ponto para decimais).\n");
                            continue;
                        }
                        break;
                    }
                    // Pontos turísticos
                    while (1) {
                        printf("Jogador B, pode me dizer quantos pontos turísticos a sua cidade tem: \n");
                        //limpar_buffer();
                        if (fgets(buffer, sizeof(buffer), stdin) == NULL || sscanf(buffer, "%d", &qtde_pontos_turisticos_jogador_B) != 1) {
                            printf("Valor inválido! Digite apenas números inteiros.\n");
                            continue;
                        }
                        break;
                    }
                    printf("\nDados informados para Jogador B:\n");
                    printf("Cidade: %s\n", str_cidade_jogador_B);
                    printf("População: %d milhões\n", int_populacao_jogador_B);
                    printf("Área: %.2f km²\n", float_area_jogador_B);
                    printf("PIB: %.2f bilhões\n", float_pib_jogador_B);
                    printf("Pontos turísticos: %d\n", qtde_pontos_turisticos_jogador_B);
                    printf("Esses são os dados que você quer usar? (s para sim, n para não):\n");
                    char confirma_B;
                    //limpar_buffer();
                    scanf(" %c", &confirma_B);
                    //limpar_buffer();
                    if (confirma_B == 's' || confirma_B == 'S') break;
                    printf("Vamos começar novamente o cadastro do Jogador B!\n\n");
                }
            } else if (escolha_jogo == 2) {
                // Modo usuário com escolha do atributo (não implementado)
                printf("Modo de escolha do atributo ainda não implementado.\n");
                tela_atual = 0;
                break;
            } else if (escolha_jogo == 3) {
                tela_atual = 0;
                break;
            }

            // CPU escolhe atributo e faz comparação
            srand((unsigned int)time(NULL));
            int aleatorio = (rand() % 7) + 1;

            printf("\nA CPU escolheu o atributo número %d para comparar!\n", aleatorio);
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. Densidade populacional\n");
            printf("4. PIB\n");
            printf("5. PIB per capita\n");
            printf("6. Pontos turísticos\n");
            printf("7. Super Poder\n\n");

            if (aleatorio == 1) {
                printf("Atributo escolhido: População\n");
                printf("Jogador A: %d milhões\n", int_populacao_jogador_A);
                printf("Jogador B: %d milhões\n", int_populacao_jogador_B);
                if (int_populacao_jogador_A > int_populacao_jogador_B) {
                    printf("Jogador A venceu na população!\n");
                } else if (int_populacao_jogador_A < int_populacao_jogador_B) {
                    printf("Jogador B venceu na população!\n");
                } else {
                    printf("Empate na população!\n");
                }
            } else if (aleatorio == 2) {
                printf("Atributo escolhido: Área\n");
                printf("Jogador A: %.2f km²\n", float_area_jogador_A);
                printf("Jogador B: %.2f km²\n", float_area_jogador_B);
                if (float_area_jogador_A > float_area_jogador_B) {
                    printf("Jogador A venceu na área!\n");
                } else if (float_area_jogador_A < float_area_jogador_B) {
                    printf("Jogador B venceu na área!\n");
                } else {
                    printf("Empate na área!\n");
                }
            } else if (aleatorio == 3) {
                printf("Atributo escolhido: Densidade populacional\n");
                double densidade_A = (float)(int_populacao_jogador_A * 1000000) / float_area_jogador_A;
                double densidade_B = (float)(int_populacao_jogador_B * 1000000) / float_area_jogador_B;
                printf("Jogador A: %.2f hab/km²\n", densidade_A);
                printf("Jogador B: %.2f hab/km²\n", densidade_B);
                if (densidade_A < densidade_B) {
                    printf("Jogador A venceu na densidade populacional!\n");
                } else if (densidade_A > densidade_B) {
                    printf("Jogador B venceu na densidade populacional!\n");
                } else {
                    printf("Empate na densidade populacional!\n");
                }
            } else if (aleatorio == 4) {
                printf("Atributo escolhido: PIB\n");
                printf("Jogador A: %.2f bilhões\n", float_pib_jogador_A);
                printf("Jogador B: %.2f bilhões\n", float_pib_jogador_B);
                if (float_pib_jogador_A > float_pib_jogador_B) {
                    printf("Jogador A venceu no PIB!\n");
                } else if (float_pib_jogador_A < float_pib_jogador_B) {
                    printf("Jogador B venceu no PIB!\n");
                } else {
                    printf("Empate no PIB!\n");
                }
            } else if (aleatorio == 5) {
                printf("Atributo escolhido: PIB per capita\n");
                double per_capita_A = (float_pib_jogador_A * 1000000000) / (float)(int_populacao_jogador_A * 1000000);
                double per_capita_B = (float_pib_jogador_B * 1000000000) / (float)(int_populacao_jogador_B * 1000000);
                printf("Jogador A: R$ %.2f\n", per_capita_A);
                printf("Jogador B: R$ %.2f\n", per_capita_B);
                if (per_capita_A > per_capita_B) {
                    printf("Jogador A venceu no PIB per capita!\n");
                } else if (per_capita_A < per_capita_B) {
                    printf("Jogador B venceu no PIB per capita!\n");
                } else {
                    printf("Empate no PIB per capita!\n");
                }
            } else if (aleatorio == 6) {
                printf("Atributo escolhido: Pontos turísticos\n");
                printf("Jogador A: %d pontos\n", qtde_pontos_turisticos_jogador_A);
                printf("Jogador B: %d pontos\n", qtde_pontos_turisticos_jogador_B);
                if (qtde_pontos_turisticos_jogador_A > qtde_pontos_turisticos_jogador_B) {
                    printf("Jogador A venceu nos pontos turísticos!\n");
                } else if (qtde_pontos_turisticos_jogador_A < qtde_pontos_turisticos_jogador_B) {
                    printf("Jogador B venceu nos pontos turísticos!\n");
                } else {
                    printf("Empate nos pontos turísticos!\n");
                }
            } else if (aleatorio == 7) {
                printf("Atributo escolhido: Super Poder\n");
                double densidade_A = (float)(int_populacao_jogador_A * 1000000) / float_area_jogador_A;
                double densidade_B = (float)(int_populacao_jogador_B * 1000000) / float_area_jogador_B;
                double per_capita_A = (float_pib_jogador_A * 1000000000) / (float)(int_populacao_jogador_A * 1000000);
                double per_capita_B = (float_pib_jogador_B * 1000000000) / (float)(int_populacao_jogador_B * 1000000);
                double super_poder_A = (double)(int_populacao_jogador_A * 1000000) + float_area_jogador_A + float_pib_jogador_A +
                                       qtde_pontos_turisticos_jogador_A + per_capita_A + (1 / densidade_A);
                double super_poder_B = (double)(int_populacao_jogador_B * 1000000) + float_area_jogador_B + float_pib_jogador_B +
                                       qtde_pontos_turisticos_jogador_B + per_capita_B + (1 / densidade_B);
                printf("Jogador A: %.2f pontos\n", super_poder_A);
                printf("Jogador B: %.2f pontos\n", super_poder_B);
                if (super_poder_A > super_poder_B) {
                    printf("Jogador A venceu no Super Poder!\n");
                } else if (super_poder_A < super_poder_B) {
                    printf("Jogador B venceu no Super Poder!\n");
                } else {
                    printf("Empate no Super Poder!\n");
                }
            }
            printf("\nObrigado por jogar! :)\n");
            printf("\n========================================\n");
            printf("Aperte Enter para continuar...");
            getchar();  // Aguarda o usuário pressionar Enter
            getchar();  // Captura o Enter
            printf("\n========================================\n");
            tela_atual = 0;
            break;
        }
        case 2: {
            printf("%s", texto_regras);
            int opcao = 0;
            while (1) {
                if (scanf("%d", &opcao) != 1) {
                    //limpar_buffer();
                    printf("\nPor favor digite 1 para voltar ao menu inicial:\n");
                    continue;
                }
                //limpar_buffer();
                if (opcao == 1) break;
                printf("\nPor favor digite 1 para voltar ao menu inicial: ");
            }
            tela_atual = 0;
            break;
        }
        case 3: {
            printf("%s", texto_sair);
            printf("Saindo do jogo. Até a próxima!\n");
            return 0;
        }
        default: {
            printf("Erro: Tela desconhecida. Voltando ao menu inicial.\n");
            tela_atual = 0;
            break;
        }
        }
    }
    return 0;
}

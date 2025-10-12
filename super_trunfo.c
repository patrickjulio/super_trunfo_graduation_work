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
   { // Introdução ao jogo
    printf("========================================\n");
    printf("          JOGO SUPER TRUNFO            \n");
    printf("========================================\n\n");
    printf("Bem-vindo ao Super Trunfo!\n\n");
    printf("Pressione Enter para iniciar o jogo...\n");
    getchar();
    limpar_buffer();
   }

    {// Textos do jogo
        typedef struct {
        char menu[1024];
        char jogo[1024];
        char regras[1024];
        char sair[1024];
    } Textos;

        Textos textos = {
        .menu =
            "\n========================================\n"
            "                MENU                   \n"
            "\n"
            "1. Iniciar Jogo\n"
            "2. Ver regras\n"
            "3. Sair\n"
            "\n"
            "Escolha uma opção digitando o número correspondente(1-3): \n",

        .jogo =
            "\n========================================\n"
            "Vamos começar!\n\n"
            "Escolha o modo de entrada de dados:\n"
            "1 - Entrada de dados pela CPU (modo demonstrativo)\n"
            "2 - Entrada de dados pelos usuários com atributo aleátorio\n"
            "3 - Voltar ao menu inicial\n"
            "========================================\n",

        .regras =
            "\n========================================\n"
            "                REGRAS                 \n"
            "1. Cada jogador escolhe ou cria uma carta com atributos de uma cidade.\n"
            "2. No modo demonstrativo a CPU escolhe um atributo aleatório para comparar.\n"
            "3. No modo usuário, cada jogador escolhe dois atributos.\n"
            "4. A carta com o maior valor no atributo (modo demonstrativo) ou soma dos atributos (modo usuário) ganha.\n"
            "========================================\n"
            "Digite 1 e clique Enter para voltar ao menu inicial:\n",

        .sair =
            "\n========================================\n"
            "          SAINDO DO JOGO               \n"
            "========================================\n"
        };
}

    {// Cartas
    // O jogo é orientado a cartas, não jogadores. Existem 08 cartas já prontas, mas cada
    //um dos dois jogadores pode criar sua própria carta.

    typedef struct {
        char cidade[33]; // Nome da cidade (máx 32 caracteres + '\0')
        int populacao;   // População em milhões
        float area;     // Área em km²
        float pib;      // PIB em bilhões
        int pontos_turisticos; // Quantidade de pontos turísticos
    } Carta;

    Carta carta_Manaus;
    strncpy(carta_Manaus.cidade, "Manaus", sizeof(carta_Manaus.cidade) - 1);
    carta_Manaus.cidade[32] = '\0';
    carta_Manaus.populacao = 2;
    carta_Manaus.area = 11401.0;
    carta_Manaus.pib = 74.0;
    carta_Manaus.pontos_turisticos = 8;

    Carta carta_SaoPaulo;
    strncpy(carta_SaoPaulo.cidade, "Sao Paulo", sizeof(carta_SaoPaulo.cidade) - 1);
    carta_SaoPaulo.cidade[32] = '\0';
    carta_SaoPaulo.populacao = 12;
    carta_SaoPaulo.area = 1521.0;
    carta_SaoPaulo.pib = 443.0;
    carta_SaoPaulo.pontos_turisticos = 15;

    Carta carta_RioDeJaneiro;
    strncpy(carta_RioDeJaneiro.cidade, "Rio de Janeiro", sizeof(carta_RioDeJaneiro.cidade) - 1);
    carta_RioDeJaneiro.cidade[32] = '\0';
    carta_RioDeJaneiro.populacao = 6;
    carta_RioDeJaneiro.area = 1182.0;
    carta_RioDeJaneiro.pib = 200.0;
    carta_RioDeJaneiro.pontos_turisticos = 10;

    Carta carta_Brasilia;
    strncpy(carta_Brasilia.cidade, "Brasilia", sizeof(carta_Brasilia.cidade) - 1);
    carta_Brasilia.cidade[32] = '\0';
    carta_Brasilia.populacao = 3;
    carta_Brasilia.area = 5802.0;
    carta_Brasilia.pib = 220.0;
    carta_Brasilia.pontos_turisticos = 5;

    Carta carta_Salvador;
    strncpy(carta_Salvador.cidade, "Salvador", sizeof(carta_Salvador.cidade) - 1);
    carta_Salvador.cidade[32] = '\0';
    carta_Salvador.populacao = 3;
    carta_Salvador.area = 693.0;
    carta_Salvador.pib = 130.0;
    carta_Salvador.pontos_turisticos = 7;

    Carta carta_Fortaleza;
    strncpy(carta_Fortaleza.cidade, "Fortaleza", sizeof(carta_Fortaleza.cidade) - 1);
    carta_Fortaleza.cidade[32] = '\0';
    carta_Fortaleza.populacao = 2;
    carta_Fortaleza.area = 313.0;
    carta_Fortaleza.pib = 90.0;
    carta_Fortaleza.pontos_turisticos = 6;

    Carta carta_BeloHorizonte;
    strncpy(carta_BeloHorizonte.cidade, "Belo Horizonte", sizeof(carta_BeloHorizonte.cidade) - 1);
    carta_BeloHorizonte.cidade[32] = '\0';
    carta_BeloHorizonte.populacao = 2;
    carta_BeloHorizonte.area = 331.0;
    carta_BeloHorizonte.pib = 110.0;
    carta_BeloHorizonte.pontos_turisticos = 4;

    Carta carta_Curitiba;
    strncpy(carta_Curitiba.cidade, "Curitiba", sizeof(carta_Curitiba.cidade) - 1);
    carta_Curitiba.cidade[32] = '\0';
    carta_Curitiba.populacao = 2;
    carta_Curitiba.area = 435.0;
    carta_Curitiba.pib = 150.0;
    carta_Curitiba.pontos_turisticos = 3;

    Carta carta_jogador_A;
    strncpy(carta_jogador_A.cidade, "", sizeof(carta_jogador_A.cidade) - 1);
    carta_jogador_A.cidade[32] = '\0';
    carta_jogador_A.populacao = 0;
    carta_jogador_A.area = 0.0;
    carta_jogador_A.pib = 0.0;
    carta_jogador_A.pontos_turisticos = 0;

    Carta carta_jogador_B;
    strncpy(carta_jogador_B.cidade, "", sizeof(carta_jogador_B.cidade) - 1);
    carta_jogador_B.cidade[32] = '\0';
    carta_jogador_B.populacao = 0;
    carta_jogador_B.area = 0.0;
    carta_jogador_B.pib = 0.0;
    carta_jogador_B.pontos_turisticos = 0;
    }

    {//Jogo
        int tela_atual = 0; // 1 = Menu inicial, 1 = Seleção de modo de jogo, 2 = Regras, 3 = Sair

        while (1) {
            switch (tela_atual) {
                // 0 = Menu inicial, 1 = Seleção de modo de jogo, 2 = Regras, 3 = Sair, 4 = Créditos
                case 0: { // Menu Inicial
                    printf("%s", textos.menu);
                    int opcao;

                    while (1) {
                        if (scanf("%d", &opcao) != 1) { // Verifica se a entrada é um número
                            limpar_buffer();
                            printf("Opção inválida. Por favor, escolha 1, 2 ou 3:\n");
                            continue;
                        }
                    switch (opcao) {
                        case 1:{
                            tela_atual = 1;
                        break;
                        }
                        case 2:{
                            tela_atual = 2;
                        break;
                        }
                        case 3:{
                            tela_atual = 3;
                        break;
                        }
                        default:{
                            printf("Opção inválida. Por favor, escolha 1, 2 ou 3:\n");
                        continue;}
                    }
                    break; // sai do while interno
                    }
                    break; // sai do case 0
                }
                case 1: { // Seleção de modo de jogo
                    printf("%s", textos.jogo);
                    int escolha_jogo = -1;
                    while (escolha_jogo < 0 || escolha_jogo > 3) {
                        if (scanf("%d", &escolha_jogo) != 1) { // Verifica se a entrada é um número
                            limpar_buffer();
                            printf("Opção inválida. Por favor, escolha 0, 1, 2 ou 3: \n");
                            continue;
                        }
                    }
                    switch (escolha_jogo){
                        int carta_escolhida_jogador_1 = -1;
                        int carta_escolhida_jogador_2 = -1;
                        case 0:{ // CPU modo demonstrativo (escolhe duas cartas prontas de 08 cartas)
                            printf("Modo demonstrativo selecionado.\n");
                            printf("\n========================================\n");
                            printf("          MODO DEMONSTRATIVO           \n");
                            printf("========================================\n\n")
                            srand((unsigned int)time(NULL));
                            carta_escolhida_jogador_1 = (rand() % 7) + 1;
                            printf("\nA CPU escolheu a carta número %d para comparar!\n", carta_escolhida_jogador_1);
                            printf("1. Manaus\n");
                            printf("2. São Paulo\n");
                            printf("3. Densidade populacional\n");
                            printf("4. PIB\n");
                            printf("5. PIB per capita\n");
                            printf("6. Pontos turísticos\n");
                            printf("7. Super Poder\n\n");
                            break;
                        }
                        case 1:{ // Modo usuário com atributo aleatório (escolha duas cartas prontas ou crie duas novas)
                            printf("\n========================================\n");
                            printf("   MODO USUÁRIO COM ATRIBUTO ALEATÓRIO   \n");
                            printf("========================================\n\n");
                            while (carta_escolhida_jogador_1 < 0 || carta_escolhida_jogador_1 > 7) {
                                if scanf("%d", &carta_escolhida_jogador_1) != 1 {
                                    limpar_buffer();
                                    printf("Opção inválida. Por favor, escolha um carta de 0 a 7:\n");
                                    continue;
                                }
                            }
                                switch (carta_escolhida_jogador_1){
                                case 0: {// Manaus
                                    /* code */
                                break;
                                }
                                case 1: {// Sao Paulo
                                    /* code */
                                break;
                                }
                                case 2: {// Rio de Janeiro
                                    /* code */
                                break;
                                }
                                case 3: {// Brasilia 
                                    /* code */
                                break;
                                }
                                case 4: {// Salvador
                                    /* code */
                                break;
                                }
                                case 5:{ // Fortaleza
                                    /* code */
                                break;
                                }
                                case 6:{ // Belo Horizonte
                                    /* code */
                                break;
                                }
                                case 7:{ // Curitiba
                                    /* code */
                                break;
                                }
                                default: printf("Opção inválida. Por favor, escolha um número de 0 a 7:\n");
                                break;
                                } 
                                break;
                        }
                        case 2:{ // Modo usuário com escolha do atributo (escolha duas cartas prontas ou crie duas novas)
                            /* code */
                        break;
                        }
                        case 3:{ // Voltar ao menu inicial
                            /* code */
                        break;
                        } 
                        default:{ printf("Opção inválida. Por favor, escolha 0, 1, 2 ou 3:\n");
                            continue;
                        break;
                        }
                    }
                }
                case 2: { // Regras
                    printf("%s", textos.regras);
                    int opcao = 0;
                    while (1) {
                        if (scanf("%d", &opcao) != 1) {
                            limpar_buffer();
                            printf("\nPor favor digite 1 para voltar ao menu inicial:\n");
                            continue;
                        }
                        limpar_buffer();
                        if (opcao == 1) break;
                        printf("\nPor favor digite 1 para voltar ao menu inicial: ");
                    }
                    tela_atual = 0;
                    break;
                 }
                case 3: { // Sair
                    printf("%s", textos.sair);
                    printf("Saindo do jogo. Até a próxima!\n");
                    return 0;
                }
                
                default: { // Erro: tela desconhecida
                    printf("Erro: Tela desconhecida. Voltando ao menu inicial.\n");
                    tela_atual = 0;
                    break;
                } 
            }

                {// Finalização do jogo - Créditos
                    printf("\nObrigado por jogar! :)\n");
                    printf("\n========================================\n");
                    printf("Aperte Enter para continuar...");
                    getchar();  // Aguarda o usuário pressionar Enter
                    getchar();  // Captura o Enter
                    printf("\n========================================\n");
                    tela_atual = 0;
                    break;
                }
        }
       return 0;
}
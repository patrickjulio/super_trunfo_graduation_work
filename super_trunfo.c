#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Identificadores de atributos
#define IDX_CIDADE 0
#define IDX_POPULACAO 1
#define IDX_AREA 2
#define IDX_PIB 3
#define IDX_PONTOS_TURISTICOS 4
#define IDX_DENSIDADE 5
#define IDX_PIB_PER_CAPITA 6
#define IDX_SUPER_PODER 7

// Função utilitária para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Definição do tipo Carta (colocada em escopo global)
typedef struct {
    char cidade[33]; // Nome da cidade (máx 32 caracteres + '\0')
    float populacao;   // População em milhões
    float area;     // Área em km²
    float pib;      // PIB em bilhões
    int pontos_turisticos; // Quantidade de pontos turísticos
    float densidade_populacional; // População por km²
    float pib_per_capita; // PIB per capita
    float super_poder; // Soma dos atributos para o modo usuário
} Carta;

// Função para acessar atributos númericos das cartas
float acessarAtributo(Carta* carta, int indice) {
    switch (indice) {
        case IDX_POPULACAO: return carta->populacao;
        case IDX_AREA: return carta->area;
        case IDX_PIB: return carta->pib;
        case IDX_PONTOS_TURISTICOS: return (float)carta->pontos_turisticos;
        case IDX_DENSIDADE: return carta->densidade_populacional;
        case IDX_PIB_PER_CAPITA: return carta->pib_per_capita;
        case IDX_SUPER_PODER: return carta->super_poder;
        default: return -1.0f; // índice inválido ou não numérico
    }
}

// Função para acessar o nome da cidade
const char* acessarNomeCidade(Carta* carta) {
    return carta->cidade;
}

// Função principal
int main(void) {
    // Telas do jogo
        typedef struct {
            char intro[1024];
            char menu_inicial[1024];
            char seleção_de_modo_de_jogo[1024];
            char regras[1024];
            char sair[1024];
            char créditos[1024];
        } Tela;

        Tela telas = {
        .intro =
            "\n========================================\n"
            "          JOGO SUPER TRUNFO            \n"
            "========================================\n\n"
            "Bem-vindo ao Super Trunfo!\n\n"
            "Pressione Enter para iniciar o jogo...\n",
        .menu_inicial =
            "\n========================================\n"
            "                MENU                   \n"
            "\n"
            "1. Iniciar Jogo\n"
            "2. Ver regras\n"
            "3. Sair\n"
            "\n"
            "Escolha uma opção digitando o número correspondente(1-3): \n",

        .seleção_de_modo_de_jogo =
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
            "Obrigado por jogar! Até a próxima!\n",
        .créditos =
            "\n========================================\n"
            "                CRÉDITOS                \n"
            "========================================\n"
            "Desenvolvido por:\n"
            " - Aluno 1\n"
            " - Aluno 2\n"
            " - Aluno 3\n"
            " - Aluno 4\n"
            " - Aluno 5\n"
            "========================================\n"
            "Aperte Enter para voltar ao menu inicial...\n"
        };

    // Cartas (instâncias de `Carta` declaradas abaixo)
    Carta carta_Manaus;
    strncpy(carta_Manaus.cidade, "Manaus", sizeof(carta_Manaus.cidade) - 1);
    carta_Manaus.cidade[sizeof(carta_Manaus.cidade)-1] = '\0';
    carta_Manaus.populacao = 2;
    carta_Manaus.area = 11401.0;
    carta_Manaus.pib = 74.0;
    carta_Manaus.pontos_turisticos = 8;
    if (carta_Manaus.area != 0.0f)
        carta_Manaus.densidade_populacional = carta_Manaus.populacao * 1000000 / carta_Manaus.area;
    else
        carta_Manaus.densidade_populacional = 0.0f;
    if (carta_Manaus.populacao != 0.0f)
        carta_Manaus.pib_per_capita = (carta_Manaus.pib * 1000000000) / (carta_Manaus.populacao * 1000000);
    else
        carta_Manaus.pib_per_capita = 0.0f;
    carta_Manaus.super_poder = carta_Manaus.populacao * 1000000 + carta_Manaus.area + carta_Manaus.pib +
                               carta_Manaus.pontos_turisticos + carta_Manaus.pib_per_capita +
                               (carta_Manaus.densidade_populacional != 0.0f ? 1.0f / carta_Manaus.densidade_populacional : 0.0f);

    Carta carta_SaoPaulo;
    strncpy(carta_SaoPaulo.cidade, "Sao Paulo", sizeof(carta_SaoPaulo.cidade) - 1);
    carta_SaoPaulo.cidade[sizeof(carta_SaoPaulo.cidade)-1] = '\0';
    carta_SaoPaulo.populacao = 12;
    carta_SaoPaulo.area = 1521.0;
    carta_SaoPaulo.pib = 443.0;
    carta_SaoPaulo.pontos_turisticos = 15;
    if (carta_SaoPaulo.area != 0.0f)
        carta_SaoPaulo.densidade_populacional = carta_SaoPaulo.populacao * 1000000 / carta_SaoPaulo.area;
    else
        carta_SaoPaulo.densidade_populacional = 0.0f;
    if (carta_SaoPaulo.populacao != 0.0f)
        carta_SaoPaulo.pib_per_capita = (carta_SaoPaulo.pib * 1000000000) / (carta_SaoPaulo.populacao * 1000000);
    else
        carta_SaoPaulo.pib_per_capita = 0.0f;
    carta_SaoPaulo.super_poder = carta_SaoPaulo.populacao * 1000000 + carta_SaoPaulo.area + carta_SaoPaulo.pib +
                                 carta_SaoPaulo.pontos_turisticos + carta_SaoPaulo.pib_per_capita +
                                 (carta_SaoPaulo.densidade_populacional != 0.0f ? 1.0f / carta_SaoPaulo.densidade_populacional : 0.0f);

    Carta carta_RioDeJaneiro;
    strncpy(carta_RioDeJaneiro.cidade, "Rio de Janeiro", sizeof(carta_RioDeJaneiro.cidade) - 1);
    carta_RioDeJaneiro.cidade[sizeof(carta_RioDeJaneiro.cidade)-1] = '\0';
    carta_RioDeJaneiro.populacao = 6;
    carta_RioDeJaneiro.area = 1182.0;
    carta_RioDeJaneiro.pib = 200.0;
    carta_RioDeJaneiro.pontos_turisticos = 10;
    if (carta_RioDeJaneiro.area != 0.0f)
        carta_RioDeJaneiro.densidade_populacional = carta_RioDeJaneiro.populacao * 1000000 / carta_RioDeJaneiro.area;
    else
        carta_RioDeJaneiro.densidade_populacional = 0.0f;
    if (carta_RioDeJaneiro.populacao != 0.0f)
        carta_RioDeJaneiro.pib_per_capita = (carta_RioDeJaneiro.pib * 1000000000) / (carta_RioDeJaneiro.populacao * 1000000);
    else
        carta_RioDeJaneiro.pib_per_capita = 0.0f;
    carta_RioDeJaneiro.super_poder = carta_RioDeJaneiro.populacao * 1000000 + carta_RioDeJaneiro.area + carta_RioDeJaneiro.pib +
                                     carta_RioDeJaneiro.pontos_turisticos + carta_RioDeJaneiro.pib_per_capita +
                                     (carta_RioDeJaneiro.densidade_populacional != 0.0f ? 1.0f / carta_RioDeJaneiro.densidade_populacional : 0.0f);

    Carta carta_Brasilia;
    strncpy(carta_Brasilia.cidade, "Brasilia", sizeof(carta_Brasilia.cidade) - 1);
    carta_Brasilia.cidade[sizeof(carta_Brasilia.cidade)-1] = '\0';
    carta_Brasilia.populacao = 3;
    carta_Brasilia.area = 5802.0;
    carta_Brasilia.pib = 220.0;
    carta_Brasilia.pontos_turisticos = 5;
    if (carta_Brasilia.area != 0.0f)
        carta_Brasilia.densidade_populacional = carta_Brasilia.populacao * 1000000 / carta_Brasilia.area;
    else
        carta_Brasilia.densidade_populacional = 0.0f;
    if (carta_Brasilia.populacao != 0.0f)
        carta_Brasilia.pib_per_capita = (carta_Brasilia.pib * 1000000000) / (carta_Brasilia.populacao * 1000000);
    else
        carta_Brasilia.pib_per_capita = 0.0f;
    carta_Brasilia.super_poder = carta_Brasilia.populacao * 1000000 + carta_Brasilia.area + carta_Brasilia.pib +
                                 carta_Brasilia.pontos_turisticos + carta_Brasilia.pib_per_capita +
                                 (carta_Brasilia.densidade_populacional != 0.0f ? 1.0f / carta_Brasilia.densidade_populacional : 0.0f);

    Carta carta_Salvador;
    strncpy(carta_Salvador.cidade, "Salvador", sizeof(carta_Salvador.cidade) - 1);
    carta_Salvador.cidade[sizeof(carta_Salvador.cidade)-1] = '\0';
    carta_Salvador.populacao = 3;
    carta_Salvador.area = 693.0;
    carta_Salvador.pib = 130.0;
    carta_Salvador.pontos_turisticos = 7;
    if (carta_Salvador.area != 0.0f)
        carta_Salvador.densidade_populacional = carta_Salvador.populacao * 1000000 / carta_Salvador.area;
    else
        carta_Salvador.densidade_populacional = 0.0f;
    if (carta_Salvador.populacao != 0.0f)
        carta_Salvador.pib_per_capita = (carta_Salvador.pib * 1000000000) / (carta_Salvador.populacao * 1000000);
    else
        carta_Salvador.pib_per_capita = 0.0f;
    carta_Salvador.super_poder = carta_Salvador.populacao * 1000000 + carta_Salvador.area + carta_Salvador.pib +
                                 carta_Salvador.pontos_turisticos + carta_Salvador.pib_per_capita +
                                 (carta_Salvador.densidade_populacional != 0.0f ? 1.0f / carta_Salvador.densidade_populacional : 0.0f);

    Carta carta_Fortaleza;
    strncpy(carta_Fortaleza.cidade, "Fortaleza", sizeof(carta_Fortaleza.cidade) - 1);
    carta_Fortaleza.cidade[sizeof(carta_Fortaleza.cidade)-1] = '\0';
    carta_Fortaleza.populacao = 2;
    carta_Fortaleza.area = 313.0;
    carta_Fortaleza.pib = 90.0;
    carta_Fortaleza.pontos_turisticos = 6;
    if (carta_Fortaleza.area != 0.0f)
        carta_Fortaleza.densidade_populacional = carta_Fortaleza.populacao * 1000000 / carta_Fortaleza.area;
    else
        carta_Fortaleza.densidade_populacional = 0.0f;
    if (carta_Fortaleza.populacao != 0.0f)
        carta_Fortaleza.pib_per_capita = (carta_Fortaleza.pib * 1000000000) / (carta_Fortaleza.populacao * 1000000);
    else
        carta_Fortaleza.pib_per_capita = 0.0f;
    carta_Fortaleza.super_poder = carta_Fortaleza.populacao * 1000000 + carta_Fortaleza.area + carta_Fortaleza.pib +
                                  carta_Fortaleza.pontos_turisticos + carta_Fortaleza.pib_per_capita +
                                  (carta_Fortaleza.densidade_populacional != 0.0f ? 1.0f / carta_Fortaleza.densidade_populacional : 0.0f);

    Carta carta_BeloHorizonte;
    strncpy(carta_BeloHorizonte.cidade, "Belo Horizonte", sizeof(carta_BeloHorizonte.cidade) - 1);
    carta_BeloHorizonte.cidade[sizeof(carta_BeloHorizonte.cidade)-1] = '\0';
    carta_BeloHorizonte.populacao = 2;
    carta_BeloHorizonte.area = 331.0;
    carta_BeloHorizonte.pib = 110.0;
    carta_BeloHorizonte.pontos_turisticos = 4;
    if (carta_BeloHorizonte.area != 0.0f)
        carta_BeloHorizonte.densidade_populacional = carta_BeloHorizonte.populacao * 1000000 / carta_BeloHorizonte.area;
    else
        carta_BeloHorizonte.densidade_populacional = 0.0f;
    if (carta_BeloHorizonte.populacao != 0.0f)
        carta_BeloHorizonte.pib_per_capita = (carta_BeloHorizonte.pib * 1000000000) / (carta_BeloHorizonte.populacao * 1000000);
    else
        carta_BeloHorizonte.pib_per_capita = 0.0f;
    carta_BeloHorizonte.super_poder = carta_BeloHorizonte.populacao * 1000000 + carta_BeloHorizonte.area + carta_BeloHorizonte.pib +
                                      carta_BeloHorizonte.pontos_turisticos + carta_BeloHorizonte.pib_per_capita +
                                      (carta_BeloHorizonte.densidade_populacional != 0.0f ? 1.0f / carta_BeloHorizonte.densidade_populacional : 0.0f);

    Carta carta_Curitiba;
    strncpy(carta_Curitiba.cidade, "Curitiba", sizeof(carta_Curitiba.cidade) - 1);
    carta_Curitiba.cidade[sizeof(carta_Curitiba.cidade)-1] = '\0';
    carta_Curitiba.populacao = 2;
    carta_Curitiba.area = 435.0;
    carta_Curitiba.pib = 150.0;
    carta_Curitiba.pontos_turisticos = 3;
    if (carta_Curitiba.area != 0.0f)
        carta_Curitiba.densidade_populacional = carta_Curitiba.populacao * 1000000 / carta_Curitiba.area;
    else
        carta_Curitiba.densidade_populacional = 0.0f;
    if (carta_Curitiba.populacao != 0.0f)
        carta_Curitiba.pib_per_capita = (carta_Curitiba.pib * 1000000000) / (carta_Curitiba.populacao * 1000000);
    else
        carta_Curitiba.pib_per_capita = 0.0f;
    carta_Curitiba.super_poder = carta_Curitiba.populacao * 1000000 + carta_Curitiba.area + carta_Curitiba.pib +
                                 carta_Curitiba.pontos_turisticos + carta_Curitiba.pib_per_capita +
                                 (carta_Curitiba.densidade_populacional != 0.0f ? 1.0f / carta_Curitiba.densidade_populacional : 0.0f);

    Carta carta_jogador_A;
    strncpy(carta_jogador_A.cidade, "", sizeof(carta_jogador_A.cidade) - 1);
    carta_jogador_A.cidade[sizeof(carta_jogador_A.cidade)-1] = '\0';
    carta_jogador_A.populacao = 0;
    carta_jogador_A.area = 0.0;
    carta_jogador_A.pib = 0.0;
    carta_jogador_A.pontos_turisticos = 0;
    if (carta_jogador_A.area != 0.0f)
        carta_jogador_A.densidade_populacional = carta_jogador_A.populacao * 1000000 / carta_jogador_A.area;
    else
        carta_jogador_A.densidade_populacional = 0.0f;
    if (carta_jogador_A.populacao != 0.0f)
        carta_jogador_A.pib_per_capita = (carta_jogador_A.pib * 1000000000) / (carta_jogador_A.populacao * 1000000);
    else
        carta_jogador_A.pib_per_capita = 0.0f;
    carta_jogador_A.super_poder = carta_jogador_A.populacao * 1000000 + carta_jogador_A.area + carta_jogador_A.pib +
                                  carta_jogador_A.pontos_turisticos + carta_jogador_A.pib_per_capita +
                                  (carta_jogador_A.densidade_populacional != 0.0f ? 1.0f / carta_jogador_A.densidade_populacional : 0.0f);

    Carta carta_jogador_B;
    strncpy(carta_jogador_B.cidade, "", sizeof(carta_jogador_B.cidade) - 1);
    carta_jogador_B.cidade[sizeof(carta_jogador_B.cidade)-1] = '\0';
    carta_jogador_B.populacao = 0;
    carta_jogador_B.area = 0.0;
    carta_jogador_B.pib = 0.0;
    carta_jogador_B.pontos_turisticos = 0;
    if (carta_jogador_B.area != 0.0f)
        carta_jogador_B.densidade_populacional = carta_jogador_B.populacao * 1000000 / carta_jogador_B.area;
    else
        carta_jogador_B.densidade_populacional = 0.0f;
    if (carta_jogador_B.populacao != 0.0f)
        carta_jogador_B.pib_per_capita = (carta_jogador_B.pib * 1000000000) / (carta_jogador_B.populacao * 1000000);
    else
        carta_jogador_B.pib_per_capita = 0.0f;
    carta_jogador_B.super_poder = carta_jogador_B.populacao * 1000000 + carta_jogador_B.area + carta_jogador_B.pib +
                                  carta_jogador_B.pontos_turisticos + carta_jogador_B.pib_per_capita +
                                  (carta_jogador_B.densidade_populacional != 0.0f ? 1.0f / carta_jogador_B.densidade_populacional : 0.0f);

    //Jogo
        int tela_atual = 0; 
        while (1) {
            switch (tela_atual) {
                // 0 = Intro 
                // 1 = Menu inicial
                // 2 = Seleção de modo de jogo 
                // 3 = Regras
                // 4 = Sair
                // 5 = Créditos
                case 0: { // Intro
                    printf("%s", telas.intro);
                    getchar();
                    limpar_buffer();
                    tela_atual = 1;
                    break;
                }
                case 1: { // Menu Inicial
                    printf("%s", telas.menu_inicial);
                    int opcao;
                    while (1) {
                        if (scanf("%d", &opcao) != 1) { // Verifica se a entrada é um número
                            limpar_buffer();
                            printf("Opção inválida. Por favor, escolha 1, 2 ou 3:\n");
                            continue;
                        }
                        switch (opcao) {
                            case 1:{
                                tela_atual = 2; // Seleção de modo de jogo
                                break;
                            }
                            case 2:{ // Regras
                                tela_atual = 3;
                                getchar();
                                limpar_buffer();
                                break;
                        }
                            case 3:{ // Sair
                                tela_atual = 4;
                                break;
                            }
                            default:{
                                printf("Opção inválida. Por favor, escolha 1, 2 ou 3:\n");
                                continue;
                        }
                        }
                        break; // sai do while
                    }
                    break; // sai do case 1
                }
                case 2: { // Seleção de modo de jogo
                    printf("%s", telas.seleção_de_modo_de_jogo);
                    int escolha_jogo = -1;
                    int carta_escolhida_jogador_1 = -1;
                    int carta_escolhida_jogador_2 = -1;
                    int atributo_escolhido = -1;
                    while (escolha_jogo < 1 || escolha_jogo > 3) {
                        if (scanf("%d", &escolha_jogo) != 1) { // Verifica se a entrada é um número
                            limpar_buffer();
                            printf("Opção inválida. Por favor, escolha 0, 1, 2 ou 3: \n");
                            continue;
                        }
                    }
                    switch (escolha_jogo){
                        case 1:{ // CPU modo demonstrativo (escolhe duas cartas prontas de 08 cartas)
                            printf("Modo demonstrativo selecionado.\n");
                            printf("\n========================================\n");
                            printf("          MODO DEMONSTRATIVO           \n");
                            printf("========================================\n\n");
                            srand((unsigned int)time(NULL));
                            // escolher índices entre 0 e 7 (o baralho tem 8 cartas)
                            carta_escolhida_jogador_1 = rand() % 8;
                            printf("\nA CPU escolheu a carta número %d para o jogador 1!\n", carta_escolhida_jogador_1);
                            carta_escolhida_jogador_2 = rand() % 8;
                            printf("A CPU escolheu a carta número %d para o jogador 2!\n", carta_escolhida_jogador_2);
                            atributo_escolhido = (rand() % 7) + 1;
                            
                            // Mapear os índices para os ponteiros das cartas
                            Carta *selA = NULL, *selB = NULL;
                            switch (carta_escolhida_jogador_1) {
                                case 0: selA = &carta_Manaus; break;
                                case 1: selA = &carta_SaoPaulo; break;
                                case 2: selA = &carta_RioDeJaneiro; break;
                                case 3: selA = &carta_Brasilia; break;
                                case 4: selA = &carta_Salvador; break;
                                case 5: selA = &carta_Fortaleza; break;
                                case 6: selA = &carta_BeloHorizonte; break;
                                case 7: selA = &carta_Curitiba; break;
                                default: selA = &carta_Manaus; break;
                            }
                            switch (carta_escolhida_jogador_2) {
                                case 0: selB = &carta_Manaus; break;
                                case 1: selB = &carta_SaoPaulo; break;
                                case 2: selB = &carta_RioDeJaneiro; break;
                                case 3: selB = &carta_Brasilia; break;
                                case 4: selB = &carta_Salvador; break;
                                case 5: selB = &carta_Fortaleza; break;
                                case 6: selB = &carta_BeloHorizonte; break;
                                case 7: selB = &carta_Curitiba; break;
                                default: selB = &carta_SaoPaulo; break;
                            }

                            // Pré-calcular variáveis usadas nas mensagens de saída
                            int int_populacao_jogador_A = (int)selA->populacao;
                            int int_populacao_jogador_B = (int)selB->populacao;
                            float float_area_jogador_A = selA->area;
                            float float_area_jogador_B = selB->area;
                            float densidade_A = selA->densidade_populacional;
                            float densidade_B = selB->densidade_populacional;
                            float float_pib_jogador_A = selA->pib;
                            float float_pib_jogador_B = selB->pib;
                            float per_capita_A = selA->pib_per_capita;
                            float per_capita_B = selB->pib_per_capita;
                            int qtde_pontos_turisticos_jogador_A = selA->pontos_turisticos;
                            int qtde_pontos_turisticos_jogador_B = selB->pontos_turisticos;
                            float super_poder_A = selA->super_poder;
                            float super_poder_B = selB->super_poder;
                            printf("\nA CPU escolheu o atributo número %d para comparar!\n", atributo_escolhido);
                            printf("Os atributos são:\n");
                            printf("1. População\n");
                            printf("2. Área\n");
                            printf("3. Densidade populacional\n");
                            printf("4. PIB\n");
                            printf("5. PIB per capita\n");
                            printf("6. Pontos turísticos\n");
                            printf("7. Super Poder\n\n");

                            switch (atributo_escolhido) {
                                case 1:{ // População
                                    printf("Atributo escolhido: População\n");
                                    printf("Jogador A: %d milhões\n", int_populacao_jogador_A);
                                    printf("Jogador B: %d milhões\n", int_populacao_jogador_B);
                                    if (int_populacao_jogador_A > int_populacao_jogador_B)
                                        printf("Jogador A venceu na população!\n");
                                    else if (int_populacao_jogador_A < int_populacao_jogador_B)
                                        printf("Jogador B venceu na população!\n");
                                    else
                                        printf("Empate na população!\n");
                                    break;
                                }
                                case 2:{ // Área
                                    printf("Atributo escolhido: Área\n");
                                    printf("Jogador A: %.2f km²\n", float_area_jogador_A);
                                    printf("Jogador B: %.2f km²\n", float_area_jogador_B);
                                    if (float_area_jogador_A > float_area_jogador_B)
                                        printf("Jogador A venceu na área!\n");
                                    else if (float_area_jogador_A < float_area_jogador_B)
                                        printf("Jogador B venceu na área!\n");
                                    else
                                        printf("Empate na área!\n");
                                    break;
                                }
                                case 3: {
                                    printf("Atributo escolhido: Densidade populacional\n");
                                    printf("Jogador A: %.2f hab/km²\n", densidade_A);
                                    printf("Jogador B: %.2f hab/km²\n", densidade_B);
                                    if (densidade_A < densidade_B)
                                        printf("Jogador A venceu na densidade populacional!\n");
                                    else if (densidade_A > densidade_B)
                                        printf("Jogador B venceu na densidade populacional!\n");
                                    else
                                        printf("Empate na densidade populacional!\n");
                                    break;
                                }
                                case 4:{
                                    printf("Atributo escolhido: PIB\n");
                                    printf("Jogador A: %.2f bilhões\n", float_pib_jogador_A);
                                    printf("Jogador B: %.2f bilhões\n", float_pib_jogador_B);
                                    if (float_pib_jogador_A > float_pib_jogador_B)
                                        printf("Jogador A venceu no PIB!\n");
                                    else if (float_pib_jogador_A < float_pib_jogador_B)
                                        printf("Jogador B venceu no PIB!\n");
                                    else
                                    printf("Empate no PIB!\n");
                                    break;
                                }
                                case 5: {
                                    printf("Atributo escolhido: PIB per capita\n");
                                    printf("Jogador A: R$ %.2f\n", per_capita_A);
                                    printf("Jogador B: R$ %.2f\n", per_capita_B);
                                    if (per_capita_A > per_capita_B)
                                        printf("Jogador A venceu no PIB per capita!\n");
                                    else if (per_capita_A < per_capita_B)
                                        printf("Jogador B venceu no PIB per capita!\n");
                                    else
                                        printf("Empate no PIB per capita!\n");
                                    break;
                                }
                                case 6:{
                                    printf("Atributo escolhido: Pontos turísticos\n");
                                    printf("Jogador A: %d pontos\n", qtde_pontos_turisticos_jogador_A);
                                    printf("Jogador B: %d pontos\n", qtde_pontos_turisticos_jogador_B);
                                    if (qtde_pontos_turisticos_jogador_A > qtde_pontos_turisticos_jogador_B)
                                        printf("Jogador A venceu nos pontos turísticos!\n");
                                    else if (qtde_pontos_turisticos_jogador_A < qtde_pontos_turisticos_jogador_B)
                                        printf("Jogador B venceu nos pontos turísticos!\n");
                                    else
                                        printf("Empate nos pontos turísticos!\n");
                                    break;
                                }
                                case 7: {
                                    printf("Atributo escolhido: Super Poder\n");
                                    printf("Jogador A: %.2f pontos\n", super_poder_A);
                                    printf("Jogador B: %.2f pontos\n", super_poder_B);
                                    if (super_poder_A > super_poder_B)
                                        printf("Jogador A venceu no Super Poder!\n");
                                    else if (super_poder_A < super_poder_B)
                                        printf("Jogador B venceu no Super Poder!\n");
                                    else
                                        printf("Empate no Super Poder!\n");
                                    break;
                                }
                                default:{
                                    printf("Atributo inválido!\n");    
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:{ // Modo usuário (escolha duas cartas prontas ou crie duas novas)
                            printf("\n========================================\n");
                            printf("   MODO USUÁRIO  \n");
                            printf("========================================\n\n");
                            
                            printf("Jogador 1, escolha sua carta (0-8):\n");
                            printf("0 - Manaus\n");
                            printf("1 - Sao Paulo\n");
                            printf("2 - Rio de Janeiro\n");
                            printf("3 - Brasilia\n");
                            printf("4 - Salvador\n");
                            printf("5 - Fortaleza\n");
                            printf("6 - Belo Horizonte\n");
                            printf("7 - Curitiba\n");
                            printf("8 - Criar nova carta\n");

                                    while (carta_escolhida_jogador_1 < 0 || carta_escolhida_jogador_1 > 8) {
                                        if (scanf("%d", &carta_escolhida_jogador_1) != 1) {
                                            limpar_buffer();
                                            printf("Opção inválida. Por favor, escolha um carta de 0 a 7:\n");
                                            continue;
                                        }
                                    }

                            printf("Jogador 2, escolha sua carta (0-8):\n");
                            printf("0 - Manaus\n");
                            printf("1 - Sao Paulo\n");
                            printf("2 - Rio de Janeiro\n");
                            printf("3 - Brasilia\n");
                            printf("4 - Salvador\n");
                            printf("5 - Fortaleza\n");
                            printf("6 - Belo Horizonte\n");
                            printf("7 - Curitiba\n");
                            printf("8 - Criar nova carta\n");

                            while (carta_escolhida_jogador_2 < 0 || carta_escolhida_jogador_2 > 8) {
                                if (scanf("%d", &carta_escolhida_jogador_2) != 1) {
                                    limpar_buffer();
                                    printf("Opção inválida. Por favor, escolha um carta de 0 a 8:\n");
                                    continue;
                                }
                            }
                            break;
                        }
                        case 3:{ // Voltar ao menu inicial
                            tela_atual = 1;
                            break;
                        } 
                        default:{ printf("Opção inválida. Por favor, escolha 0, 1, 2 ou 3:\n");
                            continue;
                        break;
                        }
                    }
                    break; /* evita fallthrough para case 3 */
                }
                case 3: { // Regras
                    printf("%s", telas.regras);
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
                case 4: { // Sair
                    printf("%s", telas.sair);
                    printf("Saindo do jogo. Até a próxima!\n");
                    return 0;
                }
                case 5: { // Créditos
                    printf("%s", telas.créditos);
                    tela_atual = 0;
                    getchar();
                    limpar_buffer();
                    break;
                }
                default: { // Erro: tela desconhecida
                    printf("Erro: Tela desconhecida. Voltando ao menu inicial.\n");
                    tela_atual = 0;
                    break;
                } 
            }
        }
       return 0;
}
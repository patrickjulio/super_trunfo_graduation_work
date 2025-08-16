#include <stdio.h>

int main() {
    // Introdução ao jogo
    printf("========================================\n");
    printf("          JOGO SUPER TRUNFO            \n");
    printf("========================================\n\n");
    printf("Bem-vindo ao Super Trunfo!\n\n");
    printf("Este é um jogo de cartas onde o objetivo é vencer o adversário com a melhor carta.\n");
    printf("As regras são simples: cada jogador cria uma carta e a compara com a do outro.\n");
    printf("A carta com o maior valor vence a rodada.\n\n");
    printf("Vamos começar!\n\n");
    
    // Variáveis para armazenar os dados dos jogadores
    char str_cidade_jogador_A [33]= "Manaus";
    char str_cidade_jogador_B [33] = "Sao Paulo";
    int int_populacao_jogador_A = 999999;
    int int_populacao_jogador_B = 999999;
    float float_area_jogador_A = 999.0;
    float float_area_jogador_B = 999.0;
    float float_pib_jogador_A = 999.00;
    float float_pib_jogador_B = 999.00;
    int qtde_pontos_turisticos_jogador_A = 9;
    int qtde_pontos_turisticos_jogador_B = 9;
    
    // Entrada de dados dos jogadores
    printf("Primeiro vamos aos dados do jogador A.\n");
    printf("Jogador A, pode me dizer qual a cidade da sua carta: \n");
    scanf("%s", str_cidade_jogador_A);
    printf("Jogador A, pode me dizer qual a população da sua cidade em milhões (exemplo: se sua cidade tiver 300.000.000 digite 300): \n");
    scanf("%d", &int_populacao_jogador_A);
    printf("Jogador A, pode me dizer qual a área da sua cidade em km²: \n");
    scanf("%f", &float_area_jogador_A);
    printf("Jogador A, pode me dizer qual o PIB da sua cidade em bilhões: \n");
    scanf("%f", &float_pib_jogador_A);
    printf("Jogador A, pode me dizer quantos pontos turísticos a sua cidade tem: \n");
    scanf("%d", &qtde_pontos_turisticos_jogador_A);

    printf("\n========================================\n");
    printf("Agora vamos aos dados do jogador B.\n");
    printf("\nJogador B, pode me dizer qual a cidade da sua carta: \n");
    scanf("%s", str_cidade_jogador_B);
    printf("Jogador B, pode me dizer qual a população da sua cidade em milhões (exemplo: se sua cidade tiver 300.000.000 digite 300):\n");
    scanf("%d", &int_populacao_jogador_B);
    printf("Jogador B, pode me dizer qual a área da sua cidade em km²: \n");
    scanf("%f", &float_area_jogador_B);
    printf("Jogador B, pode me dizer qual o PIB da sua cidade em bilhões: \n");
    scanf("%f", &float_pib_jogador_B);
    printf("Jogador B, pode me dizer quantos pontos turísticos a sua cidade tem: \n");
    scanf("%d", &qtde_pontos_turisticos_jogador_B);
    
    //Cálculos
    double double_densidade_populacional_jogador_A = (float) (int_populacao_jogador_A * 1000000) / float_area_jogador_A;
    double double_densidade_populacional_jogador_B = (float) (int_populacao_jogador_B * 1000000) / float_area_jogador_B;
    double double_per_capita_A= (float_pib_jogador_A*1000000000)/ (float) (int_populacao_jogador_A * 1000000);
    double double_pib_per_capita_B= (float_pib_jogador_B*1000000000)/ (float) (int_populacao_jogador_B * 1000000);
    double super_poder_jogador_A = (double) (int_populacao_jogador_A * 1000000) + (double) float_area_jogador_A + (double) float_pib_jogador_A + (double) qtde_pontos_turisticos_jogador_A + double_per_capita_A + (1/double_densidade_populacional_jogador_A);
    double super_poder_jogador_B = (double) (int_populacao_jogador_B * 1000000) + (double) float_area_jogador_B + (double) float_pib_jogador_B + (double) qtde_pontos_turisticos_jogador_B + double_pib_per_capita_B + (1/double_densidade_populacional_jogador_B);
   
    // Exibição dos resultados
    printf("\n========================================\n");
    printf("          RESULTADOS DA PARTIDA         \n");
    printf("========================================\n\n");

    printf("\nJogador A, sua carta é: %s\n", str_cidade_jogador_A);
    printf("População: %d milhões\n", int_populacao_jogador_A);
    printf("Área: %.2f km²\n", float_area_jogador_A);
    printf("Densidade populacional: %.0f hab/km²\n", double_densidade_populacional_jogador_A);
    printf("PIB: %.2f bilhões\n", float_pib_jogador_A);
    printf("PIB per capita: %.2f\n", double_per_capita_A);
    printf("Pontos turísticos: %d\n", qtde_pontos_turisticos_jogador_A);
    printf("Super Poder: %.2f\n", super_poder_jogador_A);

    printf("\nJogador B, sua carta é: %s\n", str_cidade_jogador_B);
    printf("População: %d milhões\n", int_populacao_jogador_B);
    printf("Área: %.2f km²\n", float_area_jogador_B);
    printf("Densidade populacional: %.2f hab/km²\n", double_densidade_populacional_jogador_B);
    printf("PIB: %.2f bilhões\n", float_pib_jogador_B);
    printf("PIB per capita: %.2f\n", double_pib_per_capita_B);
    printf("Pontos turísticos: %d\n", qtde_pontos_turisticos_jogador_B);
    printf("Super Poder: %.2f\n", super_poder_jogador_B);
    
    //Comparações
    if (int_populacao_jogador_A > int_populacao_jogador_B) {
        printf("\nJogador A venceu na população!\n");
    } else if (int_populacao_jogador_A < int_populacao_jogador_B) {
        printf("\nJogador B venceu na população!\n");
    } else {
        printf("\nEmpate na população!\n");
    }

    if (float_area_jogador_A > float_area_jogador_B) {
        printf("Jogador A venceu na área!\n");
    } else if (float_area_jogador_A < float_area_jogador_B) {
        printf("Jogador B venceu na área!\n");
    } else {
        printf("Empate na área!\n");
    }

    if (double_densidade_populacional_jogador_A < double_densidade_populacional_jogador_B) {
        printf("Jogador A venceu na densidade populacional!\n");
    } else if (double_densidade_populacional_jogador_A > double_densidade_populacional_jogador_B) {
        printf("Jogador B venceu na densidade populacional!\n");
    } else {
        printf("Empate na densidade populacional!\n");
    }

    if (float_pib_jogador_A > float_pib_jogador_B) {
        printf("Jogador A venceu no PIB!\n");
    } else if (float_pib_jogador_A < float_pib_jogador_B) {
        printf("Jogador B venceu no PIB!\n");
    } else {
        printf("Empate no PIB!\n");
    }

    if (double_per_capita_A > double_pib_per_capita_B) {
        printf("Jogador A venceu no PIB per capita!\n");
    } else if (double_per_capita_A < double_pib_per_capita_B) {
        printf("Jogador B venceu no PIB per capita!\n");
    } else {
        printf("Empate no PIB per capita!\n");
    }

    if (qtde_pontos_turisticos_jogador_A > qtde_pontos_turisticos_jogador_B) {
        printf("Jogador A venceu nos pontos turísticos!\n");
    } else if (qtde_pontos_turisticos_jogador_A < qtde_pontos_turisticos_jogador_B) {
        printf("Jogador B venceu nos pontos turísticos!\n");
    } else {
        printf("Empate nos pontos turísticos!\n");
    }

    if (super_poder_jogador_A > super_poder_jogador_B) {
        printf("Jogador A venceu no Super Poder!\n");
    } else if (super_poder_jogador_A < super_poder_jogador_B) {
        printf("Jogador B venceu no Super Poder!\n");
    } else {
        printf("Empate no Super Poder!\n");
    }

    printf("\n========================================\n");
    printf("          FIM DO JOGO SUPER TRUNFO      \n");
    printf("========================================\n\n");
    printf("Obrigado por jogar! :)\n");
    return 0;
}
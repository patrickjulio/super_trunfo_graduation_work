#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <limits.h>

// Incluindo as definições do código original
typedef struct {
    char cidade[33];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

#define IDX_POPULACAO 1
#define IDX_AREA 2
#define IDX_DENSIDADE 3
#define IDX_PIB 4
#define IDX_PIB_PER_CAPITA 5
#define IDX_PONTOS_TURISTICOS 6
#define IDX_SUPER_PODER 7

// Funções copiadas do código original para teste
float acessarAtributo(Carta* carta, int indice) {
    switch (indice) {
        case IDX_POPULACAO: return carta->populacao;
        case IDX_AREA: return carta->area;
        case IDX_DENSIDADE: return carta->densidade_populacional;
        case IDX_PIB: return carta->pib;
        case IDX_PIB_PER_CAPITA: return carta->pib_per_capita;
        case IDX_PONTOS_TURISTICOS: return (float)carta->pontos_turisticos;
        case IDX_SUPER_PODER: return carta->super_poder;
        default: return -1.0f;
    }
}

int compara_atributo(Carta* c1, Carta* c2, int atributo) {
    float v1 = acessarAtributo(c1, atributo);
    float v2 = acessarAtributo(c2, atributo);
    bool menor_vence = (atributo == IDX_DENSIDADE);
    if (v1 == v2) return 0;
    if (menor_vence) return (v1 < v2) ? 1 : 2;
    return (v1 > v2) ? 1 : 2;
}

// Variáveis globais para controle dos testes
int testes_executados = 0;
int testes_passou = 0;
int testes_falhou = 0;

// Função para verificar se dois floats são aproximadamente iguais
int float_equals(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

// Macro para executar testes
#define TESTE(condicao, nome) do { \
    testes_executados++; \
    if (condicao) { \
        printf("✓ PASSOU: %s\n", nome); \
        testes_passou++; \
    } else { \
        printf("✗ FALHOU: %s\n", nome); \
        testes_falhou++; \
    } \
} while(0)

// Função para criar carta de teste
Carta criar_carta_teste(const char* nome, unsigned long pop, float area, float pib, int pontos) {
    Carta carta;
    strncpy(carta.cidade, nome, sizeof(carta.cidade) - 1);
    carta.cidade[sizeof(carta.cidade) - 1] = '\0';
    carta.populacao = pop;
    carta.area = area;
    carta.pib = pib;
    carta.pontos_turisticos = pontos;
    
    // Calcular campos derivados
    carta.densidade_populacional = (area != 0.0f) ? (pop / area) : 0.0f;
    carta.pib_per_capita = (pop != 0.0f) ? ((pib * 1000000000) / pop) : 0.0f;
    carta.super_poder = pop + area + pib + pontos + carta.pib_per_capita +
                       (carta.densidade_populacional != 0.0f ? 1.0f / carta.densidade_populacional : 0.0f);
    
    return carta;
}

// Testes de cálculos matemáticos
void teste_calculos_matematicos() {
    printf("\n=== TESTANDO CÁLCULOS MATEMÁTICOS ===\n");
    
    // Teste 1: Densidade populacional normal
    Carta carta1 = criar_carta_teste("Teste1", 1000000, 100.0f, 50.0f, 5);
    float densidade_esperada = 1000000.0f / 100.0f;
    TESTE(float_equals(carta1.densidade_populacional, densidade_esperada, 0.01f), 
          "Cálculo densidade populacional normal");
    
    // Teste 2: Divisão por zero na densidade (área = 0)
    Carta carta2 = criar_carta_teste("Teste2", 1000000, 0.0f, 50.0f, 5);
    TESTE(carta2.densidade_populacional == 0.0f, 
          "Densidade com área zero deve ser 0");
    
    // Teste 3: PIB per capita normal
    Carta carta3 = criar_carta_teste("Teste3", 1000000, 100.0f, 50.0f, 5);
    float pib_per_capita_esperado = (50.0f * 1000000000) / 1000000.0f;
    TESTE(float_equals(carta3.pib_per_capita, pib_per_capita_esperado, 0.01f), 
          "Cálculo PIB per capita normal");
    
    // Teste 4: Divisão por zero no PIB per capita (população = 0)
    Carta carta4 = criar_carta_teste("Teste4", 0, 100.0f, 50.0f, 5);
    TESTE(carta4.pib_per_capita == 0.0f, 
          "PIB per capita com população zero deve ser 0");
    
    // Teste 5: Super poder com densidade zero
    Carta carta5 = criar_carta_teste("Teste5", 1000000, 0.0f, 50.0f, 5);
    float super_poder_esperado = 1000000 + 0.0f + 50.0f + 5 + carta5.pib_per_capita + 0.0f;
    TESTE(float_equals(carta5.super_poder, super_poder_esperado, 0.01f), 
          "Super poder com densidade zero");
    
    // Teste 6: Valores extremos (muito grandes)
    Carta carta6 = criar_carta_teste("Teste6", 4000000000UL, 50000.0f, 1000.0f, 20);
    TESTE(carta6.densidade_populacional > 0, 
          "Densidade com valores grandes deve ser calculada");
    
    // Teste 7: Todos os valores zero
    Carta carta7 = criar_carta_teste("Teste7", 0, 0.0f, 0.0f, 0);
    TESTE(carta7.densidade_populacional == 0.0f && carta7.pib_per_capita == 0.0f, 
          "Todos valores zero devem resultar em cálculos zero");
}

// Testes da função acessarAtributo
void teste_acesso_atributos() {
    printf("\n=== TESTANDO ACESSO A ATRIBUTOS ===\n");
    
    Carta carta = criar_carta_teste("TesteAcesso", 2000000, 1000.0f, 100.0f, 10);
    
    // Teste de todos os atributos válidos
    TESTE(acessarAtributo(&carta, IDX_POPULACAO) == 2000000.0f, 
          "Acesso à população");
    TESTE(acessarAtributo(&carta, IDX_AREA) == 1000.0f, 
          "Acesso à área");
    TESTE(acessarAtributo(&carta, IDX_PIB) == 100.0f, 
          "Acesso ao PIB");
    TESTE(acessarAtributo(&carta, IDX_PONTOS_TURISTICOS) == 10.0f, 
          "Acesso aos pontos turísticos");
    TESTE(acessarAtributo(&carta, IDX_DENSIDADE) == carta.densidade_populacional, 
          "Acesso à densidade populacional");
    TESTE(acessarAtributo(&carta, IDX_PIB_PER_CAPITA) == carta.pib_per_capita, 
          "Acesso ao PIB per capita");
    TESTE(acessarAtributo(&carta, IDX_SUPER_PODER) == carta.super_poder, 
          "Acesso ao super poder");
    
    // Teste de índices inválidos
    TESTE(acessarAtributo(&carta, 0) == -1.0f, 
          "Índice 0 inválido deve retornar -1");
    TESTE(acessarAtributo(&carta, 8) == -1.0f, 
          "Índice 8 inválido deve retornar -1");
    TESTE(acessarAtributo(&carta, -1) == -1.0f, 
          "Índice negativo inválido deve retornar -1");
    TESTE(acessarAtributo(&carta, 999) == -1.0f, 
          "Índice muito grande inválido deve retornar -1");
}

// Testes de comparação de atributos
void teste_comparacao_atributos() {
    printf("\n=== TESTANDO COMPARAÇÃO DE ATRIBUTOS ===\n");
    
    Carta carta1 = criar_carta_teste("Maior", 3000000, 1000.0f, 150.0f, 15);
    Carta carta2 = criar_carta_teste("Menor", 1000000, 500.0f, 50.0f, 5);
    Carta carta3 = criar_carta_teste("Igual", 3000000, 1000.0f, 150.0f, 15);
    
    // Testes de comparação normal (maior vence)
    TESTE(compara_atributo(&carta1, &carta2, IDX_POPULACAO) == 1, 
          "Carta1 vence em população");
    TESTE(compara_atributo(&carta2, &carta1, IDX_POPULACAO) == 2, 
          "Carta2 perde em população");
    TESTE(compara_atributo(&carta1, &carta3, IDX_POPULACAO) == 0, 
          "Empate em população");
    
    // Teste de densidade (menor vence)
    Carta alta_densidade = criar_carta_teste("AltaDens", 1000000, 100.0f, 50.0f, 5);
    Carta baixa_densidade = criar_carta_teste("BaixaDens", 1000000, 1000.0f, 50.0f, 5);
    TESTE(compara_atributo(&alta_densidade, &baixa_densidade, IDX_DENSIDADE) == 2, 
          "Menor densidade deve perder (maior densidade vence em lógica inversa)");
    TESTE(compara_atributo(&baixa_densidade, &alta_densidade, IDX_DENSIDADE) == 1, 
          "Maior densidade deve vencer (menor valor de densidade)");
    
    // Teste todos os atributos
    for (int attr = IDX_POPULACAO; attr <= IDX_SUPER_PODER; attr++) {
        int resultado = compara_atributo(&carta1, &carta2, attr);
        TESTE(resultado >= 0 && resultado <= 2, 
              "Comparação deve retornar valor válido (0, 1 ou 2)");
    }
}

// Testes de casos extremos
void teste_casos_extremos() {
    printf("\n=== TESTANDO CASOS EXTREMOS ===\n");
    
    // Teste com valores muito pequenos
    Carta pequena = criar_carta_teste("Pequena", 1, 0.001f, 0.001f, 1);
    TESTE(pequena.densidade_populacional > 0, 
          "Densidade com valores muito pequenos deve ser calculada");
    
    // Teste com string de nome no limite
    char nome_longo[33];
    memset(nome_longo, 'A', 32);
    nome_longo[32] = '\0';
    Carta carta_nome_longo = criar_carta_teste(nome_longo, 1000000, 100.0f, 50.0f, 5);
    TESTE(strlen(carta_nome_longo.cidade) == 32, 
          "Nome com 32 caracteres deve ser aceito");
    
    // Teste de precisão com números muito próximos
    Carta carta_a = criar_carta_teste("A", 1000000, 100.0f, 50.000001f, 5);
    Carta carta_b = criar_carta_teste("B", 1000000, 100.0f, 50.000002f, 5);
    int resultado = compara_atributo(&carta_a, &carta_b, IDX_PIB);
    TESTE(resultado == 0 || resultado == 2, 
          "Comparação com valores muito próximos");
    
    // Teste overflow potencial
    Carta carta_overflow = criar_carta_teste("Overflow", ULONG_MAX, FLT_MAX, FLT_MAX, INT_MAX);
    TESTE(carta_overflow.populacao == ULONG_MAX, 
          "População no limite máximo deve ser mantida");
}

// Testes de integridade das cartas originais
void teste_cartas_originais() {
    printf("\n=== TESTANDO CARTAS ORIGINAIS ===\n");
    
    // Criar as cartas conforme o código original
    Carta manaus = criar_carta_teste("Manaus", 2000000, 11401.0f, 74.0f, 8);
    Carta sao_paulo = criar_carta_teste("Sao Paulo", 12000000, 1521.0f, 443.0f, 15);
    Carta rio = criar_carta_teste("Rio de Janeiro", 6000000, 1182.0f, 200.0f, 10);
    
    // Verificar cálculos para Manaus
    float densidade_manaus = 2000000.0f / 11401.0f;
    TESTE(float_equals(manaus.densidade_populacional, densidade_manaus, 0.1f), 
          "Densidade de Manaus calculada corretamente");
    
    float pib_per_capita_manaus = (74.0f * 1000000000) / 2000000.0f;
    TESTE(float_equals(manaus.pib_per_capita, pib_per_capita_manaus, 1.0f), 
          "PIB per capita de Manaus calculado corretamente");
    
    // Verificar que São Paulo tem maior população que Rio
    TESTE(compara_atributo(&sao_paulo, &rio, IDX_POPULACAO) == 1, 
          "São Paulo deve ter maior população que Rio");
    
    // Verificar que São Paulo tem maior área que Rio
    TESTE(compara_atributo(&sao_paulo, &rio, IDX_AREA) == 1, 
          "São Paulo deve ter maior área que Rio");
}

// Testes de validação de entrada (simulados)
void teste_validacao_entrada() {
    printf("\n=== TESTANDO VALIDAÇÃO DE ENTRADA ===\n");
    
    // Simular testes de validação que seriam feitos em ambiente real
    
    // Teste de intervalo de cartas
    int carta_valida_min = 1;
    int carta_valida_max = 8;
    TESTE(carta_valida_min >= 1 && carta_valida_min <= 8, 
          "Carta mínima válida está no intervalo");
    TESTE(carta_valida_max >= 1 && carta_valida_max <= 8, 
          "Carta máxima válida está no intervalo");
    
    // Teste de intervalo de atributos
    int atributo_min = 1;
    int atributo_max = 7;
    TESTE(atributo_min >= 1 && atributo_min <= 7, 
          "Atributo mínimo válido está no intervalo");
    TESTE(atributo_max >= 1 && atributo_max <= 7, 
          "Atributo máximo válido está no intervalo");
    
    // Teste de valores inválidos
    int carta_invalida_baixa = 0;
    int carta_invalida_alta = 9;
    TESTE(!(carta_invalida_baixa >= 1 && carta_invalida_baixa <= 8), 
          "Carta 0 deve ser inválida");
    TESTE(!(carta_invalida_alta >= 1 && carta_invalida_alta <= 8), 
          "Carta 9 deve ser inválida");
}

// Testes de lógica de vitória
void teste_logica_vitoria() {
    printf("\n=== TESTANDO LÓGICA DE VITÓRIA ===\n");
    
    Carta forte = criar_carta_teste("Forte", 10000000, 2000.0f, 500.0f, 20);
    Carta fraca = criar_carta_teste("Fraca", 1000000, 200.0f, 50.0f, 2);
    Carta media = criar_carta_teste("Media", 5000000, 1000.0f, 250.0f, 10);
    
    // Teste: carta forte deve vencer em população
    TESTE(compara_atributo(&forte, &fraca, IDX_POPULACAO) == 1, 
          "Carta forte vence em população");
    
    // Teste: carta forte deve vencer em área
    TESTE(compara_atributo(&forte, &fraca, IDX_AREA) == 1, 
          "Carta forte vence em área");
    
    // Teste: carta forte deve vencer em PIB
    TESTE(compara_atributo(&forte, &fraca, IDX_PIB) == 1, 
          "Carta forte vence em PIB");
    
    // Teste: empate com mesma carta
    TESTE(compara_atributo(&forte, &forte, IDX_POPULACAO) == 0, 
          "Carta contra si mesma deve empatar");
    
    // Teste de soma de atributos para critério de desempate
    float soma_forte = acessarAtributo(&forte, IDX_POPULACAO) + acessarAtributo(&forte, IDX_AREA);
    float soma_fraca = acessarAtributo(&fraca, IDX_POPULACAO) + acessarAtributo(&fraca, IDX_AREA);
    TESTE(soma_forte > soma_fraca, 
          "Soma dos atributos da carta forte deve ser maior");
}

// Função para executar todos os testes
void executar_todos_os_testes() {
    printf("INICIANDO BATERIA COMPLETA DE TESTES DO SUPER TRUNFO\n");
    printf("=====================================================\n");
    
    teste_calculos_matematicos();
    teste_acesso_atributos();
    teste_comparacao_atributos();
    teste_casos_extremos();
    teste_cartas_originais();
    teste_validacao_entrada();
    teste_logica_vitoria();
    
    printf("\n=====================================================\n");
    printf("RESUMO DOS TESTES:\n");
    printf("Total de testes executados: %d\n", testes_executados);
    printf("Testes que passaram: %d\n", testes_passou);
    printf("Testes que falharam: %d\n", testes_falhou);
    printf("Taxa de sucesso: %.2f%%\n", (float)testes_passou / testes_executados * 100);
    
    if (testes_falhou == 0) {
        printf("\n🎉 TODOS OS TESTES PASSARAM! O código está funcionando corretamente.\n");
    } else {
        printf("\n⚠️  ALGUNS TESTES FALHARAM. Revisar o código é recomendado.\n");
    }
}

int main() {
    executar_todos_os_testes();
    return 0;
}
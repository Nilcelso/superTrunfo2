#include <stdio.h>

int lerInt() {
    int v;
    while (scanf("%d", &v) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Entrada inválida. Digite um número inteiro: ");
    }
    return v;
}

int main() {

    // Variáveis da Carta 1
    char estado1[3];
    char codigo1[10];
    char cidade1[50];
    int populacao1;
    int turisticos1;
    float area1;
    float pib1;
    float densidade1;
    float pibpercapta1;
    float superPoder1;

    // Variáveis carta 2
    char estado2[3];
    char codigo2[10];
    char cidade2[50];
    int populacao2;
    int turisticos2;
    float area2;
    float pib2;
    float densidade2;
    float pibpercapta2;
    float superPoder2;

    // Entrada carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (2 letras): ");
    scanf("%2s", estado1);
    printf("Digite o Codigo da Carta: ");
    scanf("%9s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Digite a Populacao (inteiro): ");
    populacao1 = lerInt();
    printf("Digite a Area da cidade (km2, decimal): ");
    while (scanf("%f", &area1) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Entrada inválida. Digite a area (decimal): ");
    }
    printf("Digite o PIB (em bilhoes de reais, decimal): ");
    while (scanf("%f", &pib1) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Entrada inválida. Digite o PIB (decimal): ");
    }
    printf("Digite o Numero de Pontos Turisticos (inteiro): ");
    turisticos1 = lerInt();

    // cálculos carta 1 (cuidar divisão por zero)
    densidade1 = (area1 != 0.0f) ? (populacao1 / area1) : 0.0f;
    pibpercapta1 = (populacao1 != 0) ? (pib1 / populacao1) : 0.0f;
    superPoder1 = populacao1 + area1 + pib1 + pibpercapta1 + ((densidade1 != 0.0f) ? (1.0f / densidade1) : 0.0f) + turisticos1;

    // Entrada carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado (2 letras): ");
    scanf("%2s", estado2);
    printf("Digite o Codigo da Carta: ");
    scanf("%9s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Digite a Populacao (inteiro): ");
    populacao2 = lerInt();
    printf("Digite a Area da cidade (km2, decimal): ");
    while (scanf("%f", &area2) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Entrada inválida. Digite a area (decimal): ");
    }
    printf("Digite o PIB (em bilhoes de reais, decimal): ");
    while (scanf("%f", &pib2) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Entrada inválida. Digite o PIB (decimal): ");
    }
    printf("Digite o Numero de Pontos Turisticos (inteiro): ");
    turisticos2 = lerInt();

    // cálculos carta 2
    densidade2 = (area2 != 0.0f) ? (populacao2 / area2) : 0.0f;
    pibpercapta2 = (populacao2 != 0) ? (pib2 / populacao2) : 0.0f;
    superPoder2 = populacao2 + area2 + pib2 + pibpercapta2 + ((densidade2 != 0.0f) ? (1.0f / densidade2) : 0.0f) + turisticos2;

    // Mostra cartas resumidas
    printf("\nCarta 1: %s (%s) - %s\n", cidade1, estado1, codigo1);
    printf(" Populacao: %d, Area: %.2f, PIB: %.2f, Pontos: %d, Densidade: %.2f, PIBpc: %.2f\n",
           populacao1, area1, pib1, turisticos1, densidade1, pibpercapta1);

    printf("\nCarta 2: %s (%s) - %s\n", cidade2, estado2, codigo2);
    printf(" Populacao: %d, Area: %.2f, PIB: %.2f, Pontos: %d, Densidade: %.2f, PIBpc: %.2f\n",
           populacao2, area2, pib2, turisticos2, densidade2, pibpercapta2);

    // Menu: escolha do primeiro atributo
    int attr1 = 0, attr2 = 0;
    while (1) {
        printf("\n=== MENU - Escolha do 1º atributo ===\n");
        printf("1 - Populacao (maior vence)\n");
        printf("2 - Area (maior vence)\n");
        printf("3 - PIB (maior vence)\n");
        printf("4 - Pontos Turisticos (maior vence)\n");
        printf("5 - Densidade Demografica (menor vence)\n");
        printf("Escolha o atributo 1 (1-5): ");
        attr1 = lerInt();
        switch (attr1) {
            case 1: case 2: case 3: case 4: case 5: break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }
        break;
    }

    // Menu dinâmico: escolha do segundo atributo (não pode ser igual ao primeiro)
    while (1) {
        printf("\n=== MENU - Escolha do 2º atributo (diferente do 1º) ===\n");
        // mostrar opções omitindo attr1
        for (int i = 1; i <= 5; i++) {
            if (i == attr1) continue;
            switch (i) {
                case 1: printf("1 - Populacao (maior vence)\n"); break;
                case 2: printf("2 - Area (maior vence)\n"); break;
                case 3: printf("3 - PIB (maior vence)\n"); break;
                case 4: printf("4 - Pontos Turisticos (maior vence)\n"); break;
                case 5: printf("5 - Densidade Demografica (menor vence)\n"); break;
            }
        }
        printf("Escolha o atributo 2: ");
        attr2 = lerInt();
        if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
            printf("Opção inválida ou igual ao primeiro atributo. Tente novamente.\n");
            continue;
        }
        break;
    }

    // Função simples para obter valor float do atributo escolhido
    float val1_attr1 = 0.0f, val2_attr1 = 0.0f;
    float val1_attr2 = 0.0f, val2_attr2 = 0.0f;
    const char *nomeA1, *nomeA2;

    // obter valores para attr1
    switch (attr1) {
        case 1: nomeA1 = "Populacao"; val1_attr1 = populacao1; val2_attr1 = populacao2; break;
        case 2: nomeA1 = "Area"; val1_attr1 = area1; val2_attr1 = area2; break;
        case 3: nomeA1 = "PIB"; val1_attr1 = pib1; val2_attr1 = pib2; break;
        case 4: nomeA1 = "Pontos Turisticos"; val1_attr1 = turisticos1; val2_attr1 = turisticos2; break;
        case 5: nomeA1 = "Densidade Demografica"; val1_attr1 = densidade1; val2_attr1 = densidade2; break;
        default: nomeA1 = ""; break;
    }

    // obter valores para attr2
    switch (attr2) {
        case 1: nomeA2 = "Populacao"; val1_attr2 = populacao1; val2_attr2 = populacao2; break;
        case 2: nomeA2 = "Area"; val1_attr2 = area1; val2_attr2 = area2; break;
        case 3: nomeA2 = "PIB"; val1_attr2 = pib1; val2_attr2 = pib2; break;
        case 4: nomeA2 = "Pontos Turisticos"; val1_attr2 = turisticos1; val2_attr2 = turisticos2; break;
        case 5: nomeA2 = "Densidade Demografica"; val1_attr2 = densidade1; val2_attr2 = densidade2; break;
        default: nomeA2 = ""; break;
    }

    // Comparações individuais
    int resA1 = 0; // 1 -> carta1 vence, -1 -> carta2 vence, 0 -> empate
    if (attr1 == 5) { // densidade: menor vence
        if (val1_attr1 < val2_attr1) resA1 = 1;
        else if (val2_attr1 < val1_attr1) resA1 = -1;
    } else {
        if (val1_attr1 > val2_attr1) resA1 = 1;
        else if (val2_attr1 > val1_attr1) resA1 = -1;
    }

    int resA2 = 0;
    if (attr2 == 5) { // densidade: menor vence
        if (val1_attr2 < val2_attr2) resA2 = 1;
        else if (val2_attr2 < val1_attr2) resA2 = -1;
    } else {
        if (val1_attr2 > val2_attr2) resA2 = 1;
        else if (val2_attr2 > val1_attr2) resA2 = -1;
    }

    // Soma dos atributos (usar valores numéricos; densidade já é numérico)
    float soma1 = val1_attr1 + val1_attr2;
    float soma2 = val2_attr1 + val2_attr2;

    // Resultado final usando operador ternário para decidir texto do vencedor
    int vencedor = (soma1 > soma2) ? 1 : ((soma2 > soma1) ? 2 : 0);

    // Exibir resultado detalhado
    printf("\n===== Resultado da Comparacao =====\n");
    printf("%s VS %s\n\n", cidade1, cidade2);

    printf("Atributo 1: %s\n", nomeA1);
    printf("  %s: %.2f\n", cidade1, val1_attr1);
    printf("  %s: %.2f\n", cidade2, val2_attr1);
    if (resA1 == 1) printf("  -> Vencedor no atributo 1: %s\n\n", cidade1);
    else if (resA1 == -1) printf("  -> Vencedor no atributo 1: %s\n\n", cidade2);
    else printf("  -> Empate no atributo 1\n\n");

    printf("Atributo 2: %s\n", nomeA2);
    printf("  %s: %.2f\n", cidade1, val1_attr2);
    printf("  %s: %.2f\n", cidade2, val2_attr2);
    if (resA2 == 1) printf("  -> Vencedor no atributo 2: %s\n\n", cidade1);
    else if (resA2 == -1) printf("  -> Vencedor no atributo 2: %s\n\n", cidade2);
    else printf("  -> Empate no atributo 2\n\n");

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", cidade1, soma1);
    printf("  %s: %.2f\n\n", cidade2, soma2);

    if (vencedor == 1) printf("Vencedor da rodada: %s\n", cidade1);
    else if (vencedor == 2) printf("Vencedor da rodada: %s\n", cidade2);
    else printf("Empate!\n");

    printf("===================================\n");

    return 0;
}

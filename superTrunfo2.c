#include <stdio.h>

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

    //variaveis carta 2

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

    // Declaração do resultado da comparação das cartas

    int resultado; 
    


    //Entrada carta 1

   printf("=== Cadastro da Carta 1 ===\n");

    printf("Digite o Estado: ");
    scanf("%2s", estado1);

    printf("Digite o Codigo da Carta: ");
    scanf("%9s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a Area da cidade (km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &turisticos1);

    // calculando dencisade populacional e renda per capita 

    densidade1 = (populacao1 / area1);
    pibpercapta1 = (pib1 / populacao1);
    superPoder1 = populacao1 + area1 + pib1 + pibpercapta1 + (1.0 / densidade1) + turisticos1;

    //Entrada carta 2

    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Digite o Estado: ");
    scanf("%s", estado2);

    printf("Digite o Codigo da Carta: ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf("%s", cidade2);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area da cidade (km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &turisticos2);

    // calculando dencisade populacional e renda per capita 

    densidade2 = (populacao2 / area2);
    pibpercapta2 = (pib2 / populacao2);
    superPoder2 = populacao2 + area2 + pib2 + pibpercapta2 + (1.0 / densidade2) + turisticos2;

    //Saida carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area(km²): %.2f\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", turisticos1);
    printf("Densidade Populacional(hab/km2): %.2f\n", densidade1);
    printf("Renda per capita: %.2f\n", pibpercapta1);

    //Saida carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area(km²): %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", turisticos2);
    printf("Densidade Populacional(hab/km²): %.1f\n", densidade2);
    printf("Renda per capita: %.1f\n", pibpercapta2);

   /* // Comparando as cartas 
    //População
    if (populacao1 > populacao2){
        printf("A cidade %s venceu em população!\n", cidade1);        
    } else {
        printf("A cidade %s venceu em população!\n", cidade2);
    }

    //Area 
    if (area1 > area2){
        printf("Carta 1 venceu em Area!\n");        
    } else {
        printf("Carta 2 venceu em Area!\n");
    }

    //Pib
    if (pib1 > pib2){
        printf("Carta 1 venceu em Pib!\n");        
    } else {
        printf("Carta 2 venceu em Pib!\n");
    }

    //pontos turisticos 
    if (turisticos1 > turisticos2){
        printf("Carta 1 venceu em pontos turisticos!\n");        
    } else {
        printf("Carta 2 venceu em pontos turisticos!\n");
    }

    //Densidade populacional
    if (densidade1 > densidade2){
        printf("Carta 2 venceu em densidade populacional!\n");        
    } else {
        printf("Carta 1 venceu em densidade populacional!\n");
    }

    //Renda per capta  
    if (pibpercapta1 > pibpercapta2){
        printf("Carta 1 venceu em renda per capta!\n");        
    } else {
        printf("Carta 2 venceu em renda per capta!\n");
    } */

    //Aprimorando o jogo 

        int opcao;

    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    switch(opcao) {

        case 1: // População
            printf("Atributo escolhido: Populacao\n");
            printf("%s: %d\n", cidade1, populacao1);
            printf("%s: %d\n", cidade2, populacao2);

            if(populacao1 > populacao2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(populacao2 > populacao1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo escolhido: Area\n");
            printf("%s: %.2f\n", cidade1, area1);
            printf("%s: %.2f\n", cidade2, area2);

            if(area1 > area2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(area2 > area1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo escolhido: PIB\n");
            printf("%s: %.2f\n", cidade1, pib1);
            printf("%s: %.2f\n", cidade2, pib2);

            if(pib1 > pib2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(pib2 > pib1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo escolhido: Pontos Turisticos\n");
            printf("%s: %d\n", cidade1, turisticos1);
            printf("%s: %d\n", cidade2, turisticos2);

            if(turisticos1 > turisticos2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(turisticos2 > turisticos1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade (MENOR vence)
            printf("Atributo escolhido: Densidade Demografica\n");
            printf("%s: %.2f\n", cidade1, densidade1);
            printf("%s: %.2f\n", cidade2, densidade2);

            if(densidade1 < densidade2) {
                printf("Vencedor: %s\n", cidade1);
            } else if(densidade2 < densidade1) {
                printf("Vencedor: %s\n", cidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida!\n");
    }    

    return 0;
}
#include <stdio.h>

/* =========================================================
   FUNÇÕES RECURSIVAS PARA TORRE, BISPO E RAINHA
   ========================================================= */

/* ---------------------------
   TORRE – Recursividade simples
   Move-se em linha reta (direita)
   --------------------------- */
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) {
        return; // caso base
    }

    printf("Direita\n");

    moverTorre(casasRestantes - 1); // chamada recursiva
}

/* -----------------------------
   RAINHA – Recursividade simples
   Move-se para a esquerda
   ----------------------------- */
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) {
        return;
    }

    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

/* ---------------------------------------------------
   BISPO – Recursividade + loops aninhados
   Lógica:
   - Cada passo recursivo representa UMA diagonal.
   - O movimento diagonal é simulado com dois loops:
        vertical (externo) e horizontal (interno).
   --------------------------------------------------- */
void moverBispo(int diagonalRestante) {

    if (diagonalRestante == 0) {
        return; // caso base
    }

    /* Simulando diagonal para cima e direita:
       - Loop externo = vertical (“Cima”)
       - Loop interno = horizontal (“Direita”) */
    for (int v = 0; v < 1; v++) {          // movimenta para cima
        for (int h = 0; h < 1; h++) {      // movimenta para direita
            printf("Cima, Direita\n");
        }
    }

    moverBispo(diagonalRestante - 1);      // chamada recursiva
}

/* ============================================================
   CAVALO – LOOPS COMPLEXOS ANINHADOS
   Movimento desejado:
   -> duas casas para CIMA
   -> uma casa para DIREITA
   Regras:
     - loops aninhados
     - múltiplas variáveis de controle
     - continue e break necessários
   ============================================================ */
void moverCavalo() {

    int movimentosVert = 2;  // duas casas para cima
    int movimentosHoriz = 1; // uma casa para direita

    printf("Movimento do Cavalo:\n");

    for (int i = 0, controle = 10; i < movimentosVert; i++, controle--) {

        // loop interno controlando condições extras
        int passo = 0;

        while (passo < 2) {

            // continue usado para pular iterações irrelevantes
            if (passo == 1 && i == 0) {
                passo++; 
                continue;
            }

            printf("Cima\n");
            passo++;

            // break para evitar repetições desnecessárias
            if (passo == 2) {
                break;
            }
        }
    }

    // Movimento final: direita
    for (int j = 0; j < movimentosHoriz; j++) {
        printf("Direita\n");
    }
}

int main() {

    /* ============================
       TORRE – RECURSIVIDADE
       ============================ */
    printf("Movimento da Torre:\n");
    moverTorre(5);
    printf("\n");

    /* ============================
       BISPO – RECURSIVIDADE + LOOPS
       ============================ */
    printf("Movimento do Bispo:\n");
    moverBispo(5);
    printf("\n");

    /* ============================
       RAINHA – RECURSIVIDADE
       ============================ */
    printf("Movimento da Rainha:\n");
    moverRainha(8);
    printf("\n");

    /* ============================
       CAVALO – LOOPS COMPLEXOS
       ============================ */
    moverCavalo();
    printf("\n");

    return 0;
}

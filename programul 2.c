#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int valoare;
    struct Nod* stanga;
    struct Nod* dreapta;
} Nod;

Nod* creeazaNod(int valoare) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    nodNou->valoare = valoare;
    nodNou->stanga = NULL;
    nodNou->dreapta = NULL;
    return nodNou;
}

int maxim(int a, int b) {
    return a > b ? a : b;
}

void cautaZigZag(Nod* nod, int esteDreapta, int lungimeCurenta, int* maximLungime) {
    if (nod == NULL) return;
    *maximLungime = maxim(*maximLungime, lungimeCurenta);
    if (esteDreapta) {
        cautaZigZag(nod->stanga, 0, lungimeCurenta + 1, maximLungime);
        cautaZigZag(nod->dreapta, 1, 1, maximLungime);  // restart din dreapta
    } else {
        cautaZigZag(nod->dreapta, 1, lungimeCurenta + 1, maximLungime);
        cautaZigZag(nod->stanga, 0, 1, maximLungime);  // restart din stanga
    }
}

int zigzagMaxim(Nod* radacina) {
    int maximLungime = 0;
    cautaZigZag(radacina->stanga, 0, 1, &maximLungime);
    cautaZigZag(radacina->dreapta, 1, 1, &maximLungime);
    return maximLungime;
}

int main() {
    Nod* radacina = creeazaNod(1);
    radacina->stanga = creeazaNod(2);
    radacina->dreapta = creeazaNod(3);
    radacina->stanga->stanga = creeazaNod(4);
    radacina->stanga->dreapta = creeazaNod(5);
    radacina->dreapta->stanga = creeazaNod(6);
    radacina->dreapta->dreapta = creeazaNod(7);
    radacina->stanga->dreapta->dreapta = creeazaNod(10);
    radacina->stanga->dreapta->dreapta->stanga = creeazaNod(11);
    radacina->stanga->dreapta->dreapta->stanga->dreapta = creeazaNod(12);

    int rezultat = zigzagMaxim(radacina);
    printf("Cea mai lunga cale ZigZag are lungimea: %d\n", rezultat);

    return 0;
}

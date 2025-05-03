#include <stdio.h>
#include <stdlib.h>
#include "ingredientes.h"
#include "receitas.h"


int main()
{
    ListaI* l = criarListaI();
    ListaR* R = criarListaR();
    inserirR(R, "Strogonoff");
    inserirI(l, "Cominho");
    percorrerI(l);

    return 0;
}

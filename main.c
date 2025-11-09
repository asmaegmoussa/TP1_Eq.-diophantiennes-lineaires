#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c, d, r, q, a0, b0;

    int u = 1, v = 0;   // Coefficients finaux u, v (tels que a0*u + b0*v = d)
    int u1 = 0, v1 = 1; // Coefficients intermediaires u1, v1
    int temp;           // Pour les echanges

    printf("donner le premier nombre a :\n");
    scanf("%d", &a);
    printf("donner le deuxieme nombre b :\n");
    scanf("%d", &b);

    a0 = a; // Sauvegarde des valeurs initiales
    b0 = b;

    // L'algorithme d'Euclide travaille avec les valeurs absolues (PGCD positif)
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        q = a / b;  // Quotient
        r = a % b;  // Reste

        printf("%d = %d * %d + %d\n", a, q, b, r);

        a = b;
        b = r;

        temp = u;
        u = u1;
        u1 = temp - q * u1;

        temp = v;
        v = v1;
        v1 = temp - q * v1;
    }

    d = a;

    if (a0 < 0) u = -u;
    if (b0 < 0) v = -v;

    if (d == 1) {
        printf("Le PGCD de ces deux nombres est : 1 \\n donc ils sont premiers entre eux :\n");
    } else {
        printf("Le PGCD de ces deux nombres est : %d\n", d);
    }

    printf("donner un troisieme nombre c :\n");
    scanf("%d", &c);

    printf("Maintenant on va trouver les solutions particulieres de l'equation diophantienne suivante: %dx + %dy = %d\n", a0, b0, c);

    if (c % d != 0) {
        // Condition : c n'est pas divisible par le PGCD (d)
        printf("%d n'est pas divisible par %d alors cette equation n'admet aucune solution entiere.\n", c, d);
    } else {
        // Condition : c est divisible par le PGCD (d)
        printf("%d divisible par %d donc cette equation admet aux moins une solution entiere.\n", c, d);

        // Calcul du facteur multiplicatif et de la solution particuliere
        int k = c / d;
        int xp = u * k;
        int yp = v * k;

        // Composantes pour la solution generale
        int a_prime = b0 / d;
        int b_prime = a0 / d;

        printf("\nSolution particuliere (xp, yp) : xp = %d et yp = %d\n", xp, yp);
        printf("L'ensemble des solutions generales est de la forme:\n");
        printf("S = { (%d + t*(%d), %d - t*(%d)) pour tout entier t }\n", xp, a_prime, yp, b_prime);
    }

    return 0;
}

#include <stdio.h>
#include "type_pile_erreurs.h"
#include "commandes_calculette.h"

int addition(PileEntiers *p)
{
    int valeur1, valeur2;
    depiler(p, &valeur1);
    depiler(p, &valeur2);
    int result = valeur1 + valeur2;
    empiler(p, result);
    return result;
}

int soustraction(PileEntiers *p)
{
    int valeur1, valeur2;
    depiler(p, &valeur1);
    depiler(p, &valeur2);
    int result = valeur2 - valeur1;
    empiler(p, result);
    print(p);
    return result;
}

int multiplication(PileEntiers *p)
{
    int valeur1, valeur2;
    depiler(p, &valeur1);
    printf("%d", valeur1);
    depiler(p, &valeur2);
    printf("%d", valeur2);
    int result = valeur1 * valeur2;
    empiler(p, result);
    return result;
}

int division(PileEntiers *p)
{
    int result = 0;
    int valeur1, valeur2;
    depiler(p, &valeur1);
    depiler(p, &valeur2);
    if (valeur1 != 0)
    {
        int result = valeur2 / valeur1;
        empiler(p, result);
    }
    else
    {
        printf("Erreur, division par 0 impossible !");
    }
    return result;
}

int main(int argc, char **argv)
{
    FILE *fichier = NULL;
    if (argc != 2)
    {
        printf("mauvaise utilisation : donnez un nom de fichier en argument\n");
        return 0;
    }

    fichier = ouvrir_commandes(argv[1]);
    PileEntiers p;
    creer_pile(&p);

    commande command;

    int value;
    int *tmp = NULL;

    while (!fin_commandes(fichier))
    {
        command = commande_suivante(fichier);
        print_commandes(command);
        switch (command.cmd)
        {
        case VIDER_PILE:
            vider(&p);
            break;
        case DEPILER_SOMMET:
            depiler(&p, tmp);
            break;
        case EMPILER_VALEUR:
            empiler(&p, command.arg);
            break;
        case EFFECTUER_ADDITION:
            value = addition(&p);
            break;
        case EFFECTUER_SOUSTRACTION:
            value = soustraction(&p);
            break;
        case EFFECTUER_MULTIPLICATION:
            value = multiplication(&p);
            break;
        case EFFECTUER_DIVISION:
            value = division(&p);
            break;
        case COMMANDE_INCORRECTE:
            printf("Commande incorrecte !\n");
            break;
        }
        print(&p);
        printf("\n");
    }
    fermer_commandes(fichier);
    return 0;
}

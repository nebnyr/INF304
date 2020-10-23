#include <stdlib.h>
#include <stdio.h>
#include "type_pile_erreurs.h"

erreur_pile creer_pile(PileEntiers *p)
{
	if (p != NULL)
	{
		return POINTEUR_NUL;
	}
	else
	{
		p->n = 0;
		return OK;
	}
}

int est_vide(PileEntiers *p)
{
	if (p != NULL)
	{
		return POINTEUR_NUL;
	}
	else
	{
		return (p->n == 0);
	}
}

erreur_pile sommet(PileEntiers *p, int *res)
{
	if (est_vide(p))
	{
		return PILE_VIDE;
	}
	else
	{
		res = &p->tab[p->n - 1];
		return OK;
	}
	free(res);
}

int taille(PileEntiers *p)
{
	if (p != NULL)
	{
		return POINTEUR_NUL;
	}
	else
	{
		return p->n;
	}
}

void print(PileEntiers *p)
{
	int i;
	printf("[ ");
	for (i = p->n - 1; i >= 0; i--)
	{
		printf("%d ", p->tab[i]);
	}
	printf("]");
}

erreur_pile vider(PileEntiers *p)
{
	if (p != NULL)
	{
		return POINTEUR_NUL;
	}
	else
	{
		p->n = 0;
		return OK;
	}
}

erreur_pile empiler(PileEntiers *p, int x)
{
	if (p != NULL)
	{
		return POINTEUR_NUL;
	}
	else if (taille(p) >= TAILLE_MAX)
	{
		return PILE_PLEINE;
	}
	else
	{
		p->tab[p->n] = x;
		p->n = p->n + 1;
		return OK;
	}
}

erreur_pile depiler(PileEntiers *p, int *resultat)
{
	if (p != NULL)
	{
		return POINTEUR_NUL;
	}
	else if (est_vide(p))
	{
		return PILE_VIDE;
	}
	else
	{
		resultat = &p->tab[p->n];
		p->n = p->n - 1;
		return OK;
	}
	free(resultat);
}

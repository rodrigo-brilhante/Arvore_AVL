#include <iostream>
using namespace std;

struct noAvl
{
	int info;
	char fb;
	noAvl *esq, *dir;
};

void insAvl(noAvl **T, int X, char *h)
{
	if (*T == NULL)
	{
		*T = new noAvl();
		(*T)->info = X;
		(*T)->dir = (*T)->esq = NULL;
		(*T)->fb = 0;
		*h = 1;
	}
	else
	{
		if (X < (*T)->info)
		{
			insAvl(&((*T)->esq), X, h);
			if (*h)
			{
				switch ((*T)->fb)
				{
				case 1:
					(*T)->fb = 0;
					*h = 0;
					break;

				case 0:
					(*T)->fb = -1;
					break;

				case -1:
					//	RD(T);
					*h = 0;
					break;

				default:
					break;
				}
			}
		}
		else if (X > (*T)->info)
		{
			insAvl(&((*T)->dir), X, h);
			if (*h)
			{
				switch ((*T)->fb)
				{
				case 1:
					//	RE(T);
					*h = 0;
					break;

				case 0:
					(*T)->fb = 1;
					break;

				case -1:
					(*T)->fb = 0;
					*h = 0;
					break;
				default:
					break;
				}

			}
		}

	}

}

void main()
{
	noAvl *T1 = NULL;
	char h;
	insAvl(&T1, 10, &h);
}
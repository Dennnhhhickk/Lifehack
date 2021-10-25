#include "Commands.h"
#include <string.h>
#include <stdlib.h>

void swap(double *a, double *b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

double root(double (*f)(double), double (*g)(double), double a, double b, double eps)
{
	if (a > b)
		swap(&a, &b);

	double m;
	while (b - a > eps)
	{
		itr++;
		m = (a + b) / 2.0;
		//if (fabs(f(m) - g(m)) < eps)
		//	break;
		if ((f(a) - g (a)) * (f(m) - g(m)) > 0)
			a = m;
		else
			b = m;
	}
	return (a + b) / 2.0;
}

double integral(double (*f)(double), double a, double b, double eps)
{
	if (a > b)
		swap(&a, &b);
	int n = 1;
	double sum = f(a) + f(b), step = (b - a) / n;
	double I = 10, I1 = 0;
	while (fabs(I - I1) > 15 * eps)
	{
		n *= 2;
		step /= 2;
		double tmp = 0;
		I1 = I;
		I = 0;
		for (int i = 0; i < n / 2; i++)
			tmp += f(a + step + 2 * i * step);
		tmp *= 2;
		I = (sum + 2 * tmp) * step / 3;
		sum += tmp;
	}
	return I;
}

int main(int argc, char* argv[])
{
	double eps = 1e-3;
	int formul_count = 3;
	double doubles[9];
	int ints[3], k = 0;
	double (*formuls[])(double) = {f1, f2, f3};

	double a = -1.9, b = 6;
	//scanf("%lf %lf", &a, &b);

	for (int i = 0; i < 3; i++)
	{
		itr = 0;
		doubles[i] = root(formuls[i], formuls[(i + 1) % 3], a, b,  eps / 6);
		doubles[3 + i] = formuls[i](doubles[i]);
		ints[i] = itr;
	}

	doubles[6] = integral(formuls[0], doubles[0], doubles[2], eps / 30);
	doubles[7] = integral(formuls[1], doubles[0], doubles[1], eps / 30);
	doubles[8] = integral(formuls[2], doubles[1], doubles[2], eps / 30);

	if (argc == 1)
		printf("%.4f\n", doubles[6] - (doubles[7] + doubles[8]));
	else
		for (int i = 1; i < argc; i++)
			for (int j = 0; j < commande_list_size; j++)
				if (strcmp(commande_list[j], argv[i]) == 0)
				{
					func(j, 3, doubles, ints);
				}
	return 0;
}

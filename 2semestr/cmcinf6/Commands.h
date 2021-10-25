#include <stdio.h>
#include "functions.h"

int commande_list_size = 6;
char* commande_list[] = {"-help", "-i", "-a", "-show", "-testi", "-testr"};
char* description_list[] = {"Display all available commands", "Display the number of iterations", "Display the point of intersection", "Display all the integrals", "Allows you to test the integration function", "Allows you to test the root function"};

void func(int command, int size, double a[], int b[])
{
	switch (command)
	{
		case 0:
			printf("COMMANDS:\n");
			for (int i = 0; i < commande_list_size; i++)
				printf("%s\t\t%s\n", commande_list[i], description_list[i]);
			break;
		case 1:
			printf("ITERATION:\n");
			for (int i = 0; i < size; i++)
				printf("%d-%d\t\t%d\n", i + 1, (i + 1) % size + 1, b[i]);
			break;
		case 2:
			printf("COORDS:\n");
			for (int i = 0; i < size; i++)
				printf("%d-%d\t\tx = %.3f\t\ty = %.3f\n", i + 1, (i + 1) % size + 1, a[i], a[3 + i]);
			break;
		case 3:
			printf("INTEGRALS:\n");
			for (int i = 0; i < size; i++)
				printf("%d\t\t%.3f\n", i + 1, a[6 + i]);
			break;
		case 4:
			{
				printf("TESTING INTEGRAL\n");
				double l, r;
				scanf("%lf %lf", &l, &r);
				printf("%.3f\n", integral(testfunc, l, r, 0.0001));
			}
			break;
		case 5:
			{
				printf("TESTING ROOT:\n");
				double l, r;
				itr = 0;
				scanf("%lf %lf", &l, &r);
				printf("%.3f\n", root(testfunc1, testfunc2, l, r, 0.001));
				printf("FUNCTIONS:\ny = -x^2\ny = 4x-1\n");
				printf("Iteration: %d\n", itr);
			}
			break;
		default:
			printf("No matches\n");
	}
}

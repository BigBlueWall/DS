#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX 10
#endif

int *stack;
int k;

void Push(int x)
{
	if(k < MAX)
		stack[k++] = x;
	else
		printf("Full Stack.\n");
}

int Pop()
{
	if(k < 1)
		return -1;
	return stack[--k];
}

int Top()
{
	if(k < 1)
		return -1;
	return stack[k-1];
}

int main(int argc, char const *argv[])
{
	int op, x;

	k = 0;
	stack = (int *)malloc(sizeof(int) * MAX);

	while(~scanf("%d", &op))
	{
		if(op == -1)
			break;

		switch(op)
		{
			case 1:
				scanf("%d", &x);
				Push(x);
				break;
			case 2:
				x = Pop();
				printf("%d\n", x);
				break;
			case 3:
				x = Top();
				printf("%d\n", x);
				break;
			default:
				printf("Invalid op arg.\n");
				break;
		}
	}

	free(stack);
	stack = NULL;

	return 0;
}



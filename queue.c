#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX 5
#endif

int *queue;
int head, tail;

void Enqueue(int x)
{
	if((tail + 1) % MAX == head)
	{
		printf("Full queue\n");
		return;
	}
	queue[tail] = x;
	tail = (tail + 1) % MAX;
}

int Dequeue()
{
	int x;
	if(head == tail)
		return -1;
	x = queue[head];
	head = (head + 1) % MAX;
	return x;
}

int Front()
{
	if(head == tail)
		return -1;
	return queue[head];
}

int main(int argc, char const *argv[])
{
	int op, x;

	head = 0;
	tail = 0;
	queue = (int *)malloc(sizeof(int) * MAX);

	while(~scanf("%d", &op))
	{
		if(op == -1)
			break;

		switch(op)
		{
			case 1:
				scanf("%d", &x);
				Enqueue(x);
				break;
			case 2:
				x = Dequeue();
				printf("%d\n", x);
				break;
			case 3:
				x = Front();
				printf("%d\n", x);
				break;
			default:
				printf("Invalid op arg.\n");
				break;
		}
	}

	free(queue);
	queue = NULL;

	return 0;
}



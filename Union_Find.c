#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX 15
#endif

int *L;
int k;

void Init()
{
    int i;
    for(i = 0; i < MAX; i++)
        L[i] = i;
}

int Find(int x)
{
    int root;
    
    if(L[x] == x)
        return x;
    root = Find(L[x]);
    L[x] = root;

    return root;
}

void Union(int x, int y)
{
    L[Find(y)] = Find(x); 
}

int main(int argc, char const *argv[])
{
    int op, x, y;
    
    k = 0;
    L = (int *)malloc(sizeof(int) * MAX);
    Init();
    
    while(~scanf("%d", &op))
    {
        if(op == -1)
            break;
        
        switch(op)
        {
            case 1:
                scanf("%d%d", &x, &y);
                Union(x, y);
                break;
            case 2:
                scanf("%d", &x);
                y = Find(x);
                printf("%d\n", y);
                break;
            default:
                printf("Invalid op arg.\n");
                break;
        }
    }

    free(L);
    L = NULL;
    
    return 0;
}

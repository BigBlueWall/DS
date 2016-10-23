#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *FrenwickTree;
int m;
int size;

void Init()
{
    int i;
    int n;
    
    scanf("%d", &n);

    size = 0;
    while((1 << size) < n)
        size ++;
    m = (1 << size) - 1;
    size += 1;
    size = (1 << size) - 1;

    FrenwickTree = (int *)malloc(sizeof(int) * size);
    for(i = 0; i < size; i++)
        FrenwickTree[i] = 0;
}

int HasLeftNeighbor(int i)
{
    while(i)
    {
        if(i % 2 == 0)
            return 1;
        i = i >> 1;
    }
    return 0;
}

int Sum(int k)
{
    int i = k;
    int sum = 0;
    
    while(1)
    {   
        if(i == 0)
            return FrenwickTree[0];
        if(i % 2 == 1)
        {
            sum += FrenwickTree[i];
            i = (i - 1) >> 1;
            if(HasLeftNeighbor(i) == 0)
                break;
            else
                i -=1;
        }
        else
            i = (i - 1) >> 1;
    }

    return sum;
}

void Set(int k, int x)
{
    int i;
    FrenwickTree[k] = x;
    for(i = (k-1)/2; i >= 0; i = (i-1)>>1)
        FrenwickTree[i] = FrenwickTree[i*2+1] + FrenwickTree[i*2+2];
}

void Done()
{
    free(FrenwickTree);
    FrenwickTree = NULL;
}

void Print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", FrenwickTree[i]);
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    int op, k, x;
    
    Init();
    
    while(~scanf("%d", &op))
    {
        if(op == -1)
            break;
        
        switch(op)
        {
            case 1:
                scanf("%d%d", &k, &x);
                k += m;
                Set(k, x);
                break;
            case 2:
                scanf("%d", &k);
                k += m;
                x = Sum(k);
                printf("%d\n", x);
                break;
            default:
                printf("Invalid op arg.\n");
                break;
        }
    }

    Done();
    
    return 0;
}

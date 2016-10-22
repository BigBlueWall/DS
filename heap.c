#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX 15
#endif

typedef struct task
{
    int x;
    int p;
    
}TASK;

TASK heap[MAX];
int k;

void swap(int i, int j)
{
    TASK t;
    
    t = heap[j];
    heap[j] = heap[i];
    heap[i] = t;
}

void Insert(int x, int p)
{
    int i;
    
    if(k < MAX)
    {
        (heap[k]).x = x;
        (heap[k++]).p = p;
        for(i = k-1; i > 0; i /= 2)
        {
            if((heap[i]).p > (heap[(i-1)/2]).p)
                swap(i, (i-1)/2);
            else
                break;
        }
    }
    else
        printf("Full Heap.\n");
}

int RemoveTop()
{
    int i, x;
    
    if(k < 1)
        return -1;
    
    x = (heap[0]).x;
    heap[0] = heap[--k];
    i = 0;
    while(1)
    {
        if(2 * i + 1 < k)
        {
            if(2 * i + 2 < k)
            {
                if((heap[2*i+1]).p > (heap[2*i+2]).p && (heap[2*i+1]).p > (heap[i]).p)
                {
                    swap(i, 2*i+1);
                    i = 2*i+1;
                }
                else if((heap[2*i+2]).p > (heap[2*i+1]).p && (heap[2*i+2]).p > (heap[i]).p)
                {
                    swap(i, 2*i+2);
                    i = 2*i+2;
                }
                else
                    break;
            }
            else if((heap[i]).p < (heap[2*i+1]).p)
            {
                swap(i, 2*i+1);
                i = 2*i+1;
            }
            else
                break;
        }
        else
            break;
    }
    
    return x;
}

int Top()
{
    if(k < 1)
        return -1;
    return (heap[0]).x;
}

int main(int argc, char const *argv[])
{
    int op, x, p;
    
    k = 0;
    
    while(~scanf("%d", &op))
    {
        if(op == -1)
            break;
        
        switch(op)
        {
            case 1:
                scanf("%d%d", &x, &p);
                Insert(x, p);
                break;
            case 2:
                x = RemoveTop();
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
    
    return 0;
}

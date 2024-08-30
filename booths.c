#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int i = 0, i1, i2, sup,count=0,carry = 0,*arr,*multiplicand,*multiplier,*accumulator;
void reverse();void mal();void decimaltobinary(int);void printResult();
void reverse();void resize();void heading();void spacex();void printm();
void printacc();void printq();void shift();void add();void binarytodecimal();
int main()
{
    printf("\nenter the Multiplicand : ");
    int M;scanf("%d", &M);
    mal();decimaltobinary(M);
    multiplicand = (int *)malloc(i * sizeof(int));
    for (int k = 0; k < i; k++)
    {
        multiplicand[k] = arr[k];
    }
    i1 = i;i = 0;free(arr);
    printf("enter the multiplier : ");
    int Q;scanf("%d", &Q);
    mal();decimaltobinary(Q);
    multiplier = (int *)malloc(i * sizeof(int));
    for (int k = 0; k < i; k++)
    {
        multiplier[k] = arr[k];
    }
    i2 = i,i = 0;free(arr);resize();
    accumulator = (int *)calloc(i, sizeof(int));
    for (int k = 0; k < i-1; k++)
    {
        accumulator[k]=0;
    }
    sup = i;reverse();count=i;
    printf("\nthe multiplicand in binary form : ");printm();
    printf("\nthe multiplier in binary form : ");
    for (int k = 0; k < i; k++)
    {
        printf("%d", multiplier[k]);
    }
    printf("\n");
    printf("initially the accumulator is : ");printacc();
    printf("\n\n");
    heading();
    printm();spacex();printf(" ");printacc();spacex();printf(" ");printq();spacex();printf("\n");
    while(1)
    {
        if (multiplier[i-1]==0)
        {
            printf("----------------|----------------------------------\n");
            printf("                |  shift operation : -->             \n");
            printf("----------------|----------------------------------\n");
            shift();
            printm();spacex();printf(" ");printacc();spacex();printf(" ");printq();spacex();printf("\n");
            count --;
            if (count==0)
            {
               break;
            }
        }
        if (multiplier[i-1]==1)
        {
            add();
            printf("----------------|----------------------------------\n");
            printf("                |   Add operation : -->            \n");
            printf("----------------|----------------------------------\n");
            printm();spacex();printf(" ");printacc();spacex();printf(" ");printq();spacex();printf("\n");
            printf("----------------|----------------------------------\n");
            printf("                |   shift operation : -->           \n");
            printf("----------------|----------------------------------\n");

            // now shift:

            shift();
            printm();spacex();printf(" ");printacc();spacex();printf(" ");printq();spacex();printf("\n");
            count--;
            if (count==0)
            {
                break;
            }
        }

    }
    printf("\nthe result is AQ : ");printResult();
    binarytodecimal();
    return 0;
}
void add()
{
    carry=0;
    for (int k = i-1 ; k >= 0 ; k--)
    {
        if (accumulator[k]==0 && multiplicand[k]==0)
        {
            if (carry==0)
            {
                carry=0;
                accumulator[k] = 0; 
            }
            else if(carry==1)
            {
                carry=0;
                accumulator[k] = 1;
            }

        }
        else if (accumulator[k]==0 && multiplicand[k]==1)
        {
            if (carry==0)
            {
                carry=0;
                accumulator[k] = 1;

            }
            else if (carry==1)
            {
                carry =1;
                accumulator[k] = 0;
            }

        }
        else if (accumulator[k]==1 && multiplicand[k]==0)
        {
            if (carry==0)
            {
                carry=0;
                accumulator[k] = 1;
            }
            else if (carry == 1)
            {
                carry = 1;
                accumulator[k]= 0;
            }
            
            
        }
        else if(accumulator[k]==1 && multiplicand[k]==1)
        {
            if (carry==0)
            {
                carry = 1;
                accumulator[k] = 0;
            }
            else if (carry==1)
            {
                carry = 1;
                accumulator[k] = 1;
            }
            
        }
                
    }
    
}
void shift()
{
    for (int k = i-1 ; k > 0 ; k--)
    {
        multiplier[k] = multiplier[k - 1];
    }
    multiplier[0] = accumulator[i - 1];
    for (int k = i-1 ; k > 0 ; k--)
    {
        accumulator[k] = accumulator[k - 1];
    }
    accumulator[0]=carry;
    carry=0;
}
void resize()
{
    printf("step_wise_evaluation is as follows:\n");
    if (i1 > i2)
    {
        multiplier = (int *)realloc(multiplier, i1 * sizeof(int));
        for (int k = i2; k < i1; k++)
        {
            multiplier[k] = 0;
        }
        i = i1;
    }
    else if (i2 > i1)
    {
        multiplicand = (int *)realloc(multiplicand, i * sizeof(int));
        for (int k = i1; k < i2; k++)
        {
            multiplicand[k] = 0;
        }
        i = i2;
    }
    else if (i2 == i1)
    {
        i1 =  i2;
        i  =  i2;
    }
}
void spacex()
{
    for (int k = 0; k < 15 - sup; k++)
    {
        printf(" ");
    }
}
void mal()
{
    arr = (int *)malloc(1 * sizeof(int));
}
void decimaltobinary(int n)
{
    while (n > 0)
    {
        int j;
        j = n % 2;
        arr[i] = j;
        n = n / 2;
        i++;
        arr = (int *)realloc(arr, (1+i) * sizeof(int));
    }
}
void heading()

{
    printf("MULTIPLICAND    |     ACCUMULATOR                Q\n");
    printf("---------------------------------------------------------------\n");
}
void reverse()
{
    for (int k = 0; k < i / 2; k++)
    {
        int t = multiplier[k];
        multiplier[k] = multiplier[i - 1 - k];
        multiplier[i - 1 - k] = t;
        int p = multiplicand[k];
        multiplicand[k] = multiplicand[i - 1 - k];
        multiplicand[i - 1 - k] = p;
    }
}
void printacc()
{
    printf("|     ");
    for (int k = 0; k < i; k++)
    {
        printf("%d", accumulator[k]);
    }
    printf("     |");
}

void printResult()
{
    for(int k = 0;k<i;k++)
    {
        printf("%d",accumulator[k]);
    } 
    for (int k = 0;k<i;k++)
    {
        printf("%d",multiplier[k]);
    }
}

void printm()
{
    for (int k = 0; k < i; k++)
    {
        printf("%d", multiplicand[k]);
    }
}
void printq()
{
    for (int k = 0; k < i; k++)
    {
        printf("%d", multiplier[k]);
    }
    printf("         count=%d",count);
}
void binarytodecimal(){
    int sum=0;
    for (int k = 0; k < i; k++)
    {
        sum=sum+accumulator[k]*pow(2,2*i-1-k)+multiplier[k]*pow(2,i-1-k);
    }      
    printf("\nthe resutl = %d\n",sum);
    
}


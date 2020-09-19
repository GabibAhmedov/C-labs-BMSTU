

#include <stdio.h>;
#include <math.h>;
float factorial(float x);
int main()
{
    float accuracy, n, summIpred,summI,nextposled;
    scanf_s("%f", &accuracy);
    n = 1;
    summI = 1 / factorial(n);
    do
    {
        summIpred = summI;
        n = n + 1;
        nextposled = 1 / factorial(n);
        summI = summI+nextposled;
        
    } while (summI - summIpred >= accuracy);
    printf("%f", summI);

}



float factorial(float n)
{
    float result;
    if (n == 0)
    {
        result = 1;
    }
    else
    {
        result = n * factorial(n - 1);
    }
return result;
}


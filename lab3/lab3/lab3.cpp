

#include <stdio.h>;
#include <math.h>;
float factorial(float x);
int main()
{
    
    float accuracy; scanf_s("%f", &accuracy);
    float  n;  n = 1;
    float  summI; summI = 1 / factorial(n);
    float summIpred;
    do
    {
        summIpred = summI;
        n = n + 1;
        float nextposled; nextposled = 1 / factorial(n);
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


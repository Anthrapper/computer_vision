#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Perceptron
{
    float w1, w2, th;
};

Perceptron train(int[], int[], int[], Perceptron);
Perceptron initialize(Perceptron);
float getRandom();
int activation(float);
void output(Perceptron);

int main()
{
    int x1[4] = {0, 0, 1, 1};
    int x2[4] = {0, 1, 0, 1};

    int yand[4] = {0, 0, 0, 1};
    int yor[4] = {0, 1, 1, 1};
    int yxor[4] = {0, 1, 1, 0};
    int ynand[4] = {1, 1, 1, 0};
    int ynor[4] = {1, 0, 0, 0};
    int n;

    struct Perceptron p;

    printf("Enter the type of logic gate output: \n1.AND\n2.OR\n3.NAND\n4.NOR\n5.XOR\n");
    scanf("%d", &n);

    Perceptron pr = initialize(p);
    switch (n)
    {
    case 1:
    {
        Perceptron pr1 = train(x1, x2, yand, pr);
        output(pr1);
        break;
    }
    case 2:
    {
        Perceptron pr1 = train(x1, x2, yor, pr);
        output(pr1);
        break;
    }
    case 3:
    {
        Perceptron pr1 = train(x1, x2, ynand, pr);
        output(pr1);
        break;
    }
    case 4:
    {
        Perceptron pr1 = train(x1, x2, ynor, pr);
        output(pr1);
        break;
    }
    case 5:
    {
        Perceptron pr1 = train(x1, x2, yxor, pr);
        output(pr1);
        break;
    }
    default:
        break;
    }

    return 0;
}

Perceptron initialize(Perceptron pr)
{
    pr.w1 = getRandom();
    pr.w2 = getRandom();
    printf("W1: %f W2: %f \n", pr.w1, pr.w2);
    printf("Enter threshold value: ");
    scanf("%f", &pr.th);

    return pr;
}

Perceptron train(int x1[], int x2[], int y[], Perceptron pr)
{
    int count = 0, itr = 0;
    while (count != 4)

    {
        count = 0;
        for (int i = 0; i < 4; i++)
        {
            float prd = pr.w1 * x1[i] + pr.w2 * x2[i] + pr.th;
            int predict = activation(prd);

            if (predict == y[i])
            {
                count++;
            }

            else if ((predict == 1) && (y[i] == 0))
            {
                pr.w1 = pr.w1 - x1[i];
                pr.w2 = pr.w2 - x2[i];
            }
            else if ((predict == 0) && (y[i] == 1))
            {
                pr.w1 = pr.w1 + x1[i];
                pr.w2 = pr.w2 + x2[i];
            }
        }
        itr++;

        if (itr == 1000)
        {
            printf("\ninvalid threshold provided or maximum iterations reached !!!\n");
            break;
        }
    }
    return pr;
}

int activation(float predict)
{

    if (predict > 0)
        return 1;
    else
        return 0;
}

int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

float getRandom()
{
    return random(-100, 100) / 100.0;
}

void output(Perceptron pr)
{
    if (pr.th < 0)
    {
        printf("\nseparation line:  %.2f x1 + %.2f x2 %.2f  = 0\n", pr.w1, pr.w2, pr.th);
    }
    else
    {
        printf("\nseparation line:  %.2f x1 + %.2f x2 + %.2f = 0\n", pr.w1, pr.w2, pr.th);
    }
}

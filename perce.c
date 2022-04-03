#include <stdio.h>
#include <string.h>

void check_weights(int[], int[], int[]);
int main()
{
    int x1[4] = {0, 0, 1, 1};
    int x2[4] = {0, 1, 0, 1};

    int y_and[4] = {0, 0, 0, 1};
    int y_xor[4] = {0, 1, 1, 0};
    char gate[10];

    printf("Enter the type of logic gate (AND / XOR) \n");
    scanf("%s", gate);

    if (strcmp(gate, "AND") == 0)
    {
        check_weights(x1, x2, y_and);
    }
    else if (strcmp(gate, "XOR") == 0)
    {
        check_weights(x1, x2, y_xor);
    }

    return 0;
}

void check_weights(int x1[], int x2[], int y[])
{
    float w1, w2, th;

    printf("Enter the initial weights w1,w2 & threshold : \n");
    scanf("%f", &w1);
    scanf("%f", &w2);
    scanf("%f", &th);

    for (int i = 0; i < 4; i++)
    {

        if ((w1 * x1[i] + w2 * x2[i] + th > 0) && (y[i] == 0))
        {
            w1 = w1 - x1[i];
            w2 = w2 - x2[i];
        }
        if ((w1 * x1[i] + w2 * x2[i] + th < 0) && (y[i] == 1))
        {
            w1 = w1 + x1[i];
            w2 = w2 + x2[i];
        }
    }

    if (th < 0)
        printf("Equation of seperation line is: %.2f x1 + %.2f x2 %.2f = 0\n", w1, w2, th);
    if (th >= 0)
        printf("Equation of seperation line is: %.2f x1 + %.2f x2 + %.2f = 0\n", w1, w2, th);
}

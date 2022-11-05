#include <stdio.h>

void main()
{
    int capacity =10 , no_items = 10, cur_weight, item;
    int used[10];
    float total_profit;
    int i;
    int weight[10] = {1,2,3,4,5,6,7,8,9,0};
    int value[10] = {0,9,8,7,6,5,4,3,2,1};

    

    for (i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) value[i] / weight[i] > (float) value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];
        if (cur_weight >= 0)
            printf("weight left is :%d\n", cur_weight);
        else
        {
            int item_percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }

    printf("value of knapsack %.2f Rs.\n", total_profit);
}
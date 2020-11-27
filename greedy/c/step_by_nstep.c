#include <stdio.h>

int max_index(int *array, int cur_steps, int nxt_index);

int num_of_steps(int *array, int len)
{
    int i = 0, max_i = 0, steps = 0;
    while(i < len)
    {
        steps++;
        if(i+1+array[i] >= len)
            break;
        max_i = max_index(array, array[i], i+1);
        i = max_i;
    }
 
    return steps;
}

int max_index(int *array, int cur_steps, int nxt_index)
{
    int max = 0, max_idx = 0;
    for(int i = nxt_index; i < cur_steps + nxt_index; ++i)
    {
        if(array[i] > max)
        {
            max = array[i];
            max_idx = i;
        }
    }

    return max_idx;
}

int main()
{
    int array[] = {2,3,1,4,1,5,2,1,3};
    int steps = num_of_steps(array, sizeof(array)/sizeof(int));
    printf("Steps: %d\n", steps);
    return 0;
}

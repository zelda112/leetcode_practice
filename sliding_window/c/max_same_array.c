#include <stdio.h>

int max_same_len(int *left, int *right, int *array, int len)
{
    int l = 0, r = 0;
    int target = array[r], array_len = len, max_len = 0; 
    while(r < array_len)
    {
        r++;
        if(array[r] != target)
        {
            if(max_len < (r - l))
            {
                max_len = r - l;
                *left = l;
                *right = r;
            }
            l = r;
            target = array[l];
        }
    }

    return max_len;
}

int main()
{
    int array[] = {2,2,2,2,2,2,3,3,3,3,5,5,5,5,5,5,5,5,5,7,7,7,7,7,7,
7,7,7,7,7,1,2,3,4,5,2,1,3,5,7,1,1,1,0,0,0,0,0,2,2,2,2};
    int len = sizeof(array)/sizeof(int);
    int left = 0, right = 0;
    int max_len = max_same_len(&left, &right, array, len);
    printf("max len: %d\n", max_len);
    for(int i = left; i < right; ++i)
        printf("%d,", array[i]);
    printf("\n");
    return 0;
}

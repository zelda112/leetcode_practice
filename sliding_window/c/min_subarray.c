#include <stdio.h>

int min_subarray_len(int *left, int *right, int s, int *array, int len)
{
    *left = 0, *right = 0;
    // if s is greater than the sum of all value in array, min_len should be greater than len forever
    int min_len = len + 1, array_len = len, total = 0;
    while(*right < array_len)
    {
       do
       {
           total += array[*right];
           ++(*right); 
       }
       while(*right < array_len && total < s);       

       while(*left < *right && total - array[*left] >= s)
       {
           total -= array[*left];
           ++(*left);
       }

       // Only change the value of min_len while s is less than the sum of all value in array 
       if(total >=s && min_len > (*right - *left) )
       {
           min_len = *right - *left;
       }
    }

    return min_len <= len ? min_len : 0;
}

int main()
{
    int array[] = {2,3,1,4,3,5,7};
    int left = 0, right = 0, s = 22; 
    int mlen = min_subarray_len(&left, &right, s, array, 7);
    printf("min len: %d\n", mlen);
    for(int i = left; i < right; ++i)
        printf("%d, ", array[i]);
    printf("\n");
    return 0;
}

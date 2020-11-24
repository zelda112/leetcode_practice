def subArray(array):
    left = 0
    right = 1
    l = 0
    r = 0
    target = array[0]
    array_len = len(array)
    max_len = 0
    while (right < array_len):
        if(array[right] != target):
            if(max_len < (right - left)):
                max_len = right - left;
                l = left
                r = right

            left = right
            target = array[left]
        right+=1
    for i in range(l, r):
        print array[i],
    print (r - l)
    return

list = [2,2,2,2,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,
4,4,4,4,3,3,5,5,5,5,5,5,5,7,7,7,7,7]
subArray(list)

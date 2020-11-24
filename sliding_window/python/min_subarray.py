def subArray(s, array):
    left = 0
    right = 0
    total = 0
    array_len = len(array)
    min_len = array_len + 1
    print s 
    while (right < array_len):
        total += array[right] 
        right+=1
        if(total >= s):
            while(left < right and total - array[left] >= s):
                total -= array[left]
                left+=1

        if(total >= s and min_len > (right - left)):
            min_len = right - left;    
    if(min_len <= array_len):
        print "sub array is",
        for i in range(left, right):
            print array[i],
        print
        return min_len 
    else:
        return 0

list = [2,3,1,4,3,5,7]
s = 15
minlen = subArray(s, list)
print "min len is",minlen

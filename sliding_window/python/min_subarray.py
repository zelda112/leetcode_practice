def subArrayLen(left, right, s, array):
    left, right, total = 0
    array_len = len(array)
    min_len = array_len + 1
    while (right < range(len(array))):
        total += array[right] 
        right += 1
        while(right < range(len(array)) and total < s):
            pass 
  
        while(left < right and total - array[left] >= s):
            total -= array[left]
            left += 1

        if(total >= s and min_len > (right - left)):
            min_len = right - left;    
      

list = [2,3,1,4,3,5,7]
l, r = 0
s = 15
subArrayLen(l, r, s, list)

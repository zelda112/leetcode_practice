#include <iostream>
#include <vector>

using std::cout;
using std::endl;

struct Solution
{
    int maxSameLen(int& left, int& right, std::vector<int> v)
    {
        int l = 0, r = 0;
        int target = v[r], len = v.size(), max_len = 0;
        while(r < len)
        {
            r++;
            if(v[r] != target)
            {
                if(max_len < (r - l))
                {
                    max_len = r - l;
                    left = l;
                    right = r;
                }
                l = r;
                target = v[l];
            }
        }
        
        cout << "left: " << left << "," << "right: " << right << endl;

        return max_len;
    }
};

int main(void)
{
    std::vector<int> v = {2,2,2,2,2,1,1,1,5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,7,7,7
,7,7,7,7,7,7,1,5,2,4,0,0,0,0,0,0,0,2,1,3,4,3,5,7,7,7,2,2,2,4,4,4,4,4,11,11}; 
    Solution sobj;
    int left = 0, right = 0;
    int maxlen = sobj.maxSameLen(left, right, v);
    cout << "max len: " << maxlen << endl;
    for(int i = left; i < right; ++i)
        cout << v[i] << ",";
    cout << endl;
    return 0;
}

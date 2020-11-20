#include <iostream>
#include <vector>

using std::cout;
using std::endl;
// 2,3,1,4,3,5,7
class Solution {
public:
    int minSubArrayLen(int& left, int& right, int s, std::vector<int>& nums) {
        int num_len= nums.size();
        //int left=0, right=0, total=0, min_len= num_len+1;
        left=0, right=0;
        int total=0, min_len = num_len+1;
        while (right < num_len) {
            do {
                cout << "right: " << right << endl;
                total += nums[right++];
            } while (right < num_len && total < s);
            while (left < right && total - nums[left] >= s) 
            {            
                cout << "left: " << left << endl;
                total -= nums[left++];
            }
            if (total >=s && min_len > right - left)
            {
                cout << "right: " << right << "-" << "left: " << left << endl;
                min_len = right- left;
                cout << "min len: " << min_len << endl;
            }
        }
        cout << "left " << left << "," << "right: " << right << endl;
        return min_len <= num_len ? min_len: 0;
    }
};

int main(void)
{
    std::vector<int> v = {2,3,1,4,3,5,7};
    int total = 15, left = 0, right = 0;
    //v.push_back(2); 
    //v.push_back(3); 
    //v.push_back(1); 
    //v.push_back(4); 
    //v.push_back(3); 
    //v.push_back(5); 
    //v.push_back(7); 
    int i;
    for(i = 0; i < v.size(); ++i)
        cout << v[i] << ",";
    cout << endl;
    Solution sobj;
    int sub_len = sobj.minSubArrayLen(left, right, total, v);
    cout << "sub array len is: " << sub_len << endl;    
    for(i = left; i < right; ++i)
        cout << v[i] << ",";
    cout << endl;
    return 0;
}

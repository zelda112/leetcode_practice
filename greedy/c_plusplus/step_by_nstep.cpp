#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Solution
{
   Solution(void) { mSeqList.clear(); }
   int numOfSteps(int array[], int len);
   vector<int>& getSeqList(void) { return mSeqList; }  
protected:
   int maxSteps(int array[], int curSteps, int nextIndex);
private:
   vector<int> mSeqList;
};

//  [2,3,1,4,1]
int Solution::numOfSteps(int array[], int len)
{
    int i = 0, steps = 0, maxIndex = 0;
    while(i < len)
    {
       steps++;
       mSeqList.push_back(array[i]);
       if(i+1+array[i] >= len)
           break; 
       maxIndex = maxSteps(array, array[i], i+1); 
       i = maxIndex;
    }

    return steps;
}

int Solution::maxSteps(int array[], int curSteps, int nextIndex)
{
    int maxIndex = 0, max = 0;
    for(int i = nextIndex; i < nextIndex + curSteps; ++i)
    {
        if(array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
    }
 
    return maxIndex;
}

int main(void)
{
    int array[] = {2,3,1,4,1,2,3,5,7,1}; 
    Solution sobj;
    int steps = sobj.numOfSteps(array, sizeof(array)/sizeof(int));
    cout << "Steps :" << steps << endl;
    vector<int> vec = sobj.getSeqList();
    vector<int>::const_iterator it = vec.begin();
    for(; it != vec.end(); ++it) 
    {
        if((it + 1) != vec.end())
	    cout << *it << "->";
        else
            cout << *it;
    }
    cout << endl;
    return 0;
}

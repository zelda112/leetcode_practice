#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int value;
    Node *next;
    explicit Node(const int x) : 
value(x),
next(NULL)
    {
    }
};

struct Solution
{
    Node* createList(int array[], const int len);
    Node* mergeSortedList(Node* l1, Node* l2);
};

Node* Solution::createList(int array[], const int len)
{
    int num = len;
    cout << "num: " << num << endl;
    Node *head = new Node(-1);
    Node *p = NULL, *cur = head;
    for(int i = 0; i < num; ++i)
    {
        p = new Node(array[i]);
        head->next = p; 
        head = p;
    }

    return cur->next;
}

Node* Solution::mergeSortedList(Node* l1, Node* l2)
{
    Node* result = new Node(-1);
    Node* mergeNode = result;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->value <= l2->value)
        {
            mergeNode->next = l1;
            l1 = l1->next;
        }
        else
        {
            mergeNode->next = l2;
            l2 = l2->next;
        }
      
        mergeNode = mergeNode->next;
    }

    mergeNode->next = l1 != NULL ? l1 : l2;
    return result->next;
}

int main(void)
{
   int array1[] = {1,2,3,4};
   int array2[] = {1,2,3,4};
   Solution sobj;
   Node* l1 = sobj.createList(array1, sizeof(array1)/sizeof(int)); 
   Node* l2 = sobj.createList(array2, sizeof(array2)/sizeof(int)); 
   Node* l3 = sobj.mergeSortedList(l1, l2);
   Node* cur = NULL;
   while(l3 != NULL)
   {
       cur = l3;
       cout << l3->value << ",";
       l3 = l3->next;
       delete cur;
   }
   cout << endl;
   return 0; 
}

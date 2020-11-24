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
    Node* reverseList(Node* l);
};

Node* Solution::createList(int array[], const int len)
{
    int num = len;
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

Node* Solution::reverseList(Node* l)
{
    Node *cur = NULL;
    Node *newhead = NULL;
    while(l != NULL)
    {
        cur = l;
        l = l->next;
        cur->next = newhead;
        newhead = cur;
    }

    return newhead;
}

int main(void)
{
    int array[] = {1,2,3,4};
    Solution sobj;
    Node *l = sobj.createList(array, sizeof(array)/sizeof(int));
    Node *reverse_l = sobj.reverseList(l);

    Node *cur = NULL;
    while(reverse_l != NULL)
    {
        cur = reverse_l;
        cout << reverse_l->value << ",";
        reverse_l = reverse_l->next;
        delete cur;
    }
    cout << endl;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int value;
    struct ListNode *next;
} Node;

Node* create_list(int *array, int len)
{
    Node *head = (Node*)malloc(sizeof(Node)+1); 
    head->value = -1;
    head->next = NULL;
    Node *p = NULL, *cur = head;
    
    for(int i = 0; i < len; ++i)
    {
        p = (Node*)malloc(sizeof(Node)+1);
        p->value = array[i];
        p->next = NULL;
        head->next = p;
        head = p;
    }

    return cur->next;
}

Node* merge_sorted_list(Node* l1, Node* l2)
{
    Node *head = (Node*)malloc(sizeof(Node)+1);
    head->value = -1;
    head->next = NULL;
    Node *merge_node = head;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->value <= l2->value)
        {
            merge_node->next = l1;
            l1 = l1->next;
        }
        else
        {
            merge_node->next = l2;
            l2 = l2->next;
        }
        merge_node = merge_node->next;
    }

    merge_node->next = l1 != NULL ? l1 : l2;

    return head->next;
}

int main()
{
    int array1[] = {1,2,5,7,11,15}; 
    int array2[] = {2,5,7,8,10,13,19}; 
    Node* l1 = create_list(array1, sizeof(array1)/sizeof(int));
    Node* l2 = create_list(array2, sizeof(array2)/sizeof(int));
    Node* l3 = merge_sorted_list(l1,l2);
    Node* cur = NULL;
    while(l3 != NULL)
    {
        cur = l3;
        printf("%d,", l3->value);
        l3 = l3->next;
        free(cur);
    }
    printf("\n");
    return 0;
}

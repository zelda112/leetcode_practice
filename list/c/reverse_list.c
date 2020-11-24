#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int value;
    struct ListNode *next;
} Node;

Node* create_list(int *array, int len)
{
    // 创建链表伪头节点
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

    // 真正的头节点在伪头节点的下一个节点
    return cur->next;
}

Node* reverse_list(Node* l)
{
    Node *cur = NULL;
    Node *new_head = NULL;
    while(l != NULL)
    {
        cur = l;
        l = l->next;
        cur->next = new_head;
        new_head = cur;
    }

    return new_head;
}

int main()
{
    int array[] = {1,2,3,4};
    Node* l = create_list(array, sizeof(array)/sizeof(int));
    Node* reverse_l = reverse_list(l);

    Node *cur = NULL;
    while(reverse_l != NULL)
    {
        cur = reverse_l;
        printf("%d,",reverse_l->value);
        reverse_l = reverse_l->next;
        free(cur); cur = NULL;
    }
    printf("\n");
    
    return 0;
    
}

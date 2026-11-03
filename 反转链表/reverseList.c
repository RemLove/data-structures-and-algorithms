#include<stdio.h>

 struct ListNode {
      int val;
      struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* reverseList(struct ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* next = NULL;
    while(head!=NULL)
    {
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}

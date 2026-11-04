#include<stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
 };
 typedef struct ListNode ListNode;
 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL) {
        return list2;
    }
    if(list2 == NULL) {
        return list1;
    }
    //一直通过cur1和cur2来比较两个链表的值，用pre串起来
    ListNode* head=(list1->val<=list2->val)?list1:list2;
    ListNode* cur1=head->next;
    ListNode* cur2=head==list1?list2:list1;
    ListNode* pre=head;
    while (cur1!=NULL&&cur2!=NULL)
    {
        if(cur1->val<=cur2->val) {
            pre->next=cur1;
            cur1=cur1->next;
        }
        else {
           pre->next=cur2;
           cur2=cur2->next;
        }
        pre=pre->next;
    }
    //有一个链表跳没了
    pre->next=(cur1==NULL)?cur2:cur1;
    return head;
}
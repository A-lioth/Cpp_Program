#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1? list1 : list2;
    return dummy.next;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    // 找到链表的中间节点并分割成两个链表
    ListNode *mid = middleNode(head);
    ListNode *rightHead = mid->next;
    mid->next = nullptr;
    // 递归排序两个链表
    ListNode *left = sortList(head);
    ListNode *right = sortList(rightHead);
    // 合并两个链表
    return mergeTwoLists(left, right);
}

int main()
{
    ListNode *head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    ListNode *sortedList = sortList(head);
    while (sortedList)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    return 0;
}
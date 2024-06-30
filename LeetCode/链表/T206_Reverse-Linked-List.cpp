#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *ret = nullptr;
    for (ListNode *p = head; p != nullptr; p = p->next)
        ret = new ListNode(p->val, ret);
    return ret;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *ret = reverseList(head);
    while (ret != nullptr)
    {
        cout << ret->val << " ";
        ret = ret->next;
    }
    return 0;
}
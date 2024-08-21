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

int count = 0;
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return nullptr;
    head->next = removeNthFromEnd(head->next, n);
    return ++count == n ? head->next : head;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;
    ListNode *result = removeNthFromEnd(head, n);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
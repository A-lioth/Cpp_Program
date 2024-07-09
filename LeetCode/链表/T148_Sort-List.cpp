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

ListNode *sortList(ListNode *head)
{
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
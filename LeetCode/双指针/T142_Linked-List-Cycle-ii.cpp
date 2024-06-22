#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    // fast和slow第一次相遇，说明有环路
    do
    {
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    // fast从头开始，slow和fast每次移动一步，直到fast和slow相遇，此时slow指向环路入口
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    ListNode *node = detectCycle(head);
    if (node)
        cout << "Cycle detected at node " << node->val << endl;
    else
        cout << "No cycle detected" << endl;
    return 0;
}
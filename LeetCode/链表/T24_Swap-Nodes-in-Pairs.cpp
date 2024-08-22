#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

ListNode *swapPairsByStack(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<ListNode *> s;
    ListNode dummy;
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        s.push(curr);
        s.push(curr->next);

        curr = curr->next->next;

        prev->next = s.top();
        s.pop();
        prev = prev->next;

        prev->next = s.top();
        s.pop();
        prev = prev->next;
    }
    prev->next = curr;

    return dummy.next;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode *newHead = swapPairsByStack(head);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}
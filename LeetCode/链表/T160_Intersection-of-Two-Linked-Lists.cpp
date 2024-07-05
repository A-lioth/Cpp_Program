#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *pA = headA, *pB = headB;
    while (pA != pB)
    {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

int main()
{
    ListNode *headA = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(1, new ListNode(5, new ListNode(6)))))))));
    ListNode *headB = new ListNode(5, new ListNode(6, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(1, new ListNode(5, new ListNode(6))))))))));
    ListNode *result = getIntersectionNode(headA, headB);
    if (result)
        cout << "Intersection node: " << result->val << endl;
    else
        cout << "No intersection node." << endl;
    return 0;
}
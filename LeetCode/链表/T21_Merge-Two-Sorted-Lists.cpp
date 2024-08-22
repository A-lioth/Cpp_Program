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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

ListNode *mergeTwoListsByStack(ListNode *list1, ListNode *list2)
{
    stack<pair<ListNode *, ListNode *>> s;
    s.push({list1, list2});

    ListNode dummy;
    ListNode *tail = &dummy;

    while (!s.empty())
    {
        auto p = s.top();
        s.pop();

        if (p.first == nullptr)
        {
            tail->next = p.second;
            continue;
        }
        if (p.second == nullptr)
        {
            tail->next = p.first;
            continue;            
        }

        if (p.first->val < p.second->val)
        {
            tail->next = p.first;
            s.push({p.first->next, p.second});
        }
        else
        {
            tail->next = p.second;
            s.push({p.first, p.second->next});
        }
        tail = tail->next;
    }
    return dummy.next;
}

int main()
{
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = mergeTwoLists(l1, l2);
    while (l3)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Compare
{
public:
    bool operator()(ListNode *l1, ListNode *l2)
    {
        return l1->val > l2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;
    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
    for (auto l : lists)
    {
        if (l)
            pq.push(l);
    }
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    while (!pq.empty())
    {
        p->next = pq.top();
        pq.pop();
        p = p->next;
        if (p->next)
            pq.push(p->next);
    }
    p->next = nullptr;
    return head->next;
}
int main()
{
    vector<ListNode *> lists;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    lists.push_back(l1);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    lists.push_back(l2);
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l3);
    ListNode *merged = mergeKLists(lists);
    while (merged)
    {
        cout << merged->val << " ";
        merged = merged->next;
    }
    return 0;
}
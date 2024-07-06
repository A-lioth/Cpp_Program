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
    ListNode *prev = nullptr;
    while (head != nullptr)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    // 找到链表的中间节点
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 翻转后半部分链表
    slow->next = reverseList(slow->next);
    // 找到前半部分链表的尾节点
    slow = slow->next;
    // 逐个比较前半部分链表和翻转后的后半部分链表
    while (slow != nullptr)
    {
        if (slow->val != head->val)
            return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
    cout << isPalindrome(head) << endl;
    return 0;
}
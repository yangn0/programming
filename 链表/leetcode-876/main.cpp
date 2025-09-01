#include "io_for_leetcode.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *p1 = head, *p2 = head;
        while (p1) {
            if (p1->next != nullptr && p1->next->next != nullptr) {
                p1 = p1->next->next;
                p2 = p2->next;
            }
            if(p1->next==nullptr){
                return p2;
            }
            if(p1->next->next==nullptr){
                return p2->next;
            }
        }
    }
};

int main()
{
    input_t input;
    auto vec = input.input_vector();
    // cout << "Please input n value: ";
    // int n;
    // cin >> n;
    ListNode *head = createList(vec);

    Solution s;
    ListNode *r = s.middleNode(head);
    outputList(r);
    return 0;
}
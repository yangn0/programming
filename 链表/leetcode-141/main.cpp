#include "io_for_leetcode.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p1) {
            if(p1->next==nullptr||p1->next->next==nullptr){
                return false;
            }
            if(p1->next == p2 || p1->next->next==p2){
                return true;
            }
            if (p1->next != nullptr && p1->next->next != nullptr) {
                p1 = p1->next->next;
                p2 = p2->next;
            }
        }
        return false;
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
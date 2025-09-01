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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        int temp=0;
        while (p1) {
            if(p1->next==nullptr||p1->next->next==nullptr){
                return nullptr;
            }
            if(p1 == p2 && temp==1){
                p1=head;
                while(p1){
                    if(p1==p2){
                        return p1;
                    }
                    p1=p1->next;
                    p2=p2->next;
                }
            }
            if (p1->next != nullptr && p1->next->next != nullptr) {
                p1 = p1->next->next;
                p2 = p2->next;
                temp=1;
            }
        }
        return nullptr;
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
    ListNode *r = s.detectCycle(head);
    outputList(r);
    return 0;
}
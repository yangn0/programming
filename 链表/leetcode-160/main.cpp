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
    /* p1先遍历A，再遍历B。p2先遍历B再遍历A。p1==p2时，就是交点*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int flag_a=0,flag_b=0;
        ListNode *p1=headA,*p2=headB;
        while(1){
            if(p1==p2) return p1;
            p1=p1->next;
            if(p1==nullptr && flag_a==0){
                p1=headB;
                flag_a=1;
            }
            p2=p2->next;
            if(p2==nullptr && flag_b==0){
                p2=headA;
                flag_b=1;
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
    ListNode *r = s.detectCycle(head);
    outputList(r);
    return 0;
}
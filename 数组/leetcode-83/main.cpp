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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        while(p&&p->next){
            if(p->next->val == p->val){
                p->next=p->next->next;
            }else{
                p=p->next;
            }
        }
        return head;
    }
};

int main()
{
    input_t input;
    output_t output;
    auto vec = input.input_vector();

    // cout << "Please input n value: ";
    // int n;
    // cin >> n;

    Solution s;
    vector<int> r = s.deleteDuplicates(vec);
    output.output_array(r);
    return 0;
}
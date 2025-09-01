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
    ListNode *p[31];
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int i=1;
        p[0]=new ListNode(0,head);
        for(i=1;;i++) {
            p[i]=head;
            head=head->next;
            if(head==nullptr){
                break;
            }
        }
        p[i+1-n-1]->next=p[i+1-n-1]->next->next;
        return p[0]->next;
    }
};

int main()
{
    input_t input;
    auto vec = input.input_vector();
    cout << "Please input n value: ";
    int n;
    cin >> n;
    ListNode* head = createList(vec);

    Solution s;
    ListNode* r=s.removeNthFromEnd(head,n);
    outputList(r);
    return 0;
}
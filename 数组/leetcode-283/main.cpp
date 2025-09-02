#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0,fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=0){
                int n=nums[fast];
                nums[fast]=0;
                nums[slow]=n;
                slow++;
            }
            fast++;
        }
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
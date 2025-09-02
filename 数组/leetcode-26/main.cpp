#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            int slow=1,fast=1;
            int temp=nums[0];
            while(fast<nums.size()){
                if(nums[fast]==temp){
                    fast++;
                }else{
                    temp=nums[fast];
                    nums[slow]=nums[fast];
                    slow++;
                }
            }
        return slow;
    }
};

int main()
{
    input_t input;
    output_t output;
    auto vec = input.input_vector();
    cout << "Please input n value: ";
    int n;
    cin >> n;

    Solution s;
    vector<int> r = s.twoSum(vec, n);
    output.output_array(r);
    return 0;
}
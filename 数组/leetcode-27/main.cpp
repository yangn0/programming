#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0,fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                slow++;
                fast++;
            }else {
                fast++;
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
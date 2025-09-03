#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }
        }
        return -1;
    }
};

int main()
{
    input_t input;
    output_t output;
    string s1,s2;
    cin>>s1>>s2;

    Solution s;
    bool r = s.search(s1, s2);
    cout<<r;
    return 0;
}
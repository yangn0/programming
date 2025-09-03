#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out;
        int left_bound,right_bound;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }
        }
        if(left>=nums.size() || nums[left] != target){
            left=-1;
        }
        left_bound=left;

        left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                left=mid+1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }
        }
        if(right>=nums.size() || nums[right] != target){
            right=-1;
        }
        right_bound=right;
        return vector<int>{left_bound,right_bound};
    }
};

int main()
{
    input_t input;
    output_t output;
    string s1;
    cin>>s1;

    Solution s;
    vector<int> r = s.searchRange(s1, n);
    cout<<r;
    return 0;
}
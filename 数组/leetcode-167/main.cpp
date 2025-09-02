#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum;
        int left=0;
        int right = numbers.size()-1;
        while(left < right){
            sum = numbers[left]+numbers[right];
            if(sum==target){
                return vector<int>{left+1,right+1};
            }
            else if(sum<target) left++;
            else if(sum>target) right--;
        }

        return vector<int>{-1,-1};
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
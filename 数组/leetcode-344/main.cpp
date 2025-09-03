#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0,right=s.size()-1;
        char temp;
        while(left<right){
            temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;right--;
        }
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
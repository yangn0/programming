#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    string is_huiwen(string s, int left, int right){
        while(left>=0 && right<s.size()){
            if(s[left]==s[right]){
                left--;right++;
            }else{
                return s.substr(left+1,right-left-1);
            }
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string max_s,temp;
        for(int i=0;i<s.size();i++){
            temp=is_huiwen(s,i,i);
            if(max_s.size()<temp.size()) max_s=temp; 
            if(s[i]==s[i+1])
            {
                temp=is_huiwen(s,i,i+1);
                if(max_s.size()<temp.size()) max_s=temp; 
            }
        }
        return max_s;
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
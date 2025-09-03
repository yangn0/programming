#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int max_len=0;
        map<char,int>window;
        while(right<s.size()){
            char c=s[right];
            window[c]++;
            right++;
            while(window[c]!=1){
                // 收缩
                char c=s[left];
                window[c]--;
                left++;
            }
            if(max_len < right-left){
                max_len=right-left;
            }
        }
        return max_len;
    }
};

int main()
{
    input_t input;
    output_t output;
    string s1,s2;
    cin>>s1;

    Solution s;
    int r = s.lengthOfLongestSubstring(s1);
    cout<<r;
    return 0;
}
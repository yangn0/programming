#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> window,need;
        int left=0,right=0;
        int valid=0,start=0,len=INT_MAX;
        for(char c: t){
            need[c]++;
        }
        while(right<s.size()){
            char c=s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c])
                    valid++;;
            }

            // 左侧是否要收缩
            while(valid==need.size()){
                if(right-left<len){
                    start=left;
                    len=right-left;
                }
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
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
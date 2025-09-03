#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left=0,right=0,valid=1;
        map<char,int>need,window;
        vector<int> out;
        for(char c: p){
            need[c]++;
        }
        right=p.size();
        for(char c: s.substr(left,right)){
            window[c]++;
        }
        while(right<s.size()+1){
            valid=1;
            for(auto pair: need){
                int key=pair.first;
                int v=pair.second;
                if(window.count(key)&&window[key]==v){

                }else{
                    // 向后移动
                    valid=0;
                    break;
                }
            }
            if(valid==1){
                out.push_back(left);
            }
            char c=s[right];
            window[c]++;
            right++;

            c=s[left];
            window[c]--;
            left++;
        }

        return out;
    }
};

int main()
{
    input_t input;
    output_t output;
    string s1,s2;
    cin>>s1>>s2;

    Solution s;
    vector<int> r = s.findAnagrams(s1, s2);
    output.output_array(r);
    return 0;
}
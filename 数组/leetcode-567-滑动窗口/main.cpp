#include "io_for_leetcode.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> need,window;
        int left=0,right=0;
        int valid=0;
        for(char c: s1){
            need[c]++;
        }
        right=s1.size();

        for(char c: s2.substr(left,right)){
            window[c]++;
        }
        while(right<s2.size()+1){
            valid=0;
            for(auto pair:need){
                char key=pair.first;
                int value=pair.second;
                if(window.count(key) && value==window[key]){

                }else{
                    if(right==s2.size()) return false;
                    // 滑动到下一个
                    valid=1;
                    char c=s2[right];
                    right++;
                    window[c]++;

                    c=s2[left];
                    left++;
                    window[c]--;
                    break;
                }
            }
            if(valid==0)
                return true;
        }
        if(s1==s2){ return true;}
        return false;
    }
};

int main()
{
    input_t input;
    output_t output;
    string s1,s2;
    cin>>s1>>s2;

    Solution s;
    bool r = s.checkInclusion(s1, s2);
    cout<<r;
    return 0;
}
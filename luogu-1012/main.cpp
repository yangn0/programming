#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    copy(a,a+n,b);
    string s=to_string(a[n-1]);
    int slen=s.length();
    for(int i=0;i<n;i++){
        string s_temp=to_string(a[i]);
        int len=s_temp.length();
        for(int u=0;u<slen-len;u++){
            s_temp.push_back(s_temp[0]);
        }
        a[i]=stoi(s_temp);
    }

    for(int i=0;i<n;i++){
        int maxnum=a[0];
        int maxindex=0;
        for(int u=0;u<n;u++){
            if(a[u]>maxnum){
                maxnum=a[u];
                maxindex=u;
            }
        }
        a[maxindex]=0;
        cout<<b[maxindex];
    }

    return 0;
}
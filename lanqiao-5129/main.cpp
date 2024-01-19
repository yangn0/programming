#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> h(n,0);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    sort(h.begin(),h.end());

    return 0;
}
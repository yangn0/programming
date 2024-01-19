#include<bits/stdc++.h>

using namespace std;

int main(){
    int L=0;cin>>L;
    int N=0;cin>>N;
    int poss[N];
    for(int i=0;i<N;i++){
        cin>>poss[i];
    }
    sort(poss,poss+N);
    for(auto i:poss){
        cout<<i;
    }
    return 0;
}
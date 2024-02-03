#include<bits/stdc++.h>

using namespace std;

int getZu(vector<int> h,int diff){
    int n=h.size();
    int zu=1;
    int temp=h[0];
    for(int i=1;i<n;i++){
        if((h[i]-temp)>diff){
            zu++;
            temp=h[i];
        }
    }
    return zu;
}

int main(){
    int n,k;cin>>n>>k;
    vector<int> h(n,0);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    sort(h.begin(),h.end());

    int l=0;
    int r=h[n-1]-h[0];
    int mid=0;
    int zu;
    while(l<r){
        mid=l+(r-l)/2;
        zu=getZu(h,mid);
        if(zu<=k) {
            // diff 找大了或正好
            r=mid;
        }else if(zu>k) {
            // diff 找小了
            l=mid+1;
        }
    }
    cout<<l;
    return 0;
}
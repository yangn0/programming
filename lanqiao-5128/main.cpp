#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,q;cin>>n>>q;

    while(q--){
      int n=1;
      string s;
      cin>>s;
      for(auto i:s){
        if(i=='L'){
          n=n*2-1;
        }else n=n*2;
      }
      cout<<n<<endl;
    }
    return 0;
}
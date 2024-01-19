#include<bits/stdc++.h>

using namespace std;

int main(){
  int T;cin>>T;
  while(T--){
    char a=0,b=0;
    int an=0,bn=0;
    string s;
    cin>>s;
    for(auto i:s){
      if(i==a){
        an++;
      }
      else if(i==b){
        bn++;
      }
      else if(a==0) {
        a=i;
        an++;
      }
      else if(b==0) {
        b=i;
        bn++;
      }
      else{
        break;
      }
    }
    if( (an==1 && bn==3) || (an==3&&bn==1) ){
      cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;
  }
  return 0;
}
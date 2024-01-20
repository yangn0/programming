#include<bits/stdc++.h>

using namespace std;

void getf(int n){
    bitset<20> b(n);
    int first_flag=1;
    for(int i=b.size()-1;i>=0;i--){
        if(b[i]==1){
            if(first_flag==0) cout<<"+";
            first_flag=0;
            cout<<"2";
            if(i!= 1) cout<<"("; 
            if(i== 0) cout<<"0"; 
            else if(i==1) ;
            else getf(i);
            if(i!= 1) cout<<")";
        }
        
    }
}

int main(){
    int n;cin>>n;

    getf(n);
    return 0;
}
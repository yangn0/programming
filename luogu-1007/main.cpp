#include<bits/stdc++.h>

using namespace std;

int main(){
    int L=0;cin>>L;
    int N=0;cin>>N;
    int poss[N];
    for(int i=0;i<N;i++){
        cin>>poss[i];
    }
    int min=0,max=0;
    for(auto i:poss){
        if( i<(L+1-i) ){
            if(i>=min){
                min=i;
            }
            if((L+1-i)>=max){
                max=(L+1-i);
            }
        }else{
            if((L+1-i)>=min){
                min=(L+1-i);
            }
            if(i>=max){
                max=i;
            }
        }
    }

    cout<<min<<' '<<max;
    

    return 0;
}
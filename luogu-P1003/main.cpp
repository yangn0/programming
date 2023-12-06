#include<bits/stdc++.h>
using namespace std;

int is_dianInDitan(int x,int y,int a,int b,int length,int width){
    if( (x>=a&&x<=a+length) && (y>=b&&y<=b+width) ){
        return 1;
    }
    return 0;
}
int main(){
    vector<vector<int>> vec;
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,length,width;
        cin>>a>>b>>length>>width;
        vec.push_back({a,b,length,width});
    }
    cin>>x>>y;
    reverse(vec.begin(),vec.end());
    for(auto i : vec){
        if(is_dianInDitan(x,y,i[0],i[1],i[2],i[3])){
            cout<<n;
            return 0;
        }
        n--;
    }
    cout<<-1;
    return -1;
}
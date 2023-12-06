#include<bits/stdc++.h>

using namespace std;

int n=0;
vector<vector<int>> vec,max_temp;
int maxz=0;

void worker(int x,int y,int z,vector<vector<int>> temp){
    if(x>n || y>n) return;
    if(x==n-1 && y==n-1){
        if(maxz<z){
            max_temp=temp;
        }
        temp.clear();
        maxz=max(maxz,z);
        return;
    }
    z+=vec[x][y];
    temp.push_back({x,y});
    if(x<n && y+1<n){
        worker(x,y+1,z,temp);
    }
    if(x+1<n && y<n){
        worker(x+1,y,z,temp);
    }
}

int main(){
    int x,y,z;
    vector<vector<int>> temp;
    cin>>n;
    for(int i=0;i<n;i++){
        vec.push_back(vector<int>(n,0));
    }
    while(1){
        cin>>x>>y>>z;
        if(x==0 && y==0 && z==0) break;
        vec[x-1][y-1]=z;
    }
    worker(0,0,0,temp);
    for(auto i : max_temp){
        vec[i[0]][i[1]]=0;
    }
    temp.clear();
    worker(0,0,maxz,temp);
    cout<<maxz;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int a;
int n;
int m;
int x;
int u;

int fib(int a){
    if(a==1||a==2) return 1;
    return fib(a-1)+fib(a-2);
}

int get_diff(int x){
    if(x==1) return a;
    if(x==2) return 0;
    if(x==3) return a;
    if(x==4) return u;
    return fib(x-4)*a+fib(x-3)*u;
}

int main(){
    cin>>a;
    cin>>n;
    cin>>m;
    cin>>x;
    int sum=0;
    if(x==n) {cout<<0;return 0;}
    if(n==1) u=m;
    else if(n==2) u=m;
    else if(n==3) u=m;
    else u=(m-(fib(n-3)+1)*a)/(fib(n-2)-1);

    for(int i=1;i<=x;i++){
        sum+=get_diff(i);
        // cout<<sum<<endl;
    }
    cout<<sum;
    return 0;
}
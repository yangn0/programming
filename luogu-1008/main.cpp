#include<bits/stdc++.h>

using namespace std;

int isNumRepeat(int a,int b){
    set<int> s;
    s.insert(a/100);
    s.insert(a%10);
    s.insert((a%100-a%10)/10);

    s.insert(b/100);
    s.insert(b%10);
    s.insert((b%100-b%10)/10);
    if(s.count(0)!=0) return 1;
    if(s.size()==6) return 0;
    else return 1;
}

int main(){
    for(int i=1;i<10;i++){
        for(int u=1;u<10;u++){
            if(u==i) continue;
            for(int y=1;y<10;y++){
                if(y==i||y==u) continue;
                int n=0;
                n=i*100+u*10+y;
                if(n*2>=1000 || n*3>=1000|| isNumRepeat(n,n*2) || isNumRepeat(n*2,n*3) || isNumRepeat(n,n*3)){
                    continue;
                }
                else{
                    cout<<n<<' '<<n*2<<' '<<n*3<<endl;
                }
            }
        }
    }
    // cout<<isNumRepeat(128,256);
    return 0;
}
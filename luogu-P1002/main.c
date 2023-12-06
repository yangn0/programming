#include<stdio.h>
#include<string.h>

long long b_x,b_y,horse_x,horse_y;
long long mem[21][21];

long long worker(long long a_x,long long a_y){
    if(a_x>b_x || a_y >b_y) return 0;
    if(mem[a_x][a_y]!=-1) return mem[a_x][a_y];
    if(a_x==horse_x && a_y==horse_y) return 0;      // C点
    if(a_x==horse_x-1 && a_y==horse_y+2) return 0;  // P3
    if(a_x==horse_x-2 && a_y==horse_y+1) return 0;  // P4
    if(a_x==horse_x-1 && a_y==horse_y-2) return 0;  // P6
    if(a_x==horse_x-2 && a_y==horse_y-1) return 0;  // P5
    if(a_x==horse_x+1 && a_y==horse_y+2) return 0;  // P2
    if(a_x==horse_x+2 && a_y==horse_y+1) return 0;  // P1
    if(a_x==horse_x+1 && a_y==horse_y-2) return 0;  // P7
    if(a_x==horse_x+2 && a_y==horse_y-1) return 0;  // P8

    if(a_x==b_x && a_y==b_y) {
        return 1;
    }

    long long tmp=worker(a_x+1,a_y)+worker(a_x,a_y+1);
    mem[a_x][a_y]=tmp;
    return tmp;
}

long long main(){
    long long n=0;
    memset(mem, -1, sizeof(mem));
    scanf("%lld %lld %lld %lld",&b_x,&b_y,&horse_x,&horse_y);
    
    n=worker(0,0);
    printf("%lld\n",n);
    
    return 0;
}
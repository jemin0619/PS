#include <stdio.h>
using namespace std;

int joseph (int n,int k) {
    if (n==1) return 0;
    if (k==1) return n-1;
    if (k>n) return (joseph(n-1,k)+k)%n;
    int cnt=n/k;
    int res=joseph(n-cnt,k);
    res-=n%k;
    if (res<0) res+=n;
    else res+=res/(k-1);
    return res;
}

int main(){
    while(true){
        int a, b; 
        scanf("%2de%d",&a,&b);
        if(a==0 && b==0) break;
        for(int i=0;i<b;i++) a*=10;
        printf("%d\n",joseph(a,2)+1);
    }
}

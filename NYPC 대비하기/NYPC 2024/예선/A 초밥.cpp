#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int T; cin>>T;
    while(T--){
        int a,b; cin>>a>>b;
        if(b<=0 || a<=0) cout<<-1<<'\n';
        else{
            int c = min(a,b); //1 1로만 나눈 쌍
            int d = a+b-2*c; //남은 초밥들
            
            if(d==0) cout<<c/2+(c%2)<<'\n'; //남은게 없는 경우
            else{
                d = d/2 + d%2; //남은 초밥들을 두 개씩 묶음
                //쌍의 수보다 '남은 초밥을 두 개씩 묶은 갯수'가 많으면 구성 불가능
                c -= d;
                if(c<0) cout<<-1<<'\n';
                else{
                    c = c/2 + c%2;
                    cout<<c+d<<'\n';
                }
            }
        }
    }
    return 0;
}

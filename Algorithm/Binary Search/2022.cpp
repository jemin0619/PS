//https://www.acmicpc.net/problem/2022

//기하학 + 실수오차로 머리가 아픈 문제입니다.

//x와 y를 빗변으로 하는 직각삼각형의 높이를 h1, h2라고 할때, 삼각형 닮음을 사용해 다음과 같은 공식을 유도할 수 있습니다.
//c = (h1*h2) / (h1+h2)
//h1 = sqrt(x^2 - w^2)
//h2 = sqrt(y^2 - w^2)

//삼각형의 성질에 의해 w는 min(x,y) 보다 작습니다.
//mid를 움직이며 c에 가장 근접한 c보다 작거나 같은 해를 찾고 출력합니다.
//TTFF로 존재하므로 T(lo)를 출력합니다.
//오차범위를 10^(-4)로 해서 hi를 출력해도 상관없을 것 같기는 합니다.
//실제로 상관이 없고, 같은 이치로 Check의 return 조건도 같다 기호를 생략해도 됩니다.
//실수오차가 존재하는 문제에서는 항상 좀 더 널널하게 잡아주는게 유리한 것 같습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ld long double

ld x,y,c;

bool Check(ld mid){ // mid는 w를 의미
    ld h1 = sqrt(x*x - mid*mid);
    ld h2 = sqrt(y*y - mid*mid);
    ld val_c = (h1*h2) / (h1+h2); // w==mid 일때의 c를 구함
    return c >= val_c; 
}

int main(){
    fastio;
    cin>>x>>y>>c;
    ld lo=0, hi=min(x,y);
    while(lo+1e-4<hi){
        ld mid = (lo+hi)/2;
        if(Check(mid)) hi = mid; //T면 경계를 <- 
        else lo = mid; //F면 경계를 ->
    }
    cout<<fixed<<setprecision(4)<<hi;
    return 0;
}

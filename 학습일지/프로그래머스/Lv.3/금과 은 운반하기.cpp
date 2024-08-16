//Parametric Search
//Check(x) : x시간만에 모든 광물을 옮길 수 있는가?
//FFTT로 존재.
//hi를 답으로 정함

//금 a와 은 b가 필요함
//g[i] i번 도시의 금
//s[i] i번 도시의 은
//w[i] i번 도시에서 한 번에 운반할 수 있는 광물의 양
//t[i] i번 도시에서 새 도시까지 편도로 이동하는 시간

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

bool Check(ll x, int a, int b, vector<int>&g, vector<int>&s, vector<int>&w, vector<int>&t){ 
    ll gold=0, silver=0, add=0, cnt=0;
    for(int i=0;i<g.size();i++){
        cnt = x/((ll)t[i]*2); //왕복으로 이동할 수 있는 횟수
        if(x%(t[i]*2) >= t[i]) cnt++;
        
        gold += min((ll)g[i],(ll)w[i]*cnt);
        silver += min((ll)s[i],(ll)w[i]*cnt);
        add += min((ll)g[i]+(ll)s[i],(ll)w[i]*cnt);
    }
    if(gold>=a && silver>=b && add>=a+b) return true;
    else return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll answer = -1;
    ll lo = -1, hi = 10e14*3;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid,a,b,g,s,w,t)) hi = mid;
        else lo = mid;
    }
    answer = hi;
    return answer;
}

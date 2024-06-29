//태그가 DP + Math인데 굳이 DP를 사용하지 않아도 된다.
//DP[i]를 i주의 기댓값으로 정의하고, Ans를 DP로 대체하면 DP 풀이로 해결할 수 있다.

//기댓값 DP라는 표현이 있어서 찾아보니 해당 블로그를 발견했다
//https://newdeal123.tistory.com/31
//여길 참고해 공부하는게 좋을 것 같다.

#include <bits/stdc++.h>
using namespace std;

double Ans = 0.0;
double N,J,C;
double Tickets;
vector<double> V;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        double x; cin>>x;
        V.push_back(x);
        Tickets += x;
    }
    cin>>J>>C;
    Ans = V[0];
    for(int i=0;i<C;i++){
        Ans += J*Ans/Tickets;
        Tickets += J;
    }
    printf("%.10f",Ans);
    return 0;
}

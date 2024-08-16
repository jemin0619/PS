#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ld long double

const int MX = 1000'000;
ld A, B, X;
set<int> S;
queue<int> Time_A;
queue<int> Time_B;

int main(){
    fastio;
    cin>>A>>B;
    cin>>X;
    for(int i=0;i<X;i++){
        int tmp; cin>>tmp;
        Time_A.push(tmp);
    }
    cin>>X;
    for(int i=0;i<X;i++){
        int tmp; cin>>tmp;
        Time_B.push(tmp);
    }

    //A가 B를 쫓는 식으로 변형
    if(A>B){
        swap(A,B);
        swap(Time_A, Time_B);
    }
    A += 4.4; //차의 길이가 4.4m
    bool isDrive_A = false;
    bool isDrive_B = false;

    for(int T=1; T<=MX*10; T++){
        if(isDrive_A) A += 1LL;
        if(isDrive_B) B += 1LL;

        if(!Time_A.empty() && T==Time_A.front()){
            Time_A.pop();
            isDrive_A = !isDrive_A;
        }
        if(!Time_B.empty() && T==Time_B.front()){
            Time_B.pop();
            isDrive_B = !isDrive_B;
        }

        if(A >= B){
            cout<<"bumper tap at time "<<T;
            return 0;
        }
    }
    cout<<"safe and sound";
    return 0;
}

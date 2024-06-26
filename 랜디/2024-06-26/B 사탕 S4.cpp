//수학적 관찰력이 필요했음
//N이 홀수이므로 문제를 해결할 수 있다. (처음에 짝수도 되는줄 알고 어떻게 풀지 고민함)
//V[0] = a0+a1 
//V[1] = a1+a2 
//V[2] = a2+a3 
//V[3] = a3+a4 
//V[4] = a4+a0
//이때 a1을 구하려면 V[0]+V[1]을 시행해 2a1+a0+a2를 만든다.
//그 후 남은 수들을 V[2]부터 - + - + - .. 순으로 연산을 해나가면 2a1만 남게 되고, 절반 값을 답으로 취할 수 있다.
//핵심은 오른쪽으로 이동하면서 모든 수를 연산에 사용하고, 오른쪽에 수가 존재하지 않으면 0번째 인덱스로 이동해서 모든 수를 사용할때까지 반복하는 것이다.

//a0을 구하는 경우엔 범위 처리가 달라져서 따로 뺐다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int N;
vector<int> V;
vector<int> Ans;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    }

    int i1 = N-1; int i2 = 0;
    int val = V[i1] + V[i2];
    bool minus = true;
    for(int i=i2+1;i<=i1-1;i++){
        if(minus) val -= V[i];
        else val += V[i];
        minus = !minus;    
    }
    val/=2;
    Ans.push_back(val);

    for(int i2=1;i2<N;i2++){
        int i1 = i2-1;
        int val = V[i1] + V[i2];
        bool minus = true;
        for(int i=i2+1;i<N;i++){
            if(minus) val -= V[i];
            else val += V[i];
            minus = !minus;
        }
        for(int i=0;i<=i1-1;i++){
            if(minus) val -= V[i];
            else val += V[i];
            minus = !minus;
        }
        val/=2;
        Ans.push_back(val);
    }
    for(int val : Ans) cout<<val<<'\n';
    return 0;
}

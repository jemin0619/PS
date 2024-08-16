//구현, 시뮬레이션

//0은 어떤 색이든 가능하다는 의미이다.
//또 최적해를 구하지 않아도 되는 문제이다. 
//그러므로 다음과 같은 전략을 세울 수 있다.
//1. 0을 포함해서 같은 색으로만 칠해진 줄이 있을 경우 그 줄은 가장 마지막에 칠해졌을 것이다. (이는 직접 시도해보면 알 수 있다.)
//2. O(NM)으로 그런 줄들을 모두 탐색하며 지운다.
//3. 색이 전부 0인 줄인 경우 예외처리를 해준다. (이땐 아무것도 되면 안됨)
//4. Ans를 reverse하여 답을 출력해준다.

//관찰이 필요한 빡구현 문제였다.

#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[103][103];
vector<tuple<char,int,int>> Ans;

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];
    while(true){ //board가 모두 0이 될때까지 반복
        bool fin = true;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(board[i][j]!=0) {fin = false; break;}
        if(fin) break;

        //가로줄 탐색 (H)
        for(int i=0;i<N;i++){
            int color = 0;
            bool canErase = true;
            for(int j=0;j<M;j++){
                if(board[i][j]==0) continue; //색이 안칠해져있다면 건너뒴
                if(color!=0 && color!=board[i][j]) {canErase=false; break;}
                color = board[i][j];
            }
            if(canErase && color!=0){
                for(int j=0;j<M;j++) board[i][j] = 0;
                Ans.push_back({'H',i+1,color});
            }
        }

        //세로줄 탐색 (V)
        for(int j=0;j<M;j++){
            int color = 0;
            bool canErase = true;
            for(int i=0;i<N;i++){
                if(board[i][j]==0) continue; //색이 안칠해져있다면 건너뒴
                if(color!=0 && color!=board[i][j]) {canErase=false; break;}
                color = board[i][j];
            }
            if(canErase && color!=0){
                for(int i=0;i<N;i++) board[i][j] = 0;
                Ans.push_back({'V',j+1,color});
            }
        }
    }

    reverse(Ans.begin(),Ans.end());
    cout<<Ans.size()<<'\n';
    for(auto [A,B,C] : Ans){
        cout<<A<<' '<<B<<' '<<C<<'\n';
    }
    return 0;
}

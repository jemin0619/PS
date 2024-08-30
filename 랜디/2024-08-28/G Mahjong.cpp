//랜덤마라톤을 12주간 풀고 있는데 그 중 꽤 인상깊던 문제 중 하나인 것 같다.
//브루트포스인데 생각보다 난이도가 좀 있다.

//머리 1, 몸통 4를 만들 수 있느냐 or 머리 7을 만들 수 있느냐
//머리 (같은 패 두 장, 같은 머리 쌍은 두개 이상 못 만듦), 몸통 (같은 패 3장 or 연속된 숫자 3개)

//1 ~ 9까지 넣어보면서 되는지 판단 (브루트포스)
//머리 7개가 만들어지는지 (= 모든 카드 장 수가 0개 혹은 2개인 경우) 체크
//머리 한 개만 만들어놓고 나머지로 몸통 4개가 나오는지 체크

//몸통을 만드는 순서에 따라 통과되야 하는 패가 미완성으로 처리되는 경우가 있다.
//이 경우 check 2에선 통과하지 못한다. 
//1 2 2 3 3 3 4 4 4 5 5 6 7
//123, 234, 345, 456, 7(7)
//그래서 두 경우를 모두 만들어서 체크해주었다.

#include <bits/stdc++.h>
using namespace std;

bool check(int num, vector<int> cnt){
    cnt[num]++;
    
    //머리 7개가 가능한가?
    int idx=1;
    while(idx<=9 && (cnt[idx]==0 || cnt[idx]==2)) idx++;
    if(idx==10) return true;

    //머리 1개, 몸통 4개가 가능한가?
    for(int i=1; i<=9; i++){
        if(cnt[i]<2) continue; //머리를 하나 고름
        vector<int> Cnt(cnt);
        Cnt[i] -= 2;

        //check 1 (연속된 패들 먼저 합치고, 3개 이상인 패들 합치기)
        vector<int> Cnt1(Cnt);
        int body1 = 0;
        for(int j=1; j<=7; j++){
            if(Cnt1[j]>0 && Cnt1[j+1]>0 && Cnt1[j+2]>0){
                int sub = min({Cnt1[j], Cnt1[j+1], Cnt1[j+2]});
                body1 += sub;
                Cnt1[j] -= sub;
                Cnt1[j+1] -= sub;
                Cnt1[j+2] -= sub;
            }
        }
        for(int j=1; j<=9; j++){
            if(Cnt1[j]>=3){
                Cnt1[j] -= 3;
                body1++;
            }
        }
        if(body1==4) return true;


        //check 2 (3개 이상인 패들 합치고, 연속된 패들 합치기)
        vector<int> Cnt2(Cnt);
        int body2 = 0;
        for(int j=1; j<=9; j++){
            if(Cnt2[j]>=3){
                Cnt2[j] -= 3;
                body2++;
            }
        }
        for(int j=1; j<=7; j++){
            if(Cnt2[j]>0 && Cnt2[j+1]>0 && Cnt2[j+2]>0){
                int sub = min({Cnt2[j], Cnt2[j+1], Cnt2[j+2]});
                body2 += sub;
                Cnt2[j] -= sub;
                Cnt2[j+1] -= sub;
                Cnt2[j+2] -= sub;
            }
        }
        if(body2==4) return true;
    }

    //패가 완성되지 못함
    return false;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    vector<int> V(13, 0);
    vector<int> cnt(10, 0);
    for(int i=0; i<13; i++){
        int x; cin>>x;
        cnt[x]++;
    }
    
    vector<int> ans;
    for(int i=1; i<=9; i++){
        if(cnt[i]==4) continue;
        if(check(i, cnt)) ans.push_back(i);
    }

    if(ans.empty()) cout<<-1;
    else for(int val : ans) cout<<val<<' ';

    return 0;
}

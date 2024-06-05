//https://www.acmicpc.net/problem/28638

//랜덤마라톤 (Beta) 첫 번째 문제였다.
//처음엔 입력되는 값들을 정렬해야하는 줄 알았는데 그럴 필요가 없었다.
//오히려 정렬하면 같은 시각에 들어온 값들에 대해 어떻게 우선순위를 정해야 할지 고민해야 한다. (stable sort? 가 떠오르긴 하지만 옳은 방식인진 모르겠다.)
//러시아어라 제대로 해석이 안되었는데 시스템 로그가 입력되는 것이기에 항상 시간 순으로 입력된다.
//적당히 구현해주면 해결할 수 있다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans[3]={0,};
    int WA[30]={0,};
    bool OK[30]={0,};
    int N; cin>>N;
    while(N--){
        string H, V; char X;
        cin>>H>>X>>V;

        int minute = ((H[0]-'0')*10 + (H[1]-'0'))*60 + (H[3]-'0')*10 + (H[4]-'0');

        //V가 WA, TL, ML, RE, CE, SV라면
        if(V!="OK"){    
            if(V=="CE") continue; //CE는 카운트 X
            WA[X-'A']++;
        }

        //V가 OK라면
        else{
            if(OK[X-'A']) continue;
            OK[X-'A'] = true;
            ans[0]++;
            ans[1] += (minute + WA[X-'A']*20);
        }
    }
    cout<<ans[0]<<' '<<ans[1];
    return 0;
}

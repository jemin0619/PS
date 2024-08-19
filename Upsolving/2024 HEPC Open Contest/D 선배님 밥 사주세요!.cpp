#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ff first 
#define ss second

bool iscon(int Pweek, int Pday, int Cweek, int Cday){
    if(Pweek==Cweek && Pday+1==Cday) return true;
    if(Pweek+1==Cweek && Pday==6 && Cday==0) return true;
    return false;
}

int N;
map<string, int> name;
vector<pair<int,int>> date; //week, day
int W[103];
int D[103];
int P[103];

int main(){
    fastio;
    cin>>N;
    for(int i=0; i<N; i++){
        string S;
        cin>>S>>W[i]>>D[i]>>P[i];
        name[S]=i;
    }
    for(int i=0; i<N; i++){
        string S; int M; 
        cin>>S>>M;
        int num = name[S];
        if(P[num]>M) continue;
        date.push_back({W[num],D[num]});
    }
    sort(date.begin(), date.end());

    if(date.size()==0) {cout<<0; return 0;}

    int ans = 1;
    int days = 1;
    for(int i=1; i<date.size(); i++){
        if(iscon(date[i-1].ff, date[i-1].ss, date[i].ff, date[i].ss)) days++;
        else if(date[i-1].ff == date[i].ff && date[i-1].ss == date[i].ss) continue;
        else{
            ans = max(ans, days);
            days = 1;
        }
    }
    ans = max(ans, days);

    cout<<ans;
    return 0;
}

//시간 끝나고 10분동안 보니 두번째 for문에서 P[i]와 M을 비교했음...

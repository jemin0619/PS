//N이 작아서 브루트포스로 풀린다.
//백트래킹으로 해도 되는데, isSelected 크기가 많아야 255여서 그냥 매번 배열을 복사해서 썼다.
//이런 문제 구현이 너무 귀찮고 버겁다...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int get_time(string S){
    string HH = ""; HH+=S[0]; HH+=S[1];
    string MM = ""; MM+=S[3]; MM+=S[4];
    int h = stoi(HH), m = stoi(MM);
    return h*60+m;
    return 0;
}

int Ans = 0;
int N;
int A[18];
int C[18][18];
int D[18][18];
int st[18][18], en[18][18];

vector<tuple<int,int,int,int,int>> V; //D, st, en, 학점, 그룹

void DFS(int depth, int preD, int preT, int score, vector<bool> isSelected){
    if(score==22) {Ans++; return;}
    if(score>22 || depth==V.size()) return;
    auto&[day,s,e,sc,group]=V[depth];
    bool flag = false;
    if(preD>day || (preD==day && preT>s)) DFS(depth+1, preD, preT, score, isSelected);
    else{
        DFS(depth+1, preD, preT, score, isSelected);
        if(!isSelected[group]){
            isSelected[group] = true;
            DFS(depth+1, day, e, score+sc, isSelected);
        }
    }
}

int main(){
    fastio; 
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
        for(int j=0; j<A[i]; j++){
            string S,E;
            cin>>C[i][j]>>D[i][j]>>S>>E;
            st[i][j] = get_time(S);
            en[i][j] = get_time(E);
            V.push_back({D[i][j],st[i][j],en[i][j],C[i][j],i});
        }
    }
    sort(V.begin(), V.end());
    vector<bool> isSelected(V.size()+3);
    DFS(0,0,0,0,isSelected);
    cout<<Ans;
    return 0;
}

//01:31 WA
//01:32 WA
//01:38 AC

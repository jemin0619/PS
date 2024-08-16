//빡구현문제...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

string str;
deque<int> V;
int adj[30]; //그래프
int turn[30]; //turn[i] i에서 회전(우회)이/(가) 가능한가?
int stage = 0;
int cur = 0;
int pre = 19;
bool fin = false;
bool reach = false;
int sz;

int GetYut(string str){
    int cnt = 0;
    for(int i=0;i<4;i++){
        if(str[i]=='0') cnt++;
    }
    return cnt;
}

void init(){
    for(int i=0;i<=18;i++) adj[i]=i+1;
    adj[19] = 0;
    turn[5] = 20;
    turn[10] = 25;
    turn[22] = 27;
    adj[25] = 26; adj[26] = 22;
    adj[20] = 21; adj[21] = 22;
    adj[27] = 28; adj[28] = 0;
    adj[23] = 24; adj[24] = 15;
}

int main(){ 
    fastio;
    init();
    while(cin>>str){
        int val = GetYut(str);
        V.push_back(val);
    }
    sz = V.size();
    while(!V.empty()){
        int val = V.front();
        if(val!=0 && val!=4) stage++;
        if(val==0) val = 5;

        if(turn[cur]!=0) {pre=cur; cur=turn[cur]; val--;}
        while(val--){
            if(cur!=22) {pre=cur; cur=adj[cur];}
            else{
                if(pre==26){
                    pre = cur;
                    cur = 27;
                }
                else if(pre==21){
                    pre = cur;
                    cur = 23;
                }  
                else cout<<"Error: 22에 도달했는데 이전 칸이 26, 21이 아님\n";
            }
            if(cur==0 && sz!=V.size()) reach = true;
            if(reach && cur==1 && stage<=10) {fin = true; break;}
        }
        V.pop_front();
        if(fin) break;
    }
    if(fin) cout<<"WIN";
    else cout<<"LOSE";
    return 0;
}

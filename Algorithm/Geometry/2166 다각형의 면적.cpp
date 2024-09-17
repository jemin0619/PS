//https://namu.wiki/w/신발끈%20공식
//신발끈 공식의 응용이 시루스 법칙이고, 그 법칙을 CCW에서 사용한 것 같다.

//https://velog.io/@mttw2820/백준-2166.-다각형의-면적
//이 글을 읽어보는 것이 좋을 것 같다.

#include<bits/stdc++.h>
using namespace std;

int n;
long double x[10003],y[10003];
long double sum1,sum2;

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    x[n]=x[0]; y[n]=y[0];
    for(int i=0;i<n;i++){
        sum1 += (x[i]*y[i+1]);
        sum2 += (y[i]*x[i+1]);
    }
    cout<<fixed;
    cout.precision(1);
    cout<<(long double)(abs(sum2-sum1)/2);
    return 0;
}

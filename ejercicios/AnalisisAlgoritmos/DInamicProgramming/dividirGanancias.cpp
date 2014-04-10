#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


long knapsack(long *c, long *p,int n,long R){
    long A[n+1][R+1];

    for(int i=0;i<=R;i++)
        A[0][i]=0;

    for(int i=1; i<=n;i++){
            int nd=c[i];
            int td=p[i];
        for(int j=0; j<=R;j++)
                    A[i][j]=(nd<=j)?max(td+A[i-1][j-nd],A[i-1][j]):A[i-1][j];
    }
        return A[n][R];
}

int main(){

    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        long p[m+1],c[m+1];
        p[0]=0, c[0]=0;
        int sum=0;
        for(int i=1;i<=m;i++){
            cin>>p[i];
            c[i]=p[i];
            sum+=p[i];
        }
        long l=sum;
        long R=(sum+1)/2;

        long t=knapsack(c,p,m,R);
        cout<<abs(l-(2*t))<<endl;

    }
return 0;
}

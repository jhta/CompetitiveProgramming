#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll maxCommonSub(int *x,int m, int *y, int n){

    ll M[m][n];
    for(int i=0; i<n;i++)
        M[0][i]=0;
    for(int i=0; i<m;i++)
        M[i][0]=0;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){

                M[i][j]=(x[i-1]==y[j-1])?M[i-1][j-1]+1: max(M[i-1][j],M[i][j-1]);

        }
    }



    return M[m-1][n-1];
}

ll compare(int *x,int m, int *y, int n){
    ll sum=0;
    for(int i=0;i<m-1;i++)
            if(x[i]==y[i]) sum+=1;
    return sum;
}
int main(){

    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int d;
        cin>>d;
        int xi[d], yi[d];
        int n= sizeof(xi)/sizeof(int);
        int m= sizeof(yi)/sizeof(int);

        for(int i=0;i<d;i++)
            cin>>xi[i];
        int e;
        cin>>e;
        cout<<"Caso "<<k<<":"<<endl;
        for(int i=0;i<e;i++){
            for(int j=0;j<d;j++)
                cin>>yi[j];
            cout<<max(maxCommonSub(xi,n+1,yi,m+1),compare(xi,n+1,yi,m+1))<<endl;
            memset(yi,0,m);
        }


    }




}

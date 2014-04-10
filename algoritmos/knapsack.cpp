
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

long knapsack(int *c, int *p,int n,int R){
    long A[n+1][R+1];

                for(int i=0;i<=R;i++){
                    A[0][i]=0;
                }
                for(int i=1; i<=n;i++){
                        int nd=c[i];
                        int td=p[i];
                    for(int j=0; j<=R;j++){

                        if(nd<=j){

                            A[i][j]=max(td+A[i-1][j-nd],A[i-1][j]);
                        }else{
                            A[i][j]=A[i-1][j];
                        }
                    }
                }

    return A[n][R];
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n+1], c[n+1],i=0;
        p[0]=0;
        c[0]=0;
        for(int i=1;i<=n;i++){
            cin>>p[i]>>c[i];
        }

        int y;
        cin>>y;
        long sum=0;
        while(y--){
            int R;
            cin>>R;
            sum+=knapsack(c,p,n,R);
        }
        cout<<sum<<endl;
}
return 0;
}

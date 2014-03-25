#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
8
50
30
20
10
60
40
70
80
*/

ll dis(int *a,int ini,int fin, int puta){
    if(fin>ini){
        int mid=(ini+fin)/2;
        ll izq=dis(a,ini,mid,puta);
        ll der=dis(a,mid+1,fin,puta);

        return der+izq;
    }
    else
        return abs(a[ini]-a[puta]);
}


int main(){

int n;
scanf("%d",&n);
vector<int> v;

int t=n;
while(n--){
    int x;
    scanf("%d",&x);
    v.push_back(x);
}
if(t==2) cout<<abs(v[0]-v[1])<<endl;
else{
    sort(v.begin(),v.end());

    int a[v.size()];
    for(int i=0;i<v.size();i++){
        a[i]=v[i];
        //cout<<a[i]<<endl;
        }

    int mid=(t-1)/2;

    ll x=dis(a,0,mid-1,mid);

    ll y=dis(a,mid+1,v.size()-1,mid);
    cout<<v[mid]<<" "<<x+y<<endl;

}

return 0;
}

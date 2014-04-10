#include<bits/stdc++.h>

using namespace std;
long long mis(vector<int> v, int n){
   int cont=1;
    long long t[n];
    t[0]=0;
    t[1]=1;
        int L[n], L_id[n], P[n];
      int lis = 0, lis_end = 0;
      for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L, L + lis, v[i]) - L;

        L[pos] = v[i];
       // L_id[pos] = i;
        P[i] = pos>0 ? L_id[pos - 1] : -1;
        if (pos + 1 > lis) {
          lis = pos + 1;
          lis_end = i;
          }
          }
        return lis;
}


int main()
{
    int n;
    vector<int> v;
    bool flag=false, flag2=false;
    int ind=0;

    while(scanf("%d",&n)==1){

        if(n==(-1) && flag) break;
        else if(n==(-1)) flag=true;

        else {flag=false;
            v.push_back(n);
        }

        if(flag){

            reverse(v.begin(),v.end());
            /*for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;*/
            cout<<"Caso de prueba "<<(++ind)<<", maximo numero posible de intercepciones: "<<mis(v,v.size())<<endl;
            v.clear();
        }

    }


}

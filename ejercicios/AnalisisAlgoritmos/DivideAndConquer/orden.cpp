    #include <bits/stdc++.h>
    using namespace std;
    int main(){

    int n,k;

    cin>>n>>k;
    vector<int> v;
    int a=0,b=0;
    while(n--){
            int t;
            cin>>t;
            v.push_back(t);
    }

    sort(v.begin(),v.end());
    int cont=1;
    bool flag=false;
    for(int i=0;i<v.size();i++){
       // cout<<cont<<" "<<k<<endl;
        for(int j=0;j<v.size();j++){

            if(cont==k) {
                //cout<<v[i];
                flag=true;
                cout<<v[i]<<" "<<v[j]<<endl;
                break;


            }

            cont++;
        }
        if(flag)break;
        }

    return 0;
    }

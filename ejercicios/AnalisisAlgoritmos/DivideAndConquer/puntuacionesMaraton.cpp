    #include <bits/stdc++.h>
    using namespace std;
    int main(){

    int n,k;
    //vector<int> v;
    map<int,int> mymap;
    cin>>n>>k;
    while(n--){
         int t;
         cin>>t;
     //    v.push_back(t);
         mymap[t]=0;
    }
//    sort(v.begin(),v.end());
     map<int, int>::const_iterator itr;
    int cont=1;
    for(itr = mymap.begin(); itr != mymap.end(); ++itr){
    //cout << "Key: " << (*itr).first << " Value: " << (*itr).second;
        mymap[(*itr).first]=cont;
        //cout<<(*itr).first<<endl;
        cont++;
    }

    while(k--){
        int b;
        cin>>b;

        if(mymap.find(b)==mymap.end())
              cout<<b<<" no se encuentra"<<endl;
        else

            cout<<b<<" se encuentra de "<<mymap[b]<<endl;

      /*bool flag=false;
        for(int i=0;i<v.size();i++){
            if(v[i]==b){
                cout<<b<<" se encuentra de "<<i<<endl;
                flag=true;
                break;
            }
            if(flag) cout<<b<<" no se encuentra"<<endl;
        }*/
    }
    return 0;
    }

    #include <bits/stdc++.h>
    using namespace std;
    int main(){

    int n,k;
    map<int,int> mymap;
    cin>>n>>k;
    while(n--){
         int t;
         cin>>t;
         mymap[t]=0;
    }
     map<int, int>::const_iterator itr;
    int cont=1;
    for(itr = mymap.begin(); itr != mymap.end(); ++itr){
        mymap[(*itr).first]=cont;
        cont++;
    }

    while(k--){
        int b;
        cin>>b;

        if(mymap.find(b)==mymap.end())
              cout<<b<<" no se encuentra"<<endl;
        else

            cout<<b<<" se encuentra de "<<mymap[b]<<endl;

    }
    return 0;
    }

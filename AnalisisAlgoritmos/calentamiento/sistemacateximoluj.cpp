    #include <bits/stdc++.h>
    using namespace std;
    int main(){

    int x,i=0;

    while(true){
            cin>>x;
        if(x<=0)break;

        cout<<(++i)<<".";
        if(x/10000000>0) {cout<<" "<<x/10000000<<" "<<"caluj";x=x%10000000;}
         if(x/100000>0) {cout<<" "<<x/100000<<" "<<"teluj";x=x%100000;}
         if(x/1000>0) {cout<<" "<<x/1000<<" "<<"xiluj";x=x%1000;}
         if(x/100>0) {cout<<" "<<x/100<<" "<<"moluj ";x=x%100;}
        if(x>0) cout<<" "<<x%100;

        cout<<endl;

    }

    return 0;
    }

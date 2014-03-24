#include <bits/stdc++.h>
using namespace std;
static int N=1000000;
vector<int> v;



int cant_divisors2(int n){
int initial_n = n;
int num_factors = 1;
for (int i = 2; i * i <= initial_n; ++i) {
    int power = 0;
    while (n % i == 0) {
        n = n / i;
        ++power;
    }
    num_factors *= (power + 1);
}
if (n > 1) num_factors = num_factors * 2;
return num_factors;
}


void calc(){
   // memset(&b,false,sizeof(b));
    int ind=2;
    v.push_back(1);
    while(ind<=N){
        v.push_back(ind);
        int f=cant_divisors2(ind);
        ind+=f;

    }

}

int main(){
calc();
int n;

cin>>n;
while(n--){
    int a,c;
    cin>>a>>c;
        int cont=0;
        vector<int>::iterator low,up;
        low=lower_bound (v.begin(), v.end(), a);
        up= upper_bound (v.begin(), v.end(), c);


    cout<<distance(low,up)<<endl;
}



return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*Casoo de prueba


3
1
1 3 140 I
12
6 8 17 I
1 5 24 C
6 5 26 I
4 8 83 C
6 5 106 C
5 6 118 R
1 4 121 C
7 2 131 I
3 6 153 I
10 7 158 U
4 7 234 I
9 8 294 I
8
1 1 12 I
2 3 61 C
1 2 105 E
2 1 134 R
2 1 160 C
1 2 171 R
1 2 210 E
2 3 223 I


output
Maraton 1:
1 0 0

Maraton 2:
1 2 145
4 1 83
6 1 126
3 0 0
5 0 0
7 0 0
9 0 0
10 0 0

Maraton 3:
2 2 221
1 0 0
*/

struct team{
    int id;
    bool flag;
    int cont;
    bool exercises[9];
    int times[9];
    int time;
    team(){
        id=3333;
        flag=false;
        cont=0;
        time=0;
        for(int i=0;i<=9;i++){
            exercises[i]=false;
            times[i]=0;
            }
    }
};


int compare(const void* x, const void* y){
	team *a= (team *)x;
	team *b= (team *)y;
	if((a->cont)>(b->cont))
        return -1;
    else if((a->cont)<(b->cont))
        return 1;
    else{
        if((a->cont)==(b->cont) && (a->time)<(b->time))
            return -1;
        else if((a->cont)==(b->cont) && (a->time)>(b->time))
            return 1;
        else{
            if((a->id)>(b->id))
                return 1;
            else if((a->id)<(b->id))
                return -1;
            else
                return 0;
        }
    }

}

int cantidad(int y[], bool x[] ){
    int ti=0;
    for(int i=0;i<=8;i++){
         ti+=(x[i])?y[i]:0;
    }
    return ti;
}

int main(){

    int n,m;
    int xd=0;
    scanf("%d",&n);
    bool f=false;
    while(n--)
        {
            if(f)
                cout<<endl;
            else{
                f=true;
            }
        scanf("%d",&m);
        int us=0;
        team v[1001];
        while(m--){
            team x;

            int idteam,numEx,tim;
            char a;
            cin>>idteam>>numEx>>tim>>a;
            v[idteam-1].id=idteam-1;
            if(a=='I'){
                if(!v[idteam-1].flag) {v[idteam-1].flag=true; us++;}
                if(v[idteam-1].exercises[numEx]){

                }else{
                    v[idteam-1].times[numEx]+=20;
                }

            }else if(a=='C'){
                if(!v[idteam-1].flag) {v[idteam-1].flag=true; us++;}
                if(!v[idteam-1].exercises[numEx]){
                    v[idteam-1].times[numEx]+=tim;
                    v[idteam-1].cont++;
                    v[idteam-1].exercises[numEx]=true;

                }
            }
        }

            for(int i=0;i<=1000;i++){
                v[i].time=cantidad(v[i].times, v[i].exercises);

                }

        qsort (v, 1000, sizeof(team), compare);
        printf("Maraton %d:\n",(++xd));

            for(int i=0; i<=1000;i++){
                if(v[i].flag)
                cout<<v[i].id+1<<" "<<v[i].cont<<" "<<v[i].time<<endl;

            }



    }


return 0;
}

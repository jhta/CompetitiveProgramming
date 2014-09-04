#include<bits/stdc++.h>

using namespace std;

bool M[100][100];
char C[100][100];
int posx[]= {-1,0,1,-1,1,-1,0,1};
int posy[]={-1,-1,-1,0,0,1,1,1};

void DFS(int xi, int yi, int sx, int sy){

    for(int i=0;i<9;i++){
        int x=xi+posx[i], y=yi+posy[i];
        if(x>=0 && y>=0 && x<sx && y<sy){
            if(C[x][y]=='#' && !M[x][y]){
                M[x][y]=true;
                DFS(x,y,sx,sy);
            }
        }

    }
}

int main(){

    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0) break;

        for(int i=0;i<a;i++){
            for(int j=0; j<b;j++){
                char ch;
                cin>>ch;
                C[i][j]=ch;
            }
        }
        int coun=0;
        for(int i=0;i<a;i++){
            for(int j=0; j<b;j++){
                if(C[i][j]=='#' && !M[i][j]){
                    M[i][j]=true;
                    DFS(i,j,a,b);
                    coun++;
                }
            }
        }
    cout<<coun<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct Point{
    double x,y;
};

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// sort by y
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// find the distance between two points
double dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) );
}

vector<Point> calcSy(double delta, double x1, Point *py){
    int piso= floor(x1-delta);
    int techo= ceil(x1+delta);
    vector<Point> v;
    v.assign(py+piso,py+techo);
    return v;
}


pair<Point> closestSplitPair(Point *px,Point *py,double delta,int n){
    double x1=px[n/2].x;
    vector<Point> v=calcSy(delta,x1,py);
    double bestD=delta;
    pair<Point, Point> bestP=NULL;
    for(int i=0;i<=v.size()-7;i++){
        for(int j=i+1;j<=i+7;j++){
            Point p=v[i], q=v[j];
            if(dist(p,d)<bestD){
                bestD=dist(p,d);
                bestP= make_pair(p,d);
            }
        }
    }
    return bestP;
}



pair<Point> closestPairs(Point *px, Point *py,int ini, int n){
    if(n>ini){
        int mid=(ini+n)/2;

        pair<Point> w,y,z;
        w=closestPairs(px,py,ini,mid);
        y=closestPairs(px,py,mid+1,n);
        double disx=dist(w.first,w.second);
        double disy=dist(y.first,y.second);
        //calculo la menor distancia de los puntos mas cercanos de la derecha y de la izquierda
        double delta=min(disx,disy);
        z=closestSplitPair(px,py,delta,n);
        double disz=dist(z.first,z.second);
        if(disz>disx && disz>disy){
            return z;
        }else if(disy>disx && disy>disx)
            return y;
        else
            return x;

    }

}





int main(){

        ii x;
        x=make_pair(12,13);
        cout<<x.first<<" "<<x.second<<" "<<endl;
        cout<<((6+2)>>2);

        Point P[] = {{0,0}, {-2,0}, {4,0}, {1,1},
	         {3,3}, {-2,2}, {5,2}};
        Point Px[] = {{0,0}, {-2,0}, {4,0}, {1,1},
	         {3,3}, {-2,2}, {5,2}};
        Point Py[] = {{0,0}, {-2,0}, {4,0}, {1,1},
	         {3,3}, {-2,2}, {5,2}};

        //primero ordeno Px y Py
        int n = sizeof(P) / sizeof(P[0]);
        qsort(Px,n,sizeof(Point),compareX());
        qsort(Py,n,sizeof(Point),compareY());

        closestPairs(Px,Py,0,n-1);

    return 0;
}

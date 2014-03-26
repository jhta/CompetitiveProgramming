#include<bits/stdc++.h>
using namespace std;
// A structure to represent a Point in 2D plane

/*
4
1 1 CAI
10 1 LGU
1 2 CAI
3 2 LGU
2
3 3 LGU
4 4 LGU
0

*/

struct Point
{
    int x, y;
    bool e;

};
 int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

//fuerza bruta en caso de que solo sean 3
float bruteForce(Point P[], int n)
{
    float mini = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < mini && P[i].e!=P[j].e)
                mini = dist(P[i], P[j]);
    return mini;
}

// A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}


// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
    float mini = d;  // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < mini; ++j)
            if (dist(strip[i],strip[j]) < mini && strip[i].e!=strip[j].e)
                mini = dist(strip[i], strip[j]);

    return mini;
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle point
    int mid = n/2;
    Point midPoint = P[mid];

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, n);
}

// Driver program to test above functions
int main()
{
    int n;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        Point P[n-1];
        int t=0;

        bool flagCai=false, flagLgu=false;
        while(n--){
            int x,y;
            string s;
            cin>>x>>y>>s;
            P[t].x=x;
            P[t].y=y;
            if(s=="CAI"){
                P[t].e=true;
                flagCai=true;

            }else{
                flagLgu=true;
                P[t].e=false;
            }
            t++;
        }
        if(flagCai!=flagLgu) cout<<"INF"<<endl;
        else{
            printf("%.4f\n", closest(P, t));
        }

    }


    return 0;
}


#include <iostream>
#include <math.h>
using namespace std;
int least[2]; //to store point with min distance so as to find third point
class Point{
    private :
        int x, y;
    public :
        Point();
        void getThem();
        friend void display(Point p);
        friend float distance(Point p1,Point p2);
        void leastDistance(Point p[],int n);
        void thirdPoint(Point p[],int size);
	    ~Point();
};
Point::Point(){
    x=0;
    y=0;
}
Point::~Point(){
}
void Point:: getThem(){
    cout<<"enter the x and y co ordinate of the point :"<<endl;
    cin>>x>>y;
}
float distance(Point p1,Point p2){
    float ans;
    ans=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    return ans;
}
void Point:: leastDistance(Point p[],int n){
    int p1=0,p2=1;
    float min=distance(p[0],p[1]),dist;
    for(int i=0;i<(n-1);i++){              //I used i<n-1 and j<n for it to not repeat last point twice
        for(int j=i+1;j<n;j++){
            dist=distance(p[i],p[j]);
            if(min>dist){
                p1=i;
                p2=j;
                min=dist;
            }
        }
    }
    least[0]=p1;   //Here I stored the two points 
    least[1]=p2;
    cout<<"the minimum distance = "<<min<<" and betwwen the points : "<<endl;
    display(p[p1]);               
    display(p[p2]);
}
float areaTriangle(Point p1,Point p2,Point p3){
    float area,a,b,c,s;
    a=distance(p1,p2);
    b=distance(p2,p3);           //Sir I used Herons formula
    c=distance(p1,p3);
    s=(a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
void Point:: thirdPoint(Point p[],int size){
    float maxArea=0,area;
    int third=0;;
        for(int i=0;i<size;i++){
            if(i!=least[0]&&i!=least[1]){
                area=areaTriangle(p[least[0]],p[least[1]],p[i]);
                if(maxArea<area){
                    maxArea=area;	//I checked if the third point is not among the points with least distance we found
                    third=i;
                }
            }
        }
    cout<<"the max area is "<<maxArea<<"  and the third point is "<<endl;
    display(p[third]); 
}
void display(Point p){
    cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}
int main() {
    Point p[10];
    int size;
    cout<<"enter the number of points you want :"<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"for the point "<<i<<" :"<<endl;
        p[i].getThem();
    }
    for(int i=0;i<size;i++){
        display(p[i]);
    }
    p[0].leastDistance(p,size);  //called to find least distance points
    p[0].thirdPoint(p,size);     //caleed to find third point
    return 0;
}

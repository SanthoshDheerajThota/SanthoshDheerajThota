#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Point{
    protected :
        int x,y;
    public :
        Point(){
            
        }
        void setThemTo(int a ,int b){
            this->x=a;
            this->y=b;
        }
        void display(){
            cout<<"( "<<this->x<<" , "<<this->y<<" ) "<<endl;
        }
        friend float distance(Point p1);
        friend void leastFromOrigin(std::vector<Point> &pointsPassed);
};
float distance(Point p1){
    float answer;
    answer=sqrt(pow(p1.x,2)+pow(p1.y,2));
    return answer;
}
void leastFromOrigin(std::vector<Point> &pointsPassed){
    int minIndex=0;
    float minDistance=distance(pointsPassed.at(0));
    for(int i=0;i<pointsPassed.size();i++){
        float hereDistance=distance(pointsPassed.at(i));
        if(minDistance>hereDistance){
            minDistance=hereDistance;
            minIndex=i;
        }
    }
    cout<<"the point that has minimum distance from origin is "<<endl;
    pointsPassed.at(minIndex).display();
    cout<<"the minimum distance is "<<minDistance<<endl;
}
int main(){
    int size;
    cin>>size;
    vector<Point> pointsHere;
    for(int i=0;i<size;i++){
        int hereX,hereY;
        cin>>hereX>>hereY;
        pointsHere.push_back(Point());
        pointsHere.at(i).setThemTo(hereX,hereY);
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        pointsHere.at(i).display();
    }
    leastFromOrigin(pointsHere);
}

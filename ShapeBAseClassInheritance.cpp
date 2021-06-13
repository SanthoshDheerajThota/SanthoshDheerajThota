#include <iostream>
using namespace std;
class Shape{
    protected:
        float length;
        float breadth;
        float area;
        float perimeter;
    public :
        virtual void setData(){
            cout<<"enter the length and breadth of the shape :"<<endl;
            cin>>this->length>>this->breadth;
        }
        virtual void printData(){
            cout<<"the length of the shape is "<<this->length<<endl;
            cout<<"the breadth of the shape is "<<this->breadth<<endl;
        }
        virtual void areaCalculator(){
            this->area=length*breadth;
            cout<<"the area of the shape is "<<this->area<<endl;
        }
        virtual void perimeterCalculator(){
            this->perimeter=2*(length+breadth);
            cout<<"the perimeter of the shape is "<<this->perimeter<<endl;
        }
};
class Rectangle:virtual public Shape{
};
class Square:virtual public Shape{
    public :
        void setData(){
            cout<<"enter the side of the square :"<<endl;
            cin>>this->length;
            breadth=length;
        }
        void printData(){
            cout<<"the side of the square is "<<this->length<<endl;\
        }
};
class Triangle:virtual public Shape{
    public:
        void setData(){
            cout<<"enter the base and height of the triangle "<<endl;
            cin>>this->length>>this->breadth;
        }
        void areaCalculator(){
            area=(length*breadth)/2.0;
            cout<<"the area of triangle is  "<<this->area<<endl;
        }
        void printData(){
            cout<<"the base of the shape is "<<this->length<<endl;
            cout<<"the height of the shape is "<<this->breadth<<endl;
        }
};
class Circle:virtual public Shape{
    public :
        void setData(){
            cout<<"enter the radius of circle :"<<endl;
            cin>>this->length;
        }
        void areaCalculator(){
            this->area=2*(3.14)*length*length;
            cout<<"the area of the circle is "<<this->area<<endl;
        }
        void printData(){
            cout<<"the radius of the circle is "<<this->length<<endl;
        }
        void perimeterCalculator(){
            this->perimeter=2*(3.14)*length;
            cout<<"the perimeter of the circle is "<<this->perimeter<<endl<<endl;
        }
};
int main(){
    Shape *myShape;
    
    myShape=new Rectangle;
    
    myShape->setData();
    myShape->printData();
    myShape->areaCalculator();
    myShape->perimeterCalculator();
    cout<<endl;
    
    myShape = new Square;
    
    myShape->setData();
    myShape->printData();
    myShape->areaCalculator();
    myShape->perimeterCalculator();
    cout<<endl;
    
    myShape = new Triangle;
    
    myShape->setData();
    myShape->printData();
    myShape->areaCalculator();
    myShape->perimeterCalculator();
    cout<<endl;
    
    myShape = new Circle;
    
    myShape->setData();
    myShape->printData();
    myShape->areaCalculator();
    myShape->perimeterCalculator();
    cout<<endl;
    
    return 0;
}


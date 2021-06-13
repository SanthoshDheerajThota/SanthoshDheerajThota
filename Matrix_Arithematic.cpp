#include <iostream>
#include <conio.h>
using namespace std;
class Matrix{
    private :
        int **matrix;
        int row , column;
    public :
        Matrix();
        Matrix(int rows,int columns);
        friend ostream &operator <<(ostream &output,Matrix m);
        friend istream &operator >>(istream &input,Matrix &m);
        Matrix operator+(Matrix m);
        friend Matrix operator *(Matrix m1,Matrix m2);
        friend void setToIdentity(Matrix &m,int orderFinalSquare);
};
Matrix::Matrix(){
    this->row=0;
    this->column=0;
    matrix=new int *;
    for(int i=0;i<row;i++){
        matrix[i]=new int[column];
    }
}
Matrix ::Matrix(int rows,int columns){
    this->row=rows;
    this->column=columns;
    matrix=new int *;
    for(int i=0;i<row;i++){
        matrix[i]=new int[column];
    }
    for(int i=0;i<rows;i++){            // initializing all elemets to zero
        for(int j=0;j<columns;j++){
            this->matrix[i][j]=0;
        }
    }
}
istream &operator >>(istream &input,Matrix &m){
    cout<<"enter the number of  rows and columns of the matrix :"<<endl;
    input>>m.row>>m.column;
    m.matrix=new int *;
    for(int i=0;i<m.row;i++){
        m.matrix[i]=new int[m.column];
    }
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.column;j++){
            cout<<"enter "<<i<<" row "<< j<<" column element :"<<endl;
            input>>m.matrix[i][j];
        }
    }
    return input;
}
ostream &operator <<(ostream &output,Matrix m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.column;j++){
            output<<m.matrix[i][j]<<"   ";
        }
        output<<endl;
    }
    return output;
}
Matrix Matrix :: operator+(Matrix m){
    Matrix result(this->row,this->column);
    if(!(this->row==m.row&&this->column==m.column)){
        cout<<"the matri addition is not at all possible :"<<endl;
        return result;
    }
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++){
            result.matrix[i][j]=matrix[i][j]+m.matrix[i][j];
        }
    }
    return result;
}
Matrix operator*(Matrix m1,Matrix m2){
    Matrix result(m1.row,m2.column);
    if(!(m1.column==m2.row)){
        cout<<"the matrix multiplication is not at all possible :"<<endl;
        return result;
    }
    for(int i=0;i<m1.row;i++){
        for(int j=0;j<m1.column;j++){
            result.matrix[i][j]=0;
            for(int k=0;k<m1.row;k++){
                result.matrix[i][j]+=m1.matrix[i][k]*m2.matrix[k][j];
            }
        }
    }
    return result;
}
void setToIdentity(Matrix &m,int orderFinalSquare){
    for(int i=0;i<orderFinalSquare;i++){
        m.matrix[orderFinalSquare][orderFinalSquare]=1;
    }
    return ;
}
int main(){
    Matrix *matrices;
    int numberOfMatrices;
    int orderFinalSquare;
    cout<<"enter the number of matrices you want :"<<endl;
    cin>>numberOfMatrices;
    cout<<"make sure to take order of all matrices same and square matrices  :"<<endl<<endl;
    cout<<" enter the order of square matrices you want for overall :"<<endl;
    cin>>orderFinalSquare;
    cout<<endl;
    matrices=new Matrix[numberOfMatrices];
    for(int i=0;i<numberOfMatrices;i++){
        cout<<"for the matrix "<<i+1<<"enter elemnts: "<<endl;
        cin>>matrices[i];
    }
    for(int i=0;i<numberOfMatrices;i++){
        cout<<"the matrix "<<i+1<<" is :"<<endl;
        cout<<matrices[i]<<endl;
    }
    char tempe;
    tempe=getche();
    system("cls");
    cout<<" the addition of all matrices is given by "<<endl<<endl;
    Matrix *result=new Matrix(orderFinalSquare,orderFinalSquare);
    Matrix TotalAddition(orderFinalSquare,orderFinalSquare);// Creating a null matrix 
    (*result)=matrices[0];      
    for(int i=1;i<numberOfMatrices;i++){
        (*result)=(*result)+matrices[i];
        TotalAddition=TotalAddition+(*result);
        cout<<(*result)<<endl;
    }
    delete result;
    char temp;
    temp=getche();
    system("cls");    
    cout<<" the multiplication of all matrices is given by "<<endl<<endl;
    Matrix result1; 
    result1=matrices[0];
    Matrix TotalMultiplication(orderFinalSquare,orderFinalSquare);
    setToIdentity(TotalMultiplication,orderFinalSquare);
    for(int i=1;i<numberOfMatrices;i++){
        TotalMultiplication=TotalMultiplication*result1;
        cout<<(result1*matrices[i])<<endl;
    };
    char key;
    key=getche();
    system("cls");
    cout<<"the total addition of all matrices  entered is "<<endl;
    cout<<TotalAddition<<endl<<endl;
    cout<<"the total Multiplication of all matrices  entered is "<<endl;
    cout<<TotalMultiplication<<endl;
    delete []matrices;
    return 0;
}

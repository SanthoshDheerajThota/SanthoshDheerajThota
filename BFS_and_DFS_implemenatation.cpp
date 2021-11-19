/*
    this code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
#include <queue>
using namespace std;
/*
    0	1	2	3	4	5	6	7	8	9 
0   0	1	1	0	0	0	0	1	0	0
1	1	0	1	1	1	0	0	1	0	1
2	1	1	0	1	1	0	0	0	1	0
3	0	1	1	0	1	0	0	0	0	0
4	0	1	1	1	0	1	0	1	1	0
5	0	0	0	0	1	0	1	0	1	1
6	0	0	0	0	0	1	0	0	1	0
7	1	1	0	0	1	0	0	0	0	0
8	0	0	1	0	1	1	1	0	0	0
9	0	1	0	0	0	1	0	0	0	0

{0,1,1,0,0,0,0,1,0,0};
{1,0,1,1,1,0,0,1,0,1},
{1,1,0,1,1,0,0,0,1,0},
{0,1,1,0,1,0,0,0,0,0},
{0,1,1,1,0,1,0,1,1,0},
{0,0,0,0,1,0,1,0,1,1},
{0,0,0,0,0,1,0,0,1,0},
{1,1,0,0,1,0,0,0,0,0},
{0,0,1,0,1,1,1,0,0,0},
{0,1,0,0,0,1,0,0,0,0}
*/
const int n=10;
int graph[n][n]={
        {0,1,1,0,0,0,0,1,0,0},
        {1,0,1,1,1,0,0,1,0,1},
        {1,1,0,1,1,0,0,0,1,0},
        {0,1,1,0,1,0,0,0,0,0},
        {0,1,1,1,0,1,0,1,1,0},
        {0,0,0,0,1,0,1,0,1,1},
        {0,0,0,0,0,1,0,0,1,0},
        {1,1,0,0,1,0,0,0,0,0},
        {0,0,1,0,1,1,1,0,0,0},
        {0,1,0,0,0,1,0,0,0,0}
    };
int visited[n]={0};
void DFS(int i){
    cout<<i<<"   ";
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(graph[i][j]==1&&visited[j]==0){
            DFS(j);
        }
    }
}
int main(){
    int k;
    cout<<"enter the node to start the BFS with"<<endl;
    cin>>k;
    visited[k]=1;
    queue<int> explorartion;
    explorartion.push(k);
    cout<<k<<"   ";
    while(explorartion.empty()!=true){
        int temp=explorartion.front();
        explorartion.pop();
        for(int i=0;i<n;i++){
            if(graph[temp][i]==1&&visited[i]==0){
                visited[i]=1;
                explorartion.push(i);
                cout<<i<<"   ";
            }
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    cout<<endl;
    cout<<"the DFS with following node is as follows :"<<endl;
    DFS(k);
    return 0;
}

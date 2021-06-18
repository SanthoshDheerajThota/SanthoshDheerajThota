#include <iostream>
#include <map>
using namespace std;
/*
    |----------------------------------------------------------------------------------------------------------------------------|
    |   This is just a basic cipher encrypt and decrypter used to showcase how encryption and decryption on multilevel work      |
    |----------------------------------------------------------------------------------------------------------------------------| 
    1 2 3 4 5 6 7 8 9 10 11 12 13
    ________________________________
    A B C D E F G H I J  K  L  M
    | | | | | | | | | |  |  |  |                                This is how the ascii values are encrypted 
    Z Y X W V U T S R Q  P  O  N
    _________________________________
*/
map<char,char> myMap;
string cipherEncryptOne(string s,int x=0){
    if(x==0){
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                s[i]=char('m'+'n'-s[i]);
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                s[i]=char('M'+'N'-s[i]);
            }
            else{
                s[i]++;
            }
        }
        return s;
    }
    else{
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                s[i]=char('m'+'n'-s[i]);
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                s[i]=char('M'+'N'-s[i]);
            }
            else{
                s[i]--;
            }
        }
        return s;
    }
}
string cipherDecryptOne(string s){
    string answer=cipherEncryptOne(s,1);
    return answer;
}
string cipherEncryptTwo(string s){
    for(int i=0;i<s.size();i++){
        s[i]++;
    }
    return s;
}
string cipherDecryptTwo(string s){
    for(int i=0;i<s.size();i++){
        s[i]--;
    }
    return s;
}
int main(){
    string mainS,amswer;
    getline(cin,mainS);
    amswer=cipherEncryptTwo(cipherEncryptOne(mainS));
    cout<<amswer<<endl;
    amswer=cipherDecryptOne(cipherDecryptTwo(amswer));
    cout<<amswer<<endl;
    return 0;
}

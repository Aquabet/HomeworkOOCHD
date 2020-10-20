#include<iostream>
using namespace std;

class SeqStack{
    public:
    void pop(){
        top--;
    }
    void push(char word){
        a[++top]=word;
    }
    char getTop(){
        return a[top];
    }
    private:
    char a[10000];
    int top=-1;
};

int main(){
    SeqStack s;
    s.push('a');
    cout<<s.getTop()<<endl;
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class SeqStack{
    public:
    int top;
    void pop(){
        if(top>=0)
        top--;
    }
    void push(char word){
    	top++;
        a[top]=word;
    }
    char getTop(){
    	if(top>=0)
        return a[top];
        return '0';//此处非常规栈处理
    } 
    SeqStack(){
        memset(a,'0',sizeof(a));
        top=-1;
    }
    bool empty(){
        if(top>=0) return false;
        return true;
    }
    SeqStack(const SeqStack& C){
        top=C.top;
        for(int i=0;i<10000;i++)
        a[i]=C.a[i];
    }//??????
    private:
    char a[10000];
};
//finished

class BigInteger{
    public:
    void read(){
        char a[10000];
        cout<<"请输入一个大数字"<<endl;
        cin>>a;
        int len=strlen(a);
        for(int i=0;i<len;i++){
            data.push(a[i]); 
        }
    }//finish
    void add(BigInteger b,BigInteger &result){
        int flag=0;
        int transSet[10000];
        int maxNum=max(b.data.top,data.top)+1;
        int minNum=min(b.data.top,data.top)+1;
        int c;
        for(int i=0;i<=maxNum;i++){
        	c=data.getTop()-'0'+b.data.getTop()-'0'+flag;
            	
            if(c>9) {
                c=c-10;
                flag=1;
            }
            else flag=0;
            transSet[i]=c;
            data.pop();b.data.pop(); 
        }
        if(transSet[maxNum]==0){
            maxNum--;
        }
        for(int i=maxNum;i>=0;i--){
            result.data.push(transSet[i]+'0');
        }
    }//对拍通过
    void display(){
        SeqStack trans;
        while(!data.empty()){
            trans.push(data.getTop());
            data.pop();
        }
        while(!trans.empty()){
            cout<<trans.getTop();
            trans.pop();
        }
        cout<<endl;
    }
    private:
    SeqStack data;
};


int main(){
//	freopen("data.in","r",stdin);
//	freopen("testdata.out","w",stdout);
    cout<<"进行栈的测试"<<endl;
    SeqStack s;
    char charactor;
    while (true){
        int func;
        cout<<"请输入想要执行的功能 1.push 2.pop 3.输出当前栈的情况 4.结束测试"<<endl;
        cin>>func;
        if(func==1){
            cout<<"请输入想要入栈的字符：";
            cin>>charactor;
            s.push(charactor);
        }
        else if(func==2){
            if(s.top>=0) s.pop();
            else cout<<"栈空 无法实现pop操作"<<endl;
        }
        else if(func==3){
            cout<<"栈内共有"<<s.top+1<<"个元素"<<endl<<"栈顶元素为："<<s.getTop()<<endl;
        }
        else if(func==4) break;
        else cout<<"请输入正确的选项"<<endl;
    }

    cout<<"进行大整数加法测试："<<endl;
    BigInteger a,b;
    a.read();
    b.read();
    BigInteger c;
    a.add(b,c);
    c.display();//对拍通过 
}

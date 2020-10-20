#include<iostream>
using namespace std;

class CPU{
    public:
    enum CPURank {i3=1, i5, i7, i9, R3, R5, R7};
    CPU(){
        cout<<"CPU的无参构造函数被执行"<<endl;
    }
    CPU(CPURank r,float f){
        cout<<"CPU的有参构造函数被执行"<<endl;
    }
    ~CPU(){
        cout<<"CPU的析构函数被执行"<<endl;
    }
    void run(){
        cout<<"CPU的run函数被执行"<<endl;
    }
    void stop(){
        cout<<"CPU的stop函数被执行"<<endl;
    }
    void set(CPURank r,float f){
        rank = r;
        frequency = f;
    }
    void get(){
        cout<<"CPURank = " <<rank<<"frequency = "<<frequency<<endl;
    }
    private:
    CPURank rank;
    float frequency;
};

class RAM{
    public:
    RAM(){
        cout<<"RAM的无参构造函数被执行"<<endl;
    }
    ~RAM(){
        cout<<"RAM的析构函数被执行"<<endl;
    }
    void run(){
        cout<<"RAM的run函数被执行"<<endl;
    }
    void stop(){
        cout<<"RAM的stop函数被执行"<<endl;
    }
};

class HardDisk{
    public:
    HardDisk(){
        cout<<"HardDisk的无参构造函数被执行"<<endl;
    }
    ~HardDisk(){
        cout<<"HardDisk的析构函数被执行"<<endl;
    }
    void run(){
        cout<<"HardDisk的run函数被执行"<<endl;
    }
    void stop(){
        cout<<"HardDisk的stop函数被执行"<<endl;
    }
};

class Monitor{
    public:
    Monitor(){
        cout<<"Monitor的无参构造函数被执行"<<endl;
    }
    ~Monitor(){
        cout<<"Monitor的析构函数被执行"<<endl;
    }
    void run(){
        cout<<"Monitor的run函数被执行"<<endl;
    }
    void stop(){
        cout<<"Monitor的stop函数被执行"<<endl;
    }
};

class Computer{
    public:
    Computer(CPU cpu,RAM ram,HardDisk hardDisk,Monitor monitor){
        cout<<"Computer的有参构造函数被执行"<<endl;
    }
    Computer(){
        cout<<"Computer的无参构造函数被执行"<<endl;
    }
    Computer(const Computer& C){
        cpu = C.cpu;
        ram = C.ram;
        hardDisk = C.hardDisk;
        monitor = C.monitor;
        cout<<"Computer的复制构造函数被执行"<<endl;
    }
    ~Computer(){
        cout<<"Computer的析构函数被执行"<<endl;
    }
    void turnON(){
        cout<<"Computer的turnON函数被执行"<<endl;
    }
    void turnOFF(){
        cout<<"Computer的turnOFF函数被执行"<<endl;
    }
    private:
    CPU cpu;
    RAM ram;
    HardDisk hardDisk;
    Monitor monitor;
};
int main(){
    // CPU cpu;
    // RAM ram;
    // HardDisk hardDisk;
    // Monitor monitor;
    // Computer c(cpu,ram,hardDisk,monitor);
    Computer c;
    return 0;
}
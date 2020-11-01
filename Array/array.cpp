//array.cpp 
#include <iostream> 
#include <string> 
#include "array.h"
using namespace std; 

//错误信息
string errorMsg[] = {
    "Invalid array size",
    "Memory allocation error",
    "Invalid index: "
};

//错误处理函数
void Array::handleError(ErrorType error, int badIndex) const {
    cout << errorMsg[error]; //根据错误类型，输出相应错误信息
    if (error == indexOutOfRange)
        cout << badIndex; //如果是下标越界错误，输出错误的下标值
    cout << endl;
    exit(-1);
}

//构造函数
Array::Array(int sz) {
    if (sz <= 0) //检查是否sz<= 0 
        handleError(invalidArraySize);
    size = sz;
    data = new int[size];
    if(data == NULL) {
        handleError(memoryAllocationError);
    }
}//finished

//析构函数
Array::~Array() {
    if (data) {
        delete[] data;
    }
}//finished

//复制构造函数
Array::Array(const Array& a) {
    if(a.data == NULL) {
        handleError(invalidArraySize);
    }
    size = a.size;
    data = data = new int[size];
    if(data == NULL) {
        handleError(memoryAllocationError);
    }
    for (int i = 0; i < size; i++) {
        if (a.data + i) {
            *(data + i) = *(a.data + i);
        }
    }
}//finished

//设置数组下标为n处元素的值为value
void Array::setElement(int n, int value) {
    if(n >= size) {
        handleError(indexOutOfRange,n);
    }
    *(data + n) = value;
}//finished

//取数组下标为n的元素的值
int& Array::getElement(int n) {
    if(n >= size) {
        handleError(indexOutOfRange,n);
    }
    return  *(data + n);
}//finished

//返回数组大小
int Array::arraySize() const {
    return size;
}//finished

//将数组大小修改为sz 
void Array::resize(int sz) {
    if (sz <= 0) //检查是否sz<= 0 
        handleError(invalidArraySize);
    if (sz == size) //如果size==sz，则退出本函数
        return;

    int* newlist = new int[sz]; //申请新的数组内存
    if (newlist == NULL) //内存申请是否成功？
        handleError(memoryAllocationError);

    int n = (sz <= size) ? sz : size;

    int* srcptr = data; //原数组首地址 
    int* destptr = newlist; //新数组首地址
    while (n--) {
        *destptr++ = *srcptr++; //复制数组元素
    }
    delete[] data; //释放原数组所占内存
    data = newlist; //使data指向新数组 
    size = sz; //更新
}

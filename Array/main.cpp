/**
 **李佳弦 201924020323
 **关于代码的部分Feature （不是BUG！不是BUG！）
 **数组中未初始化的元素 尊重C语言设计的“Feature” 为一个未初始化的数
 **Array::arraySize()函数的返回值是数组的元素个数n, 数组的下标为从 0 ~ (n-1)。
 **/
#include <iostream> 
#include <ctime>
#include "array.h"

using namespace std; 

int main() {
    Array a(10);
    srand(time(0));
    int i;

    for (i = 0; i < 10; ++i)
        a.setElement(i, 1 + rand() % 9);

    cout << "Size Of Array ：" << a.arraySize() << endl;
    cout << "数组a的元素值：";
    for (i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "调整数组a的大小为原来的2倍: " << endl;
    a.resize(a.arraySize() * 2);
    cout << "调整大小后数组的大小: " << a.arraySize() << endl;

    cout << "用复制构造函数，用数组a初始化b" << endl;
    Array b(a);

    cout << "修改数组a的最后一个元素值为100" << endl;
    a.setElement(a.arraySize() - 1, 100);
    cout << "数组a的值: ";
    for (i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "数组b的元素值: ";
    for (i = 0; i < b.arraySize(); ++i)
        cout << b.getElement(i) << " ";
    cout << endl;
    
//	错误处理测试
//	a.resize(-10);
//  a.setElement(1000, 1000);
//  a.getElement(1000);

    cout << "Quit...." << endl;
    return 0;
}

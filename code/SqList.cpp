#include   <iostream>
using namespace std;

//定义结构体中的元素类型-Defines the element type of the struct
#define ElemType int 

//定义最大值-Define the maximum value
#define MaxSize 12
//啊实打实大苏打实打实的

//定义线性表的结构体-A structure that defines a linear list
typedef struct
{
    //定义数组类型-Defining Array types
    ElemType* elem;

    //定义长度-Defining Array types
    int length;
     //sdfasdfa
    /* data */
}SqList;

//初始化线性表-Initialize the linear table
bool InitSqList(SqList& L) {

    //申请地址空间-Requesting address space
    L.elem = new ElemType[MaxSize];

    //判断是否成功-Determine whether it is successful.
    if (!L.elem) return false;
    L.length = 0;
    return true;
}

//获取指定位置的元素值-Retrieves the element value at the specified position
bool GetElem(SqList& L, int i, ElemType& e) {
    //合法性判断-Judgment of legitimacy
    if (i<1 || i>L.length)return false;
    e = L.elem[i - 1];
    return true;
}

//查找元素是否在表中查元素是否表中-Check whether the element is in the table
int  LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)return i + 1;
    }
    return 0;
    //-时间复杂度-time complexity-O(n);
}


//指定位置插入元素-Inserts an element at the specified position
bool InsertElem(SqList& L, int i, ElemType e) {
    if (i<1 || i>L.length + 1)return false;
    if (L.length == MaxSize)return false;
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return true;
    //-时间复杂度-time complexity-O(n);
}

//删除指定元素-Remove the specified element
bool DelElem(SqList& L, int i, ElemType& e) {
    if (i<1 || i>L.length)return false;
    if (L.length == 0)return false;
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return true;
}

//遍历整个表-Iterate over the entire table
void CoutSqList(SqList L) {
    for (int i = 0; i < L.length; i++)cout << "第" << i << "个元素是：" << L.elem[i] << "\t";
    cout << endl;
}

int main() {
    SqList L;
    InitSqList(L);
    for (int i = 0; i < 10; i++) {
        L.elem[i] = i;
        L.length++;
    }
    cout << L.length << endl;
    CoutSqList(L);
    int e=11;
    InsertElem(L,11,e);    
    CoutSqList(L);
    DelElem(L,4,e);
    CoutSqList(L);
    return 0;
}

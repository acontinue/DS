#include   <iostream>
using namespace std;

//����ṹ���е�Ԫ������-Defines the element type of the struct
#define ElemType int 

//�������ֵ-Define the maximum value
#define MaxSize 12

//�������Ա�Ľṹ��-A structure that defines a linear list
typedef struct
{
    //������������-Defining Array types
    ElemType* elem;

    //���峤��-Defining Array types
    int length;
    /* data */
}SqList;

//��ʼ�����Ա�-Initialize the linear table
bool InitSqList(SqList& L) {

    //�����ַ�ռ�-Requesting address space
    L.elem = new ElemType[MaxSize];

    //�ж��Ƿ�ɹ�-Determine whether it is successful.
    if (!L.elem) return false;
    L.length = 0;
    return true;
}

//��ȡָ��λ�õ�Ԫ��ֵ-Retrieves the element value at the specified position
bool GetElem(SqList& L, int i, ElemType& e) {
    //�Ϸ����ж�-Judgment of legitimacy
    if (i<1 || i>L.length)return false;
    e = L.elem[i - 1];
    return true;
}

//����Ԫ���Ƿ��ڱ��в�Ԫ���Ƿ����-Check whether the element is in the table
int  LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)return i + 1;
    }
    return 0;
    //-ʱ�临�Ӷ�-time complexity-O(n);
}


//ָ��λ�ò���Ԫ��-Inserts an element at the specified position
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
    //-ʱ�临�Ӷ�-time complexity-O(n);
}

//ɾ��ָ��Ԫ��-Remove the specified element
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

//����������-Iterate over the entire table
void CoutSqList(SqList L) {
    for (int i = 0; i < L.length; i++)cout << "��" << i << "��Ԫ���ǣ�" << L.elem[i] << "\t";
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
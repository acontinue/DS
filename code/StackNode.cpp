#include <iostream> 
using  namespace std;

#define ElemType int
#define MaxSize 20


//�ṹ��
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;



//��ʼ����ջ������ͷ�ڵ㣩
bool InitLinkStack(LinkStack &s,ElemType e) {
	s = new StackNode;
	if (!s)return false;
	s->data = e;
	s->next = nullptr;
	return true;
}

//�ж���ջ�Ƿ�Ϊ�ա�--Determines whether the chain stack is empty.
bool IsEmpty(LinkStack &s) {
	if (s==nullptr)return true;
	return false;
}

bool Push(LinkStack &s,ElemType e) {
	LinkStack p = new StackNode ;
	p->data = e;
	p->next = s;
	s = p;
	return true;
}

bool Pop(LinkStack& s, ElemType& e) {
	if (IsEmpty(s))return false;
	LinkStack p = s;
	e = p->data;
	s = p->next;
	delete p;
	return true;
}



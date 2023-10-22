#include <iostream> 
using  namespace std;

#define ElemType int
#define MaxSize 20

//顺序栈结构体--Sequential stack structure	
typedef struct {
	int top;
	ElemType *data;//ElemType data[MaxSize]
}SqStack;

//共享栈--Shared stack
typedef struct ShareStack {
	ElemType *data;
	int top0;
	int top1;
}SStack;


//初始化顺序栈--Initialize the sequential stack
bool InitStack(SqStack &s) {
	s.data = new ElemType[MaxSize];
	if (!s.data)return false;
	s.top = -1;
	return true;
}

//判空--Is the stack empty?
bool IsEmpty(SqStack s) {
	if (s.top == -1)return true;
	return false;
}


//栈满--Is the stack full?
bool IsFull(SqStack s) {
	if (s.top == MaxSize - 1)return true;
	return false;
}


//入栈--Push
bool Push(SqStack& s, ElemType e) {
	if (IsFull)return false;
	s.data[++s.top] = e;
	return true;
}

//出栈--Pop
bool Pop(SqStack& s, ElemType e) {
	if (IsEmpty)return false;
	e = s.data[s.top--];
	return true;
}

//获取栈顶元素--Gets the top element of the stack
bool GetTopElem(SqStack s,ElemType e) {
	if (IsEmpty)return false;
	e = s.data[s.top];
	return true;
}


//初始化共享栈--Initialize the shared stack
bool InitShareStack(SStack &s) 
{
	s.data = new ElemType[MaxSize];
	if (!s.data)return false;
	s.top0 = -1;
	s.top1 = MaxSize ;
}

//共享栈判空--Is the share  stack empty?
bool IsEmptySStack(SStack s) {
	if (s.top0 == -1 && s.top1 == MaxSize - 1)return true;
	return false;
}

//共享栈判空--Is the share stack Full?
bool IsFullSStack(SStack s) {
	if (s.top0 + 1 == s.top1)return true;
	return false;
}


//入栈--Push Share Stack
bool PushSStack(SStack &s,int num,ElemType e) {
	if (IsFullSStack(s))return false;
	if (num == 1) {
		s.data[++s.top1] = e;
	}
	else
	{
		s.data[++s.top0] = e;
	}
	return true;
}


//出栈--Pop share stack
bool PopSStack(SStack &s,int num,ElemType &e) {
	if (IsEmptySStack(s))return false;
	if (num == 1)e = s.data[s.top1--];
	else e = s.data[s.top0--];
	return true;
}


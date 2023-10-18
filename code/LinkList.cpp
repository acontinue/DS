#include <iostream>

using namespace std;
#define ElemType int 


typedef struct LNode{
	ElemType data;
	struct LNode*  next;
} LNode,*LinkList ;

bool InitLinkList(LinkList &L) {
	L = new LNode;
	if (!L)return false;
	L->next = NULL;
	return true;
}


bool GetElem(LinkList L, int i, ElemType &e) {
	if (!L)return false;
	LinkList p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p)return false;
	e = p->data;
	return true;
}

LinkList FindElem(LinkList L, ElemType e) {
	if (!L)return nullptr;
	LinkList p = L->next;
	while (p)
	{
		if (p->data == e)return p;
		p = p->next;
	}
	return nullptr;
}


bool InsertLinkList(LinkList& L, int i, ElemType e) {
	LinkList p = L->next;
	int j = 1;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)return false;
	LinkList s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	if (i == 1)L->next = s;//插入表头的情况。
	return true;
}


bool DelLinkList(LinkList& L, int i) {
	if (i < 1 || L == nullptr)return false;
	LinkList p = L;
	LinkList q = p->next;
	int j = 0;
	while (q && j < i )
	{
		p = q;
		q = q->next;
		j++;
	}
	if (!q || j > i )return false;
	p->next = q->next;
	delete q;
	return true;
}


bool HeadInsertLinkList(LinkList &L,ElemType arr[],int n){
	LinkList p = L;
	for (int i = 0; i <= n-1; i++) {//i<n也可以
		LinkList s = new LNode;
		s->data = arr[i];
		s->next = p->next;
		p->next = s;
	}
	return true;
}

bool TailInsertLinkList(LinkList& L, ElemType arr[], int n) {
	LinkList r = L;
	for (int i = 0; i < n;i++) {
		LinkList s = new LNode;
		s->data = arr[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
	return true;
}

void CoutLinkList(LinkList L) {
	LinkList p = L->next;
	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

int main() {
	LinkList L1 = new LNode;
	LinkList L2 = new LNode;
	InitLinkList(L1);
	InitLinkList(L2);
	int arr[5] = { 1,2,3,4,5 };
	HeadInsertLinkList(L1, arr, 5);
	CoutLinkList(L1);
	TailInsertLinkList(L2, arr, 5);
	CoutLinkList(L2);
	return 0;
}
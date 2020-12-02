#include<iostream>
using namespace std;
template <typename Coe>
class Poly{
	class Term {
	public:
		Coe coe;
		int exp;
	};
	class Node {
		
	public:
		Term data;
		Node* next;
		Node(Coe a = 0, int b = 0, Node* c = nullptr) {
			data.coe = a;
			data.exp = b;
			next = c;
		}
	};

private:
	int myDegree;
	Node* myTerms;
public:
	Poly<Coe>() {
		myTerms = new Node(0, 0);
	}
	void add(Coe a) {
		Node* p = myTerms;
		for (Coe i = 1; i <= a;++i) {
			p->next= new Poly<Coe>::Node(i, (int)i);
			p = p->next;
		}
	}
	void display() {
		Node* p = myTerms->next;
		while (p != nullptr) {
			cout << p->data.coe <<"x("<< p->data.exp<<") ";
			p = p->next;
		}
		cout << endl;
	}
	Poly<Coe> operator+(const Poly<Coe>& sec) {
		Poly<Coe> sumPoly;
		Poly<Coe>::Node* ptra = myTerms->next;
		Poly<Coe>::Node* ptrb = sec.myTerms->next;
		Poly<Coe>::Node* ptrc = sumPoly.myTerms;
		int degree = 0;
		while (ptra != nullptr || ptrb != nullptr) {
			if ((ptrb == nullptr) || ((ptra != nullptr) && (ptra->data.exp < ptrb->data.exp)))
			{
				ptrc->next = new Poly<Coe>::Node(ptra->data.coe, ptra->data.exp);
				degree = ptra->data.exp;
				ptra = ptra->next;
				ptrc = ptrc->next;
			}
			else if ((ptra == nullptr) || ((ptrb != nullptr) && (ptrb->data.exp < ptra->data.exp)))
			{
				ptrc->next = new Poly<Coe>::Node(ptrb->data.coe, ptrb->data.exp);
				degree = ptrb->data.exp;
				ptrb = ptrb->next;
				ptrc = ptrc->next;
			}
			else {
				Coe sum = ptra->data.coe + ptrb->data.coe;
				if (sum != 0)
				{
					ptrc->next = new Poly<Coe>::Node(sum, ptra->data.exp);
					degree = ptra->data.exp;
					ptrc = ptrc->next;
				}
				ptra = ptra->next;
				ptrb = ptrb->next;
			}
		}
			sumPoly.myDegree = degree;
			return sumPoly;
		
	}
	Poly<Coe> operator*(const Poly<Coe>& sec) {
		Poly<Coe> sumPoly;
		Poly<Coe>::Node* ptra = myTerms->next;
		Poly<Coe>::Node* ptrc = sumPoly.myTerms;
		int degree = 0;
		while (ptra != nullptr) {
			Poly<Coe>::Node* ptrb = sec.myTerms->next;
			Poly<Coe> ssum;
			Poly<Coe>::Node* ptrd = ssum.myTerms;
			while (ptrb != nullptr) {
				ptrd->next = new Poly<Coe>::Node(ptrb->data.coe * ptra->data.coe, ptrb->data.exp + ptra->data.exp);
				ptrb = ptrb->next;
				ptrd = ptrd->next;
				if(ptrb != nullptr)
					degree = ptrb->data.exp + ptra->data.exp;
			}
			sumPoly=sumPoly+ssum;
			ptra = ptra->next;
		}
		sumPoly.myDegree = degree;
		return sumPoly;
	}
	Poly<Coe> Derivation() {
		Poly<Coe> sumPoly;
		Poly<Coe>::Node* ptra = myTerms->next;
		Poly<Coe>::Node* ptrc = sumPoly.myTerms;
		int degree = 0;
		while (ptra != nullptr) {
			if(ptra->data.exp!=0)
				ptrc->next = new Poly<Coe>::Node(ptra->data.coe * ptra->data.exp, ptra->data.exp - 1);
			degree = ptra->data.exp - 1;
			ptrc = ptrc->next;
			ptra = ptra->next;
		}
		sumPoly.myDegree = degree;
		return sumPoly;
	}
};
#include "stdafx.h"
#include <iostream> 
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


class LinkedList {
protected: 
	struct node {
		int data;
		node* next;
	};

	node* head = nullptr;
	node* curr = nullptr;
	node* tail = nullptr;
	node* track = nullptr;

public:
	LinkedList() {};
	~LinkedList() {};

	void Output()
	{
		ofstream myfile;
		myfile.open("Mel.Nichols.lList.txt");

		curr = head;
		while (curr != nullptr) {
			cout << curr->data << "\t";
			myfile << curr->data << "\t";
			curr = curr->next;
		}
		myfile.close();
	};

	void NewNode(int someData) 
	{ 
		node* n = new node;
		n->next = nullptr;
		n->data = someData;

		if (head != nullptr) {
			curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = n;
		}
		else
		{
			head = n;
		}
		tail = n;
	};

	void Delete(int deleteData) 
	{
		node* deletePointer = nullptr;
		curr = head;
		while ((curr != nullptr) && (curr->data != deleteData)) {
			track = curr;
			curr = curr->next;
		}

		deletePointer = curr;
		curr = curr->next;
		track->next = curr;
		delete deletePointer;
		
	};

	void Insert(int insertData, int count)
	{
		node* n = new node;
		n->next = nullptr;
		n->data = insertData;

		if (head != nullptr) {
			curr = head;
			for (int i = 0; i < count - 2; i++) {
				curr = curr->next;
				track = curr->next;
			}
			curr->next = n;
			curr->next->next = track;
		}
		else
		{
			head = n;
		}
	}
};


template<class T>
class LinearList
{
private:
	int length;
	int MaxSize;
	T *element;
public:
	LinearList(int MaxLinearSize = 11);
	~LinearList() { delete[]element; }
	int isEmpty()const { return length == 0; }
	int Length()const { return length; }
	int Find(int k, T&x)const;
	int Search(const T&x)const;
	void Delete(int k, T&x);
	void Insert(int k, const T&x);
	void Output()const;
};
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}
template<class T>
int LinearList<T>::Find(int k, T&x)const
{
	if (k<1 || k>length)
		return 0;
	x = element[k - 1];
	return 1;
}
template<class T>
int LinearList<T>::Search(const T&x)const
{
	for (int i = 0; i<length; i++)
		if (element[i] == x)
			return ++i;
	return 0;
}
template<class T>
void LinearList<T>::Delete(int k, T&x)
{
	if (Find(k, x))
	{
		for (int i = k; i<length; i++)
			element[i - 1] = element[i];
		length--;
	}
	else
		cout << "out of bounds\n";
}
template<class T>
void LinearList<T>::Insert(int k, const T&x)
{
	if (k<0 || k>length)
		cout << "out of bounds\n";
	if (length == MaxSize)
		cout << "no memory\n";
	for (int i = length - 1; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
}
template<class T>
void LinearList<T>::Output()const
{
	ofstream myfile;
	myfile.open("Mel.Nichols.aList.txt");
	
	
	if (isEmpty())
		cout << "list is empty\n";
	else
		for (int i = 0; i < length; i++) {
			cout << element[i] << "\t";
			myfile << element[i] << "\t";
		}
			
	myfile.close();
}
void menu()
{
	cout << "\n MENU\n";
	cout << "-----------\n";
	cout << "1.Length\n";
	cout << "2.Find\n";
	cout << "3.Search\n";
	cout << "4.Delete\n";
	cout << "5.Insert\n";
	cout << "6.Output\n";
	cout << "-------------\n";
}
int main()
{

	int ch;
	int k, x, len, p;
	LinearList <int> obj;

	obj.Insert(0, 11);
	obj.Insert(1, 10);
	obj.Insert(2, 9);
	obj.Insert(3, 8);
	obj.Insert(4, 7);
	obj.Insert(5, 6);
	obj.Insert(6, 5);
	obj.Insert(7, 4);
	obj.Insert(8, 3);
	obj.Insert(9, 2);
	obj.Insert(10, 1);


	obj.Output();
	cout << endl;


	int temp = 7;
	obj.Delete(5, temp);

	obj.Output();
	cout << endl;

	obj.Insert(7, 100);

	obj.Output();

	cout << endl;

	LinkedList Linkie;

	Linkie.NewNode(11);
	Linkie.NewNode(10);
	Linkie.NewNode(9);
	Linkie.NewNode(8);
	Linkie.NewNode(7);
	Linkie.NewNode(6);
	Linkie.NewNode(5);
	Linkie.NewNode(4);
	Linkie.NewNode(3);
	Linkie.NewNode(2);
	Linkie.NewNode(1);

	cout << endl;

	Linkie.Output();

	cout << endl;

	Linkie.Delete(7);
	Linkie.Output();

	cout << endl;

	Linkie.Insert(100, 8);
	Linkie.Output();

	return 0;
}

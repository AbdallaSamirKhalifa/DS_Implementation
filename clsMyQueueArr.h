#pragma once
#include"clsDynamicArray.h"
template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T>_MyDynamicArray;

public:
	void push(T value) {
		_MyDynamicArray.InsertAtEnd(value);
	}

	void pop() {
		_MyDynamicArray.DeleteFirstItem();
	}

	void Print() {
		_MyDynamicArray.PrintList();
	}

	int Size() {
		return _MyDynamicArray.Size();
	}

	bool IsEmpty() {
		return _MyDynamicArray.IsEmpty();
	}

	T front() {
		return _MyDynamicArray.GetItem(0);
	}
	
	T back() {
		return _MyDynamicArray.GetItem(Size()-1);
	}

	T GetItem(int Index) {
		return _MyDynamicArray.GetItem(Index);
	}
	
	void Reverse() {
		_MyDynamicArray.Reverse();
	}

	void UpdateItem(int Index,T value) {
		_MyDynamicArray.SetItem(Index, value);
	}

	void InsertAfter(int Index, T value) {
		_MyDynamicArray.InsertAfter(Index, value);
	}

	void InsertAtFront(T value) {
		_MyDynamicArray.InsertAtBeginning(value);
	}

	void InsertAtBack(T value) {
		_MyDynamicArray.InsertAtEnd(value);
	}

	void Clear() {
		_MyDynamicArray.Clear();
	}
};


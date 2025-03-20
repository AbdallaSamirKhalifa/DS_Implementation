#pragma once
#include "clsDblLinkedList.h"
template <class T>
class clsDynamicArray 
{
protected:
    int _Size=0;
    T* _TempArray;
public:
    T* OriginalArray;
    clsDynamicArray(int size=0) {
        if (size < 0)size = 0;
        _Size = size;

        OriginalArray = new T[size];

    }
    ~clsDynamicArray() {
        delete[] OriginalArray;
    }

    bool SetItem(int index, T Item) {
        if (index >= _Size || _Size < 0)
            return false;

        OriginalArray[index] = Item;
        return true;
    }

    void PrintList() {
        cout << endl;
        for (short i = 0; i < _Size; i++) {
            cout << OriginalArray[i] << " ";
        }
    }

    int Size() {
        return _Size;
    }

    bool IsEmpty() {
        return (_Size == 0);
    }

    void Resize(int NewSize) {

        if (NewSize < 0)
            NewSize = 0;

         _TempArray=new T[NewSize];

         if (NewSize < _Size)
             _Size = NewSize;

        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    T GetItem(int Index) {
        return OriginalArray[Index];
    }

    void Clear() {
        _Size = 0;
        _TempArray = new T[0];
        delete[]OriginalArray;
        OriginalArray = _TempArray;
    }

    void Reverse() {
      
        _TempArray = new T[_Size];
        int Counter = 0;

        for (int i = _Size-1; i >=0; i--)
        {
            _TempArray[Counter] = OriginalArray[i];
            Counter++;
        }
       
        delete[]OriginalArray;
        OriginalArray = _TempArray;

    }

    bool DeleteItemAt(int Index) {
        if (Index >= _Size  || Index < 0)return false;
      
        _Size--;
        _TempArray = new T[(_Size)];
        
        //Copy All Before Index
        for (int i = 0; i <Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }
        //Copy All After Index
        for (int i =Index+1; i <_Size+1; i++)
        {
            _TempArray[i-1] = OriginalArray[i];
        }
        delete[]OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }

    void DeleteFirstItem() {
        
        DeleteItemAt(0);
    }

    void DeleteLastItem() {
        
        DeleteItemAt(_Size - 1);
    }

    int Find(T value) {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == value)
                return i;
        }
        return -1;
    }

    bool DeleteItem(T value) {
        int Index = Find(value);
      
        if (Index==-1)
        {
            return false;
        }

        
        return DeleteItemAt(Index);
    }

    bool InsertAt(int index, T value) {

        if (index > _Size || index < 0 ||index==NULL) {
            return false;
        }

        _Size++;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[index] = value;

        //copy all after index
        for (int i = index; i < _Size - 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }

    void InsertAtBeginning(T value) {
        InsertAt(0, value);
    }
    
    bool InsertBefore(int index, T value) {
        if (index < 1)
        {
            return InsertAt(0, value);
        }
        else
            return InsertAt(index - 1, value);
    }

    void InsertAtEnd(T value) {
        InsertAt(_Size, value);
    }
    
    bool InsertAfter(int index, T value) {
        if (index >= _Size)
            return InsertAt(_Size - 1, value);
        else
            return InsertAt(index+1, value);
    }

};


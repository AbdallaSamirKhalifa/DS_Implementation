#pragma once
#include <stack>
#include <iostream>

using namespace std;

class clsMyString
{
	string _Value;
	stack<string>_Undo;
	stack<string>_Redo;

public:

	void Set(string NewValue) {
		_Undo.push(_Value);
		_Value = NewValue;
	}
	string Get() {
		return _Value;
	}
	__declspec(property(get = Get, put = Set))string Value;

		
	void Undo() {
		if (!_Undo.empty()) {
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
		
	}

	void Redo() {
		if (!_Redo.empty()) {
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}
};
//private:
	//
	//	stack <string> _Undo;
	//	stack <string> _Redo;
	//	string _Value;
	//
	//public:
	//
	//	void Set(string value)
	//	{
	//		_Undo.push(_Value);
	//		_Value = value;
	//	}
	//
	//	string Get()
	//	{
	//		return _Value;
	//	}
	//
	//	__declspec(property(get = Get, put = Set)) string Value;
	//
	//
	//	void Undo()
	//	{
	//
	//		if (!_Undo.empty())
	//		{
	//			_Redo.push(_Value);
	//			_Value = _Undo.top();
	//			_Undo.pop();
	//		}
	//
	//	}
	//
	//	void Redo()
	//	{
	//
	//		if (!_Redo.empty())
	//		{
	//			_Undo.push(_Value);
	//			_Value = _Redo.top();
	//			_Redo.pop();
	//		}
	//
	//
	//	}

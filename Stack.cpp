#include "Stack.h"
#include "VectorStack.h"
#include "LinkedListStack.h"

Stack::Stack(StackContainer container){
	_containerType = container;
	if (container == StackContainer::Vector){
		_pimpl = new VectorStack();
	}
	else if (container == StackContainer::List){
		_pimpl = new LinkedListStack();

	}
}


Stack::Stack(const Stack& copyStack) = default; 
/*
{
    *this = copyStack;
}
*/
Stack& Stack::operator=(const Stack& copyStack) = default;
/*
{
	if (this != &copyStack){
	    _containerType = copyStack._containerType;
	    _pimpl = new copyStack._pimpl
	}
    return *this;
}
*/

Stack::Stack(Stack&& moveStack) noexcept = default;
Stack& Stack::operator=(Stack&& moveStack) noexcept = default;

Stack::~Stack() = default;



Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container){
	_containerType = container;

	if (container == StackContainer::Vector){
		_pimpl = new VectorStack(valueArray, arraySize);
	}
	else if (container == StackContainer::List){
		_pimpl = new LinkedListStack(valueArray, arraySize);
	}
}

void Stack::push(const ValueType& value){
	_pimpl->push(value);
}

void Stack::pop(){
	_pimpl->pop();
}

const ValueType& Stack::top() const{
	return _pimpl->top();
}

bool Stack::isEmpty() const{
	return _pimpl->isEmpty(); 
}

size_t Stack::size() const{
	return _pimpl->size();
} 



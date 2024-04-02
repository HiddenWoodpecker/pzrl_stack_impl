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


Stack::Stack(const Stack& copyStack){
    StackContainer container = copyStack._containerType;

    if(copyStack.size() == 0 || copyStack._pimpl == nullptr){
        Stack(copyStack._containerType); 
    }

    else{
	    ValueType * valueArray = copyStack._pimpl->getSequence();
        int arraySize = copyStack.size();

        if (container == StackContainer::Vector){
		    _pimpl = new VectorStack(valueArray, arraySize);
	    }
	    else if (container == StackContainer::List){
		    _pimpl = new LinkedListStack(valueArray, arraySize);
	    }

        delete[] valueArray;
    }
}

Stack& Stack::operator=(const Stack& copyStack){
    StackContainer container = copyStack._containerType;

    if (this != &copyStack){
        if(copyStack.size() == 0 || copyStack._pimpl == nullptr){
        Stack(copyStack._containerType);
    }
    else{
	    ValueType * valueArray = copyStack._pimpl->getSequence();
        int arraySize = copyStack.size();
        delete _pimpl;
        if (container == StackContainer::Vector){
		    _pimpl = new VectorStack(valueArray, arraySize);
	    }
	    else if (container == StackContainer::List){
		    _pimpl = new LinkedListStack(valueArray, arraySize);
	    }

        delete[] valueArray;
        }

    }
    return *this;
} 

Stack::Stack(Stack&& moveStack) noexcept {
    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
}
Stack& Stack::operator=(Stack&& moveStack) noexcept {
    if (&moveStack != this){
        _pimpl = moveStack._pimpl;
         moveStack._pimpl = nullptr;
    }
    return *this;
};

Stack::~Stack() {
    delete _pimpl;
}



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



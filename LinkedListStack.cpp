#include "LinkedListStack.h"


LinkedListStack::LinkedListStack() = default;
/*
    lst = new std::list<ValueType>;

}
*/
LinkedListStack::LinkedListStack(const ValueType* valueArray, const size_t arraySize){
	//lst = new std::list<ValueType>;
	for (int i = 0; i < arraySize; ++i){
		lst.push_back(valueArray[i]);
	}
}
/*
LinkedListStack::~LinkedListStack(){
	delete lst;
}
*/
void LinkedListStack::push(const ValueType& value){
	lst.push_back(value);
}

void LinkedListStack::pop(){
	lst.pop_back();
}

const ValueType& LinkedListStack::top() const {
	return lst.back();
}

bool LinkedListStack::isEmpty()const{
	return lst.empty();
}

size_t LinkedListStack::size() const {
	return lst.size();
}

ValueType* LinkedListStack::getSequence() const {
    ValueType *arr = new ValueType[lst.size()];
    int l = 0;
    for (auto &a : lst){
        arr[l++] =a;
    }
    return arr;
}


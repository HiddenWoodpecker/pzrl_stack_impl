#include "VectorStack.h"
#include <iostream>


VectorStack::VectorStack() = default;

VectorStack::VectorStack(const ValueType* valueArray, const size_t arraySize){
	for (int i = 0; i < arraySize; ++i){
		vec.push_back(valueArray[i]);
	}
}


void VectorStack::push(const ValueType& value){
	vec.push_back(value);
}

void VectorStack::pop(){
	vec.pop_back();
}

const ValueType& VectorStack::top() const {
	return vec.at(vec.size()-1);
}

bool VectorStack::isEmpty()const{
	return vec.empty();
}

size_t VectorStack::size() const {
	return vec.size();
}



ValueType* VectorStack::getSequence() const {
    ValueType *arr = new ValueType[vec.size()];
    for (int i = 0; i< vec.size(); ++i){
        arr[i] = vec.at(i);
    }
    return arr;
}

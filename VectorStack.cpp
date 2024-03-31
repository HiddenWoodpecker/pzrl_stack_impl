#include "VectorStack.h"
VectorStack::VectorStack(){
	vec = new std::vector<ValueType>;
}

VectorStack::VectorStack(const ValueType* valueArray, const size_t arraySize){
	vec = new std::vector<ValueType>;
	for (int i = 0; i < arraySize; ++i){
		vec->push_back(valueArray[i]);
	}
}

VectorStack::~VectorStack(){
	delete vec;
}

void VectorStack::push(const ValueType& value){
	vec->push_back(value);
}

void VectorStack::pop(){
	vec->pop_back();
}

const ValueType& VectorStack::top() const {
	return vec->at(vec->size()-1);
}

bool VectorStack::isEmpty()const{
	return vec->empty();
}

size_t VectorStack::size() const {
	return vec->size();
}


#pragma once
#include "StackImplementation.h"
#include <list>
using ValueType = double;

class LinkedListStack : public IStackImplementation{
	
	public:

	LinkedListStack();
	LinkedListStack(const ValueType* valueArray, const size_t arraySize);
	~LinkedListStack();

	void push(const ValueType& value) override;
	void pop() override;
	const ValueType& top() const override;
	bool isEmpty() const override;
	size_t size() const override;
    ValueType* getSequence() const override;
	std::list<ValueType>* lst = nullptr;
};


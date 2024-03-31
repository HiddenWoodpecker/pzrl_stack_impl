#pragma once
#include "StackImplementation.h"
#include <vector>
using ValueType = double;

class VectorStack : public IStackImplementation{
	
	public:

	VectorStack();
	VectorStack(const ValueType* valueArray, const size_t arraySize);
	~VectorStack();

	void push(const ValueType& value) override;
	void pop() override;
	const ValueType& top() const override;
	bool isEmpty() const override;
	size_t size() const override;
    ValueType* getSequence() const override;	
	std::vector<ValueType>* vec = nullptr;
};


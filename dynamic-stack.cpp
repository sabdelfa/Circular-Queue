#include "dynamic-stack.h"
#include <iostream>
using namespace std;
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ = 16;
    size_ = 0;

    items_ = new StackItem[ init_capacity_ ];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    capacity_ = capacity;
    init_capacity_ = capacity_;

    size_ = 0;

    items_ = new StackItem[ capacity_ ];
}

DynamicStack::~DynamicStack()
{
    delete[] items_;
    items_ = NULL;
}

bool DynamicStack::empty() const
{
    if( size_ == 0 ) return true;
    else return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if( size_ < capacity_ )
    {
        items_[size_] = value;
        size_++;
    }
    else
    {
        int newCapacity = capacity_ * 2;
        StackItem* tempStack = new StackItem[ newCapacity ];
        for( int i = 0; i < (capacity_-1); ++i )
        {
            tempStack[i] = items_[i];
        }

        capacity_ = newCapacity;
        delete[] items_;
        items_ = tempStack;

        items_[size_] = value;
        size_++;
    }
}

DynamicStack::StackItem DynamicStack::pop()
{
    if( empty() ) return EMPTY_STACK;

    if( !empty() )
    {
        int topItem = items_[size_ - 1];
        items_[size_ - 1] = NULL;
        size_--;

        if( size_ <= (capacity_ / 4) )
        {
            int halfCapacity = capacity_ / 2;
            if ( halfCapacity >= init_capacity_ )
            {
                StackItem* tempStack = new StackItem[ halfCapacity ];
                for (int i = 0; i < halfCapacity; ++i)
                {
                    tempStack[i] = items_[i];
                }
                capacity_ = halfCapacity;
                delete[] items_;
                items_ = tempStack;
            }
        }
        return topItem;
    }
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if( empty() ) return EMPTY_STACK;
    return items_[size_-1];
}

void DynamicStack::print() const
{
    for( int i = (size_-1); i >= 0; --i)
    {
        cout << items_[i] << endl;
    }
}

#include "circular-queue.h"
#include <iostream>
using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;

    items_ = new QueueItem[ capacity_ ];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;

    items_ = new QueueItem[ capacity_ ];
}

CircularQueue::~CircularQueue()
{
    delete[] items_;
}

bool CircularQueue::empty() const
{
    return( size_ == 0 );
}

bool CircularQueue::full() const
{
    return( size_ == capacity_ );
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if( !full() )
    {
        items_[tail_] = value;
        size_ ++;
        tail_ = (tail_+1) % capacity_;
        return true;
    }
    else return false;
}

CircularQueue::QueueItem CircularQueue::dequeue()
{
    if( empty() ) return EMPTY_QUEUE;

    int firstItem = items_[head_];

    head_ = (head_+1) % capacity_;;
    size_--;
    return firstItem;
}

CircularQueue::QueueItem CircularQueue::peek() const
{
    if( empty() ) return EMPTY_QUEUE;
    else return items_[head_];
}

void CircularQueue::print() const
{
    for( int i = head_; i < size_; ++i )
    {
        cout << items_[i] << endl;
    }
}
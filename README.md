# Part 1: Dynamic Stack Implementation

# Purpose of this assignment:

In this project, you practice your knowledge about stack by implementing a data
type called dynamic stack. You need to use dynamically re-sizable array to implement it. (Note that ”dynamic” here means that the size of the array can change dynamically. It is different from the meaning of ”dynamic” in dynamic memory allocation.)
The header file dynamic-stack.h, which is explained below, provides the structure of the
DynamicStack class with declarations of member functions. Do not modify the signatures
of any of these functions. You need to implement all of the public member functions listed
in dynamic-stack.cpp

# Description:

The details of the header file dynamic-stack.h are as follows:
Defined using typedef, StackItem is the kind of data that the stack will contain. Being
public, it can be accessed directly as DynamicStack::StackItem.
StackItem EMPTY STACK is a static constant data member that will be used to indicate an
empty stack. (Note that any actual data value stored in the stack should not be the same
as this value.) Being public, it can be accessed directly as DynamicStack::EMPTY STACK.

# Member variables:

items : An array of stack items. (Note that in C++, an array name is a pointer to the first
element of the array.)
capacity : Maximum number of elements allowed in the current stack.
size : Current number of elements in the stack.
init capacity : Initial capacity of the array (i.e., the capacity used in the constructor).
This is used by pop() to determine if we should decrease the capacity.

# Constructors and Destructor:

DynamicStack(): Default constructor of the class DynamicStack. It uses 16 as the initial
capacity of the array and allocates the required memory space for the stack. The function
appropriately initializes the fields of the created empty stack.
DynamicStack(unsigned int capacity): Parametric constructor of the class DynamicStack. It allocates the required memory space for the stack of the given capacity. The
function appropriately initializes the fields of the created empty stack.
~DynamicStack(): Destructor of the class DynamicStack. It deallocates the memory space
allocated for the stack.

# Constant member functions:

int size() const: Returns the number of items in the stack.
bool empty() const: Returns true if the stack is empty and false otherwise.
void print() const: Prints the stack items sequentially and in order, from the top to the
bottom of the stack. (Note: it is mainly used to help you visualize the data. It will not be
used in any test cases for grading.)
StackItem peek() const: Returns the value at the top of the stack without removing it.
If the stack is empty, it returns the EMPTY STACK constant instead.
2

# Non-constant member functions:

void push(StackItem value): Takes as an argument a StackItem value. If the stack is
not full, the value is pushed onto the stack. Otherwise, the capacity of the stack is doubled,
and the item is then pushed onto the resized stack.
StackItem pop(): Removes and returns the top item from the stack as long as the stack is
not empty. If the number of items remaining in the stack after popping is less than or equal
to one quarter of the capacity of the array, then the array is halved. However, if the new
halved capacity is less than the initial capacity, then no resizing takes place. Finally, If the
stack is empty before the pop, the EMPTY STACK constant is returned

**Note**
All indexes must start with 0.
Attention, you will need to define the EMPTY STACK constant in your own dynamic-stack.cpp
file.


# Part 2: Circular Queue Implementation

# Purpose of this assignment:

In this project, you practice your knowledge about queue by implementing a data
type called Circular Queue. You need to use circular array to implement it. The
header file circular-queue.h, which is explained below, provides the structure of the
CircularQueue class with declarations of member functions. Do not modify the signatures of any of these functions. You need to implement all of the public member functions
listed in circular-queue.cpp


# Description:

The details of the header file circular-queue.h are as follows:
QueueItem defines the kind of data that the queue will contain. Being public, it can be
accessed directly as CircularQueue::QueueItem.
QueueItem EMPTY QUEUE defines a constant that will be used to indicate an empty queue.
(Note that any actual data value stored in the queue should not be the same as this value.)
Being public, it can be accessed directly as CircularQueue::EMPTY QUEUE.

# Member variables:

items : An array of queue items.
head : Index of the first element in the circular queue.
tail : Index of the element after the last item in the circular queue.
capacity : Maximum number of items in the queue.
size : Current number of items in the queue.

# Constructors and Destructor:

CircularQueue(): Default constructor of the class CircularQueue. It uses 16 as the capacity of the array and allocates the required memory space for the queue. The function
appropriately initializes the fields of the created empty queue.
CircularQueue(unsigned int capacity): Parametric constructor of the class CircularQueue.
It allocates the required memory space for the queue of the given capacity. The function
appropriately initializes the fields of the created empty queue.
~CircularQueue(): Destructor of the class CircularQueue. It deallocates the memory
space allocated for the queue’s items.

# Constant member functions:

int size() const: Returns the number of items in the queue.
bool empty() const: Returns true if the queue is empty, and false otherwise.
bool full() const: Returns true if the queue is full, and false otherwise.
void print() const: Prints the queue items sequentially and in order, from the front to
the rear of the queue. (Note: it is mainly used to help you visualize the data. It will not be
used in any test cases for grading.)
2
QueueItem peek() const: Returns the value at the front of the queue without removing it
from the queue. If the queue is empty, it returns the EMPTY QUEUE constant instead.
Non-constant member functions:
bool enqueue(QueueItem value): Takes as an argument a QueueItem value. If the queue
is not at capacity, it inserts the value at the rear of the queue after the last item, and returns
true. If the insertion fails due to lack of space, it returns false.
QueueItem dequeue(): Removes the item from the front of the queue and returns it. If the
queue is empty, it returns the EMPTY QUEUE constant instead.

**Note**
All indexes must start with 0.

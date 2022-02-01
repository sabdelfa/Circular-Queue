//
// Created by Rongbing Xu on 2020-07-03.
//

#ifndef BME122_A2_TEST_H
#define BME122_A2_TEST_H

#include "circular-queue.h"
#include "dynamic-stack.h"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class CircularQueueTest
{
public:
    // new empty queue is valid
    bool test1()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);

        ASSERT_TRUE(queue.size() == 0)
        ASSERT_TRUE(queue.empty())
        ASSERT_TRUE(!queue.full())
        return true;
    }

    // enqueue() an element on zero-element queues
    bool test2()
    {
        unsigned int capacity = 5;
        CircularQueue queue1(capacity);
        CircularQueue queue2(capacity);
        ASSERT_TRUE(queue1.enqueue(100))
        ASSERT_TRUE(queue2.enqueue(100))

        ASSERT_TRUE(queue1.size() == queue2.size() && queue1.size() == 1)
        ASSERT_TRUE(queue1.items_ != nullptr)
        ASSERT_TRUE(queue2.items_ != nullptr)
        ASSERT_TRUE(queue1.head_ == 0 && queue1.tail_ == 1)
        ASSERT_TRUE(queue2.head_ == 0 && queue2.tail_ == 1)
        return true;
    }

    // peek(), enqueue(), and dequeue() work properly
    bool test3()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);
        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(queue.enqueue(i*100))
        }

        ASSERT_TRUE(queue.size_ == queue.size() && queue.size_ == queue.capacity_ && queue.capacity_ == 5)
        ASSERT_TRUE(queue.head_ == 0)
        ASSERT_TRUE(queue.tail_ == 0)

        ASSERT_TRUE(queue.peek() == 0 && queue.peek() == queue.dequeue())
        ASSERT_TRUE(queue.peek() == 100 && queue.peek() == queue.dequeue())
        ASSERT_TRUE(queue.peek() == 200 && queue.peek() == queue.dequeue())
        ASSERT_TRUE(queue.peek() == 300 && queue.peek() == queue.dequeue())
        ASSERT_TRUE(queue.peek() == 400 && queue.peek() == queue.dequeue())

        return true;
    }

    // peek() and dequeue() on one-element queue
    bool test4()
    {
        unsigned int capacity = 5;
        CircularQueue queue1(capacity);
        CircularQueue queue2(capacity);
        ASSERT_TRUE(queue1.enqueue(100))
        ASSERT_TRUE(queue2.enqueue(100))
        ASSERT_TRUE(queue1.peek() == 100 && queue1.dequeue() == 100)
        ASSERT_TRUE(queue2.peek() == 100 && queue2.dequeue() == 100)

        ASSERT_TRUE(queue1.size_ == queue2.size_ && queue1.size_ == 0)
        ASSERT_TRUE(queue1.empty() && queue2.empty())
        return true;
    }

    // enqueue() too many elements should fail
    bool test5()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);
        // Fill up the list.
        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(queue.enqueue(i))
        }

        // Try overfilling (they should all return false with no modifications).
        int val_not_inserted = 100;
        ASSERT_FALSE(queue.enqueue(val_not_inserted))

        // Check size is correct.
        ASSERT_TRUE(queue.full() && !queue.empty())
        ASSERT_TRUE(queue.size_ == queue.capacity_ && queue.capacity_ == capacity)

        return true;
    }

    // enqueue() keeps changing tail
    bool test6()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);

        for (unsigned int i = 0; i < capacity - 1; i++) {
            ASSERT_TRUE(queue.enqueue(i))
            ASSERT_TRUE(queue.size_ == (i + 1))
            ASSERT_TRUE(queue.items_[queue.tail_ % capacity - 1] == i)
        }
        ASSERT_TRUE(queue.items_[4] == 4)

        return true;
    }

    // dequeue() keeps changing head
    bool test7()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);

        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(queue.enqueue(i))
        }

        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(queue.items_[queue.head_] == i && queue.dequeue() == i)
            ASSERT_TRUE(queue.size_ == (capacity - i - 1))
        }

        return true;
    }

    // try to dequeue() too many elements, then enqueue() a few elements
    bool test8()
    {
        unsigned int capacity = 5;
        const int num_elems = 4;
        CircularQueue queue(capacity);
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(queue.enqueue(i))
        }
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(queue.dequeue() == i)
        }

        ASSERT_TRUE(queue.peek() == queue.EMPTY_QUEUE && queue.dequeue() == queue.EMPTY_QUEUE)
        ASSERT_TRUE(queue.empty() && queue.size_ == 0)

        int expected_value = 1234;
        ASSERT_TRUE(queue.enqueue(expected_value))
        ASSERT_TRUE(queue.items_[queue.head_] == expected_value)
        return true;
    }

    // lots of enqueue() and dequeue(), all of them valid
    bool test9()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);

        ASSERT_TRUE(queue.enqueue(33))
        ASSERT_TRUE(queue.enqueue(44))
        ASSERT_TRUE(queue.enqueue(22))
        ASSERT_TRUE(queue.dequeue() == 33)
        ASSERT_TRUE(queue.dequeue() == 44)
        ASSERT_TRUE(queue.enqueue(88))
        ASSERT_TRUE(queue.dequeue() == 22)
        ASSERT_TRUE(queue.enqueue(99))

        ASSERT_TRUE(queue.peek() == 88 && queue.items_[queue.head_] == 88)
        ASSERT_TRUE(queue.items_[4] == 99)
        ASSERT_TRUE(queue.size() == queue.size_ && queue.size_ == 2)

        return true;
    }

    // lots of enqueue() and dequeue(), some of them invalid
    bool test10()
    {
        unsigned int capacity = 5;
        CircularQueue queue(capacity);

        ASSERT_TRUE(queue.dequeue() == queue.EMPTY_QUEUE && queue.peek() == queue.EMPTY_QUEUE)
        ASSERT_TRUE(queue.enqueue(33))
        ASSERT_TRUE(queue.enqueue(44))
        ASSERT_TRUE(queue.enqueue(22))
        ASSERT_TRUE(queue.enqueue(11))
        ASSERT_TRUE(queue.dequeue() == 33)
        ASSERT_TRUE(queue.dequeue() == 44)
        ASSERT_TRUE(queue.dequeue() == 22)
        ASSERT_TRUE(queue.enqueue(88))
        ASSERT_TRUE(queue.dequeue() == 11)
        ASSERT_TRUE(queue.dequeue() == 88)
        ASSERT_TRUE(queue.dequeue() == queue.EMPTY_QUEUE && queue.peek() == queue.EMPTY_QUEUE)
        ASSERT_TRUE(queue.enqueue(99))

        ASSERT_TRUE(queue.peek() == queue.items_[queue.head_])
        ASSERT_TRUE(queue.items_[queue.head_] == queue.items_[queue.tail_ - 1])
        ASSERT_TRUE(queue.items_[queue.tail_ - 1] == 99)

        return true;
    }
};

class DynamicStackTest
{
public:
    // new empty stack is valid
    bool test1()
    {
        unsigned int capacity = 5;
        DynamicStack stack(capacity);

        ASSERT_TRUE(stack.size() == 0)
        ASSERT_TRUE(stack.empty())
        return true;
    }

    // push() an element on zero-element stacks
    bool test2()
    {
        unsigned int capacity = 5;
        DynamicStack stack1(capacity);
        DynamicStack stack2(capacity);
        stack1.push(100);
        stack2.push(100);

        ASSERT_TRUE(stack1.size() == stack2.size() && stack1.size() == 1)
        ASSERT_TRUE(stack1.items_ != nullptr)
        ASSERT_TRUE(stack1.items_ != nullptr)
        ASSERT_TRUE(stack1.peek() == stack2.peek() && stack1.peek() == 100)
        return true;
    }

    // peek(), push(), and pop() work properly
    bool test3()
    {
        unsigned int capacity = 5;
        DynamicStack stack(capacity);
        for (unsigned int i = 0; i < capacity; i++) {
            stack.push(i*100);
        }

        ASSERT_TRUE(stack.size_ == stack.size() && stack.size_ == stack.capacity_ && stack.capacity_ == stack.init_capacity_ && stack.init_capacity_ == 5)

        ASSERT_TRUE(stack.peek() == 400 && stack.peek() == stack.pop())
        ASSERT_TRUE(stack.peek() == 300 && stack.peek() == stack.pop())
        ASSERT_TRUE(stack.peek() == 200 && stack.peek() == stack.pop())
        ASSERT_TRUE(stack.peek() == 100 && stack.peek() == stack.pop())
        ASSERT_TRUE(stack.peek() == 0 && stack.peek() == stack.pop())
        ASSERT_TRUE(stack.init_capacity_ == 5 && stack.capacity_ == 5 && stack.empty() && stack.size_ == 0)

        return true;
    }

    // peek() and pop() on one-element stack
    bool test4()
    {
        unsigned int capacity = 5;
        DynamicStack stack1(capacity);
        DynamicStack stack2(capacity);
        stack1.push(100);
        stack2.push(100);
        ASSERT_TRUE(stack1.init_capacity_ == 5 && stack1.capacity_ == 5 && stack1.size_ == 1)
        ASSERT_TRUE(stack2.init_capacity_ == 5 && stack2.capacity_ == 5 && stack2.size_ == 1)
        ASSERT_TRUE(stack1.peek() == 100 && stack1.pop() == 100)
        ASSERT_TRUE(stack2.peek() == 100 && stack2.pop() == 100)
        ASSERT_TRUE(stack1.init_capacity_ == 5 && stack1.capacity_ == 5 && stack1.empty() && stack1.size_ == 0)
        ASSERT_TRUE(stack2.init_capacity_ == 5 && stack2.capacity_ == 5 && stack2.empty() && stack2.size_ == 0)

        return true;
    }

    // push() too many elements should increase capacity
    bool test5()
    {
        unsigned int capacity = 3;
        DynamicStack stack(capacity);
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 3 && stack.empty() && stack.size_ == 0)
        // Fill up the list.
        for (unsigned int i = 0; i < capacity; i++) {
            stack.push(i*100);
        }

        int val_not_inserted = 300;
        stack.push(val_not_inserted);

        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 6 && stack.size_ == 4)

        return true;
    }

    // push() keeps changing size and capacity
    bool test6()
    {
        unsigned int capacity = 3;
        DynamicStack stack(capacity);

        for (unsigned int i = 0; i < 3; i++) {
            stack.push(i);
        }
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 3 && stack.size_ == 3)

        for (unsigned int i = 3; i < 6; i++) {
            stack.push(i);
        }
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 6 && stack.size_ == 6)

        for (unsigned int i = 6; i < 9; i++) {
            stack.push(i);
        }
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 12 && stack.size_ == 9)

        return true;
    }

    // pop() keeps changing size and capacity
    bool test7()
    {
        unsigned int capacity = 3;
        DynamicStack stack(capacity);

        for (unsigned int i = 0; i < 10; i++) {
            stack.push(i);
        }
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 12 && stack.size_ == 10)

        for (unsigned int i = 0; i < 7; i++) {
            stack.pop();
        }
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 6 && stack.size_ == 3)

        stack.pop();
        stack.pop();
        ASSERT_TRUE(stack.init_capacity_ == 3 && stack.capacity_ == 3 && stack.size_ == 1)

        return true;
    }

    // try to pop() too many elements, then push() a few elements
    bool test8()
    {
        unsigned int capacity = 5;
        const int num_elems = 4;
        DynamicStack stack(capacity);
        for (int i = 0; i < num_elems; i++) {
            stack.push(i);
        }
        for (int i = num_elems; i > 0; i--) {
            ASSERT_TRUE(stack.pop() == i - 1)
        }

        ASSERT_TRUE(stack.peek() == stack.EMPTY_STACK && stack.pop() == stack.EMPTY_STACK)
        ASSERT_TRUE(stack.empty() && stack.size_ == 0)

        int expected_value = 1234;
        stack.push(expected_value);
        ASSERT_TRUE(stack.items_[0] == expected_value)
        return true;
    }

    // lots of push() and pop(), all of them valid
    bool test9()
    {
        unsigned int capacity = 5;
        DynamicStack stack(capacity);

        stack.push(33);
        stack.push(44);
        stack.push(22);
        ASSERT_TRUE(stack.pop() == 22)
        ASSERT_TRUE(stack.pop() == 44)
        stack.push(88);
        ASSERT_TRUE(stack.pop() == 88)
        stack.push(99);

        ASSERT_TRUE(stack.peek() == 99 && stack.items_[1] == 99)
        ASSERT_TRUE(stack.items_[0] == 33)
        ASSERT_TRUE(stack.size() == stack.size_ && stack.size_ == 2)

        return true;
    }

    // lots of push() and pop(), some of them invalid
    bool test10()
    {
        unsigned int capacity = 5;
        DynamicStack stack(capacity);

        ASSERT_TRUE(stack.pop() == stack.EMPTY_STACK && stack.peek() == stack.EMPTY_STACK)
        stack.push(33);
        stack.push(44);
        stack.push(22);
        stack.push(11);
        ASSERT_TRUE(stack.pop() == 11)
        ASSERT_TRUE(stack.pop() == 22)
        ASSERT_TRUE(stack.pop() == 44)
        stack.push(88);
        ASSERT_TRUE(stack.pop() == 88)
        ASSERT_TRUE(stack.pop() == 33)
        ASSERT_TRUE(stack.pop() == stack.EMPTY_STACK && stack.peek() == stack.EMPTY_STACK)
        stack.push(99);

        ASSERT_TRUE(stack.peek() == stack.items_[0] && stack.items_[0] == 99)

        return true;
    }
};

#endif //BME122_A2_TEST_H

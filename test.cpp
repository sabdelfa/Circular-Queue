/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include <string>
#include "test.h"

using namespace std;

string get_status_str(bool status)
{
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main()
{
    int grade = 10;
    CircularQueueTest queue_test;
    DynamicStackTest stack_test;

    string queue_test_descriptions[10] = {
            "Test1: new empty queue is valid",
            "Test2: enqueue() an element on zero-element queues",
            "Test3: peek(), enqueue(), and dequeue() work properly",
            "Test4: peek() and dequeue() on one-element queue",
            "Test5: enqueue() too many elements should fail",
            "Test6: enqueue() keeps changing tail",
            "Test7: dequeue() keeps changing head",
            "Test8: try to dequeue() too many elements, then enqueue() a few elements",
            "Test9: lots of enqueue() and dequeue(), all of them valid",
            "Test10: lots of enqueue() and dequeue(), some of them invalid"
    };

    bool queue_test_results[10] = {false,false,false,false,false,false,false,false,false,false};
    queue_test_results[0] = queue_test.test1();
    queue_test_results[1] = queue_test.test2();
    queue_test_results[2] = queue_test.test3();
    queue_test_results[3] = queue_test.test4();
    queue_test_results[4] = queue_test.test5();
    queue_test_results[5] = queue_test.test6();
    queue_test_results[6] = queue_test.test7();
    queue_test_results[7] = queue_test.test8();
    queue_test_results[8] = queue_test.test9();
    queue_test_results[9] = queue_test.test10();

    cout << "CIRCULAR QUEUE TESTING RESULTS \n";
    cout << "******************************* \n";
    for (int i = 0; i < 10; ++i) {
        cout << queue_test_descriptions[i] << endl << get_status_str(queue_test_results[i]) << endl;
        if (queue_test_results[i]) grade += 4;
    }
    cout << endl << "Total grade: " << grade << endl << endl;

    grade += 10;

    string stack_test_descriptions[10] = {
            "Test1: new empty stack is valid",
            "Test2: push() an element on zero-element stacks",
            "Test3: peek(), push(), and pop() work properly",
            "Test4: peek() and pop() on one-element stack",
            "Test5: push() too many elements should increase capacity",
            "Test6: push() keeps changing size and capacity",
            "Test7: pop() keeps changing size and capacity",
            "Test8: try to pop() too many elements, then push() a few elements",
            "Test9: lots of push() and pop(), all of them valid",
            "Test10: lots of push() and pop(), some of them invalid"
    };

    bool stack_test_results[10] = {false,false,false,false,false,false,false,false,false,false};
    stack_test_results[0] = stack_test.test1();
    stack_test_results[1] = stack_test.test2();
    stack_test_results[2] = stack_test.test3();
    stack_test_results[3] = stack_test.test4();
    stack_test_results[4] = stack_test.test5();
    stack_test_results[5] = stack_test.test6();
    stack_test_results[6] = stack_test.test7();
    stack_test_results[7] = stack_test.test8();
    stack_test_results[8] = stack_test.test9();
    stack_test_results[9] = stack_test.test10();

    cout << "DYNAMIC STACK TESTING RESULTS \n";
    cout << "********************************** \n";
    for (int i = 0; i < 10; ++i) {
        cout << stack_test_descriptions[i] << endl << get_status_str(stack_test_results[i]) << endl;
        if (stack_test_results[i]) grade += 4;
    }
    cout << endl << "Total grade: " << grade << endl << endl;
}
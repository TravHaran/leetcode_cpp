#include <iostream>
#include <vector>

// implement a fixed-size circular buffer

class fixedCircBuffer {
public:

    class PeekEmptyBufferException : public std::runtime_error {
        public:
            PeekEmptyBufferException() : std::runtime_error("attempted to peek an empty buffer LOL") {}
    };

    std::vector<int> buffer;
    int start;
    int end;

    fixedCircBuffer(int bufferSize) {
        // initialize buffer in empty state
        start = -1;
        end = -1;
        buffer = std::vector<int>(bufferSize);
    }

    int peek() {
        if (isEmpty()) throw PeekEmptyBufferException();
        return buffer[start];
    }

    void pop() {
        // if the buffer is empty we dont need to do anything
        if (isEmpty()) return;
        // if we have exactly one element in the buffer and we pop
        // then we must revert back to the empty state of the queue
        if (start == end){
            start = -1;
            end = -1;
        }
        else start = start + 1 % buffer.size();
    }

    void push(int n) {
        // if buffer is full then we need to increment our start
        // this will maintian the fixed buffer property
        if (isFull())
            start = start + 1 % buffer.size();
        // if queue is empty then  both are start and end are set to -1
        // so we need to increment start so that it points to the first element that just got pushed
        if (isEmpty())
            start++;
        end = end + 1 % buffer.size();
        buffer[end] = n;
    }

    bool isEmpty() {
        // if buffer is empty both start and end will be set to -1
        // so we can just return if either of them is -1
        return start == -1;
    }

    bool isFull() {
        // if the next index after end is equal to start then our buffer is full
        return (end + 1) % buffer.size() == start;
    }

    int getCapacity() {
        return buffer.size();
    }
};

// To execute C++, please define "int main()"
int main() {
    fixedCircBuffer a(4);
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    // buffer state should now be 10, 20, 30, 40
    a.pop();
    // buffer state should now be 20, 30, 40
    std::cout << a.peek() << std::endl;
    a.pop();
    // buffer state should now be 30, 40
    std::cout << a.peek() << std::endl;
    // now we will push past the buffer size
    a.push(50);
    a.push(60);
    a.push(70);
    // buffer state should now be 40, 50 60 70
    std::cout << a.peek() << std::endl;
    a.pop();
    a.pop();
    a.pop();
    // buffer state should now be 70
    std::cout << a.peek() << std::endl;
    a.pop();
    // buffer state should now be empty
    std::cout << a.peek() << std::endl; // this should throw error
    return 0;
}
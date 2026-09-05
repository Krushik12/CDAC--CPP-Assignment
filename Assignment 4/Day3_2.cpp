//============================================================================
// Name        : Ques3_2.cpp
// Author      : Krushik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <typename T>
class DataBuffer {
private:

    T* data;
    int capacity;
    int head;
    int tail;
    int count;

public:
    DataBuffer(int capacity)
        : capacity(capacity),
          head(0),
          tail(0),
          count(0)
    {
        data = new T[capacity];
    }

    ~DataBuffer() {
        delete[] data;
    }

    void push(const T& value) {

        data[tail] = value;

        tail = (tail + 1) % capacity;

        if (count < capacity) {
            count++;
        }
        else {
            head = (head + 1) % capacity;
        }
    }

    T pop() {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }
    T peek() const {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        return data[head];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }
    template <typename U>
        friend ostream& operator<<(ostream& out,
                                   const DataBuffer<U>& buf);

};
template <typename U>ostream& operator<<(ostream& out,
                               const DataBuffer<U>& buf) {

        out << "[";

        for (int i = 0; i < buf.count; i++) {

            int head = (buf.head + i) % buf.capacity;

            out << buf.data[head];

            if (i < buf.count - 1) {
                out << ", ";
            }
        }

        out << "]";

        return out;
    }



int main() {

	    // Integer buffer
	    DataBuffer<int> tickBuffer(5);

	    for (int i = 1; i <= 7; i++) {
	        tickBuffer.push(i * 10);
	    }

	    cout << "Tick Buffer: "
	         << tickBuffer << endl;


	    // Double buffer
	    DataBuffer<double> tempBuffer(4);

	    tempBuffer.push(36.6);
	    tempBuffer.push(37.1);
	    tempBuffer.push(38.2);
	    tempBuffer.push(36.9);

	    cout << "Before pop: "
	         << tempBuffer << endl;

	    cout << "Popped: "
	         << tempBuffer.pop() << endl;

	    cout << "After pop: "
	         << tempBuffer << endl;


	    // String buffer
	    DataBuffer<string> logBuffer(3);

	    logBuffer.push("INFO: Server started");
	    logBuffer.push("WARN: High memory usage");
	    logBuffer.push("ERROR: DB connection timeout");
	    logBuffer.push("INFO: Retry successful");

	    cout << "Log Buffer: "
	         << logBuffer << endl;


	    return 0;
}


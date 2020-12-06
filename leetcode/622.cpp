class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int last, first, len;
    bool empty;
    int arr[1010];
    MyCircularQueue(int k) {
        len = k;
        first = last = 0;
        empty = true;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(last == first && !empty)return false;
        arr[last] = value;
        empty = false;
        last++;
        if(last == len)last = 0;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(last == first && empty)return false;
        // if(last == first){empty = true; return true;}
        first++;
        if(first == len)first = 0;
        if(last == first)empty = true;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(empty)return -1;
        return arr[first];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(empty)return -1;
        return arr[(last+len-1)%len];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(empty)return true;
        else return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(last == first && !empty)return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


#include <iostream>


template<class T> 
class Queue {
public:
    struct Item {
        Item * next = nullptr;
        T value;
    };

    void enque(T item)
    {
        Item * i = new Item();
        i->value = item;
        i->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = i;
        }
        else {
            rear->next = i;
            rear = i;
        }
    }

    T deque()
    {
        if (front == nullptr) {
            throw std::out_of_range ("no elements");
        }
        
        Item * temp = front;
        T toReturn = temp->value;

        front = front->next;
        delete temp;
        return toReturn;
    }

    bool empty()
    {
        return front == nullptr;
    }

private:
    Item * front = nullptr;
    Item * rear = nullptr;
};



int main()
{
    
    Queue<int> queue;
    queue.enque(10);
    queue.enque(20);
    queue.enque(30);
    queue.enque(40);
    queue.enque(50);

    while (! queue.empty())
    {
        auto item = queue.deque();
        std::cout << item << "\n";
    }
       
}
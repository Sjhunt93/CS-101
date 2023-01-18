#include <iostream>

template<class T> 
class Stack {
public:
    struct Item {
        Item * next = nullptr;
        T value;
    };

    void push(T item)
    {
        Item * i = new Item();
        i->value = item;
        i->next = top;

        top = i;
    }

    T pop()
    {
        if (top == nullptr) {
            throw std::out_of_range ("no elements");
        }
        
        Item * temp = top;
        T toReturn = temp->value;

        top = top->next;
        delete temp;
        return toReturn;    
    }

    bool empty()
    {
        return top == nullptr;
    }
private:
    Item * top = nullptr;
};



int main()
{
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.pop();
    stack.push(50);
    stack.push(80);
    
    while (! stack.empty())
    {
        auto item = stack.pop();
        std::cout << item << "\n";
    }
       
}
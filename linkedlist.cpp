#include <iostream>


class List {
public:
    struct Node {
        Node * next = nullptr;
        int value = 0;
    };

    ~List()
    {
        Node * current = start;
        while (current != nullptr) {
            std::cout << "deleting node: " << &(*current) << "\n";
            Node * temp = current;
            current = current->next;
            delete temp;
        }        
    }

    void push(int value)
    {
        Node * n = new Node();
        n->value = value;
        if (start == nullptr)
        {
            start = n;
            end = n;
        }
        else {
            end->next = n;
            end = n;
        }    
    }

    void delete_node(Node * node)
    {
        Node * prev = start;
        if (node == start) {
            start = start->next;
             
        }
        else {
            Node * current = prev->next;
            while (current != nullptr && current != node)
            {
                prev = current;
                current = current->next;
            }
            // current is now what we want to delete
            // [-prev-] -> [-current-] -> [-next-]
            // [-prev-] ----------------> [-next-]s

            if (current == end) {
                end = prev;
                end->next = nullptr;
            }
            else {
                prev->next = current->next;
            }
   
        }
        delete node;
    }

    void insert_after(Node * node, int value) 
    {
        Node * itr = start;

        if (node == end) { 
            push(value);
        }
        while (itr != node && itr != nullptr) {

            itr = itr->next;
        }
        if (itr == nullptr) {
            // error
        }
        else {
            Node * temp = itr->next; //unlink next
            Node * n = new Node();
            n->value = value;

            itr->next = n;
            n->next = temp;
        }
    }

    Node * find(int value) 
    {
        Node * current = start;
        while (current != nullptr)
        {
            if (current->value == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node * get_start()
    {
        return start;
    }

    Node * get_end()
    {
        return end;
    }
private:
    Node * start = nullptr;
    Node * end = nullptr;

};

int main()
{
    List list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);

    List::Node * middle = list.get_start()->next->next;
    list.delete_node(middle);

    list.insert_after(list.get_start()->next, 25);
    


    List::Node * start = list.get_start();
    while (start != nullptr)
    {
        std::cout << "Node: " << &(*start) << " has value " << start->value << "\n";
        start = start->next;
    }
    
}
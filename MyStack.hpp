// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class T, class FRIEND>
class ListNode              // узел списка
{
private:
    T d;                    // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка

    ListNode() : next(nullptr) {} // конструктор по умолчанию
    ListNode(T d_, ListNode* top) : d(d_), next(top) {} // конструктор с параметрами
    
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class T>
class MyStack {
private:
    typedef class ListNode<T, MyStack<T>> Node;
    Node *top;
public:
    MyStack() : top(nullptr) {}          // конструктор
    ~MyStack() {                         // освободить динамическую память
        while (!empty()) {
            pop();
        }
    }
    bool empty() { return (top == nullptr); } // стек пустой?
    
    bool push(T n) {
        top = new Node(n, top);
        return true;
    }       // добавить узел в вершину стека
    
    bool pop() {          // удалить узел из вершины стека
        if (empty()) return false;
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }
    
    T top_inf() { return top->d; }      // считать информацию из вершины стека

    
    void copyFrom(const MyStack& other) {
        if (other.top == nullptr) {
            top = nullptr;
            return;
        }

        top = new Node(other.top->d, nullptr);
        Node* current = top;
        Node* otherCurrent = other.top->next;

        while (otherCurrent != nullptr) {
            current->next = new Node(otherCurrent->d, nullptr);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        current->next = nullptr;
    }

    MyStack(const MyStack& other) : top(nullptr) {
        copyFrom(other);
    }
    
    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            while (!empty()) {
                pop();
            }
            copyFrom(other);
        }
        return *this;
    }

    void print(){
        Node *a = top; 
        while (a->next != nullptr){
            std::cout << a->d << ' ';
            a = a->next;
        }
        std::cout << a->d << ' ';
    }
};



#endif
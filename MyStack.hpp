// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class T, class FRIEND>
class ListNode              // узел списка
{
private:
    T d;                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка

    ListNode(void) { next = nullptr; } //конструктор
    ListNode(T d_, ListNode* top) {
        this->d = d_;
        this->next = top;
    }
    
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class T>
class MyStack {
private:
    typedef class ListNode<T, MyStack<T>> Node;
    Node *top;
public:
    MyStack(void) {
        top = nullptr;
    };           // конструктор
    ~MyStack(void){
        if (!= nullptr){
            delete &low->next;
        }
    };          // освободить динамическую память
    bool empty(void) {
        return (top == nullptr);
    }        // стек пустой?
    bool push(T n); {
        Node a = new Node(n, top);
        top = a;
        return 0;
    }       // добавить узел в вершину стека
    bool pop(void){
        if (!empty()){
            Node *a = this->&top->next;
            delete this->&top;
            top = a;
            return 0;
        }
        else{
            return 1;
        }
    };          // удалить узел из вершины стека
    T top_inf(void){
        return top->d;
    };      // считать информацию из вершины стека

};

#endif
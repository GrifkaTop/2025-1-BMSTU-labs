#include "article.hpp"
#include "my_vector.hpp"
#include <iostream>
#include <limits>

using namespace std;

void print(MyVector<Article*>& container) {
    for (size_t i = 0; i < container.get_size(); ++i) {
        cout << "[" << i << "] ";
        container[i]->show();
    }
}

void remove(MyVector<Article*>& container, size_t index) {
    if (index >= container.get_size()) {
        cout << "Invalid index!" << endl;
        return;
    }
    delete container[index];
    container.delete_element(index);
    cout << "Item removed" << endl;
}

void clear(MyVector<Article*>& container) {
    for (size_t i = 0; i < container.get_size(); ++i) {
        delete container[i];
    }
    container.clear();
    cout << "Container cleared" << endl;
}

int main() {
    MyVector<Article*> container;

    container.add_element(new Dairy((char*) "Yogurt", (char*) "2023-10-15", 14));
    container.add_element(new Bear((char*) "Teddy", 3, (char*) "brown"));
    container.add_element(new Dairy((char*) "Cheese", (char*) "2023-10-20", 30));
    container.add_element(new Bear((char*) "Paddington", 5, (char*) "blue"));

    print(container);
    cout << '\n';
    remove(container, 1);
    print(container);
    cout << '\n';
    clear(container);
    print(container);
    cout << '\n';
}
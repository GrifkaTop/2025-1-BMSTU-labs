#include "article.hpp"
#include "myvector.hpp"
#include <iostream>
#include <limits>

using namespace std;

void print(Vector<Article*>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        cout << "[" << i << "] ";
        container[i]->show();
    }
}

void remove(Vector<Article*>& container, size_t index) {
    if (index >= container.size()) {
        cout << "Invalid index!" << endl;
        return;
    }
    delete container[index];
    container.erase(index);
    cout << "Item removed" << endl;
}

void clear(Vector<Article*>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        delete container[i];
    }
    container.clear();
    cout << "Container cleared" << endl;
}

int main() {
    Vector<Article*> container;

    // Демонстрационный режим
    container.push_back(new Dairy("Yogurt"));
    container.push_back(new Bear("Teddy"));
    container.push_back(new Dairy("Cheese"));
    container.push_back(new Bear("Paddington"));
    print(container);

    remove(container, 1);
    print(container);

    clear(container);
    print(container);
}
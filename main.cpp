#include <iostream>
#include <string>
#include "my_vector.h"
#include "my_set.h"

// Test MyVector functionality
template <typename T>
void testMyVector() {
    std::cout << "\n=== Testing MyVector with type " << typeid(T).name() << " ===" << std::endl;
    
    // Create a vector
    MyVector<T> vec;
    std::cout << "Initial max_size: " << vec.get_max_size() << std::endl;
    
    // Add elements
    for (int i = 1; i <= 10; i++) {
        vec.add_element(static_cast<T>(i));
        std::cout << "Added element " << i << ", size: " << vec.get_size() 
                  << ", max_size: " << vec.get_max_size() << std::endl;
    }
    
    // Access elements
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.get_size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    // Find element
    T element = static_cast<T>(5);
    int index = vec.find(element);
    std::cout << "Find element " << element << ": index = " << index << std::endl;
    
    // Delete element
    vec.delete_element(4);  // Delete the 5th element (index 4)
    std::cout << "After deleting element at index 4, size: " << vec.get_size() 
              << ", max_size: " << vec.get_max_size() << std::endl;
    
    // Print elements after deletion
    std::cout << "Elements after deletion: ";
    for (size_t i = 0; i < vec.get_size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    // Copy constructor
    MyVector<T> vec2 = vec;
    std::cout << "Copied vector elements: ";
    for (size_t i = 0; i < vec2.get_size(); i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    
    // Assignment operator
    MyVector<T> vec3;
    vec3 = vec;
    std::cout << "Assigned vector elements: ";
    for (size_t i = 0; i < vec3.get_size(); i++) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;
}

// Test MySet functionality
template <typename T>
void testMySet() {
    std::cout << "\n=== Testing MySet with type " << typeid(T).name() << " ===" << std::endl;
    
    // Create sets
    MySet<T> set1;
    for (int i : {1, 4, 5, 6}) {
        set1.add_element(static_cast<T>(i));
    }
    
    MySet<T> set2;
    for (int i : {1, 2, 3, 4}) {
        set2.add_element(static_cast<T>(i));
    }
    
    std::cout << "Set1: " << set1 << std::endl;
    std::cout << "Set2: " << set2 << std::endl;
    
    // Test is_element
    std::cout << "Is 4 in Set1? " << (set1.is_element(static_cast<T>(4)) ? "Yes" : "No") << std::endl;
    std::cout << "Is 7 in Set1? " << (set1.is_element(static_cast<T>(7)) ? "Yes" : "No") << std::endl;
    
    // Test union
    MySet<T> unionSet = set1 + set2;
    std::cout << "Union (Set1 + Set2): " << unionSet << std::endl;
    
    // Test intersection
    MySet<T> intersectionSet = set1 * set2;
    std::cout << "Intersection (Set1 * Set2): " << intersectionSet << std::endl;
    
    // Test difference
    MySet<T> differenceSet = set1 - set2;
    std::cout << "Difference (Set1 - Set2): " << differenceSet << std::endl;
    
    // Test compound operators
    MySet<T> set3 = set1;
    set3 += set2;
    std::cout << "Set3 (Set1 += Set2): " << set3 << std::endl;
    
    MySet<T> set4 = set1;
    set4 *= set2;
    std::cout << "Set4 (Set1 *= Set2): " << set4 << std::endl;
    
    MySet<T> set5 = set1;
    set5 -= set2;
    std::cout << "Set5 (Set1 -= Set2): " << set5 << std::endl;
    
    // Test equality
    std::cout << "Is Set1 == Set2? " << (set1 == set2 ? "Yes" : "No") << std::endl;
    std::cout << "Is Set3 == unionSet? " << (set3 == unionSet ? "Yes" : "No") << std::endl;
    
    // Test add and delete
    set5.add_element(static_cast<T>(10));
    std::cout << "Set5 after adding 10: " << set5 << std::endl;
    
    set5.delete_element(static_cast<T>(10));
    std::cout << "Set5 after deleting 10: " << set5 << std::endl;
}

// Specialization for std::string to demonstrate template flexibility
template <>
void testMySet<std::string>() {
    std::cout << "\n=== Testing MySet with type std::string ===" << std::endl;
    
    // Create sets
    MySet<std::string> set1;
    set1.add_element("apple");
    set1.add_element("banana");
    set1.add_element("cherry");
    set1.add_element("date");
    
    MySet<std::string> set2;
    set2.add_element("apple");
    set2.add_element("banana");
    set2.add_element("fig");
    set2.add_element("grape");
    
    std::cout << "Set1: " << set1 << std::endl;
    std::cout << "Set2: " << set2 << std::endl;
    
    // Test is_element
    std::cout << "Is 'apple' in Set1? " << (set1.is_element("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'kiwi' in Set1? " << (set1.is_element("kiwi") ? "Yes" : "No") << std::endl;
    
    // Test union
    MySet<std::string> unionSet = set1 + set2;
    std::cout << "Union (Set1 + Set2): " << unionSet << std::endl;
    
    // Test intersection
    MySet<std::string> intersectionSet = set1 * set2;
    std::cout << "Intersection (Set1 * Set2): " << intersectionSet << std::endl;
    
    // Test difference
    MySet<std::string> differenceSet = set1 - set2;
    std::cout << "Difference (Set1 - Set2): " << differenceSet << std::endl;
}

int main() {
    std::cout << "Testing MyVector and MySet template classes" << std::endl;
    
    // Test with different types
    testMyVector<int>();
    testMyVector<double>();
    
    testMySet<int>();
    testMySet<double>();
    testMySet<std::string>();
    
    return 0;
}

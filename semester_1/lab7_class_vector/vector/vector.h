#pragma once
#include <iostream>
#include <initializer_list>
class Vector {
private:
    int* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void reallocate(size_t new_capacity);

public:
    Vector();
    
    explicit Vector(size_t size);
    
    Vector(std::initializer_list<int> init_list);
    
    Vector(const Vector& other);
    
    Vector& operator=(const Vector& other);
    
    ~Vector();
    
    void Swap(Vector& other);
    
    int& operator[](size_t index);
    
    const int& operator[](size_t index) const;
    
    size_t Size() const;

    size_t Capacity() const;
    
    void PushBack(int value);
    
    void PopBack();
    
    void Clear();
    
    void Reserve(size_t new_capacity);
    
    
};

std::ostream& operator<<(std::ostream& os, const Vector& vec);

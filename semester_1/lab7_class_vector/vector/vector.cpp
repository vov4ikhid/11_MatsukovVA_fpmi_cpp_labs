#include "vector.h"

Vector::Vector() = default;

Vector::Vector(size_t size) : size_(size), capacity_(size) {
    if (size > 0) {
        data_ = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data_[i] = 0;
        }
    }
}

Vector::Vector(std::initializer_list<int> list) : size_(list.size()), capacity_(list.size()) {
    if (size_ > 0) {
        data_ = new int[size_];
        size_t i = 0;
        for (int num : list) {
            data_[i] = num;
            ++i;
        }
    }
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

Vector::~Vector() {
    delete[] data_;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        Vector temp(other);
        
        int* temp_data = data_;
        data_ = temp.data_;
        temp.data_ = temp_data;
        
        size_t temp_size = size_;
        size_ = temp.size_;
        temp.size_ = temp_size;
        
        size_t temp_cap = capacity_;
        capacity_ = temp.capacity_;
        temp.capacity_ = temp_cap;
    }
    return *this;
}

int& Vector::operator[](size_t index) {
    return data_[index];
}

const int& Vector::operator[](size_t index) const {
    return data_[index];
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int value) {
    if (size_ >= capacity_) {
        size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
        Reserve(new_cap);
    }
    data_[size_] = value;
    ++size_;
}

void Vector::PopBack() {
    if (size_ > 0) {
        --size_;
    }
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity) {
    if (new_capacity <= capacity_) {
        return;
    }
    
    int* new_data = new int[new_capacity];
    
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

void Vector::Swap(Vector& other) {
    int* temp_data = data_;
    data_ = other.data_;
    other.data_ = temp_data;
    
    size_t temp_size = size_;
    size_ = other.size_;
    other.size_ = temp_size;
    
    size_t temp_cap = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = temp_cap;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (size_t i = 0; i < vec.Size(); ++i) {
        os << vec[i];
        if (i + 1 != vec.Size()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
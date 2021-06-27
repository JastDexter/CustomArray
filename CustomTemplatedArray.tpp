#include "CustomTemplatedArray.h"
#include <cstdlib>
#include <vector>

template<typename Data>
CustomTemplatedArray<Data>::CustomTemplatedArray(int size) {
    _size = size;
    _array = (Data *) malloc(sizeof(Data) * _size);
}

template<typename Data>
CustomTemplatedArray<Data>::CustomTemplatedArray(const CustomTemplatedArray<Data> &array) {
    _size = array._size;
    _array = (Data *) malloc(sizeof(Data) * _size);
    memcpy_s(_array, _size* sizeof(Data), array._array, array._size* sizeof(Data));
}

template<typename Data>
int CustomTemplatedArray<Data>::size() const {
    return _size;
}

template<typename Data>
bool CustomTemplatedArray<Data>::operator==(const CustomTemplatedArray &rhs) const {
    if (_array == rhs._array)
        return true;
    if (_size != rhs._size)
        return false;

    for (long i = 0; i < size(); ++i) {
        if (*(_array + i) != *(rhs._array + i))
            return false;
    }
    return true;
}

template<typename Data>
bool CustomTemplatedArray<Data>::operator!=(const CustomTemplatedArray &rhs) const {
    return !(rhs == *this);
}

template<typename Data>
Data &CustomTemplatedArray<Data>::operator[](const long id) const{
    return *(_array + id);
}

template<typename Data>
Data &CustomTemplatedArray<Data>::operator[](long id) {
    return *(_array + id);
}

template<typename Data>
CustomTemplatedArray<Data>::~CustomTemplatedArray() {
    free(_array);
    _size = 0;
}
template<typename Data>
std::ostream &operator<<(std::ostream &os, const CustomTemplatedArray<Data> array) {
    os << "_array: " << array._array;
    return os;
}
/*
template<typename Data>
CustomTemplatedArray<Data>::CustomTemplatedArray(Data *array) {
    _size = sizeof(array) / sizeof(*array);
    _array = (Data *) malloc(sizeof(array));
    memcpy_s(_array, sizeof(array), array, sizeof(array));
}

template<typename Data>
CustomTemplatedArray<Data>::CustomTemplatedArray(const Data *array) {
    _size = sizeof(array) / sizeof(*array);
    _array = (Data *) malloc(sizeof(array));
    memcpy_s(_array, _size* sizeof(Data), array, _size* sizeof(Data));
}

*/
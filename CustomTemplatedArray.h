#ifndef CUSTOMARRAY_CUSTOMTEMPLATEDARRAY_H
#define CUSTOMARRAY_CUSTOMTEMPLATEDARRAY_H

template<typename Data>
class CustomTemplatedArray {
private:
    Data *_array = nullptr;
    long _size = 0;
public:
    CustomTemplatedArray() = default;
    explicit CustomTemplatedArray(int size);
/*    explicit CustomTemplatedArray(Data* array);
    explicit CustomTemplatedArray(const Data* array);*/
    CustomTemplatedArray(CustomTemplatedArray<Data> const &array);

    bool operator==(const CustomTemplatedArray &rhs) const;

    bool operator!=(const CustomTemplatedArray &rhs) const;

    Data &operator[](long id) const;
    Data &operator[](long id);

    friend std::ostream &operator<<(std::ostream &os, const CustomTemplatedArray &array);

    int size() const;

    virtual ~CustomTemplatedArray();
};

#include <ostream>
#include "CustomTemplatedArray.tpp"

#endif
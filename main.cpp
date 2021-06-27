#include <iostream>
#include "CustomTemplatedArray.h"

int main() {
    CustomTemplatedArray<int> arr = CustomTemplatedArray<int>(2);
    arr[0] = 1;
    arr[1] = 0;
    auto arr2 = CustomTemplatedArray<int>(2);
    arr2[0] = 1;
    arr2[1] = 0;
    std::cout << "Hello, World!" << arr[0] << arr2[0] << (arr == arr2) << std::endl;
    return 0;
}

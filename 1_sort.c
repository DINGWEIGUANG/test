#include <stdio.h>
#include <stdbool.h>

// 比较函数指针的类型
typedef int (*CompareFunc)(void *, void *);

// 交换两个元素的值
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// 冒泡排序函数
void bubbleSort(void *arr, size_t numElements, size_t size, CompareFunc compare) {
    for (size_t i = 0; i < numElements - 1; i++) {
        for (size_t j = 0; j < numElements - i - 1; j++) {
            void *element1 = (char *)arr + j * size;
            void *element2 = (char *)arr + (j + 1) * size;
            
            if (compare(element1, element2) > 0) {
                swap(element1, element2, size);
            }
        }
    }
}

// 示例比较函数，用于比较整数
int compareInt(void *a, void *b) {
    int *intA = (int *)a;
    int *intB = (int *)b;
    return (*intA - *intB);
}

//用于比较字符
char compareChar(void *a,void *b){
    char *charA = (char *)a;
    char *charB = (char *)b;
    return (*charA - *charB);
}

int main() {
    int intArray[] = {5, 2, 9, 1, 5, 6};
    size_t numElements = sizeof(intArray) / sizeof(intArray[0]);

    bubbleSort(intArray, numElements, sizeof(intArray[0]), compareInt);

    for (size_t i = 0; i < numElements; i++) {
        printf("%d ", intArray[i]);
    }

    return 0;
}

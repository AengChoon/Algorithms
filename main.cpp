#include <algorithm>

#include "Sort/BubbleSort.h"
#include "Sort/SelectionSort.h"

int main()
{
    int c[] {5,4,3,2,1};
    BubbleSort(std::begin(c), std::end(c));
}

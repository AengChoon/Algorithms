#include <algorithm>
#include "Sort/MergeSort.h"

int main()
{
    int c[] {5,4,3,2,1};
    MergeSort(std::begin(c), std::end(c));
}

//
// Created by kurchin ilya on 18.12.2025.
//

#include <iostream>

void quickOutput (float* fractionalNumbers) {
    for (int i = 0; i < 15; i++) {
        std::cout << fractionalNumbers[i] << " ";
    }
}
void bubblesort(float* l, float* r)  {
    int sz = r - l;
    if (sz <= 1) return;
    bool b = true;
    while (b) {
        b = false;
        for (float* i = l; i + 1 < r; i++) {
            if (*i < *(i + 1)) {
                std::swap(*i, *(i + 1));
                b = true;
            }
        }
        r--;
    }
}
void shakersort(float* l, float* r) {
    int sz = r - l;
    if (sz <= 1) return;
    bool b = true;
    float* beg = l - 1;
    float* end = r - 1;
    while (b) {
        b = false;
        beg++;
        for (float* i = beg; i < end; i++) {
            if (*i < *(i + 1)) {
                std::swap(*i, *(i + 1));
                b = true;
            }
        }
        if (!b) break;
        end--;
        for (float* i = end; i > beg; i--) {
            if (*i > *(i - 1)) {
                std::swap(*i, *(i - 1));
                b = true;
            }
        }
    }
}
void combsort(float* l, float* r) {
    int sz = r - l;
    if (sz <= 1) return;
    double k = 1.2473309;
    int step = sz - 1;
    while (step > 1) {
        for (float* i = l; i + step < r; i++) {
            if (*i < *(i + step))
                std::swap(*i, *(i + step));
        }
        step /= k;
    }
    bool b = true;
    while (b) {
        b = false;
        for (float* i = l; i + 1 < r; i++) {
            if (*i < *(i + 1)) {
                std::swap(*i, *(i + 1));
                b = true;
            }
        }
    }
}


int main () {
    float fractionalNumbers[15] {1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};
    std::cout << "A previously created sequence of real numbers:\n";
    quickOutput (fractionalNumbers);

    std::string ask;
    std::cout << "\n\nIf you want to enter array elements from the keyboard, press Y/y, else print N/n: ";
    std::cin >> ask;
    if (ask == "Y" || ask == "y") {
        std::cout << "\nStart typing: ";
        for (int i = 0; i < 15; i++) {
            std::cin >> fractionalNumbers[i];
        }
        std::cout << "\nYour sequence:\n";
        quickOutput (fractionalNumbers);
    } else {
        std::cout << "You have decided to keep the original sequence.\n";
    }

    int n = sizeof(fractionalNumbers)/sizeof(fractionalNumbers[0]);
    bubblesort(fractionalNumbers, fractionalNumbers + n);

    std::cout << "\n\nThe array is sorted using bubble sort from largest to smallest:\n";
    quickOutput (fractionalNumbers);

    shakersort(fractionalNumbers, fractionalNumbers + n);

    std::cout << "\n\nThe array is sorted using shake sort from largest to smallest:\n";
    quickOutput (fractionalNumbers);

    combsort(fractionalNumbers, fractionalNumbers + n);
    std::cout << "\n\nThe array is sorted using the comb method from largest to smallest:\n";
    quickOutput(fractionalNumbers);




}
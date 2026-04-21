#include <iostream>

template <class Iterator>
bool IsTwiceSequence(Iterator first, Iterator last) {
    Iterator slow = first;
    Iterator fast = first;

    while (fast != last) {
        ++fast;
        if (fast == last) {
            return false;
        }
        ++fast;
        ++slow;
    }

    Iterator first_half = first;
    Iterator second_half = slow;

    while (second_half != last) {
        if (!(*first_half == *second_half)) {
            return false;
        }
        ++first_half;
        ++second_half;
    }

    return true;
}

int main(int, char**) {
    const char s1[] = "abcdabcd";
    const char s2[] = "abcdabdc";
    int a[] = {1, 2, 3, 4, 1, 2, 3, 4};
    bool b[] = {true, false, true};

    std::cout << IsTwiceSequence(s1, s1 + 8) << '\n';
    std::cout << IsTwiceSequence(s2, s2 + 8) << '\n';
    std::cout << IsTwiceSequence(a, a + 8) << '\n';
    std::cout << IsTwiceSequence(b, b + 3) << '\n';

    return 0;
}
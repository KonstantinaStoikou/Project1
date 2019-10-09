#include <iostream>
#include "../include/read_functions.h"

int main(int argc, char const *argv[]) {
    if (read_vectors_file(
            "../sample datasets/vectors/siftsmall/input_small_id") < 0) {
        std::cout << "errpor";
    }
    return 0;
}

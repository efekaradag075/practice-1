#include <iostream>

namespace karadag {

int run_aft_max() {
    long long val = 0;
    long long max_val = 0;
    int count_since_max = 0;
    bool has_elements = false;

    while (std::cin >> val) {
        if (val == 0) {
            break;
        }

        if (!has_elements) {
            has_elements = true;
            max_val = val;
            count_since_max = 0;
        } else {
            if (val > max_val) {
                max_val = val;
                count_since_max = 0;
            } else {
                count_since_max++;
            }
        }
    }

    // Ошибка ввода (не число) -> Код 1
    if (std::cin.fail() && !std::cin.eof()) {
        std::cerr << "Error: Invalid input data." << std::endl;
        return 1;
    }

    // Пустая последовательность -> Код 2
    if (!has_elements) {
        std::cerr << "Error: Sequence is empty." << std::endl;
        return 2;
    }

    std::cout << count_since_max << std::endl;
    return 0;
}

} // namespace karadag

int main() {
    return karadag::run_aft_max();
}

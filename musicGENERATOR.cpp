#include "mskgen.hpp"


int main() {
    int variable;
    int size;
    while (true) {
        print("1. Моя песня\n2. Сгенерировать");
        learn(variable);

        switch (variable) {

        case 1:
            for (int i = 40; i <= 1000; i += 10) {
                beep(i, 150);
            }
            break;

        case 2:
            print("Размер (сложность): ");
            learn(size);
            autobeep(size);
            CLEAR_CONSOLE;
            break;
        }
    }
    return 0;
}

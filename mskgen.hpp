#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <random>
#include <string>

// MEMO:
// speaker-test -t sine -f hz -l loops > dev/null 2>&1 &
// killall speaker-test > dev/null 2>&1

std::random_device rd;
std::mt19937 R4(rd());
std::uniform_int_distribution<> ran(1, 2); // 50 / 50

std::random_device rn;
std::mt19937 R4Note(rn());
std::uniform_int_distribution<> rann(0, 7); 

constexpr int Do1  = 523; // C5
constexpr int Re1  = 587; // D5
constexpr int Mi1  = 659; // E5
constexpr int Fa1  = 698; // F5
constexpr int Sol1 = 784; // G5
constexpr int La1  = 880; // A5
constexpr int Si1  = 988; // B5
constexpr int Do2  = 1046; // C6

int notes[] = {Do1, Re1, Mi1, Fa1, Sol1, La1, Si1, Do2};

template <typename ... T>
void print(const T& ... ar) {
    (std::cout << ... << ar) << '\n';
}


#define wait(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))
#define RRANDOM ran(R4)
#define RRANDOM_NOTE rann(R4Note)

template <typename ... T>
void learn(T& ... ar) {
    (std::cin >> ... >> ar);
}



void beep(const int hz, const int milliseconds) { // Manual sound creation
    std::string command = "speaker-test -t sine -f " + std::to_string(hz) + " > /dev/null 2>&1 &";
    std::system(command.c_str());
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    std::system("killall speaker-test > /dev/null 2>&1");
}

int random_time() {
    return (RRANDOM == 1) ? 260 : 500;
}


/* Index memo
Do1  = 523;  0 
Re1  = 587;  1
Mi1  = 659;  2
Fa1  = 698;  3
Sol1 = 784;  4
La1  = 880;  5
Si1  = 988;  6
Do2  = 1046; 7
*/


void autobeep(const int times) {
    int next_notes[8][2] = {
        {2, 4}, 
        {3, 5}, 
        {4, 6}, 
        {5, 7}, 
        {6, 1}, 
        {7, 2}, 
        {1, 3}, 
        {4, 2}  
    };

    int real_step = RRANDOM_NOTE; 
    std::string command;

    for (int i = 0; i < times; ++i) {
        command = "speaker-test -t sine -f " + std::to_string(notes[real_step]) + " > /dev/null 2>&1 &";
        std::system(command.c_str());
        wait(random_time());
        std::system("killall speaker-test > /dev/null 2>&1");
        
        int random_column = RRANDOM - 1; 
        real_step = next_notes[real_step][random_column];
    }
}

#define CLEAR_CONSOLE std::system("clear")
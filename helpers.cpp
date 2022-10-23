#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) 
    #include <windows.h>
#elif __linux__
        #include <sys/ioctl.h>
        #include <stdio.h>
        #include <unistd.h>
#endif

int window_columns, window_rows;

void declare_window_length() {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) 
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        window_columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        window_rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    #elif __linux__
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        window_columns = w.ws_col;
        window_rows = w.ws_row;

    #else
        window_columns = 60;
        window_rows = 10;

    #endif
}

int getWindowColumns() {
    return window_columns;
}

int getWindowRows() {
    return window_rows;
}

int letter_to_int(char letter) {
    switch (letter) {
            case 'A' : 
                return 0;
            case 'B' :
                return 1;
            case 'C' :
                return 2;
            case 'D' :
                return 3;
            case 'E' :
                return 4;
            case 'F' :
                return 5;
            case 'G' :
                return 6;
            case 'H' :
                return 7;
            case 'I' :
                return 8;
            case 'J' :
                return 9;
            default :
                return 100;
        }
}

char int_to_letter(int number) {
    std::vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    return letters[number];
}

void print_line(const char* sym, int length = -1, bool new_line = true){
    if (length == -1) {length = getWindowColumns();}
    for (int i=0; i < length; i++) {
        std::cout << sym;
    }
    if (new_line) {std::cout << "\n";}
}

void middle_dashes() {
    print_line(" ", getWindowColumns() / 2 - 5, false);
    print_line("-", 10);
    std::cout << "\n";
}

char input_checker_char(int num_options) {
    char choice;
    bool accepted = false;
    while (!accepted) {
        std::cout << "Enter an option from A - " << int_to_letter(num_options - 1) << ": ";
        std::cin >> choice;
        //choice = std::getchar(); // >> choice;
        std::cin.ignore(100,'\n');
        if (letter_to_int(choice) >= num_options) {
            std::cout << "Invalid input. Try again.\n";
        } else {
            accepted = true;
        }
    }
    std::cout << "\n";
    middle_dashes();
    return choice;
}

void pause(bool dashes_following = true) {
    std::cout << "Press ENTER to continue... ";
    char trash[80]; 
    std::cin.getline(trash,80,'\n');
    std::cout << "\n";
    if (dashes_following) {middle_dashes();}
}

bool isNumber(const std::string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

int input_checker_positive_int() {
    std::string choice;
    bool accepted = false;
    int choice_int;
    while (!accepted) {
        std::cout << "Enter a positive integer: ";
        std::cin >> choice;
        //choice = std::getchar(); // >> choice;
        std::cin.ignore(100,'\n');
        if (isNumber(choice)) {
            choice_int = std::stoi(choice);
            if (choice_int > 0) {
                accepted = true;
            }
            else {
                std::cout << "Not a positive integer. Try again.\n";
            }
        } else {
            std::cout << "Invalid input. Try again.\n";
        }
    }
    std::cout << "\n";
    middle_dashes();
    return choice_int;
}

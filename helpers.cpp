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

void print_nice(std::string str) {
    declare_window_length();
    int win_len = getWindowColumns();
    int line_len = 0;
    bool skip_space = true;
    bool check_leading_space = true;
    std::string word;

    int N = str.size();

    for (int i = 0; i < N; i++) {
        char ch = str[i];
        if (check_leading_space) {
            if (ch == ' ') {
                std::cout << " ";
                continue;
            }
            else {
                check_leading_space = false;
            } 
        }
        if (!(ch == ' ' || ch == '\n')) {
            word.append(std::string(1,ch));
        } else {
            if (ch == '\n') {
                if (skip_space) {
                    std::cout << word << "\n";
                } else {
                    std::cout << " " << word << "\n";
                }
                line_len = 0;
                word = "";
                skip_space = true;
            }
            else {
                if (line_len + word.size() + 1 > win_len) {
                    std::cout << std::endl;
                    std::cout << word;
                    line_len = word.size();
                } 
                else {
                    if (skip_space) {
                        std::cout << word;
                        skip_space = false;
                        line_len += word.size();
                    } else {
                        std::cout << " " << word;
                        line_len += word.size() + 1;
                    }
                }
                if (i == N - 1 && ch == ' ') {std::cout << " ";}
            }
            word = "";
        }
        if (i == N - 1) {std::cout << word;}
    }
}

std::string double_to_nice_string(double dbl) {
    std::string str = std::to_string(dbl);
    bool past_decimal = false;
    int str_len;
    for (int i = 0; i < str.size(); i++) {
        if (past_decimal && str[i] != '0') {
            str_len = i + 1;
        }
        if (str[i] == '.') {
            str_len = i;
            past_decimal = true;
        }
    }
    return str.substr(0,str_len);
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
        print_nice("Enter an option from A - " + std::string(1, int_to_letter(num_options - 1)) + ": ");
        std::cin >> choice;
        //choice = std::getchar(); // >> choice;
        std::cin.ignore(100,'\n');
        if (letter_to_int(choice) >= num_options) {
            print_nice("Invalid input. Try again.\n");
        } else {
            accepted = true;
        }
    }
    print_nice("\n");
    middle_dashes();
    return choice;
}

void pause0(bool dashes_following = true) {
    print_nice("Press ENTER to continue... ");
    char trash[80]; 
    std::cin.getline(trash,80,'\n');
    print_nice("\n");
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
        print_nice("Enter a positive integer: ");
        std::cin >> choice;
        //choice = std::getchar(); // >> choice;
        std::cin.ignore(100,'\n');
        if (isNumber(choice)) {
            choice_int = std::stoi(choice);
            if (choice_int > 0) {
                accepted = true;
            }
            else {
                print_nice("Not a positive integer. Try again.\n");
            }
        } else {
            print_nice("Invalid input. Try again.\n");
        }
    }
    print_nice("\n");
    middle_dashes();
    return choice_int;
}

std::string yes_or_no() {
    //Returns "Y" or "N" as a string
    while (true) {
        print_nice("Enter Y or N: ");
        std::string response;
        std::cin >> response;
        std::cin.ignore(100,'\n');
        if (response == "Y" || response == "N") {
            print_nice("\n");
            middle_dashes();
            return response;
        }
        print_nice("Invalid input.\n");
    }
}
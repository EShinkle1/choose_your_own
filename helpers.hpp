#ifndef HELPERS_HPP
#define HELPERS_HPP

int letter_to_int(char letter);
char input_checker_char(int num_options);
void print_line(const char* sym, int length = -1, bool new_line = true);
void pause(bool dashes_following = true);
void declare_window_length();
int getWindowColumns();
int getWindowRows();
void middle_dashes();

#endif
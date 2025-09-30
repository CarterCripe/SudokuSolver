#include <iostream>
#include <string>
using namespace std;

struct ansi {
    static constexpr const char* reset  = "\x1b[0m";
    static constexpr const char* bold   = "\x1b[1m";
    static constexpr const char* italic = "\x1b[3m";
    static constexpr const char* red    = "\x1b[31m";
    static constexpr const char* green  = "\x1b[32m";
    static constexpr const char* blue   = "\x1b[34m";
    static constexpr const char* debug = "\x1b[33m";
};

void get_board(int (&board)[9][9][10]) {

    // string rawstring[9];
    cout << ansi::blue << "Please enter the board values:\n" << ansi::reset;
    for (int i = 0; i < 9; i++) {
        bool valid = false;

        string input = "         ";
        while (!valid) {
            cout << ansi::blue << "\n[ " << ansi::reset << i + 1 << ansi::blue << " / " << ansi::reset << 9 << ansi::blue << " ]  Please enter the next row: " << ansi::reset;
            getline(std::cin, input);;
            if (input.size() == 9) {
                valid = true;
            }
            else {
                cout << ansi::blue << "Please enter a valid input!\n" << ansi::reset;
            }
        }
        for (int j = 0; j < 9; j++) {
            board[i][j][0] = input[j] - '0';
            for (int k = 1; k < 10; k++) {
                board[i][j][k] = k;
            }
        }
    }
}
void print_board(int (&board)[9][9][10]) {
    cout << ansi::bold << "-------------------------" << endl << ansi::reset;
    for (int i = 0; i < 3; i++) {

        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 0; j < 3; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 3; j < 6; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 6; j < 9; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "|" << ansi::reset << endl;
    }
    cout << ansi::bold << "-------------------------" << endl << ansi::reset;
    for (int i = 3; i < 6; i++) {

        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 0; j < 3; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 3; j < 6; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 6; j < 9; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "|" << ansi::reset << endl;
    }
    cout << ansi::bold << "-------------------------" << endl << ansi::reset;
    for (int i = 6; i < 9; i++) {

        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 0; j < 3; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 3; j < 6; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "| " << ansi::reset;
        for (int j = 6; j < 9; j++) {
            if (board[i][j][0] == 0) {
                cout << ansi::red << board[i][j][0] << " " << ansi::reset;
            }
            else {
                cout << ansi::green << board[i][j][0] << " " << ansi::reset;
            }
        }
        cout << ansi::bold << "|" << ansi::reset << endl;
    }
    cout << ansi::bold << "-------------------------"  << ansi::reset << endl;
}
void remove_val_from_possibles(int (&board)[9][9][10], int val, int row, int col) {
    for (int i = 1; i < 10; i++) {
        if (board[row][col][i] == val) {
            board[row][col][i] = 0;
        }
    }
}
bool check_if_possible(int (&board)[9][9][10], int row, int col, int val) {
    for (int i = 1; i < 10; i++) {
        if (board[row][col][i] == val) {
            return true;
        }
    }
    return false;
}
void check_row(int (&board)[9][9][10], int idx, int col) {

    for (int i = 0; i < 9; i++) {
        if (board[idx][i][0] <= 0 || board[idx][i][0] >= 10) {

        }
        else {
            remove_val_from_possibles(board, board[idx][i][0], idx, col);
        }
    }
}
void check_col(int (&board)[9][9][10], int idx, int row) {

    for (int i = 0; i < 9; i++) {
        if (board[i][idx][0] <= 0 || board[i][idx][0] >= 10) {

        }
        else {
            remove_val_from_possibles(board, board[i][idx][0], row, idx);
        }
    }
}
void check_box(int (&board)[9][9][10], int box_row, int box_col, int row, int col) {
    for (int i = box_row; i < (box_row + 3); i++) {
        for (int j = box_col; j < (box_col + 3); j++) {
            if (board[i][j][0] <= 0 || board[i][j][0] >= 10) {

            }
            else {
                remove_val_from_possibles(board, board[i][j][0], row, col);
            }
        }
    }
}
// Returns true if there is no other valid spot in the row for val
bool logic_row(int (&board)[9][9][10], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if ((board[row][i][0] == 0) && (i != col)) {
            for (int j = 1; j < 10; j++) {
                if (board[row][i][j] == val) {
                    return false;
                }
            }
        }
    }
    return true;
}
// Returns true if there is no other valid spot in the col
bool logic_col(int (&board)[9][9][10], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if ((board[i][col][0] == 0) && (i != row)) {
            for (int j = 1; j < 10; j++) {
                if (board[i][col][j] == val) {
                    return false;
                }
            }
        }
    }
    return true;
}
// Returns true if there is no other valid spot in the box
bool logic_box(int (&board)[9][9][10], int box_row, int box_col, int row, int col, int val) {
    for (int i = box_row; i < (box_row + 3); i++) {
        for (int j = box_col; j < (box_col + 3); j++) {

            if ((board[i][j][0] == 0) && ((i != row) || (j != col))) {
                for (int k = 1; k < 10; k++) {
                    if (board[i][j][k] == val) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int calc_box(const int idx) {
    if (idx < 3) {
        return 0;
    }
    if (idx < 6) {
        return 3;
    }
    if (idx < 9) {
        return 6;
    }
    return -1;
}
void print_possibles(const int (&board)[9][9][10], int row, int col) {
    cout << ansi::debug << "Possibles [" << (row + 1) << ", " << (col + 1) << "]: " << ansi::reset;
    for (int i = 1; i < 10; i++) {
        cout << ansi::debug << board[row][col][i] << " " << ansi::reset;
    }
    cout << endl << ansi::reset;
}
void get_possibles(int row, int col, int (&board)[9][9][10], int debug) {
    int box_row = calc_box(row);
    int box_col = calc_box(col);
    if (box_row == -1 || box_col == -1) {
        if (debug == 1) {cout << ansi::debug << ansi::bold << "|||| BIG BOX CALC ERROR |||" << endl << ansi::reset;}
        return;
    }
    check_box(board, box_row, box_col, row, col);
    check_row(board, row, col);
    check_col(board, col, row);
    if (debug == 1) {print_possibles(board, row, col);}

}
void clear_possibles(int (&board)[9][9][10], int row, int col) {
    for (int i = 1; i < 10; i++) {
        board[row][col][i] = 0;
    }
}
int check_single_possible(int (&board)[9][9][10], int row, int col) {
    int latest = -1;
    int count = 0;
    for (int i = 1; i < 10; i++) {
        if (board[row][col][i] >= 1) {
            count++;
            latest = board[row][col][i];
        }
    }
    if (count == 1) {
        clear_possibles(board, row, col);
        return latest;
    }
    return -1;
}
bool do_logic_operations(int (&board)[9][9][10], int debug, int row, int col) {
    int box_row = calc_box(row);
    int box_col = calc_box(col);
    if (box_row == -1 || box_col == -1) {
        if (debug == 1) {cout << ansi::debug << ansi::bold << "|||| BIG BOX CALC ERROR |||" << endl << ansi::reset;}
        return false;
    }
    for (int i = 1; i < 10; i++) {
        if (board[row][col][i] != 0) {
            int val = board[row][col][i];
            if (logic_row(board, row, col, val) || logic_col(board, row, col, val) || logic_box(board, box_row, box_col, row, col, val)) {
                board[row][col][0] = val;
                clear_possibles(board, row, col);
                return true;
            }
        }
    }
    return false;
}
int get_all_possibles(int (&board)[9][9][10], int debug, bool advanced) {
    int flag = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j][0] == 0) {
                get_possibles(i, j, board, debug);
                flag += 1;
                int single = check_single_possible(board, i, j);
                if (single != -1) {
                    board[i][j][0] = single;
                    flag -= 1;
                }
                else if (advanced) {
                    bool solved = do_logic_operations(board, debug, i, j);
                    if (debug) {
                        cout << ansi::debug << ansi::bold << "Used Advanced to adjust [ " << i + 1 << ", " << j + 1 << "] to " << board[i][j][0] << ansi::reset << endl;
                    }
                    if (solved) {
                        flag -= 1;
                    }
                }
            }
        }
    }
    if (debug == 1){cout << ansi::debug << "Returning flag: " << flag << endl << ansi::reset;}

    return flag;
}



int main() {
    int debug = 0;

    string app = "Sudoku Solver";
    cout << ansi::blue << "\nHello and welcome to " << app << "!\n" << ansi::reset;

    int board[9][9][10];
    get_board(board);
    cout << ansi::blue << ansi::bold << "\n\n-------------------------\n|| STARTING BOARD ||\n-------------------------\n" << ansi::reset << endl;
    print_board(board);
    int i = 0;
    cout << ansi::blue << ansi::bold << "\n\n-------------------------\n|| BEGINNING COMPUTATION ||\n-------------------------\n" << ansi::reset << endl;
    int flag = 0;
    int last_flag = 0;
    bool advanced = false;
    do {
        last_flag = flag;
        flag = get_all_possibles(board, debug, advanced);
        i += 1;
        if (last_flag == flag) {
            advanced = true;
        }
        if (i > 15) {
            cout << ansi::bold << ansi::red << "\n\nERROR: ITERATIONS TIMED OUT\nUnfortunately this board is not solvable, please double check your entry and try again!\n\n"<< ansi::reset;
            cout << ansi::blue << "Heres where we got before the error: " << ansi::reset << endl;
            print_board(board);
            return 0;
        }
        cout << ansi::blue << "Ran iteration " << i << ", " << flag << " tiles remaining...\n" << ansi::reset;
    } while (flag >= 1);
    cout << ansi::blue << ansi::bold << "\n\n-------------------------\n|| SOLVED BOARD ||\n-------------------------\n" << ansi::reset << endl;
    print_board(board);
    return 0;
}
// 002170006
// 090008053
// 040300018
// 000800640
// 980027001
// 003090027
// 501900070
// 070451960
// 429030000

// 000034091
// 400170000
// 006000700
// 100003000
// 905000120
// 004500067
// 620009000
// 540210986
// 870356410
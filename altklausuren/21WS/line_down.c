/*
make line_down && ./line_down
*/

#include "base.h"

// <purpose statement>
int line_down(String s, int cursor) {
    require_not_null(s);
    int n = strlen(s);
    require("valid cursor", 0 <= cursor && cursor <= n);
    // todo: implement
    return 0; 
}

void test(void) {
    test_equal_i(line_down("", 0), 0);
    test_equal_i(line_down("xxx", 0), 0);
    test_equal_i(line_down("xxx", 3), 3);
    //                      01 23
    test_equal_i(line_down("x\nx", 1), 3);
    //                      01234 56789 0123
    test_equal_i(line_down("abcd\nefgh\nijk", 0), 5);
    test_equal_i(line_down("abcd\nefgh\nijk", 3), 8);
    test_equal_i(line_down("abcd\nefgh\nijk", 4), 9);
    test_equal_i(line_down("abcd\nefgh\nijk", 5), 10);
    test_equal_i(line_down("abcd\nefgh\nijk", 9), 13);
    test_equal_i(line_down("abcd\nefgh\nijk", 10), 10);
    test_equal_i(line_down("abcd\nefgh\nijk", 11), 11);
    test_equal_i(line_down("abcd\nefghi\nj\nkl", 7), 12);
    test_equal_i(line_down("abcd\nefghi\nj\n\nl", 7), 12);
}

int main(void) {
    test();
    return 0;
}
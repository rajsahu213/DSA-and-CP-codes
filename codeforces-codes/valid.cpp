#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 10, "testCount");
    inf.readEoln();

    for (int i = 0; i < testCount; i++) {
        int n = inf.readInt(1, 1000, "n");
        inf.readSpace();
        inf.readInt(1, n, "w");
        inf.readEoln();

        for (int i = 0; i < n; ++i) {
            inf.readInt(1, 100000, "p_i");
            if (i < n - 1)
                inf.readSpace();
        }
        inf.readEoln();
    }

    inf.readEof();
}
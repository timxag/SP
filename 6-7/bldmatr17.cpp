//                 bldmatr.cpp 2017
#include <iostream>
#include <iomanip>
#include "kngramma.h"
#include "precmat.h"

using namespace std;

const int SIZE_LINE = 100;

int main(int argc, char *argv[]) {
    char buf[SIZE_LINE];

    do {
        cout << "Input gramma name>";
        *buf = 0;
        cin.getline(buf, SIZE_LINE);
        if (!*buf) break;

        char *name = buf;
        bool print = false;
        if (*name == '+') {
            ++name;
            print = true;
        }
        string gramma_name = string(name) + ".txt";
        cout << "Gramma:" << gramma_name << endl;
//_ _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _
        tGramma gr;
        gr.loadFromFile(gramma_name.c_str());
        outgr(cout, gr);
//_ _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _
        tPrecedence prc;
        prc.build(gr);
        if (!prc) {
            cout << prc.getError() << endl;
            continue;
        }
//_ _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _

        if (print)
            out_matrix(cout, gr, prc);
        //_ _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _
        size_t maxw = gr.smbWidth() + 1;
        size_t n = prc.size();
        bool noConflict = true;
        for (size_t i = 1; i < n; ++i)
            for (size_t j = 1; j < n; ++j) {
                int k = prc.rel(i, j);
                if (k && k != 1 && k != 2 && k != 4) {
                    if (noConflict) {
                        noConflict = false;
                        cout << "Conflicts:" << endl;
                    }
                    cout << setw(5) << prc.reltostr(i, j) << " ";
                    cout << setw(maxw) << gr.decode(i) << " ";
                    cout << setw(maxw) << gr.decode(j);
                    cout << endl;
                }
            }
//
        if (noConflict) cout << "No conflicts!\n";
    } while (true);
    return 0;
}

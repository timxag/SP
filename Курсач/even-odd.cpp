/*  gta2018   */
#include "mlisp.h"
double one();
double two();
double even__bits(double n);
double odd__bits(double n);
double display__bin(double n);
double report__results(double n);
double mil();
double tho();
double dd();
double mm();
double yyyy();
//________________ 
double one() {
return 1;
}
double two() {
return 2;
}
double even__bits(double n) {
return (n == 0) ?one():(remainder(n, two()) == 0) ?even__bits(quotient(n, two())):odd__bits(quotient(n, two()));
}
double odd__bits(double n) {
return (n == 0) ?0:(remainder(n, two()) == 0) ?odd__bits(quotient(n, two())):even__bits(quotient(n, two()));
}
double display__bin(double n) {
display(remainder(n, two()));
return (n == 0) ?0:display__bin(quotient(n, two()));
}
double report__results(double n) {
display("Happy birthday to you!\n\t");
display(n);
display(" (decimal)\n\t");
newline();
n = display__bin(n);
display("(reversed binary)\n");
display("\teven?\t");
display((even__bits(n) == one()) ?"yes":"no");
newline();
display("\todd?\t");
display((odd__bits(n) == one()) ?"yes":"no");
newline();
return 0;
}
double mil() {
return 1000000;
}
double tho() {
return 10000;
}
double dd() {
return 23;
}
double mm() {
return 6;
}
double yyyy() {
return 1998;
}
int main(void) {
display(report__results(( (( (dd() * mil())) + ( (mm() * tho())) + yyyy())))); newline();
    std::cin.get();
 return 0;
}


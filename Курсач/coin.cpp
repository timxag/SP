/*  gta2018   */
#include "mlisp.h"
double dd();
double mm();
double LARGEST__COIN();
double one();
double two();
double three();
double sto();
double cc(double amount, double largest__coin);
double count__change(double amount);
double next__coin(double coin);
double GR__AMOUNT();
//________________ 
double dd() {
return 23;
}
double mm() {
return 6;
}
double LARGEST__COIN() {
return 3;
}
double one() {
return 1;
}
double two() {
return 2;
}
double three() {
return 3;
}
double sto() {
return 100;
}
double cc(double amount, double largest__coin) {
return ((amount == 0) || (largest__coin == one())) ?one():((amount <= 0) || (largest__coin <= 0)) ?0:( (cc(amount, next__coin(largest__coin)) + cc(( (amount - largest__coin)), largest__coin)));
}
double count__change(double amount) {
return cc(amount, LARGEST__COIN());
}
double next__coin(double coin) {
return (coin == three()) ?two():(coin == two()) ?one():0;
}
double GR__AMOUNT() {
return ( (( (sto() * mm())) + dd()));
}
int main(void) {
display(" gta variant 20");
newline();
display(" 1-2-3");
newline();
display("count-change for 100 \t= ");
display(count__change(sto()));
newline();
display("count-change for ");
display(GR__AMOUNT());
display(" \t= ");
display(count__change(GR__AMOUNT()));
newline();
    std::cin.get();
 return 0;
}


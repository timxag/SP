/*  gta2018   */
#include "mlisp.h"
double one();
double two__d();
double two();
double three();
double tmp1();
double tmp2();
double four();
double tolerance();
double half__interval__metod(double a, double b, double a__value, double b__value);
double __gta2018__try(double neg__point, double pos__point, double midpoint, double test__value);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double root(double a, double b, double temp);
double six();
double fun(double z);
//________________ 
double one() {
return 1;
}
double two__d() {
return 2.0;
}
double two() {
return 2;
}
double three() {
return 3;
}
double tmp1() {
return 40;
}
double tmp2() {
return 41;
}
double four() {
return 4;
}
double tolerance() {
return 0.000001;
}
double half__interval__metod(double a, double b, double a__value, double b__value) {
a__value = fun(a);
b__value = fun(b);
return (!((!(a__value <= 0)) || (b__value <= 0))) ?__gta2018__try(a, b, 0, 0):(!((a__value <= 0) || (!(b__value <= 0)))) ?__gta2018__try(b, a, 0, 0):( (b + one()));
}
double __gta2018__try(double neg__point, double pos__point, double midpoint, double test__value) {
midpoint = average(neg__point, pos__point);
test__value = 0;
display("+");
return close__enough_Q(neg__point, pos__point) ?midpoint:(!(fun(midpoint) <= 0)) ?__gta2018__try(neg__point, midpoint, 0, 0):(fun(midpoint) <= 0) ?__gta2018__try(midpoint, pos__point, 0, 0):midpoint;
}
bool close__enough_Q(double x, double y){
  return (abs(( (x - y))) <= tolerance());
}
double average(double x, double y) {
return ( (x + y))/two__d();
}
double root(double a, double b, double temp) {
display("interval=\t[");
display(a);
display(" , ");
display(b);
display("]\n");
temp = half__interval__metod(a, b, 0, 0);
newline();
display("discrepancy=\t");
display(fun(temp));
newline();
display("root=\t\t");
display((( (temp - ( (b + one())))) == 0) ?"[bad]":"[good]");
return temp;
}
double six() {
return 6;
}
double fun(double z) {
z = ( (z - ( (tmp1()/tmp2() + one()/e))));
return ( (( (six() * expt(atan(( (z - two()))), four()))) - one()));
}
int main(void) {
display(" gta variant 40"); newline();
display(root(two(), three(), 0)); newline();
    std::cin.get();
 return 0;
}


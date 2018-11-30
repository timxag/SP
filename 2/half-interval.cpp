//  half-interval.cpp 2018
/*
(define(fun z)
  (set! z (- z (/ 40 41)(/ e)))
  (- (* 6 ( expt (atan (- z 2)) 4))
    1)
)*/

#include "mlisp.h"

double tolerance = 0.000001;

double fun(double z);
double average(double x, double y);
double close_enough_Q(double x, double y);
double __gta__try(double neg_point, double pos_point);
double half_interval_method(int a, int b);
double root(int a, int b);

double fun(double z) {
    z=(z-40.0/41.0-1.0/ e);
    return 6*atan(z-2)*atan(z-2)*atan(z-2)*atan(z-2) -1;
}

double average(double x, double y) {
    return (x + y) / 2.0;
}

double close_enough_Q(double x, double y) {
    return abs(x - y) < tolerance;
}

double __gta__try(double neg_point, double pos_point) {
    {//let
        double midpoint(average(neg_point, pos_point));
        double test_value(0);
        display("+");
        return close_enough_Q(neg_point, pos_point)
               ? midpoint
               : true
                 ? test_value = fun(midpoint), (test_value > 0)
                 ? __gta__try(neg_point, midpoint)
                                    : (test_value < 0)
                                      ? __gta__try(midpoint, pos_point)
                                      : midpoint
                 : _infinity;
    }
}

double half_interval_method(int a, int b) {
    {//let
        double a_value(fun(a));
        double b_value(fun(b));
        return (a_value < 0 && b_value > 0) ? __gta__try(a, b)
                                            : (a_value > 0 && b_value < 0)
                                              ? __gta__try(b, a)
                                              : b + 1;
    }
}


double root(int a, int b) {
    display("interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]");
    newline();
    {//let
        double temp = half_interval_method(a, b);
        newline();
        display("discrepancy=\t");
        display(fun(temp));
        newline();
        display("root=\t\t");
        display((temp - b - 1 == 0) ? "[bad]" : "[good]");
        return temp;
    }
}


//BSM_ROOT
int main() {
    display("GTA var 40");
    newline();
    display(root(2, 3));
    newline();
}

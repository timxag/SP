/*
(define(even-bits n)
  (cond((= n 0)1)
       ((=(remainder n 2)0)
          (even-bits (quotient n 2)))
       (else(odd-bits(quotient n 2)))
       ))
(define(odd-bits n)
  (cond((= n 0)0)
       ((=(remainder n 2)0)
          (odd-bits (quotient n 2)))
       (#t(even-bits(quotient n 2)))
       ))
(define(display-bin n)
  (display(remainder n 2))
  (if(= n 0)0 (display-bin (quotient n 2)))
       )
(define(report-results n)
  (display "Happy birthday to you!\n\t")
  (display n)(display " (decimal)\n\t")
  (display-bin n)(display "(reversed binary)\n")
  (display "\teven?\t")(display (if(=(even-bits n)1) "yes" "no"))
  (newline)
  (display "\todd?\t")(display (if(=(odd-bits n)1) "yes" "no"))
  (newline)
  0
       )
;***** Date of YOUR birthday *******
(define dd 23)
(define mm 06)
(define yyyy 1998)
;***********************************
(report-results (+ (* dd 1000000)
                   (* mm 10000)
                   yyyy))
*/
#include "mlisp.h"

double even__bits(double);
double odd__bits(double);
double display__bin(double);
double report__results(double);

double dd = 23;
double mm = 06;
double yyyy = 1998;

double even__bits(double n)
{
  return (n == 0 ? 1
    : remainder(n, 2) == 0 ?
    even__bits(quotient(n, 2))
    : odd__bits(quotient(n, 2)));
}

double display__bin(double n) {
  display(remainder(n, 2));
  return(n == 0 ? 0 :
    display__bin(quotient(n, 2)));
}

double odd__bits(double n)
 {
  return (n == 0 ? 0
       : remainder(n,2) == 0 ?
                odd__bits (quotient(n,2))
       : true ? even__bits(quotient(n,2))
       : _infinity);
 }

double report__results(double n) {
  display("Happy birthday to you!\n\t");
  display(n);
  display(" (decimal)\n\t");
  display__bin(n);
  display("(reversed binary)\n");
  display("\teven?\t");
  display((even__bits(n)) == 1 ? "yes" : "no");
  newline();
  display("\todd?\t");
  display((odd__bits(n)) == 1 ? "yes" : "no");
  return 0;
}

/* GTA */
int main(){
 display(report__results (dd*1000000+
                         mm*10000+
                         yyyy));
 newline();
 return 0;
}

;even-odd
;(define(even-bits n)
;  (cond((= n 0)1)
 ;      ((=(remainder n 2)0)
  ;        (even-bits (quotient n 2)))
   ;    (else(odd-bits(quotient n 2)))
    ;   ))
(define (one) 1)
(define (two) 2)

(define(even-bits n)
  (if(= n 0) (one)
       (if (=(remainder n (two))0)
          (even-bits (quotient n (two))) 
       (odd-bits(quotient n (two))))
       ))

(define(odd-bits n)
  (if(= n 0)0
       (if (=(remainder n (two))0)
          (odd-bits (quotient n (two)))
       (even-bits(quotient n (two)))
       )))
(define(display-bin n)
  (display(remainder n (two)))
  (if(= n 0)0 (display-bin (quotient n (two))))
       )
(define(report-results n)
  (display "Happy birthday to you!\n\t")
  (display n)(display " (decimal)\n\t")
  (newline)
  (set! n(display-bin n))
  (display "(reversed binary)\n")
  (display "\teven?\t")(display (if(=(even-bits n)(one)) "yes" "no"))
  (newline)
  (display "\todd?\t")(display (if(=(odd-bits n)(one)) "yes" "no"))
  (newline)
  0
       )
;***** Date of YOUR birthday *******
(define (mil) 1000000)
(define (tho) 10000)
(define (dd) 23)
(define (mm) 6)
(define (yyyy) 1998)
;***********************************
(report-results (+ (* (dd) (mil))
                   (* (mm) (tho))
                   (yyyy)))


 

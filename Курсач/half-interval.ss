;  half-interval.ss 2018
(define (one) 1)
(define (two-d) 2.0)
(define (two) 2)
(define (three) 3)
(define (tmp1) 40)
(define (tmp2) 41)
(define (four) 4)
(define (tolerance) 0.000001)
(define (half-interval-metod a b a-value b-value)
  (set! a-value (fun a))
  (set! b-value (fun b))
      
     (if(not(or (not(<= a-value 0)) (<= b-value 0)))
                 (try a b 0 0)
         (if (not(or (<= a-value 0) (not(<= b-value 0))))
                 (try b a 0 0)
         (+ b (one)))
     )
  
)

(define(try neg-point pos-point midpoint test-value)
 (set! midpoint (average neg-point pos-point))
 (set! test-value 0)
     
     (display "+")
     (if(close-enough? neg-point pos-point) midpoint
         ;(set! test-value (fun midpoint))
            (if(not(<= (fun midpoint) 0))(try neg-point midpoint 0 0)
                 (if(<= (fun midpoint) 0) (try midpoint pos-point 0 0)
                 midpoint)
             )
         
     )
 )


(define (close-enough? x y)
  (<=(abs (- x y))(tolerance)))
(define (average x y)(/(+ x y)(two-d)))

(define (root a b temp)
 (display"interval=\t[")
 (display a)
 (display" , ")
 (display b)
 (display"]\n")
 (set! temp (half-interval-metod a b 0 0))
      (newline)
      (display"discrepancy=\t")
      (display(fun temp))(newline)
      (display"root=\t\t")
      (display(if(=(- temp (+ b (one)))0)"[bad]" "[good]"))
      temp 
 )
(define (six) 6)
(define(fun z)
  (set! z (- z (+ (/ (tmp1) (tmp2)) (/ (one) e ))))
  (- (* (six) ( expt (atan (- z (two))) (four)))
    (one))
)

" gta variant 40"
(root (two) (three) 0)

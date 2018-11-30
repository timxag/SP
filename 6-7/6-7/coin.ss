(define dd 23)
(define mm 6)
(define LARGEST-COIN 3)

(define (cc amount largest-coin)
(cond((or(= amount 0)(= largest-coin 1)) 1)
     ((not(and (> amount 0) (> largest-coin 0))) 0) 
     (else (+ (cc amount (next-coin largest-coin)) (cc (- amount largest-coin) largest-coin)))
  ))
(define (count-change amount)
  (cc amount LARGEST-COIN)
)

(define (next-coin coin)
(cond((= coin 3) 2)
     ((= coin 2) 1)
     (#t 0)
     )
)
(define (GR-AMOUNT)
  (+(* 100 mm) dd))

(display " gta variant 20") (newline)

(display " 1-2-3") (newline)

(display "count-change for 100 \t= ")

(display (count-change 100)) (newline)

(display "count-change for ")

(display (GR-AMOUNT))

(display " \t= ")

(display (count-change (GR-AMOUNT))) (newline)

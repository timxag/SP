(define (dd) 23)
(define (mm) 6)
(define (LARGEST-COIN) 3)
(define (one) 1)
(define (two) 2)
(define (three) 3)
(define (sto) 100)
(define (cc amount largest-coin)
(if(or(= amount 0)(= largest-coin (one))) (one)
     ;(if (not(and (> amount 0) (> largest-coin 0))) 0
   (if (or (<= amount 0) (<= largest-coin 0)) 0
      (+ (cc amount (next-coin largest-coin)) (cc (- amount largest-coin) largest-coin))
  )))
(define (count-change amount)
  (cc amount (LARGEST-COIN))
)

(define (next-coin coin)
(if (= coin (three)) (two)
     (if (= coin (two)) (one) 0)
     )
)
(define (GR-AMOUNT)
  (+(* (sto) (mm)) (dd)))

(display " gta variant 20")
(newline)

(display " 1-2-3") (newline)

(display "count-change for 100 \t= ")

(display (count-change (sto)))
(newline)

(display "count-change for ")

(display (GR-AMOUNT))

(display " \t= ")

(display (count-change (GR-AMOUNT)))
(newline)

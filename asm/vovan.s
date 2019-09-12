.name "vovan"
.comment "Za vovana"
start1:
		live %1
		zjmp %:dead
dead:
		ld %0, r4
		sti r1, %:start1, %1
		sti r1, %:dead, %0
dead1:
		sti r1, %:start, %1
		sti r1, %:dead1, %0
dead2:
		zjmp %:ff
start:
		live %1
		zjmp %:start
ff:
    sti r1, %:dead2, %:dead2
    fork %1
    zjmp %:start
    sti  r4,%:start1, %0

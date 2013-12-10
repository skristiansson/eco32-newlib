# setjmp/longjmp for eco32.
# (c)Jens Mehler - THM 2013

# Register	jmpbuf offset
# $0 and $2 don't need to be saved
# $0 is tied to zero by hardware
# $2 is function return register and set by longjump
# $4 holds the address of the jump_buffer to which we have to store the env
#	=> function arg regs : $4 - $7

	.text
	.global	setjmp
	.type	setjmp,@function
setjmp:
#	skip $0
	stw $1,$4,0
#	skip $2
	stw $3,$4,4
	stw $4,$4,8
	stw $5,$4,12
	stw $6,$4,16
	stw $7,$4,20
	stw $8,$4,24
	stw $9,$4,28
	stw $10,$4,32
	stw $11,$4,36
	stw $12,$4,40
	stw $13,$4,44
	stw $14,$4,48
	stw $15,$4,52
	stw $16,$4,56
	stw $17,$4,60
	stw $18,$4,64
	stw $19,$4,68
	stw $20,$4,72
	stw $21,$4,76
	stw $22,$4,80
	stw $23,$4,84
	stw $24,$4,88
	stw $25,$4,92
	stw $26,$4,96
	stw $27,$4,100
	stw $28,$4,104
	stw $29,$4,108
	stw $30,$4,112
	stw $31,$4,116
	add $2,$0,$0	# zero result
	jr 	$31			# return
.Lend1:
	.size	setjmp,.Lend1-setjmp

	.global	longjmp
	.type	longjmp,@function
longjmp:
#	set the correct result for this function

# in case that second argument is zero return 1 otherwise return second argument
	beq $5,$0,zero
	add $2,$0,$5
	j restore

zero:
	addi $2,$0,1

restore:
#	skip $0
	ldw $1,$4,0
#	skip $2
	ldw $3,$4,4
#	$4 is last to be restored : obvious isn't it :)
	ldw $5,$4,12
	ldw $6,$4,16
	ldw $7,$4,20
	ldw $8,$4,24
	ldw $9,$4,28
	ldw $10,$4,32
	ldw $11,$4,36
	ldw $12,$4,40
	ldw $13,$4,44
	ldw $14,$4,48
	ldw $15,$4,52
	ldw $16,$4,56
	ldw $17,$4,60
	ldw $18,$4,64
	ldw $19,$4,68
	ldw $20,$4,72
	ldw $21,$4,76
	ldw $22,$4,80
	ldw $23,$4,84
	ldw $24,$4,88
	ldw $25,$4,92
	ldw $26,$4,96
	ldw $27,$4,100
	ldw $28,$4,104
	ldw $29,$4,108
	ldw $30,$4,112
	ldw $31,$4,116
	ldw $4,$4,8 	# $4 needs to be restored last because it holds address of jump_buffer!
	jr 	$31			# return is like setjmp but the result in $2 matters !!
.Lend2:
	.size	longjmp,.Lend2-longjmp

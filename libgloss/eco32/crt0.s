#
# start.s -- startup code
#
	.global reset
	.global	main
	.global	_ecode
	.global	_edata
	.global	_ebss

	.global	_bcode
	.global	_bdata
	.global	_bbss

	.text
_bcode:

	.data
_bdata:

.section	.bss
_bbss:

	.text

	# reset arrives here
reset:
	j	_start

	# interrupts arrive here
intrpt:
	j	intrpt

	# user TLB misses arrive here
userMiss:
	j	userMiss

_start:
	mvfs	$8,0
	ori		$8,$8,1 << 27	# let vector point to RAM
	mvts	$8,0
	addi	$29,$0,stack	# set sp
	addi	$8,$0,_bbss		# clear bss
	addi	$9,$0,_ebss
	j		clrtest
clrloop:
	stw		$0,$8,0
	addi	$8,$8,4
clrtest:
	bltu	$8,$9,clrloop
	jal		main			# call 'main'

	addi	$4,$2,0
	jal	exit
stop:
	j		stop			# loop to be sure 

.section	.bss

	.align	4
	.space	0x800
stack:

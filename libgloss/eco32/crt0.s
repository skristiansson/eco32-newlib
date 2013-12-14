#
# start.s -- startup code
#
	.global _start
	.global	main

	.section .vectors, "ax", @progbits
	# reset arrives here
reset:
	j	_start

	# interrupts arrive here
intrpt:
	j	intrpt

	# user TLB misses arrive here
userMiss:
	j	userMiss

	.section .text
_start:
	mvfs	$8,0
	ori		$8,$8,1 << 27	# let vector point to RAM
	mvts	$8,0
	addi	$29,$0,stack-4*4	# set sp (& allocate argument registers)
	addi	$8,$0,__bss_start	# clear bss
	addi	$9,$0,end
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

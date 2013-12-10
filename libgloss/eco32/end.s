#
# end.s -- end-of-segment labels
#

	.global	_ecode
	.global	_edata
	.global	_ebss

	.text
	.align	4
_ecode:

	.data
	.align	4
_edata:

.section	.bss
	.align	4
_ebss:

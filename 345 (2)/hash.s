	.file	"hash.cpp"
	.data
	.align 4
	.type	_ZL15hash_table_size, @object
	.size	_ZL15hash_table_size, 4
_ZL15hash_table_size:
	.long	65537
	.text
	.align 2
.globl _ZN12hash_controlD2Ev
	.type	_ZN12hash_controlD2Ev, @function
_ZN12hash_controlD2Ev:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	_ZN12hash_controlD2Ev, .-_ZN12hash_controlD2Ev
.globl _ZN12hash_controlD1Ev
	.set	_ZN12hash_controlD1Ev,_ZN12hash_controlD2Ev
	.align 2
.globl _ZN12hash_controlC2Ev
	.type	_ZN12hash_controlC2Ev, @function
_ZN12hash_controlC2Ev:
.LFB8:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control4initEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN12hash_controlC2Ev, .-_ZN12hash_controlC2Ev
.globl _ZN12hash_controlC1Ev
	.set	_ZN12hash_controlC1Ev,_ZN12hash_controlC2Ev
	.align 2
.globl _ZN12hash_controlC2Ej
	.type	_ZN12hash_controlC2Ej, @function
_ZN12hash_controlC2Ej:
.LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control8get_sizeEv
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control8set_sizeEm
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control4initEv
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control8set_sizeEm
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE11:
	.size	_ZN12hash_controlC2Ej, .-_ZN12hash_controlC2Ej
.globl _ZN12hash_controlC1Ej
	.set	_ZN12hash_controlC1Ej,_ZN12hash_controlC2Ej
	.align 2
.globl _ZN12hash_control8set_sizeEm
	.type	_ZN12hash_control8set_sizeEm, @function
_ZN12hash_control8set_sizeEm:
.LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	%eax, _ZL15hash_table_size
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE13:
	.size	_ZN12hash_control8set_sizeEm, .-_ZN12hash_control8set_sizeEm
	.align 2
.globl _ZN12hash_control6loopupEPKcjPPP10hash_entryPm
	.type	_ZN12hash_control6loopupEPKcjPPP10hash_entryPm, @function
_ZN12hash_control6loopupEPKcjPPP10hash_entryPm:
.LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L7
.L8:
	movl	-16(%ebp), %eax
	movl	12(%ebp), %edx
	leal	(%edx,%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	sall	$17, %eax
	addl	-28(%ebp), %eax
	addl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	shrl	$2, %eax
	xorl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
.L7:
	movl	-16(%ebp), %eax
	cmpl	16(%ebp), %eax
	setb	%al
	testb	%al, %al
	jne	.L8
	movl	16(%ebp), %eax
	sall	$17, %eax
	addl	16(%ebp), %eax
	addl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	shrl	$2, %eax
	xorl	%eax, -12(%ebp)
	cmpl	$0, 24(%ebp)
	je	.L9
	movl	24(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
.L9:
	movl	8(%ebp), %eax
	movl	4(%eax), %ecx
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, -32(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-32(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, -36(%ebp)
	cmpl	$0, 20(%ebp)
	je	.L10
	movl	20(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%eax)
.L10:
	movl	$0, -24(%ebp)
	movl	-36(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	jmp	.L11
.L15:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-12(%ebp), %eax
	jne	.L12
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	strncmp
	testl	%eax, %eax
	jne	.L12
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	addl	16(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L12
	cmpl	$0, -24(%ebp)
	je	.L13
	movl	-20(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %eax
	movl	%edx, (%eax)
	movl	-36(%ebp), %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	movl	%edx, (%eax)
	movl	-36(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
.L13:
	movl	-20(%ebp), %eax
	jmp	.L14
.L12:
	movl	-20(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
.L11:
	cmpl	$0, -20(%ebp)
	setne	%al
	testb	%al, %al
	jne	.L15
	movl	$0, %eax
.L14:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE14:
	.size	_ZN12hash_control6loopupEPKcjPPP10hash_entryPm, .-_ZN12hash_control6loopupEPKcjPPP10hash_entryPm
	.align 2
.globl _ZN12hash_control8get_sizeEv
	.type	_ZN12hash_control8get_sizeEv, @function
_ZN12hash_control8get_sizeEv:
.LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L17
.L20:
	movl	-4(%ebp), %eax
	movl	_ZZN12hash_control8get_sizeEvE16hash_size_primes(,%eax,4), %edx
	movl	_ZL15hash_table_size, %eax
	cmpl	%eax, %edx
	jae	.L21
.L18:
	addl	$1, -4(%ebp)
.L17:
	cmpl	$3, -4(%ebp)
	setbe	%al
	testb	%al, %al
	jne	.L20
	jmp	.L19
.L21:
	nop
.L19:
	movl	-4(%ebp), %eax
	movl	_ZZN12hash_control8get_sizeEvE16hash_size_primes(,%eax,4), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE15:
	.size	_ZN12hash_control8get_sizeEv, .-_ZN12hash_control8get_sizeEv
	.section	.rodata
.LC0:
	.string	"hash_control:"
	.text
	.align 2
.globl _ZN12hash_control4initEv
	.type	_ZN12hash_control4initEv, @function
_ZN12hash_control4initEv:
.LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control8get_sizeEv
	movl	8(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_Znaj
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	.L23
	movl	$.LC0, (%esp)
	call	perror
	movl	$1, (%esp)
	call	exit
.L23:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	memset
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE16:
	.size	_ZN12hash_control4initEv, .-_ZN12hash_control4initEv
	.section	.rodata
.LC1:
	.string	"exists"
	.text
	.align 2
.globl _ZN12hash_control6insertEPKci
	.type	_ZN12hash_control6insertEPKci, @function
_ZN12hash_control6insertEPKci:
.LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	strlen
	leal	-20(%ebp), %edx
	movl	%edx, 16(%esp)
	leal	-16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control6loopupEPKcjPPP10hash_entryPm
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	.L25
	movl	$.LC1, %eax
	jmp	.L26
.L25:
	movl	$16, (%esp)
	call	_Znwj
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-20(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-16(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$0, %eax
.L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE17:
	.size	_ZN12hash_control6insertEPKci, .-_ZN12hash_control6insertEPKci
	.align 2
.globl _ZN12hash_control4findEPKc
	.type	_ZN12hash_control4findEPKc, @function
_ZN12hash_control4findEPKc:
.LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	strlen
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control6loopupEPKcjPPP10hash_entryPm
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L28
	movl	$0, %eax
	jmp	.L29
.L28:
	movl	-12(%ebp), %eax
	movl	12(%eax), %eax
.L29:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE18:
	.size	_ZN12hash_control4findEPKc, .-_ZN12hash_control4findEPKc
	.align 2
.globl _ZN12hash_control7replaceEPKci
	.type	_ZN12hash_control7replaceEPKci, @function
_ZN12hash_control7replaceEPKci:
.LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	strlen
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control6loopupEPKcjPPP10hash_entryPm
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L31
	movl	$0, %eax
	jmp	.L32
.L31:
	movl	-12(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-16(%ebp), %eax
.L32:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE19:
	.size	_ZN12hash_control7replaceEPKci, .-_ZN12hash_control7replaceEPKci
	.align 2
.globl _ZN12hash_control5eraseEPKc
	.type	_ZN12hash_control5eraseEPKc, @function
_ZN12hash_control5eraseEPKc:
.LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	strlen
	movl	$0, 16(%esp)
	leal	-20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12hash_control6loopupEPKcjPPP10hash_entryPm
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L34
	movl	$0, %eax
	jmp	.L35
.L34:
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	cmpl	-12(%ebp), %eax
	je	.L36
	call	abort
.L36:
	movl	-20(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZdlPv
	movl	-16(%ebp), %eax
.L35:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE20:
	.size	_ZN12hash_control5eraseEPKc, .-_ZN12hash_control5eraseEPKc
	.section	.rodata
	.align 4
	.type	_ZZN12hash_control8get_sizeEvE16hash_size_primes, @object
	.size	_ZZN12hash_control8get_sizeEvE16hash_size_primes, 20
_ZZN12hash_control8get_sizeEvE16hash_size_primes:
	.long	1021
	.long	4051
	.long	8599
	.long	16699
	.long	65537
	.ident	"GCC: (Gentoo 4.5.3-r1 p1.0, pie-0.4.5) 4.5.3"
	.section	.note.GNU-stack,"",@progbits

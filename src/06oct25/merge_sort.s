	.file	"merge_sort.c"
	.text
	.p2align 4
	.globl	mergeSort
	.type	mergeSort, @function
mergeSort:
.LFB31:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movslq	%esi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	cmpl	$1, %r12d
	jle	.L1
	movl	%r12d, %r15d
	movq	%rdi, %r14
	sarl	%r15d
	movl	%r15d, %esi
	call	mergeSort
	movslq	%r15d, %rax
	movl	%r12d, %r9d
	subl	%r15d, %r9d
	leaq	(%r14,%rax,4), %r8
	movq	%r8, %rdi
	movl	%r9d, %esi
	movl	%r9d, 24(%rsp)
	movq	%r8, 16(%rsp)
	call	mergeSort
	leaq	0(,%r12,4), %rax
	movq	%rax, %rdi
	movq	%rax, 8(%rsp)
	call	malloc@PLT
	movl	24(%rsp), %r9d
	movq	16(%rsp), %r8
	movq	%rax, %r12
	testl	%r9d, %r9d
	je	.L11
	movl	$1, %edx
	xorl	%ebp, %ebp
	xorl	%r13d, %r13d
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L19:
	movl	%esi, %eax
	addl	$1, %r13d
	movl	%eax, -4(%r12,%rdx,4)
	leaq	1(%rdx), %rax
	cmpl	%r13d, %r15d
	jle	.L13
.L20:
	cmpl	%ebp, %r9d
	jle	.L13
	movq	%rax, %rdx
.L6:
	movslq	%r13d, %rax
	movl	(%r14,%rax,4), %esi
	movslq	%ebp, %rax
	movl	(%r8,%rax,4), %eax
	cmpl	%eax, %esi
	jle	.L19
	movl	%eax, -4(%r12,%rdx,4)
	addl	$1, %ebp
	leaq	1(%rdx), %rax
	cmpl	%r13d, %r15d
	jg	.L20
.L13:
	movl	%edx, %ebx
	cmpl	%r13d, %r15d
	jle	.L8
.L3:
	movslq	%ebx, %rax
	movq	%r8, 24(%rsp)
	leaq	(%r12,%rax,4), %rdi
	leal	-1(%r15), %eax
	addl	%ebx, %r15d
	movl	%r9d, 16(%rsp)
	subl	%r13d, %eax
	movl	%r15d, %ebx
	leaq	4(,%rax,4), %rdx
	movslq	%r13d, %rax
	subl	%r13d, %ebx
	leaq	(%r14,%rax,4), %rsi
	call	memcpy@PLT
	movq	24(%rsp), %r8
	movl	16(%rsp), %r9d
.L8:
	cmpl	%ebp, %r9d
	jle	.L10
	subl	$1, %r9d
	movslq	%ebx, %rdx
	movslq	%ebp, %rax
	subl	%ebp, %r9d
	leaq	(%r12,%rdx,4), %rdi
	leaq	(%r8,%rax,4), %rsi
	leaq	4(,%r9,4), %rdx
	call	memcpy@PLT
.L10:
	movq	8(%rsp), %rdx
	movq	%r14, %rdi
	movq	%r12, %rsi
	call	memcpy@PLT
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r12, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	jmp	free@PLT
	.p2align 4,,10
	.p2align 3
.L1:
	.cfi_restore_state
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	.cfi_restore_state
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
	xorl	%r13d, %r13d
	jmp	.L3
	.cfi_endproc
.LFE31:
	.size	mergeSort, .-mergeSort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

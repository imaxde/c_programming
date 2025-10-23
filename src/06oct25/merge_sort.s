	.file	"merge_sort.c"
	.text
	.p2align 4
	.globl	merge
	.type	merge, @function
merge:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movq	%rsi, %r9
	movq	%rdx, %r10
	movl	%ecx, %r11d
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbx
	testl	%ecx, %ecx
	jle	.L12
	testl	%r8d, %r8d
	jle	.L12
	movl	$1, %ecx
	xorl	%esi, %esi
	xorl	%edi, %edi
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L28:
	movl	%eax, %edx
	addl	$1, %edi
	leaq	1(%rcx), %rax
	movl	%edx, -4(%r10,%rcx,4)
	cmpl	%r11d, %edi
	jge	.L2
.L29:
	cmpl	%r8d, %esi
	jge	.L2
	movq	%rax, %rcx
.L5:
	movslq	%edi, %rax
	movslq	%esi, %rdx
	movl	(%rbx,%rax,4), %eax
	movl	(%r9,%rdx,4), %edx
	cmpl	%eax, %edx
	jge	.L28
	movl	%edx, -4(%r10,%rcx,4)
	addl	$1, %esi
	leaq	1(%rcx), %rax
	cmpl	%r11d, %edi
	jl	.L29
.L2:
	cmpl	%edi, %r11d
	jle	.L7
	movslq	%edi, %rax
	movl	%r11d, %ebp
	leaq	(%rbx,%rax,4), %r12
	subl	%edi, %ebp
	movslq	%ecx, %rax
	leaq	(%r10,%rax,4), %rbx
	salq	$2, %rbp
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	movl	(%r12,%rax), %edx
	movl	%edx, (%rbx,%rax)
	addq	$4, %rax
	cmpq	%rax, %rbp
	jne	.L8
	addl	%ecx, %r11d
	movl	%r11d, %ecx
	subl	%edi, %ecx
.L7:
	cmpl	%esi, %r8d
	jle	.L1
	subl	%esi, %r8d
	movslq	%esi, %rax
	movslq	%ecx, %rcx
	leaq	(%r9,%rax,4), %rsi
	salq	$2, %r8
	leaq	(%r10,%rcx,4), %rcx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L10:
	movl	(%rsi,%rax), %edx
	movl	%edx, (%rcx,%rax)
	addq	$4, %rax
	cmpq	%r8, %rax
	jne	.L10
.L1:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore_state
	xorl	%ecx, %ecx
	xorl	%esi, %esi
	xorl	%edi, %edi
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	merge, .-merge
	.p2align 4
	.globl	merge_sort
	.type	merge_sort, @function
merge_sort:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	movq	%rsp, -72(%rbp)
	cmpl	$1, %esi
	jle	.L30
	movl	%esi, %r15d
	movl	%esi, %ecx
	movq	%rsp, %rsi
	movq	%rdi, %rbx
	sarl	%r15d
	movslq	%r15d, %r8
	salq	$2, %r8
	leaq	15(%r8), %rax
	movq	%rax, %rdx
	andq	$-4096, %rax
	subq	%rax, %rsi
	andq	$-16, %rdx
	cmpq	%rsi, %rsp
	je	.L34
.L48:
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	cmpq	%rsi, %rsp
	jne	.L48
.L34:
	andl	$4095, %edx
	subq	%rdx, %rsp
	testq	%rdx, %rdx
	jne	.L49
.L35:
	movl	%ecx, %r13d
	movq	%rsp, %rsi
	movq	%rsp, %r14
	subl	%r15d, %r13d
	movslq	%r13d, %rax
	leaq	15(,%rax,4), %rax
	movq	%rax, %rdx
	andq	$-4096, %rax
	andq	$-16, %rdx
	subq	%rax, %rsi
.L36:
	cmpq	%rsi, %rsp
	je	.L37
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L36
.L37:
	andl	$4095, %edx
	subq	%rdx, %rsp
	testq	%rdx, %rdx
	je	.L38
	orq	$0, -8(%rsp,%rdx)
.L38:
	movl	%r15d, %edx
	movq	%rbx, %rsi
	movq	%r14, %rdi
	movl	%ecx, -84(%rbp)
	salq	$2, %rdx
	movq	%r8, -80(%rbp)
	movq	%rsp, %r12
	call	memcpy@PLT
	movl	-84(%rbp), %ecx
	cmpl	%r15d, %ecx
	jle	.L39
	movq	-80(%rbp), %r8
	subl	$1, %ecx
	movq	%r12, %rdi
	subl	%r15d, %ecx
	leaq	4(,%rcx,4), %rdx
	leaq	(%rbx,%r8), %rsi
	call	memcpy@PLT
.L39:
	movl	%r15d, %esi
	movq	%r14, %rdi
	call	merge_sort
	movl	%r13d, %esi
	movq	%r12, %rdi
	call	merge_sort
	movl	%r13d, %r8d
	movl	%r15d, %ecx
	movq	%rbx, %rdx
	movq	%r12, %rsi
	movq	%r14, %rdi
	call	merge
	movq	-72(%rbp), %rsp
.L30:
	movq	-56(%rbp), %rax
	subq	%fs:40, %rax
	jne	.L50
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	.cfi_restore_state
	orq	$0, -8(%rsp,%rdx)
	jmp	.L35
.L50:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1:
	.size	merge_sort, .-merge_sort
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

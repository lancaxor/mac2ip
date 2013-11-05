	.file	"mac2ipc.c"
	.globl	ipoksize
	.bss
	.align 4
	.type	ipoksize, @object
	.size	ipoksize, 4
ipoksize:
	.zero	4
	.globl	macoksize
	.align 4
	.type	macoksize, @object
	.size	macoksize, 4
macoksize:
	.zero	4
	.section	.rodata
.LC0:
	.string	"Enter MAC"
.LC1:
	.string	"%s"
.LC2:
	.string	"Enter outer IP"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movq	$0, -8(%rbp)
	movq	$0, -16(%rbp)
	movl	$.LC0, %edi
	call	puts
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC2, %edi
	call	puts
	leaq	-240(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	splitIP
	.type	splitIP, @function
splitIP:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, %eax
	movb	%al, -76(%rbp)
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$1, -20(%rbp)
	movq	-72(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	je	.L4
	movq	-72(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %eax
	cmpb	$58, %al
	je	.L4
	movq	-72(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %eax
	cmpb	$46, %al
	jne	.L5
.L4:
	movl	$2, -20(%rbp)
	jmp	.L6
.L5:
	movq	-72(%rbp), %rax
	addq	$4, %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	je	.L7
	movq	-72(%rbp), %rax
	addq	$4, %rax
	movzbl	(%rax), %eax
	cmpb	$58, %al
	je	.L7
	movq	-72(%rbp), %rax
	addq	$4, %rax
	movzbl	(%rax), %eax
	cmpb	$46, %al
	jne	.L8
.L7:
	movl	$4, -20(%rbp)
	jmp	.L6
.L8:
	movl	$1024, %eax
	jmp	.L9
.L6:
	cmpb	$109, -76(%rbp)
	jne	.L10
	movl	-20(%rbp), %eax
	movl	%eax, macoksize(%rip)
	jmp	.L11
.L10:
	cmpb	$105, -76(%rbp)
	jne	.L12
	movl	-20(%rbp), %eax
	movl	%eax, ipoksize(%rip)
	jmp	.L11
.L12:
	movl	$1025, %eax
	jmp	.L9
.L11:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -40(%rbp)
	cltq
	salq	$3, %rax
	leaq	7(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movq	$16, -104(%rbp)
	movl	$0, %edx
	divq	-104(%rbp)
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$7, %rax
	shrq	$3, %rax
	salq	$3, %rax
	movq	%rax, -48(%rbp)
	movl	$12, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	-20(%rbp)
	movl	%eax, -52(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L13
.L16:
	movq	-48(%rbp), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	movq	$0, (%rax,%rdx,8)
	movl	$0, -28(%rbp)
	jmp	.L14
.L15:
	movl	-28(%rbp), %eax
	movl	-20(%rbp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	subl	$1, %eax
	movl	%eax, -56(%rbp)
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbq	%al, %rax
	movq	%rax, %rdi
	call	atoi
	cvtsi2sd	%eax, %xmm0
	movsd	%xmm0, -88(%rbp)
	cvtsi2sd	-56(%rbp), %xmm0
	movabsq	$4621819117588971520, %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -96(%rbp)
	movsd	-96(%rbp), %xmm0
	call	pow
	mulsd	-88(%rbp), %xmm0
	cvttsd2siq	%xmm0, %rcx
	movq	-48(%rbp), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	movq	%rcx, (%rax,%rdx,8)
	addl	$1, -28(%rbp)
.L14:
	movl	-28(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L15
	addl	$1, -24(%rbp)
.L13:
	movl	-24(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L16
	movq	-48(%rbp), %rax
.L9:
	movq	%rbx, %rsp
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	splitIP, .-splitIP
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits

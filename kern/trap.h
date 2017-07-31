/* See COPYRIGHT for copyright information. */

#ifndef JOS_KERN_TRAP_H
#define JOS_KERN_TRAP_H
#ifndef JOS_KERNEL
# error "This is a JOS kernel header; user programs should not #include it"
#endif

#include <inc/trap.h>
#include <inc/mmu.h>

/* The kernel's interrupt descriptor table */
extern struct Gatedesc idt[];
extern struct Pseudodesc idt_pd;

extern void trap_divide();
extern void trap_debug();
extern void trap_nmi();
extern void trap_brkpt();
extern void trap_oflow();
extern void trap_bound();
extern void trap_illop();
extern void trap_device();
extern void trap_dblflt();
extern void trap_coproc();
extern void trap_tss();
extern void trap_segnp();
extern void trap_stack();
extern void trap_gpflt();
extern void trap_pgflt();
extern void trap_res();
extern void trap_fperr();
extern void trap_align();
extern void trap_mchk();
extern void trap_simderr();

void trap_init(void);
void trap_init_percpu(void);
void print_regs(struct PushRegs *regs);
void print_trapframe(struct Trapframe *tf);
void page_fault_handler(struct Trapframe *);
void backtrace(struct Trapframe *);

#endif /* JOS_KERN_TRAP_H */

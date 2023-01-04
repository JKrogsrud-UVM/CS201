# this is the code from Lecture 3-B
# * it shows how to call the function f1(14)
# * the parameter goes in a0
# * the return value of the function goes into a0
#
# here's what the stack looks like for f
#   mem[s0-4] is the saved value of ra
#   mem[s0-8] is the saved value of s0
#   mem[s0-12] is the saved value of a0
#   mem[s0-16] is i

f1:
  addi    sp, sp, -16  # reserve 4 words on the stack
  sw      ra, 12(sp)   # save ra in mem[sp+12]
  sw      s0, 8(sp)    # save fp (s0) in mem[sp+8]
  addi    s0, sp, 16   # s0 <- sp + 16
  sw      a0, -12(s0)  # save a0 in mem[sp+4]
  lw      a0, -12(s0)  # load a0 from mem[sp+4]
  addi    a0, a0, 45   # a0 <- a0 + 45
  sw      a0, -16(s0)  # store a0 in mem[sp]; this is i
  lw      a0, -16(s0)  # load a0 from mem[sp]; this is the rtnval
  lw      s0, 8(sp)    # load s0 from mem[sp+8]
  lw      ra, 12(sp)   # load ra from mem[sp+12]
  addi    sp, sp, 16   # restore sp: sp ¬ sp + 16
  jalr    x0, ra, 0    # jump to return address

main:
  addi sp, x0, 64      # set the stack pointer to 64 (arbitrary value > 0)
  addi a0, x0, 14      # put 14 in a0 (the parameter)
  jal  ra, f1          # jump to f, saving the return value in ra
  addi a2, a0, 0       # a random statement after the function call

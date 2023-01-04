# example: the for loop
#
# assume that i is stored in mem[s0-12]
#
# for (i=0; i<4; ++i) {
#   // do something
# }
# // after the loop
#
# we load 4 into a1 each time because a1 could potentially
# be used inside the loop; similary, after the loop body,
# we load i again into a0 because a0 could have been used
# inside the loop

  # this is setup
  addi s0, x0, 16

  addi a0, x0, 0 # a0 <- 0
  sw a0, -12(s0) # save i to mem[s0-12]
L1:
  addi a1, x0, 4 # a1 <- 4
  lw a0, -12(s0) # load i from mem[s0-12]
  beq a0, a1, L2 # compare
  # do something
  lw a0, -12(s0) # load i from mem[s0-12]
  addi a0, a0, 1 # a0 <- a0 + 1
  sw a0, -12(s0) # save i to mem[s0-12]
  jal x0, L1     # back to top of loop
L2:
  # after the loop


# example: the while loop
#
# assume that i is stored in mem[s0-16]
# assume that j is stored in mem[s0-20]
#
# i = 8;
# while (i > j) {
#   // do something
#   i = i - 1;
# }
# after the loop

  # this is setup
  addi s0, x0, 32
  addi a1, x0, 5
  sw a1, -20(s0)

  addi a0, x0, 8  # a0 <- 8
  sw a0, -16(s0)  # save i to mem[s0-16]
L1:
  lw a0, -16(s0)  # load i from mem[s0-16]
  lw a1, -20(s0)  # load j from mem[s0-20]
  bge a1, a0, L2  # branch if a1 >= a0
  # do something
  lw a0, -16(s0)  # load i from mem[s0-16]
  addi a0, a0, -1 # subtract 1 from a0
  sw a0, -16(s0)  # store i in mem[s0-16]
  jal x0, L1      # back to top of loop
L2:
  # after the loop

# example: if-then-else statement
#
# assume that i is stored in mem[s0-16]
# assume that j is stored in mem[s0-20]
#
# if (i < j) {
#   // do something
# } else {
#   // do something else
# }
# after the if-then-else

  lw a0, -16(s0)  # load i
  lw a1, -20(s0)  # load j
  blt a0, a1, L1
  # do something else
  jal x0, L2
L1:
  # do something
L2:
  # after the if-then-else


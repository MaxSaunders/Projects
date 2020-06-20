# Max Saunders ------ 9/13/19
# Lab 2
# Write a program which increments from 0 to 15 and 
# display results in Decimal on the console and hexidecimal

.data
NewLine:		.asciiz		"\n"
Space:			.asciiz		"	"


.text
	main:
		li $t1, 1
	Loop:	bgt $t1, 15, Exit	#exit condition
		
		
		move $a0, $t1
		li $v0, 1		#Print value
		syscall
		
		la $a0, Space
		li $v0, 4
		syscall
		
		move $a0, $t1
   		li $v0, 34
   		syscall			#print in hexadeciaml

   		la $a0, NewLine		# Print /n
   		li $v0, 4
   		syscall
		
		addi $t1, $t1, 1	#increment
		j Loop			#loop
		
		
	Exit:	li $v0, 10		#exit
		syscall
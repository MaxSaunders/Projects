# Max Saunders -- 11/1/19
# lab8
# Part A - Letter Frequency Counter
# Part B - Histogram
# Part C - Word Frequency Counter
# then print in decimal value
#===============================================================
#Registers used:
# $a0 - Used to store string input
# $t0 - Used to store sting through code
# $s0 - Used to store the string for partA
# $t1 - Used to store characters of the string
# $t2 - Used to store characters for the first section
# $t3 - Counter for F
# $t4 - Counter for L
# $t5 - Counter for O
# $t6 - Counter for R
# $t7 - Counter for I
# $t8 - Counter for D
# $t9 - Counter for A
# $s1 - Counter for P
# $s2 - Counter for Y
# $s3 - Pointer for PartB

.data
	NewLine:	.asciiz 	"\n"
 	string:		.space 		800
 	space:		.asciiz 	" "
 	dashes:		.asciiz		":------------"
 	f:		.asciiz		"F"
 	l:		.asciiz		"L"
 	o:		.asciiz		"O"
 	r:		.asciiz		"R"
 	i:		.asciiz		"I"
 	d:		.asciiz		"D"
 	a:		.asciiz		"A"
 	p:		.asciiz		"P"
 	y:		.asciiz		"Y"
 	hash:		.asciiz		"#"
 	colon:		.asciiz		":"
 	frequency:	.asciiz		"\nLetter Frequency:\n"
 	histogram:	.asciiz		"\nHistogram: \n"
 	paragraph:	.asciiz		"Florida has teams in all of the major league sports — National  Football  League,  Major  League  Baseball,  National  Basketball  Association, National Hockey League, and Major League Soccer. In the early 1980s, Florida had major league teams in only the NFL. Florida has since added two NBA teams in the late 1980s. Florida added two NHL teams in the 1990s as part of the NHL's expansion into the south, and two MLB teams in the 1990s. Florida's most recent major-league team, Orlando City, began play in MLS in 2015."
	case1:		.asciiz		"It was the game of Humans vs. Zombies, a highly imaginative version of tag played by groups across the globe, and the Clearwater, Florida, native is one of those responsible for bringing it to Florida Poly's campus. Human players must remain vigilant and defend themselves with socks and dart blasters to avoid being tagged by a growing zombie horde."
	out0:		.asciiz		"Please enter text: \n"
	out1:		.asciiz		"Please enter the first word: "
	out2:		.asciiz		"Please enter the second word: "
	divider:	.asciiz		"\n=======================================================\n"
	
.text
main:
	li, $t3, 0
	li, $t4, 0
	li, $t5, 0
	li, $t6, 0
	li, $t7, 0
	li, $t8, 0
	li, $t9, 0
	li, $s1, 0
	li, $s2, 0
	
	la $a0, divider
	li $v0, 4
	syscall
	la $a0, out0
	syscall
	li $v0, 8
	la $a0, string
	li $a1, 800		#Asks for user input
	syscall
	la $t0, string
	la $s0, string
	la $s3, string
	
toLowerCase:	
	lb $t2, 0($t0)	 	 #loads next character
	beqz $t2, print   	 # if is equal to zero, the string is terminated 
	bge $t2, 'A', upperCaseTest2	#if (character >= 'A')
    
	j continue   
	
upperCaseTest2: 
	# && character <= 'Z') 
     	ble $t2, 'Z', isUpperCase
     	
     	j continue
     	
continue: 
   	# Continue the iteration 
   	addi $t0, $t0, 1   
	# Increment the address 
	j toLowerCase 
	
isUpperCase: 
	# add 32, so it goes lower case 
	addi $t2, $t2, 32
	
	sb $t2, 0($t0) 
        # store it in the string 
           
	j continue 
        # continue iteration as always 
               

print:
	li $v0, 4 # Print the string 
	la $a0, string
	#syscall 
	
#==========================================================================   
	
PartA:	lb $t1, 0($s0)
	beqz $t1, results
	beq $t1, 'f', isF
	beq $t1, 'l', isL
	beq $t1, 'o', isO
	beq $t1, 'r', isR
	beq $t1, 'i', isI
	beq $t1, 'd', isD
	beq $t1, 'a', isA
	beq $t1, 'p', isP
	beq $t1, 'y', isY
	addi $s0, $s0, 1
	j PartA
	
isF:	addi $t3, $t3, 1
	addi $s0, $s0, 1
	j PartA
	
isL:	addi $t4, $t4, 1
	addi $s0, $s0, 1
	j PartA
	
isO:	addi $t5, $t5, 1
	addi $s0, $s0, 1
	j PartA
	
isR:	addi $t6, $t6, 1
	addi $s0, $s0, 1
	j PartA
	
isI:	addi $t7, $t7, 1
	addi $s0, $s0, 1
	j PartA
	
isD:	addi $t8, $t8, 1
	addi $s0, $s0, 1
	j PartA
	
isA:	addi $t9, $t9, 1
	addi $s0, $s0, 1
	j PartA
	
isP:	addi $s1, $s1, 1
	addi $s0, $s0, 1
	j PartA
	
isY:	addi $s2, $s2, 1
	addi $s0, $s0, 1
	j PartA

results:##Print letter frequency
	li $v0, 4	 # A newline   
	la $a0, frequency
	syscall
	la $a0, NewLine 
	syscall 
	
	la $a0, f
	syscall
	la $a0, dashes
	syscall
	move $a0, $t3
	li $v0, 1
	syscall
	
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, l
	syscall
	la $a0, dashes
	syscall
	move $a0, $t4
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, o
	syscall
	la $a0, dashes
	syscall
	move $a0, $t5
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, r
	syscall
	la $a0, dashes
	syscall
	move $a0, $t6
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, i
	syscall
	la $a0, dashes
	syscall
	move $a0, $t7
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, d
	syscall
	la $a0, dashes
	syscall
	move $a0, $t8
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, a
	syscall
	la $a0, dashes
	syscall
	move $a0, $t9
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, p
	syscall
	la $a0, dashes
	syscall
	move $a0, $s1
	li $v0, 1
	syscall
	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, y
	syscall
	la $a0, dashes
	syscall
	move $a0, $s2
	li $v0, 1
	syscall
	
#==========================================================================
##Print Histogram

PartB:	li $v0, 4 	# A newline   
	la $a0, histogram
	syscall
	la $a0, NewLine 
	syscall 
	
	la $a0, f		#F
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileF:	beq $s4, $t3, jump1	
	syscall
	addi $s4, $s4, 1
	j whileF
jump1:
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, l		#L
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileL:	beq $s4, $t4, jump2
	syscall
	addi $s4, $s4, 1
	j whileL
jump2:
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, o		#O
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileO:	beq $s4, $t5, jump3
	syscall
	addi $s4, $s4, 1
	j whileO
jump3:
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, r		#R
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileR:	beq $s4, $t6, jump4
	syscall
	addi $s4, $s4, 1
	j whileR
jump4:
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, i		#I
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileI:	beq $s4, $t7, jump5
	syscall
	addi $s4, $s4, 1
	j whileI
jump5:	
	li $v0, 4	 # A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, d		#D
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileD:	beq $s4, $t8, jump6
	syscall
	addi $s4, $s4, 1
	j whileD
jump6:
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, a		#A
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileA:	beq $s4, $t9, jump7
	syscall
	addi $s4, $s4, 1
	j whileA
jump7:	
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, p		#P
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileP: beq $s4, $s1, jump8
	syscall
	addi $s4, $s4, 1
	j whileP
jump8:	
	li $v0, 4 	# A newline   
	la $a0, NewLine 
	syscall 
	
	la $a0, y		#Y
	syscall
	la $a0, colon
	syscall
	la $a0, hash
	li $s4, 0
whileY:	beq $s4, $s2, jump9
	syscall
	addi $s4, $s4, 1
	j whileY
	
jump9:	la $a0, NewLine
	li $v0, 4
	syscall
	syscall
#==========================================================================
	
PartC:	li $t4, 0
	la $t0, paragraph
	li $v0, 4
	la $a0, out1
	syscall
	
	la $a0, string
	la $a1, 10
	la $t1, string
	
	li $v0, 8	#Asks for user input for 1st word
	syscall
	la $t0, string
	
	li $v0, 4
	move $a0, $t0
	syscall
	
w:	lb $t2, ($t0)
	lb $t3, ($t1)
	beqz $t2, end
	beq $t2, $t3, check
	addi $t2, $t2, 1
	j w
	
check:	

end:

	li $v0, 10 
	syscall







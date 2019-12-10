.name "1"
.comment "la meilleure defense c'est d'avoir une bonne defense"

start:

start_piege:
ld		%-16, r5				# r2 = soustraction de start pr aller a r2 : carry a 1
ld		%-12, r4				# r4 = suite (soustraction de start pr aller a r3 : suite du carry)
ld		%-8, r6					# r6 = soustration de start pr aller a r10 : zjmp
ld		%150994944, r10			# r10 = zjmp
ld		%42991616, r2			# debut de carry a 1
ld		%256, r3				# suite du carry a 1
ld		%16, r16				# decrementation de start
ld		%12, r7					# r7 = addition de end pr aller a r7 : carry a 1
ld		%16, r9					# r9 = suite (addition de end pr aller a r9 : suite du carry)
ld		%20, r11				# r11 = addition de end pr aller a r11 : zjmp
ld		%23, r12				# compteur pour le nombres de pieges
ld		%1, r13
ld		%0, r8					# carry = 1
fork	%:start_piege

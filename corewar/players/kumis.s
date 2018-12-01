.name	"Drunken_by_Kumis"
.comment "Өте мықты бағдарлама"

begin:
	sti		r1, %:step, %1
	sti		r1, %:born, %1
	sti		r1, %:scream, %1
	fork	%:born
step:
	live	%0
	fork	%:step
born:
	ld		%0, r2
	live	%0
	zjmp	%3
	fork	%:born
scream:
	live	%0

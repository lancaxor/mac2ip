install:
	@echo installing...
	@gcc -std=c99 bcopy.c -o bcopy
	@echo application successfull installed!
	@echo Enter ./bcopy -h for help.

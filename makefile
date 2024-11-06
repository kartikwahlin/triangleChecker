.PHONY: clean run compile
run: triChecker
	@./triChecker
clean:
	rm *.o
	rm triChecker
compile triChecker: triChecker.o
	@gcc -o triChecker triChecker.o
triChecker.o: triChecker.c
	@gcc -c triChecker.c

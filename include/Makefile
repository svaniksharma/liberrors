LIBERRORS="liberrors.c"

liberrors_debug: liberrors_lib
	"$(CC)" -c -g -Wall test/liberrors_test.c -o test/liberrors_test.o -DLIBERRORS_ALLOW_DEBUG
	"$(CC)" -g -Wall "$(LIBERRORS)" test/liberrors_test.o -o test/liberrors_test -lerrors -L.
	rm -r test/liberrors_test.dSYM
	./make_tests.sh c

liberrors_lib: liberrors_obj liberrors_so

liberrors_obj: liberrors.c liberrors.h
	"$(CC)" -c -g -Wall "$(LIBERRORS)" liberrors.c

liberrors_so: liberrors.o
	"$(CC)" -g -Wall liberrors.o -o liberrors.so -shared -fPIC


clean:
	-rm liberrors.so
	-rm -f *.o test/*.o
	-./make_tests.sh d
	-rm test/liberrors_test

LIBERRORS="liberrors.c"

liberrors_debug:
	cc -g -Wall "$(LIBERRORS)" test/liberrors_test.c -o test/liberrors_test -DLIBERRORS_ALLOW_DEBUG
	rm -r test/liberrors_test.dSYM
	./make_tests.sh c

clean:
	./make_tests.sh d

CC=gcc
W=-Wall -Wextra -Werror
CFLAGS=-std=c11 -g

LIBS=-lcheck
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS += -lsubunit -lm
endif

TARGET=s21_math

SRCS=s21_math.c

TEST_SRC=test_math.c

TEST_TARG=test

all: clean s21_math.a test gcov_report

check :
	find -name "*.c" -exec clang-format -i {} \;
	find -name "*.h" -exec clang-format -i {} \;

s21_math.o :
	$(CC) ${W} $(SRCS) $(CFLAGS) -c

s21_math.a: s21_math.o
	ar r libs21_math.a s21_math.o
	ar r s21_math.a s21_math.o

test: clean s21_math.a
	$(CC) $(TEST_SRC) $(CFLAGS) $(LIBS) -L. -ls21_math -o $(TEST_TARG)
	./$(TEST_TARG)
	rm -f *.o

test2 : clean s21_math.a
	$(CC) test.c $(CFLAGS) $(LIBS) -L. -ls21_math -o test2
	# ./test2

gcov_report: 
	$(CC) --coverage ${W} $(FLAGS) $(SRCS) $(TEST_SRC) -o $(TEST_TARG) $(LIBS)
	./$(TEST_TARG)
	lcov -t "$(TEST_TARG)" -o $(TEST_TARG).info -c -d .
	genhtml -o report $(TEST_TARG).info
	rm -f *.gcda *.gcno *.info $(TEST_TARG)

clean:
	rm -f *.a *.o
	rm -f *.gcno *.gcda *.info *.gcov $(TEST_TARG)
	rm -rf report
	
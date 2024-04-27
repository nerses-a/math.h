CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
STRING = s21_math
OS = $(shell uname -s)

GCOV_FLAGS = -ftest-coverage -fprofile-arcs -fPIC --coverage

LIBRARY_SRC = functions/s21_abs.c functions/s21_asin.c functions/s21_acos.c functions/s21_atan.c functions/s21_ceil.c functions/s21_floor.c functions/s21_fabs.c functions/s21_fmod.c functions/s21_log.c functions/s21_pow.c functions/s21_sin.c functions/s21_cos.c functions/s21_sqrt.c functions/s21_tan.c functions/s21_exp.c

LIBRARY_OBJ = $(LIBRARY_SRC:.c=.o)

ifeq ($(OS), Linux)
	ADD_FLAGS += -lm -lpthread -lrt -lsubunit 
	TEST_FLAGS = -lcheck
	OPENER = xdg_open
endif

ifeq ($(OS), Darwin)
	TEST_FLAGS = $(shell pkg-config --cflags --libs check)
	OPENER = open
endif

all: clean s21_math.a test gcov_report

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_math.a: $(LIBRARY_OBJ)
	ar rcs $(STRING).a $^

test: $(LIBRARY_SRC) $(STRING).a
	$(CC) $(CFLAGS) tests/test.c $(STRING).a -o test  $(TEST_FLAGS) $(ADD_FLAGS)
	./test

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test

cppcheck:
	cppcheck —enable=all —suppress=missingIncludeSystem .

style_check:
	clang-format -n --style=Google *.[ch]

style_clean:
	clang-format -i --style=Google *.[ch]

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info test
	rm -rf report gcov_test
	rm -rf functions/*.o
	rm -rf tests/*.o

rebuild:
	make clean
	make all

gcov_report: test
	$(CC) $(СFLAGS) $(GCOV_FLAGS) -ftest-coverage tests/test.c $(LIBRARY_SRC) $(TEST_FLAGS) $(ADD_FLAGS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

CFLAGS = -Wall -Werror -g -O0

all: constants_lesson constants_lesson_preprocessed

constants_lesson: constants_lesson.c
	gcc $(CFLAGS) constants_lesson.c -o constants_lesson

constants_lesson_preprocessed: constants_lesson
	gcc -E constants_lesson.c > constants_lesson_preprocessed.c

clean:
	rm -f constants_lesson
	rm -f constants_lesson_preprocessed.c


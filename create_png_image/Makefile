
CFLAGS = -Wall -Werror -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -g -O0

create_png_image: create_png_image.c
	gcc $(CFLAGS) create_png_image.c -o create_png_image -lpng

clean:
	rm -f create_png_image



CFLAGS = -Wall -g -O0
# gcc $(CFLAGS) hidapi_test.c -o hidapi_test -lhidapi-hidraw

hidapi_test: hidapi_test.c
	gcc $(CFLAGS) hidapi_test.c -o hidapi_test -lusb-1.0

clean:
	rm -f hidapi_test


#include <stdio.h> // printf
#include <wchar.h> // wprintf

// #include "/usr/include/hidapi/hidapi.h"
#include "hidapi/hidapi.h"

#define MAX_STR 255

int main(int argc, char* argv[])
{

	printf("test");

	int res;
	unsigned char buf[65];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i;

	// Initialize the hidapi library
	res = hid_init();

	// Open the device using the VID, PID,
	// and optionally the Serial number.

	// Bus 003 Device 013: ID 1e7d:2dd2 ROCCAT ROCCAT Kone Pure Ultra
	handle = hid_open(0x1E7D, 0x2DD2, NULL);

	// Read the Manufacturer String



	res = hid_read(handle, buf, 65);

	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	res = hid_exit();

	return 0;

	// Toggle LED (cmd 0x80). The first byte is the report number (0x0).
	// buf[0] = 0x0;
	// buf[1] = 0x80;
	// res = hid_write(handle, buf, 65);

	// Request state (cmd 0x81). The first byte is the report number (0x0).
	// buf[0] = 0x0;
	// buf[1] = 0x81;
	// res = hid_write(handle, buf, 65);

	// // Read requested state
	// res = hid_read(handle, buf, 65);

	// // Print out the returned buffer.
	// for (i = 0; i < 4; i++)
	// 	printf("buf[%d]: %d\n", i, buf[i]);

	// // Close the device
	// hid_close(handle);

	// // Finalize the hidapi library
	// res = hid_exit();

	// return 0;
}
#include <stdio.h> // printf
#include <wchar.h> // wprintf

// #include <hidapi.h> // is not found but i have libhidapi-dev installed
// #include "/usr/include/hidapi/hidapi.h"
#include <hidapi/hidapi.h> // is not found but i have libhidapi-dev installed
#include <stdlib.h>
#include "./../c_helpers/typename.c"

#define MAX_STR 255

void list_devices()
{
  int res;
  unsigned char buf[64];
  #define MAX_STR 1024
  wchar_t wstr[MAX_STR];
  hid_device *handle;
  int i;

  // Enumerate and print the HID devices on the system
  struct hid_device_info *devs, *cur_dev;
    char foundpath[MAX_STR]; // 1024 should be enough for anyone :)

  devs = hid_enumerate(0x0, 0x0);
  cur_dev = devs;
  while (cur_dev) {
    printf("\nVendor id: product id: %04hx/%04hx\n", cur_dev->vendor_id, cur_dev->product_id);
    cur_dev = cur_dev->next;
  }
  hid_free_enumeration(devs);
  
  
  // Open the device using the VID, PID,
  // and optionally the Serial number.
  // handle = hid_open(0x16C0, 0x0486, NULL);
  // handle = hid_open_path( foundpath );

}

int main(int argc, char* argv[])
{
	if(geteuid() != 0)
	{
		printf("root required: usb device access needs root");
		exit(1);
	// Tell user to run app as root, then exit.
	}

	list_devices();

	// int res;
	// unsigned char buf[65];
	// wchar_t wstr[MAX_STR];
	// hid_device *handle;
	// int i;

	// // Initialize the hidapi library
	// res = hid_init();
	
	// // // Bus 001 Device 003: ID 09e8:0028 AKAI  Professional M.I. Corp. APC MINI 
	// // Bus 001 Device 006: ID 054c:0ce6 Sony Corp. Wireless Controller
	// // // Open the device using the VID, PID,
	// // // and optionally the Serial number.
	// handle = hid_open(0x09e8, 0x0028, NULL);//akai apc mini // not working
	// // handle = hid_open(0x054c, 0x0ce6, NULL);//dualsense working 

	// printf("typename%s", typename(handle));
	// printf("value%i", handle);
	
	// // // // Read the Manufacturer String
	// // res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	// // //printf("%s\n" , wstr);
	// // wprintf(L"Manufacturer String: %s\n", wstr);

	// // // // Read the Product String
	// // res = hid_get_product_string(handle, wstr, MAX_STR);
	// // wprintf(L"Product String: %s\n", wstr);

	// // // // Read the Serial Number String
	// // res = hid_get_serial_number_string(handle, wstr, MAX_STR);
	// // wprintf(L"Serial Number String: (%d) %s\n", wstr[0], wstr);

	// // // // Read Indexed String 1
	// // res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
	// // wprintf(L"Indexed String 1: %s\n", wstr);

	// // // Toggle LED (cmd 0x80). The first byte is the report number (0x0).
	// // buf[0] = 0x0;

	// // buf[1] = 0x80;
	// // res = hid_write(handle, buf, 65);

	// // // Request state (cmd 0x81). The first byte is the report number (0x0).
	// // buf[0] = 0x0;
	// // buf[1] = 0x81;
	// // res = hid_write(handle, buf, 65);

	// // // // Read requested state
	// // res = hid_read(handle, buf, 65);

	// // // Print out the returned buffer.
	// // for (i = 0; i < 4; i++)
	// // 	printf("buf[%d]: %d\n", i, buf[i]);

	// // // Close the device
	// hid_close(handle);

	// // // Finalize the hidapi library
	// res = hid_exit();

	return 0;
}
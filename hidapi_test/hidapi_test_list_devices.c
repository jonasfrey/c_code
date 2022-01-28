
// hidapi-enum-tst.c -- Demonstrate enumerating
//
// Build with:  (assumes you have checked out 'hidapi' into a side directory)
// Mac:
//  gcc -I ../hidapi/hidapi ../hidapi/mac/hid.c -framework IOKit -framework CoreFoundation hidapi-enum-tst.c -o hidapi-enum-tst 
// Linux (hidraw):
//  gcc -I ../hidapi/hidapi ../hidapi/linux/hid.c -ludev hidapi-enum-tst.c -o hidapi-enum-tst
// Linux (libusb):
// gcc -I ../hidapi/hidapi -I /usr/include/libusb-1.0 ../hidapi/libusb/hid.c -lpthread -lusb-1.0 hidapi-enum-tst.c -o hidapi-enum-tst
//
// Tod E. Kurt / github.com/todbot
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hidapi/hidapi.h>



void printbuf(char* buf, int bufsize) {
  printf("buf:");
  for (int i = 0; i < bufsize; i++) {
    printf("%d,", buf[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[])
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
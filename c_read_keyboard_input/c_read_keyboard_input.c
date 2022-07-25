// find out what device the keyboard is
// sudo less -f AFSD | hexdump

// sudo less -f pci-0000:02:00.0-usb-0:10:1.2-event-kbd | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.2:1.1-event-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.4:1.0-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:10:1.2-event-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.2:1.1-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:7:1.1-event-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:10:1.2-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.2:1.2-event-kbd | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:7:1.1-mouse | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.1:1.0-event | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.2:1.3-event | hexdump
// sudo less -f pci-0000:0c:00.3-usb-0:4:1.3-event | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.2:1.0-event-kbd | hexdump
// sudo less -f pci-0000:02:00.0-usb-0:4.4:1.0-event-mouse | hexdump

#include <stdio.h>
#include <stdlib.h>
int main() {


    FILE *o_file;
    o_file = fopen("/dev/input/by-path/pci-0000:02:00.0-usb-0:4.2:1.0-event-kbd", "rb"); 
    char * a_s_char = malloc(1); 
    if (o_file == NULL) {
        perror("Failed: ");
        return 1;
    }

    while(1){
        o_file = fopen("/dev/input/by-path/pci-0000:02:00.0-usb-0:4.2:1.0-event-kbd", "rb"); 
        fread(a_s_char, 1, 1, o_file); // Read in the entire file
        fclose(o_file); // Close the file
        printf("char is(char)|(dec)|(hex): %c|%u|%x\n", *a_s_char,*a_s_char,*a_s_char);
    }


    return 0;
}
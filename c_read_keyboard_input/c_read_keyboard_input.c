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
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

struct O_input_event {
struct timeval time;
u_int16_t type;
u_int16_t code;
__S32_TYPE value;
};

static int o_file;


int main() {

    struct O_input_event o_input_event;
    // FILE *o_file;
    o_file =  open("/dev/input/by-path/pci-0000:02:00.0-usb-0:4.2:1.0-event-kbd", O_RDONLY);
    // o_file = fopen("/dev/input/by-path/pci-0000:02:00.0-usb-0:4.2:1.0-event-kbd", "rb");

    char * a_s_char = malloc(1); 
    if (o_file < 0) {
        perror("Failed: ");
        return 1;
    }



    while(1){
        read(o_file, &o_input_event, sizeof(o_input_event));
        // fread(a_s_char, 1, 1, o_file); // Read in the entire file
        // printf("char is(char)|(dec)|(hex): %c|%u|%x\n", *a_s_char,*a_s_char,*a_s_char);
        // fclose(o_file); // Close the file

        printf("o_file.time.tv_usec is(li): %li\n", o_input_event.time.tv_usec);
        printf("o_file.code is(i): %i\n", o_input_event.code);

    }

    close(o_file); 

    return 0;
}
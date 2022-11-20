
// c file 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


int main() {
   /* my first program in C */

	int n_socket_filedescriptor;

	/* Open RAW socket to send on */
   n_socket_filedescriptor = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

	if(n_socket_filedescriptor == -1) {
       printf("socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW); returned -1");
	    perror("socket");
	}


   // ssize_t read(int fd, void *buf, size_t count);
   ssize_t n_read_return = 0;

   char n_buf = 0;

   int n_length = 0;
   ioctl(n_socket_filedescriptor, FIONREAD, &n_length);
   printf("n_length: %i\n", n_length);

   
   while(n_length > 0){
      n_length = read(n_socket_filedescriptor, &n_buf, n_length);
      printf("%i\n", n_buf);
      
   }

   int n_i = 0; 
   while(n_i < 1000000){
      n_read_return = read(n_socket_filedescriptor, &n_buf, 1);
      // printf("n_buf: %u\n", n_buf);
      printf("n_buf: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(n_buf));
      n_i+=1;
   }

   
   return 0;
}

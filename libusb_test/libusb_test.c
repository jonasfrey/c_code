#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

#define VENDOR_ID_AKAI_APC_MINI 0x9e8
#define PRODUCT_ID_AKAI_APC_MINI 0x28

//original code https://falsinsoft.blogspot.com/2015/02/asynchronous-bulk-transfer-using-libusb.html

void callbackUSBTransferComplete(struct libusb_transfer *xfr)
{
   printf("\ncallbackUSBTransferComplete was called");
    switch(xfr->status)
    {
        case LIBUSB_TRANSFER_COMPLETED:
            // Success here, data transfered are inside 
            // xfr->buffer
            // and the length is
            // xfr->actual_length
            printf("\n data as string %s", xfr->buffer);
            break;
        case LIBUSB_TRANSFER_CANCELLED:
            printf("\n error LIBUSB_TRANSFER_CANCELLED");
        case LIBUSB_TRANSFER_NO_DEVICE:
            printf("\n error LIBUSB_TRANSFER_NO_DEVICE");
        case LIBUSB_TRANSFER_TIMED_OUT:
            printf("\n error LIBUSB_TRANSFER_TIMED_OUT");
        case LIBUSB_TRANSFER_ERROR:
            printf("\n error LIBUSB_TRANSFER_ERROR");
        case LIBUSB_TRANSFER_STALL:
            printf("\n error LIBUSB_TRANSFER_STALL");
        case LIBUSB_TRANSFER_OVERFLOW:
            printf("\n error LIBUSB_TRANSFER_OVERFLOW");
            // Various type of errors here
            break;
    }
}

int main(){

   libusb_device_handle *dev_handle = NULL;
   libusb_device **list;
   size_t count, i;

   // Initialize library
   libusb_init(NULL);
   // Get list of USB devices currently connected
   count = libusb_get_device_list(NULL, &list);

   for(i = 0; i < count; i++)
   {
      struct libusb_device_descriptor desc;
      libusb_get_device_descriptor(list[i], &desc);

      // Is our device?
      if(
         desc.idVendor == VENDOR_ID_AKAI_APC_MINI
         && 
         desc.idProduct == PRODUCT_ID_AKAI_APC_MINI)
      {
         
         // Open USB device and get handle
         libusb_open(list[i], &dev_handle);
         printf("\ndevice found %p", dev_handle);
         break;

      }

   }

   struct libusb_transfer *xfr;
   unsigned char *data;
   const unsigned int size = 40+1;

   data = malloc(size);

   xfr = libusb_alloc_transfer(0);

   libusb_fill_bulk_transfer(
      xfr,
      dev_handle,
      0x82, // Endpoint ID
      data,
      size,
      callbackUSBTransferComplete,
      NULL,
      5000 // 5000 ms 
   );

   int submit_response = libusb_submit_transfer(xfr); 

   if(submit_response == LIBUSB_SUCCESS){printf("\n LIBUSB_SUCCESS Success (no error)");}
   if(submit_response == LIBUSB_ERROR_IO){printf("\n LIBUSB_ERROR_IO Input/output error.");}
   if(submit_response == LIBUSB_ERROR_INVALID_PARAM){printf("\n LIBUSB_ERROR_INVALID_PARAM Invalid parameter.");}
   if(submit_response == LIBUSB_ERROR_ACCESS){printf("\n LIBUSB_ERROR_ACCESS Access denied (insufficient permissions)");}
   if(submit_response == LIBUSB_ERROR_NO_DEVICE){printf("\n LIBUSB_ERROR_NO_DEVICE No such device (it may have been disconnected)");}
   if(submit_response == LIBUSB_ERROR_NOT_FOUND){printf("\n LIBUSB_ERROR_NOT_FOUND Entity not found.");}
   if(submit_response == LIBUSB_ERROR_BUSY){printf("\n LIBUSB_ERROR_BUSY Resource busy.");}
   if(submit_response == LIBUSB_ERROR_TIMEOUT){printf("\n LIBUSB_ERROR_TIMEOUT Operation timed out.");}
   if(submit_response == LIBUSB_ERROR_OVERFLOW){printf("\n LIBUSB_ERROR_OVERFLOW Overflow.");}
   if(submit_response == LIBUSB_ERROR_PIPE){printf("\n LIBUSB_ERROR_PIPE Pipe error.");}
   if(submit_response == LIBUSB_ERROR_INTERRUPTED){printf("\n LIBUSB_ERROR_INTERRUPTED System call interrupted (perhaps due to signal)");}
   if(submit_response == LIBUSB_ERROR_NO_MEM){printf("\n LIBUSB_ERROR_NO_MEM Insufficient memory.");}
   if(submit_response == LIBUSB_ERROR_NOT_SUPPORTED){printf("\n LIBUSB_ERROR_NOT_SUPPORTED Operation not supported or unimplemented on this platform.");}
   if(submit_response == LIBUSB_ERROR_OTHER){printf("\n LIBUSB_ERROR_OTHER Other error.");}
   
   if(submit_response < 0)

   {

      // Error
      printf("\nlibusb_submit_transfer error");
      printf("\nsubmit_response: %i", submit_response);
      libusb_free_transfer(xfr);
      free(data);

   }
   // while(1)
   // {
   //    if(libusb_handle_events(NULL) != LIBUSB_SUCCESS) break;
   // }
   return 0;
}
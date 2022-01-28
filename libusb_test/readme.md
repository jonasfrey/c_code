https://falsinsoft.blogspot.com/2015/02/asynchronous-bulk-transfer-using-libusb.html

![](//1.bp.blogspot.com/-3DbyIgZAIMw/VMNn_n7YCiI/AAAAAAAABV8/Fp3MEeKMp7c/s1600/usb.png)

  
  

The 'linusb' is one of the most used open source library for work with usb devices. It allow to make the basic usb data transfers operation in a little bit easier way compared to standard system calls. Here a short tutorial regarding how to use asynchronous bulk transfer.

  
  

Asynchronous transfer allow to launch the transfer command and return immediately, a callback function will be called once the data will be transfer/received completely. Using such transfer mode is quite simple, let's go to see a practical example. At first we have to initialize libusb library and look for the USB device we want to communicate to. Usually device is referred using the two values called **Vendor ID** and **Product ID**. The first is a unique number "assigned" to each hardware device producer and the second is a number reporting the device type and model.

  
```c
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

   libusb_get_device_descriptor(list\[i\], &desc);
 
   // Is our device?
   if(desc.idVendor == 0x1234 && desc.idProduct == 0x5678)
   {
      // Open USB device and get handle
      libusb_open(list\[i\], &dev_handle);
      break;
   }
}

libusb_free_device_list(list, 1);
```
  

Now we have the handle to the USB device we want to communicate. The steps to performs an asynchronous bulk transfer are basically two, first prepare the structure with all the data for "instruct" USB controller to make request operation and then submit the data for start the transfer. Please note that the transfer direction (IN or OUT) is determined by the USB endpoint type we want to communicate to/from. An USB device usually provide some connections called Endpoint for allow data transfer between host and device. An _Endpoint_ is usually marked as IN and OUT where, please note, in/out direction are from host point of view. This mean an endpoint marked as IN, for example, transfer data from device to host (usually the PC where the USB device is connected). Once clarified this point we can move to see the asynchronous transfer procedure as follow:

  
```c
struct libusb_transfer *xfr;
unsigned char *data;
const unsigned int size = 1024;

data = malloc(size);
xfr = libusb_alloc_transfer(0);

libusb_fill_bulk_transfer(xfr,
                          dev_handle,
                          0x82, // Endpoint ID
                          data,
                          size,
                          callbackUSBTransferComplete,
                          NULL,
                          5000
                          );

if(libusb_submit_transfer(xfr) < 0)
{
    // Error
    libusb_free_transfer(xfr);
    free(data);
}
```
  

Detailed explanation about each params used can be found at official documentation [here](http://libusb.sourceforge.net/api-1.0/index.html). In this example we prepare for a bulk transfer from the device using endpoint 0x82. Data size to transfer are 1024 bytes and timeout is 5000 milliseconds. _callbackUSBTransferComplete_ is the name of the function automatically called when the transfer will be completed. Please note here the function will be called also in case of errors. It's necessary to check params returned  as follow:

  
```c
void callbackUSBTransferComplete(struct libusb_transfer *xfr)
{
    switch(xfr->status)
    {
        case LIBUSB_TRANSFER_COMPLETED:
            // Success here, data transfered are inside 
            // xfr->buffer
            // and the length is
            // xfr->actual_length
            break;
        case LIBUSB_TRANSFER_CANCELLED:
        case LIBUSB_TRANSFER_NO_DEVICE:
        case LIBUSB_TRANSFER_TIMED_OUT:
        case LIBUSB_TRANSFER_ERROR:
        case LIBUSB_TRANSFER_STALL:
        case LIBUSB_TRANSFER_OVERFLOW:
            // Various type of errors here
            break;
    }
}
```
  

Now the transfer code seem complete. However an additional step have to be made. What is not very clear here (at least it wasn't clear for me in the past) is that the "internal USB engine" who make the transfer and automatically call the callback function is not in a separate thread working in parallel but, for have it working as expected, need to be "keep alive" by continuously calling the function _libusb_handle_events_ as follow:

  
```c
while(1)
{
    if(libusb_handle_events(NULL) != LIBUSB_SUCCESS) break;
}
```
  

As you can note this is an infinite loop with minimum of error check used just for example purpose. In case you need to manage additional error conditions and provide some way to exit from loop if your software require it. This small snippet is only to explain that if you don't continuously call the _libusb_handle_events_ function your callback function will never be called also if the USB transfer was completed (and this can result in many hours lost in search for the problem... ^_^).
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <libusb-1.0/libusb.h>


#define BULK_EP_OUT     0x82    
#define BULK_EP_IN      0x08   
#define BULK_URB_IN_ENDPOINT 0x81

// wireshark summary 
// 27	58.851327	1.10.1	host	USB	128	URB_BULK in
// USB URB
//     [Source: 1.10.1]
//     [Destination: host]
//     URB id: 0xffff8ed11ea6f440
//     URB type: URB_COMPLETE ('C')
//     URB transfer type: URB_BULK (0x03)
//     Endpoint: 0x81, Direction: IN
//         1... .... = Direction: IN (1)
//         .... 0001 = Endpoint number: 1
//     Device: 10
//     URB bus id: 1
//     Device setup request: not relevant ('-')
//     Data: present (0)
//     URB sec: 1643135937
//     URB usec: 703649
//     URB status: Success (0)
//     URB length [bytes]: 64
//     Data length [bytes]: 64
//     [Request in: 14]
//     [Time from request: 11.290895000 seconds]
//     [bInterfaceClass: Unknown (0xffff)]
//     Unused Setup Header
//     Interval: 0
//     Start frame: 0
//     Copy of Transfer Flags: 0x00000204, No transfer DMA map, Dir IN
//         .... .... .... .... .... .... .... ...0 = Short not OK: False
//         .... .... .... .... .... .... .... ..0. = ISO ASAP: False
//         .... .... .... .... .... .... .... .1.. = No transfer DMA map: True
//         .... .... .... .... .... .... ..0. .... = No FSBR: False
//         .... .... .... .... .... .... .0.. .... = Zero Packet: False
//         .... .... .... .... .... .... 0... .... = No Interrupt: False
//         .... .... .... .... .... ...0 .... .... = Free Buffer: False
//         .... .... .... .... .... ..1. .... .... = Dir IN: True
//         .... .... .... ...0 .... .... .... .... = DMA Map Single: False
//         .... .... .... ..0. .... .... .... .... = DMA Map Page: False
//         .... .... .... .0.. .... .... .... .... = DMA Map SG: False
//         .... .... .... 0... .... .... .... .... = Map Local: False
//         .... .... ...0 .... .... .... .... .... = Setup Map Single: False
//         .... .... ..0. .... .... .... .... .... = Setup Map Local: False
//         .... .... .0.. .... .... .... .... .... = DMA S-G Combined: False
//         .... .... 0... .... .... .... .... .... = Aligned Temp Buffer: False
//     Number of ISO descriptors: 0


// lsusb 
// Bus 001 Device 009: ID 09e8:0028 AKAI  Professional M.I. Corp. APC MINI
#define VENDOR_ID_AKAI_APC_MINI 0x09e8
#define PRODUCT_ID_AKAI_APC_MINI 0x0028

int interface_ref = 0;    
int alt_interface,interface_number;    

int print_configuration(struct libusb_device_handle *hDevice,struct libusb_config_descriptor *config)    
{    
    char *data;    
    int index;    

    data = (char *)malloc(512);    
    memset(data,0,512);    

    index = config->iConfiguration;    

    libusb_get_string_descriptor_ascii(hDevice,index,data,512);    

    printf("\nInterface Descriptors: ");    
    printf("\n\tNumber of Interfaces : %d",config->bNumInterfaces);    
    printf("\n\tLength : %d",config->bLength);    
    printf("\n\tDesc_Type : %d",config->bDescriptorType);    
    printf("\n\tConfig_index : %d",config->iConfiguration);    
    printf("\n\tTotal length : %lu",config->wTotalLength);    
    printf("\n\tConfiguration Value  : %d",config->bConfigurationValue);    
    printf("\n\tConfiguration Attributes : %d",config->bmAttributes);    
    printf("\n\tMaxPower(mA) : %d\n",config->MaxPower);    

    free(data);    
    data = NULL;    
    return 0;    
}    

struct libusb_endpoint_descriptor* active_config(struct libusb_device *dev,struct libusb_device_handle *handle)    
{    
    struct libusb_device_handle *hDevice_req;    
    struct libusb_config_descriptor *config;    
    struct libusb_endpoint_descriptor *endpoint;    
    int altsetting_index,interface_index=0,ret_active;    
    int i,ret_print;    

    hDevice_req = handle;    

    ret_active = libusb_get_active_config_descriptor(dev,&config);    
    ret_print = print_configuration(hDevice_req,config);    

    for(interface_index=0;interface_index<config->bNumInterfaces;interface_index++)    
    {    
        const struct libusb_interface *iface = &config->interface[interface_index];    
        for(altsetting_index=0;altsetting_index<iface->num_altsetting;altsetting_index++)    
        {    
            const struct libusb_interface_descriptor *altsetting = &iface->altsetting[altsetting_index];    

            int endpoint_index;    
            for(endpoint_index=0;endpoint_index<altsetting->bNumEndpoints;endpoint_index++)    
            {    
                const struct libusb_endpoint_desriptor *ep = &altsetting->endpoint[endpoint_index];    
                endpoint = ep;      
                alt_interface = altsetting->bAlternateSetting;    
                interface_number = altsetting->bInterfaceNumber;    
            }    

            printf("\nEndPoint Descriptors: ");    
            printf("\n\tSize of EndPoint Descriptor : %d",endpoint->bLength);    
            printf("\n\tType of Descriptor : %d",endpoint->bDescriptorType);    
            printf("\n\tEndpoint Address : 0x0%x",endpoint->bEndpointAddress);    
            printf("\n\tMaximum Packet Size: %x",endpoint->wMaxPacketSize);    
            printf("\n\tAttributes applied to Endpoint: %d",endpoint->bmAttributes);    
            printf("\n\tInterval for Polling for data Tranfer : %d\n",endpoint->bInterval);    
        }    
    }    
    libusb_free_config_descriptor(NULL);    
    return endpoint;    
}    

int main(void)    
{    
    int r = 1;    
    struct libusb_device **devs;    
    struct libusb_device_handle *handle = NULL, *hDevice_expected = NULL;    
    struct libusb_device *dev,*dev_expected;    

    struct libusb_device_descriptor desc;    
    struct libusb_endpoint_descriptor *epdesc;    
    struct libusb_interface_descriptor *intdesc;    

    ssize_t cnt;    
    int e = 0,config2;    
    int i = 0,index;    
    char str1[64], str2[64];    
    char found = 0;    

// Init libusb     
    r = libusb_init(NULL);    
    if(r < 0)    
    {    
        printf("\nfailed to initialise libusb\n");    
        return 1;    
    }    
    else    
        printf("\nInit Successful!\n");    

// Get a list os USB devices    
    cnt = libusb_get_device_list(NULL, &devs);    
    if (cnt < 0)    
    {    
        printf("\nThere are no USB devices on bus\n");    
        return -1;    
    }    
    printf("\nDevice Count : %d\n-------------------------------\n",cnt);    

    while ((dev = devs[i++]) != NULL)    
    {    
        r = libusb_get_device_descriptor(dev, &desc);    
        if (r < 0)    
            {    
            printf("failed to get device descriptor\n");    
            libusb_free_device_list(devs,1);    
            libusb_close(handle);    
            break;    
        }    

        e = libusb_open(dev,&handle);    
        if (e < 0)    
        {    
            printf("error opening device\n");    
            libusb_free_device_list(devs,1);    
            libusb_close(handle);    
            break;    
        }    

        printf("\nDevice Descriptors: ");    
        printf("\n\tVendor ID : %x",desc.idVendor);    
        printf("\n\tProduct ID : %x",desc.idProduct);    
        printf("\n\tSerial Number : %x",desc.iSerialNumber);    
        printf("\n\tSize of Device Descriptor : %d",desc.bLength);    
        printf("\n\tType of Descriptor : %d",desc.bDescriptorType);    
        printf("\n\tUSB Specification Release Number : %d",desc.bcdUSB);    
        printf("\n\tDevice Release Number : %d",desc.bcdDevice);    
        printf("\n\tDevice Class : %d",desc.bDeviceClass);    
        printf("\n\tDevice Sub-Class : %d",desc.bDeviceSubClass);    
        printf("\n\tDevice Protocol : %d",desc.bDeviceProtocol);    
        printf("\n\tMax. Packet Size : %d",desc.bMaxPacketSize0);    
        printf("\n\tNo. of Configuraions : %d\n",desc.bNumConfigurations);    

        e = libusb_get_string_descriptor_ascii(handle, desc.iManufacturer, (unsigned char*) str1, sizeof(str1));    
        if (e < 0)    
        {    
        libusb_free_device_list(devs,1);    
            libusb_close(handle);    
            break;    
        }    
        printf("\nManufactured : %s",str1);    

        e = libusb_get_string_descriptor_ascii(handle, desc.iProduct, (unsigned char*) str2, sizeof(str2));    
        if(e < 0)    
        {    
        libusb_free_device_list(devs,1);    
            libusb_close(handle);    
            break;    
        }    
        printf("\nProduct : %s",str2);    
        printf("\n----------------------------------------");    

        if(desc.idVendor == VENDOR_ID_AKAI_APC_MINI && desc.idProduct == PRODUCT_ID_AKAI_APC_MINI)    
        {    
            
            found = 1;    
            break;    
        }    
    }//end of while    
    if(found == 0)    
    {    
        printf("\nDevice NOT found\n");    
        libusb_free_device_list(devs,1);    
        libusb_close(handle);    
        return 1;    
    }    
    else    
    {    
        printf("\nDevice found");    
        dev_expected = dev;    
        hDevice_expected = handle;    
    }    

    e = libusb_get_configuration(handle,&config2);    
    if(e!=0)    
    {    
        printf("\n***Error in libusb_get_configuration\n");    
        libusb_free_device_list(devs,1);    
        libusb_close(handle);    
        return -1;    
    }    
    printf("\nConfigured value : %d",config2);    

    if(config2 != 1)    
    {    
        libusb_set_configuration(handle, 1);    
        if(e!=0)    
        {    
            printf("Error in libusb_set_configuration\n");    
            libusb_free_device_list(devs,1);    
            libusb_close(handle);    
            return -1;    
        }    
        else    
            printf("\nDevice is in configured state!");    
    }    

    libusb_free_device_list(devs, 1);    

    if(libusb_kernel_driver_active(handle, 0) == 1)    
    {    
        printf("\nKernel Driver Active");    
        if(libusb_detach_kernel_driver(handle, 0) == 0)    
            printf("\nKernel Driver Detached!");    
        else    
        {    
            printf("\nCouldn't detach kernel driver!\n");    
            libusb_free_device_list(devs,1);    
            libusb_close(handle);    
            return -1;    
        }    
    }    

    e = libusb_claim_interface(handle, 0);    
    if(e < 0)    
    {    
        printf("\nCannot Claim Interface");    
        libusb_free_device_list(devs,1);    
        libusb_close(handle);    
        return -1;    
    }    
    else    
        printf("\nClaimed Interface\n");    

    active_config(dev_expected,hDevice_expected);    

    //   Communicate     

    char *my_string, *my_string1;    
    int transferred = 0;    
    int received = 0;    
    int length = 0;    
    int nbytes = 40; 
    my_string = (char *)malloc(nbytes + 1);    
    my_string1 = (char *)malloc(nbytes + 1);    

    memset(my_string,'\0',64);    
    memset(my_string1,'\0',64);    

    strcpy(my_string,"prasad divesd");    
    length = strlen(my_string);    

    printf("\nTo be sent : %s",my_string);    

    // printf("\n trying to write to device")
    // e = libusb_bulk_transfer(handle,BULK_EP_IN,my_string,length,&transferred,0);    
    // if(e == 0 && transferred == length)    
    // {    
    //     printf("\nWrite successful!");    
    //     printf("\nSent %d bytes with string: %s\n", transferred, my_string);    
    // }    
    // else    
    //     printf("\nError in write! e = %d and transferred = %d\n",e,transferred);    

    // sleep(3);    



    // int libusb_bulk_transfer(
    //      struct libusb_device_handle *devh,
    //      unsigned char endpoint,
    //      unsigned	char *data,
    //      int	length,
    //      int *transferred,
    //      unsigned int timeout
    // ) Perform an USB bulk transfer.  A timeout value of	zero means no
    // timeout.  The timeout value is given in milliseconds.  Returns 0 on suc-
    // cess, LIBUSB_ERROR_TIMEOUT	if the transfer	timed out, LIBUSB_ERROR_PIPE
    // if	the control request was	not supported, LIBUSB_ERROR_OVERFLOW if	the
    // device offered more data, LIBUSB_ERROR_NO_DEVICE if the device has	been
    // disconnected and a	LIBUSB_ERROR code on other failure.

    int n_data_bytes = 40; // endpoint adress 0x81, max packet size 40
    int n_transfered_bytes = 0;
    char *s_data;
    s_data = (char *)malloc(n_data_bytes + 1);     

    printf("\n trying to read from device");
    sleep(10);
    i = 0;    
    for(i = 0; i < length; i++)    
    {    
        e = libusb_bulk_transfer(
            handle,
            BULK_URB_IN_ENDPOINT,
            s_data,
            n_data_bytes,
            &n_transfered_bytes,
            0
            );  //64 : Max Packet Lenght    

        if(e == 0)    
        {    
            printf("\n_transfered_bytes: ");    
            printf("data as string is %s", s_data);
            sleep(1);
        }    
        else
        {    
            if(e == LIBUSB_SUCCESS){printf("\n LIBUSB_SUCCESS Success (no error)");}

            if(e == LIBUSB_ERROR_IO){printf("\n LIBUSB_ERROR_IO Input/output error.");}

            if(e == LIBUSB_ERROR_INVALID_PARAM){printf("\n LIBUSB_ERROR_INVALID_PARAM Invalid parameter.");}

            if(e == LIBUSB_ERROR_ACCESS){printf("\n LIBUSB_ERROR_ACCESS Access denied (insufficient permissions)");}

            if(e == LIBUSB_ERROR_NO_DEVICE){printf("\n LIBUSB_ERROR_NO_DEVICE No such device (it may have been disconnected)");}

            if(e == LIBUSB_ERROR_NOT_FOUND){printf("\n LIBUSB_ERROR_NOT_FOUND Entity not found.");}

            if(e == LIBUSB_ERROR_BUSY){printf("\n LIBUSB_ERROR_BUSY Resource busy.");}

            if(e == LIBUSB_ERROR_TIMEOUT){printf("\n LIBUSB_ERROR_TIMEOUT Operation timed out.");}

            if(e == LIBUSB_ERROR_OVERFLOW){printf("\n LIBUSB_ERROR_OVERFLOW Overflow.");}

            if(e == LIBUSB_ERROR_PIPE){printf("\n LIBUSB_ERROR_PIPE Pipe error.");}

            if(e == LIBUSB_ERROR_INTERRUPTED){printf("\n LIBUSB_ERROR_INTERRUPTED System call interrupted (perhaps due to signal)");}

            if(e == LIBUSB_ERROR_NO_MEM){printf("\n LIBUSB_ERROR_NO_MEM Insufficient memory.");}

            if(e == LIBUSB_ERROR_NOT_SUPPORTED){printf("\n LIBUSB_ERROR_NOT_SUPPORTED Operation not supported or unimplemented on this platform.");}

            if(e == LIBUSB_ERROR_OTHER){printf("\n LIBUSB_ERROR_OTHER Other error.");}

            //if(e == LIBUSB_ERROR){printf("error is LIBUSB_ERROR");}
           printf("\nError in read! e = %d and received = %d\n",e,received);    
            return -1;    
        }    
    }    


    e = libusb_release_interface(handle, 0);    

    libusb_close(handle);    
    libusb_exit(NULL);    

    printf("\n");    
    return 0;    
} 
# how to find packages 
```
locate libusb.h
```
or
```
dpkg --listfiles libhidapi-dev
```

# if header not found 
```
#include <hidapi.h> // error not found
```
since the file is in /usr/include/hidapi/hidapi.h
in my case
i have to 
```
#include <hidapi/hidapi.h> //<realtive_path_starting_in_usr/include>
```
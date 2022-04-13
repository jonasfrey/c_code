
// c file 
#include <stdlib.h>
#include <stdio.h>

#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define f_s_typename(x) _Generic((x),        /* Get the name of a type */             \
                                                                                  \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")

#define S_ANSI_COLOR_RED     "\x1b[31m"
#define S_ANSI_COLOR_GREEN   "\x1b[32m"
#define S_ANSI_COLOR_YELLOW  "\x1b[33m"
#define S_ANSI_COLOR_BLUE    "\x1b[34m"
#define S_ANSI_COLOR_MAGENTA "\x1b[35m"
#define S_ANSI_COLOR_CYAN    "\x1b[36m"
#define S_ANSI_COLOR_RESET   "\x1b[0m"


typedef unsigned int my_fancy_own_data_type;


// source : https://www.lemoda.net/c/write-png/
// install libpng / png.h => sudo apt-get install libpng-dev
// compile gcc  write_png_image.c -o write_png_image -lpng 
// link the libpng-dev with -lpng !!!!


float f_n_random_normalized()
{
      float r = (float)rand() / (float)RAND_MAX;
      return r;
}

/* A coloured pixel. */
typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}
pixel_t;

/* A picture. */
    
typedef struct
{
    pixel_t *pixels;
    size_t width;
    size_t height;
}
bitmap_t;
    
int n_bits_per_color = 8;
/* Given "bitmap", this returns the pixel of bitmap at the point 
   ("x", "y"). */

static pixel_t * pixel_at (bitmap_t * bitmap, int x, int y)
{
    return bitmap->pixels + bitmap->width * y + x;
}
    
/* Write "bitmap" to a PNG file specified by "path"; returns 0 on
   success, non-zero on error. */

static int save_png_to_file (bitmap_t *bitmap, const char *path)
{
    FILE * fp;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    size_t x, y;
    png_byte ** row_pointers = NULL;
    /* "status" contains the return value of this function. At first
       it is set to a value which means 'failure'. When the routine
       has finished its work, it is set to a value which means
       'success'. */
    int status = -1;
    /* The following number is set by trial and error only. I cannot
       see where it it is documented in the libpng manual.
    */
    int pixel_size = 3;
    
    fp = fopen (path, "wb");
    if (! fp) {
        goto fopen_failed;
    }

    png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL) {
        goto png_create_write_struct_failed;
    }
    
    info_ptr = png_create_info_struct (png_ptr);
    if (info_ptr == NULL) {
        goto png_create_info_struct_failed;
    }
    
    /* Set up error handling. */

    if (setjmp (png_jmpbuf (png_ptr))) {
        goto png_failure;
    }
    
    /* Set image attributes. */

    png_set_IHDR (png_ptr,
                  info_ptr,
                  bitmap->width,
                  bitmap->height,
                  n_bits_per_color,
                  PNG_COLOR_TYPE_RGB,
                  PNG_INTERLACE_NONE,
                  PNG_COMPRESSION_TYPE_DEFAULT,
                  PNG_FILTER_TYPE_DEFAULT);
    
    /* Initialize rows of PNG. */

    row_pointers = png_malloc (png_ptr, bitmap->height * sizeof (png_byte *));
    for (y = 0; y < bitmap->height; y++) {
        png_byte *row = 
            png_malloc (png_ptr, sizeof (uint8_t) * bitmap->width * pixel_size);
        row_pointers[y] = row;
        for (x = 0; x < bitmap->width; x++) {
            pixel_t * pixel = pixel_at (bitmap, x, y);
            *row++ = pixel->red;
            *row++ = pixel->green;
            *row++ = pixel->blue;
        }
    }
    
    /* Write the image data to "fp". */

    png_init_io (png_ptr, fp);
    png_set_rows (png_ptr, info_ptr, row_pointers);
    png_write_png (png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

    /* The routine has successfully written the file, so we set
       "status" to a value which indicates success. */

    status = 0;
    
    for (y = 0; y < bitmap->height; y++) {
        png_free (png_ptr, row_pointers[y]);
    }
    png_free (png_ptr, row_pointers);
    
 png_failure:
 png_create_info_struct_failed:
    png_destroy_write_struct (&png_ptr, &info_ptr);
 png_create_write_struct_failed:
    fclose (fp);
 fopen_failed:
    return status;
}

/* Given "value" and "max", the maximum value which we expect "value"
   to take, this returns an integer between 0 and 255 proportional to
   "value" divided by "max". */

static int pix (int value, int max)
{
    if (value < 0) {
        return 0;
    }
    return (int) (256.0 *((double) (value)/(double) max));
}


void f_read_file_with_fopen_and_fgetc(){

   char * s_filename = "./i_am_text";
   char * s_fopen_mode_read_binary = "rb";
   // FILE is just a typedef
   // like my_fancy_own_data_type
   my_fancy_own_data_type n_num = 18;
   FILE * s_fopen_stream = fopen(
      s_filename,
      s_fopen_mode_read_binary
   );

   if(s_fopen_stream == NULL){
      printf(S_ANSI_COLOR_RED "file open failure!\n" S_ANSI_COLOR_RESET);
   }else{
      printf(S_ANSI_COLOR_GREEN "file open success!\n" S_ANSI_COLOR_RESET);
   }
   
   printf(S_ANSI_COLOR_GREEN "f_s_typename(s_fopen_stream)        :" S_ANSI_COLOR_RESET "%s\n"  ,f_s_typename(s_fopen_stream));


   // lookss like the struct is full with (nil)... 
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_read_ptr      :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_read_ptr);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_read_base     :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_read_base);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_backup_base   :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_backup_base);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_buf_base      :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_buf_base);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_freeres_buf      :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_freeres_buf);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_chain            :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_chain);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_wide_data        :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_wide_data);

   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_buf_end       :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_buf_end);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_read_end      :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_read_end);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_save_end      :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_save_end);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_write_end     :" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_write_end);


   // but now there is another function to read a char

   int n_fgetc_ret = fgetc(s_fopen_stream);
   printf(S_ANSI_COLOR_YELLOW "(as int %%i)fgetc(s_fopen_stream)              :" S_ANSI_COLOR_RESET "%i\n"  ,n_fgetc_ret);
   printf(S_ANSI_COLOR_YELLOW "(as char %%c) fgetc(s_fopen_stream)            :" S_ANSI_COLOR_RESET "%c\n"  ,n_fgetc_ret);
   // printf(S_ANSI_COLOR_YELLOW "(as pointer %%c) fgetc(s_fopen_stream)         :" S_ANSI_COLOR_RESET "%p\n"  ,n_fgetc_ret);

   printf(S_ANSI_COLOR_YELLOW "(as int %%i)fgetc(s_fopen_stream)+1            :" S_ANSI_COLOR_RESET "%i\n"  ,n_fgetc_ret+1);
   printf(S_ANSI_COLOR_YELLOW "(as char %%c) fgetc(s_fopen_stream)+1          :" S_ANSI_COLOR_RESET "%c\n"  ,n_fgetc_ret+1);
   // printf(S_ANSI_COLOR_YELLOW "(as pointer %%c) fgetc(s_fopen_stream+1)       :" S_ANSI_COLOR_RESET "%p\n"  ,n_fgetc_ret+1);

   printf(S_ANSI_COLOR_YELLOW "(as int %%i)fgetc(s_fopen_stream+1)            :" S_ANSI_COLOR_RESET "%i\n"  ,fgetc(s_fopen_stream+1));
   printf(S_ANSI_COLOR_YELLOW "(as char %%c) fgetc(s_fopen_stream+1)          :" S_ANSI_COLOR_RESET "%c\n"  ,fgetc(s_fopen_stream+1));
   // printf(S_ANSI_COLOR_YELLOW "(as pointer %%c) fgetc(s_fopen_stream+1)       :" S_ANSI_COLOR_RESET "%p\n"  ,n_fgetc_ret+1);


   // printf("%i", s_fopen_stream[0]);

}

void f_binary_io_fread(){
// size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

   char * s_filename = "./i_am_text";
   char * s_fopen_mode_read_binary = "rb";
   // FILE is just a typedef
   // like my_fancy_own_data_type
   my_fancy_own_data_type n_num = 18;
   FILE * n_pointer_to_file_struct = fopen(
      s_filename,
      s_fopen_mode_read_binary
   );
   if(n_pointer_to_file_struct == NULL){
      printf(S_ANSI_COLOR_RED "file open failure!\n" S_ANSI_COLOR_RESET);
   }else{
      printf(S_ANSI_COLOR_GREEN "file open success!\n" S_ANSI_COLOR_RESET);
   }
   void * n_void_pointer = malloc(1);
   // size_t n_length_of_elements = 8;// 8 bit ??? 1 
   size_t n_length_of_elements = 1;// 1 byte ??? 1 
   size_t n_number_of_elements = 10;

   size_t fread_return = fread(
      n_void_pointer, 
      n_length_of_elements, 
      n_number_of_elements,
      n_pointer_to_file_struct
   );
   // printf(S_ANSI_COLOR_YELLOW "(as char %%c) fread_return                                 :" S_ANSI_COLOR_RESET "%c\n"  ,fread_return);
   printf(S_ANSI_COLOR_YELLOW "(as long unsigned int (size_t) %%li) fread_return           :" S_ANSI_COLOR_RESET "%li\n"  ,fread_return);
   // printf(S_ANSI_COLOR_YELLOW "(as string %%s) fread_return                               :" S_ANSI_COLOR_RESET "%s\n"  ,fread_return);


   printf(S_ANSI_COLOR_YELLOW "(as pointer %%p) n_void_pointer           :" S_ANSI_COLOR_RESET "%p\n"  ,n_void_pointer);


   // printf(S_ANSI_COLOR_YELLOW "(as string %%s) n_void_pointer           :" S_ANSI_COLOR_RESET "%s\n"  ,n_void_pointer);

   printf(S_ANSI_COLOR_YELLOW "(as char casted to (char *) %%c) n_void_pointer           :" S_ANSI_COLOR_RESET "%s\n"  ,(char *) n_void_pointer);


}
double f_d_normalized_by_n(
   int n_uint8_ascii_from_33_to_126
){
   int n_start = 33; 
   int n_end = 126; 
   int n_range = n_end - n_start; 
   return (n_uint8_ascii_from_33_to_126-n_start)/(n_range);
}

int f_n_mai_pixel_index_by_xy(
   int n_x, 
   int n_y, 
   int n_buffer_length, 
   char * a_buffer_as_char_pointer, 
   int b_last_char_is_newline
){
   int n_newline = 1;
   // int n_index = n_heigth * (n_x+n_newline) + n_x + (b_last_char_is_newline * 1);
   int n_index = n_y * (n_x+n_newline) + n_x;
   return n_index;
}
void f_binary_io_monochrome_ascii_image(){
   // char * s_file_path_name = "./monochrome_ascii_image.mai";
   char * s_file_path_name = "./monochrome_ascii_image_last_char_no_newline.mai";
   char * s_fopen_mode_read_binary = "rb";
   FILE * n_pointer_to_file_struct = fopen(
      s_file_path_name,
      s_fopen_mode_read_binary
   );
   if(n_pointer_to_file_struct == NULL){
      printf(S_ANSI_COLOR_RED "file open failure!\n" S_ANSI_COLOR_RESET);
      exit(0);
   }else{
      printf(S_ANSI_COLOR_GREEN "file open success!\n" S_ANSI_COLOR_RESET);
   }
   
   fseek(n_pointer_to_file_struct, 0, SEEK_END);
   int n_buffer_length = ftell(n_pointer_to_file_struct);
   fseek(n_pointer_to_file_struct, 0, SEEK_SET);
   size_t n_bytes_per_element = 1;
   void * a_buffer = malloc(n_buffer_length);
   if (a_buffer)
   {
      fread(a_buffer, n_bytes_per_element, n_buffer_length, n_pointer_to_file_struct);
   }
   fclose(n_pointer_to_file_struct);
    

    // printf("bufferlen is %li\n", *n_buffer_length);

   if (a_buffer)
   {
   printf(S_ANSI_COLOR_GREEN "file buffer set!\n" S_ANSI_COLOR_RESET);
   }

   printf("n_buffer_length:%i\n", n_buffer_length);


   int n_buffer_index = 0; 
   int n_pixel_x = 0;
   int n_pixel_y = 0;
   int n_image_width = 0; 
   int n_image_heigth = 0;
   char s_new_line = '\n';
   char * a_buffer_as_char_pointer = (char*)(a_buffer);

   while(n_buffer_index < n_buffer_length){
      int n_value = a_buffer_as_char_pointer[n_buffer_index]; 
      if(n_value == s_new_line){
         n_image_width = n_buffer_index;
         break;
      }
      printf("%c\n", n_value);
      printf("%i\n", n_value);
      n_buffer_index++;
   }


   printf("a_buffer_as_char_pointer[n_buffer_length-1]:%c\n", a_buffer_as_char_pointer[n_buffer_length-1]);
   printf("a_buffer_as_char_pointer[n_buffer_length-1]:%i\n", a_buffer_as_char_pointer[n_buffer_length-1]);
   printf("a_buffer_as_char_pointer[n_buffer_length-1] is a newline:%i\n", a_buffer_as_char_pointer[n_buffer_length-1]  == s_new_line);
   printf(S_ANSI_COLOR_CYAN "END!\n" S_ANSI_COLOR_RESET);

   int b_last_character_is_newline = a_buffer_as_char_pointer[n_buffer_length-1]  == s_new_line; 
   if(b_last_character_is_newline){
      n_image_heigth = n_buffer_length / (n_image_width+1);
   }else{
      n_image_heigth = (n_buffer_length+1) / (n_image_width+1);
   }

   printf("n_image_width:%i\n", n_image_width);
   printf("n_image_heigth:%i\n", n_image_heigth);

   bitmap_t o_image;
    int x;
    int y;
    int status;

    status = 0;

    /* Create an image. */

    o_image.width = n_image_width;
    o_image.height = n_image_heigth;

    o_image.pixels = calloc (o_image.width * o_image.height, sizeof (pixel_t));

    if (! o_image.pixels) {
	return -1;
    }

    for (y = 0; y < o_image.height; y++) {
        for (x = 0; x < o_image.width; x++) {
            pixel_t * pixel = pixel_at (&o_image, x, y);
            int n_mai_index = f_n_mai_pixel_index_by_xy(x,y, n_buffer_length, a_buffer_as_char_pointer, b_last_character_is_newline);
            int n_value_normalized = f_d_normalized_by_n(a_buffer_as_char_pointer[n_mai_index]);
            uint8_t n_value_denormalized = n_value_normalized * (pow(2,8)-1);

            pixel->red = n_value_denormalized;
            pixel->green = n_value_denormalized;
            pixel->blue = n_value_denormalized;
        }
    }

    /* Write the image to a file 'o_image.png'. */

   char * s_file_path_name_output_ending = ".png";
   char * s_file_path_name_output = malloc(strlen(s_file_path_name)+strlen(s_file_path_name_output_ending)+1);
   strcpy(s_file_path_name_output, s_file_path_name);
   // strcat(s_file_path_name_output, s_file_path_name);
   strcat(s_file_path_name_output, s_file_path_name_output_ending);
   printf("s_file_path_name_output: %s", s_file_path_name_output);
   
    if (save_png_to_file (& o_image, s_file_path_name_output)) {
	fprintf (stderr, "Error writing file.\n");
	status = -1;
    }

   free (o_image.pixels);

   return status;
   
}
int main() {

   // f_read_file_with_fopen_and_fgetc();

   // f_binary_io_fread();

   f_binary_io_monochrome_ascii_image();
}

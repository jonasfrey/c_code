#ifndef ANSI_COLOR_RESET
    #include "./../terminal_color_fun/ansi_color_constants.c"
#endif

#include <time.h>

// dump not die
// currently only working for integers
#define dnd(var)\
   printf("\n");\
   print_current_unix_timestamp_formatted();\
   printf(": %s : ", #var);\
   printf("%i", var);

// dump not die
// currently only working for long integers
#define dndli(var)\
   printf("\n");\
   print_current_unix_timestamp_formatted();\
   printf(": %s : ", #var);\
   printf("%li", var);

int get_current_unix_timestamp(){
   //  January 1st, 1970 at UTC
   int n_current_unix_timestamp = (unsigned long)time(NULL);
   return n_current_unix_timestamp;
}

void print_current_unix_timestamp_formatted(){

   // January 1st, 1970 at UTC
   int n_current_unix_timestamp = get_current_unix_timestamp();

   // int n_years = n_current_unix_timestamp / (60.0*60*24*365) + 1970;
   //int n_months = n_current_unix_timestamp / (60.0*60*24*365) + 1970;
   //int n_days = n_current_unix_timestamp / (60.0*60*24) + 1970;

   int n_seconds = (int) n_current_unix_timestamp % 60;
   int n_minutes = (int) n_current_unix_timestamp % (60*60) / (60.0);
   int n_hours = (int) n_current_unix_timestamp % (60*60*24) / (60.0*60);

   //utc +1 or so
   n_hours = (n_hours + 1) % 24;

   // // char s_h_m_s[] = "00:00:00";
   // printf("%05i", n_seconds);
   // printf("%05i", n_minutes);
   // printf("%05i", n_hours);

   // char s_seconds_padded[] = "00";
   // char s_minutes_padded[] = "00";
   // char s_hours_padded[] = "00";

   // sprintf(s_seconds_padded, "%02i", n_seconds);
   // sprintf(s_minutes_padded, "%02i", n_minutes);
   // sprintf(s_hours_padded, "%02i", n_hours);

   // char s_unix_ts_formatted[] = "00:00:00";

   // printf("%s:%s:%s", s_hours_padded, s_minutes_padded, s_seconds_padded);
   printf(ANSI_BG_COLOR_UNSATURATED_BLACK "%i:%i:%i" ANSI_COLOR_RESET, n_hours, n_minutes, n_seconds);

   // printf("%s", s_unix_ts_formatted);
   // return s_unix_ts_formatted;
   //return 1;
}
//#include "../drivers/ports.c"
#define CURRENT_YEAR        2021                            // Change this each year!
//#include "../drivers/ports.h"
void printTime();
void printDate();
static void readRTC();
 static int get_RTC_register(int reg);
static int century_register = 0x00;                                // Set by ACPI table parsing code if possible
 
unsigned char second;
unsigned char minute;
unsigned char hour;
unsigned char day;
unsigned char month;
unsigned int year;
 

static int cmos_address = 0x70;
static int cmos_data    = 0x71;
 

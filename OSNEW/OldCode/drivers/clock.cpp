
//#include "../drivers/ports.c"
#define CURRENT_YEAR        2021                            // Change this each year!
#include "../drivers/ports.hpp"

static int century_register = 0x00;                                // Set by ACPI table parsing code if possible
 
unsigned char second;
unsigned char minute;
unsigned char hour;
unsigned char day;
unsigned char month;
unsigned int year;
 

static int cmos_address = 0x70;
static int cmos_data    = 0x71;
 

static int get_RTC_register(int reg) {
      writePort(cmos_address, reg);
      return readPort(cmos_data);
}
 
static void read_rtc() {
      unsigned char century;
      unsigned char registerB;

      second = get_RTC_register(0x00);
      minute = get_RTC_register(0x02);
      hour = get_RTC_register(0x04);
      day = get_RTC_register(0x07);
      month = get_RTC_register(0x08);
      year = get_RTC_register(0x09);
      century = get_RTC_register(century_register);
      registerB = get_RTC_register(0x0B);

 if (!(registerB & 0x04)) {
            second = (second & 0x0F) + ((second / 16) * 10);
            minute = (minute & 0x0F) + ((minute / 16) * 10);
            hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
            day = (day & 0x0F) + ((day / 16) * 10);
            month = (month & 0x0F) + ((month / 16) * 10);
            year = (year & 0x0F) + ((year / 16) * 10);
            if(century_register != 0) {
                  century = (century & 0x0F) + ((century / 16) * 10);
            }
      }
       
}
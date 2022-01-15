
#include <drivers/clock.h>
static int get_RTC_register(int reg) {
      writePort(cmos_address, reg);
      return readPort(cmos_data);
}
 
static void readRTC() {
      unsigned char registerB;

      second = get_RTC_register(0x00);
      minute = get_RTC_register(0x02);
      hour = get_RTC_register(0x04);
      day = get_RTC_register(0x07);
      month = get_RTC_register(0x08);
      year = get_RTC_register(0x09);
      registerB = get_RTC_register(0x0B);

 if (!(registerB & 0x04)) {
            second = (second & 0x0F) + ((second / 16) * 10);
            minute = (minute & 0x0F) + ((minute / 16) * 10);
            hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
            day = (day & 0x0F) + ((day / 16) * 10);
            month = (month & 0x0F) + ((month / 16) * 10);
            year = (year & 0x0F) + ((year / 16) * 10);
      }
       
}
void printTime(){ 
    readRTC();
    newLine();
    print(intToChar(hour));
    print(":");
    print(intToChar(minute));
    print(":");
    print(intToChar(second));
}
void printDate(){
    readRTC();
    newLine();
    print(intToChar(day));
    print("/");
    print(intToChar(month));
    print("/");
    print(intToChar(year)); 
}
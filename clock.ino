
// DS1302:  RST pin    -> Arduino Digital 2
//          DATA pin   -> Arduino Digital 3
//          CLK pin  -> Arduino Digital 4

#include <DS1302.h>
#include <Wire.h>  




DS1302 rtc(2, 3, 4);



void setup()
{
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);

   //The following lines can be commented out to use the values already stored in the DS1302
rtc.setDOW(FRIDAY);        // Set Day-of-Week to FRIDAY
rtc.setTime(10, 55, 0);     // Set the time to 12:00:00 (24hr format)
rtc.setDate(29, 5, 2020);   // Set the date to August 6th, 2010
}

void loop()
{
  // Display time centered on the upper line

  Serial.print(rtc.getTimeStr());
  Serial.print("\n");
  
  // Display abbreviated Day-of-Week in the lower left corner
  
  Serial.print(rtc.getDOWStr(FORMAT_SHORT));
  Serial.print("\n");
  
  // Display date in the lower right corner
  
  Serial.print(rtc.getDateStr());
  Serial.print("\n");
  // Wait one second before repeating :)
  delay (1000);
}

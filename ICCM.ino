/**********************************************************************************************************************************
* Instrument Cluster Control Module (ICCM)
*  0.3
* F0: Main
* ©2015 Derrick Codomo
* 
* Organized by Section (§0) and Block (B00)
* 
**********************************************************************************************************************************/

/* §1 INCLUSIONS & DECLARATIONS
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*/
  //B00: standard arduino library inclusions
    #include <Scheduler.h> /*allows multiple functions to run at the same time*/
    #include <SD.h>
    #include <SPI.h>
    #include <Wire.h>


  //B01: third-party library inclusions
    #include "GPU.h" /* specialized version of gameduino library */
    //#include "Graphics.h"
    #include "Time.h"
    //#include "Clock.h" //errors in this library!!
    //#include "Adafruit_LSM303_U.h" //MagAccl
    //#include "Adafruit_Sensor.h"
    //#include "Adafruit_SSD1306.h" //OLEDs
    //#include "Adafruit_VS1053.h" //Audio

  //B02: support file inclusions
    #include "constants.h"
    
  //B03: device config definitions
    /* audio board */
    //Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(48,49,46,45,47); // RST, CS, XDCS, DREQ, SDCS

    /* i2c devices */
    /* Assign a unique ID (2) to accelerometer sensor */
    //Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(2);
    /* Assign a unique ID (3) to magnetometer sensor */
    //Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(3);
    /* note: RTC also uses I2C, but does not need explicit definitons here*/


/* §2 SETUP
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*/
  void setup() {
    
    //B00: communication & diagnostics
      /* initialize serial communication */
      Serial.begin(9600);
      Serial.println("CP-F00S02B00-00: serial connection OK");
      
    //B01: devices initialization
      /* initialize internal clock*/
//      setSyncProvider(RTC.get);   // the function to get the time from the RTC
//      if(timeStatus()!= timeSet){ 
//        error(000002001000); /* problem syncing with the real-time clock */
//      }
      /* initialize magnetometer*/
//      if(!mag.begin()){
//        error(000002001001); /* problem initializing magnetometer */
//      }
      /* initialize gpu board */
      if(!gpu.begin()){
        error(000002001002); /* problem initializing gpu board */
      }
      
    //B02: scheduler
      Scheduler.startLoop(loop2);
    
    //B03: boot user experience
    /* loads splash screens and other effects so that they may display while other setup functions continue to execute.*/
      uxxx_boot();
      Serial.println("CP-F00S02B3-00: setup sequence complete");
      delay(1000);

  }


/* §3 GLOBAL VARIABLES
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*/
  //B00: timing deadlines (dlne) declaration
  /* part of the Master Timing mechanism (see readme), declares timing intervals for functions.
  *  
  *  initial value options are:
  *  -1   : function will not be called until a deadline for it is set by another function during runtime
  *   0   : function will be executed during the initial run of the master timing loop, during which each function can determine
  *         an appropriate deadline for itself.
  */
    long dlne_clokSync = 0;

  //B01: status (stat) variables
    static uint16_t value = 0;

    
/* §4 MASTER TIMING LOOPS
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  part of the Master Timing mechanism (see readme), controls all timing.
*  Uses millis(); function
*/
  //B00: Main Loop
    void loop() {
      
      unsigned long curMills = millis();
      /* retrieves current time (in milliseconds) to use as a comparison between different timing deadlines (dlne) and runs the 
      *  associated functions when such deadline has passed.
      * 
      */
    
    }
  //B01: GPU Loop
  void loop2(){
    
  }
  
/* §5 ERROR HANDLING
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  
*/
void error(long errorCode){
  Serial.print("Error: ");
  Serial.println(errorCode);
}

/* §6 SHUTDOWN
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  saves all unsaved data and signals the local controller (a seperate device) to cut power to the ICCM (this device)
*/

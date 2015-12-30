/**********************************************************************************************************************************
* Instrument Cluster Control Module (ICCM)
*  2.0
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
    //#include <Scheduler.h>
    #include <SD.h>
    #include <SPI.h>
    #include <Wire.h>


  //B01: third-party library inclusions
    #include "GD2.h"
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
      /* initialize external devices */
      //setSyncProvider(RTC.get);
  
      /* initialize gpu board */
      Serial.println("CP-F00S02B1-01: attempting to initialize gui board");
      GD.begin();
      Serial.println("CP-F00S02B1-02: gui board OK");
  
    //B02: boot user experience
    /* loads splash screens and other effects so that they may display while other setup functions continue to execute.*/

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

/* §4 MASTER TIMING LOOP
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  part of the Master Timing mechanism (see readme), controls all timing.
*  Uses millis(); function
*/
  void loop() {
    
    unsigned long curMills = millis();
    /* retrieves current time (in milliseconds) to use as a comparison between different timing deadlines (dlne) and runs the 
    *  associated functions when such deadline has passed.
    * 
    */
  
  }

/* §5 SHUTDOWN
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  saves all unsaved data and signals the local controller (a seperate device) to cut power to the ICCM (this device)
*/

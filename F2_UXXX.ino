/**********************************************************************************************************************************
* F2: User Experience (UXXX)
* this section directs the user experience of the instrument cluster at a more broad level. It keeps track of things such as what
* menu/screen the user is currently in, processing of user inputs, and triggering alerts and notifications.
* 
**********************************************************************************************************************************/

/* §1 CORE FUNCTIONS
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  
*/
void uxxx_boot() {
//  gpu.Begin(RECTS);
//  gpu.Vertex2ii(0, 0);
//  gpu.Vertex2ii(40, 272);
//  gpu.Vertex2ii(440, 0);
//  gpu.Vertex2ii(480, 272);
  
  gpu.text(50, 20, 29, 200, "LOLA");
  gpu.text(50, 70, 26, 200, "ICCM Ver. 0.3");
  gpu.text(50, 85, 26, 200, "(c)2015 Derrick Codomo");
//  gpu.text(50, 115, 26, 200, "This instrument cluster is custom equipment that has not");
//  gpu.text(50, 130, 26, 200, "been tested by Ford Motor Company, use at your own risk.");

  gpu.Begin(RECTS);
  gpu.Vertex2ii(44, 138);
  gpu.Vertex2ii(436, 232);
  gpu.ColorRGB(0, 0, 0);
  gpu.Begin(RECTS);
  gpu.Vertex2ii(47, 141);
  gpu.Vertex2ii(433, 229);
  gpu.ColorRGB(255, 255, 255);
  gpu.text(68, 153, 27 , 200, "Starting up...");
  gpu.cmd_bgcolor(0x000000);
  gpu.cmd_progress(70, 202, 320, 10, 0, 0, 1000);
  gpu.commit();
  
//  gpu.ScissorSize(320,10);
//  gpu.ScissorXY(70,202);
  for(int val = 0; val<101; val++){
  //gpu.clear();
  value++;
  gpu.Begin(RECTS);
  gpu.Vertex2ii(44, 138);
  gpu.Vertex2ii(436, 232);
  gpu.ColorRGB(0, 0, 0);
  gpu.Begin(RECTS);
  gpu.Vertex2ii(47, 141);
  gpu.Vertex2ii(433, 229);
  gpu.ColorRGB(255, 255, 255);
  gpu.text(68, 153, 27 , 200, "Starting up...");
  gpu.cmd_bgcolor(0x000000);
  //gpu.cmd_progress(70, 202, 320, 10, 0, 0, 100);
  gpu.commit();
  
  gpu.Tag(255);
  gpu.cmd_progress(70, 202, 320, 10, 0, value, 100);
  gpu.commit();
  }
  //guix_statusBar();
}

/* §2 FORMATTING (FRMT)
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*/

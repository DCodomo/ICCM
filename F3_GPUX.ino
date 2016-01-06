/**********************************************************************************************************************************
* F3: Graphics Processing Unit (GPUX)
* Controls the drawing of the user interface
* 
**********************************************************************************************************************************/



void guix_statusBar() {
/* bar at top of screen, shows screen title, clock, compass, etc. */
  gpu.clear();
  gpu.text(30, 12, 28, 200, "NW");
  gpu.text(30, 42, 28, centered, "NW");
  gpu.text(30, 72, 28, 1024, "NW");
  gpu.text(320, 12, 28, centered,"12:00");
  gpu.commit();
}
void guix_actionBar() {
/* bar at button of the screen the shows button labels */
  
}


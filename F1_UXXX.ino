/**********************************************************************************************************************************
* F1: User Experience (UXXX)
* this section directs the user experience of the instrument cluster at a more broad level. It keeps track of things such as what
* menu/screen the user is currently in, processing of user inputs, and triggering alerts and notifications.
* 
**********************************************************************************************************************************/

/* §1 INTERFACE (INTF)
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*  controls the user interface of the information center. including menus & controls
*/
void uxxx_homeScreen()
{
  uxxx_actvScreen = homeScreen;
  guix_baseMode = 'A';
  uxxx_setActionBar("0",0,"Menu",mainMenu);
}

/* §2 FORMATTING (FRMT)
*  ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
*/

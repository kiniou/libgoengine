#include <stdio.h>
#include <stdlib.h>

/*#include <Manager_System.h>*/
#include <GOEN_Manager_Display.h>
#include <GOEN_Manager_Input.h>


#include "App_Test.h"



//Managers Declaration
Manager_System  mgr_system;
Manager_Display mgr_display;
/*Manager_Input   mgr_input;*/

App_Test app_test;

int32 millisec;

void inc_timer();

int main()
{
	defaultExceptionHandler();
    mgr_system.init_DS();
    mgr_system.init_timer(inc_timer,&millisec);

	timerStart(0,ClockDivider_1024,timerFreqToTicks_1024(24),inc_timer);

    app_test.init( &mgr_display /*, &mgr_input */, &mgr_system);
    app_test.start();
    return 0;
}//end main

void inc_timer()
{
    millisec += 1;
}

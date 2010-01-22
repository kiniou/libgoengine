#ifndef APP_TEST_H
#define APP_TEST_H

#include <nds.h>
#include <stdio.h>
#include <nds/arm9/image.h>
#include <math.h>

#include <sys/dir.h>
#include <unistd.h>

#include <GOEN_Manager_Display.h>
#include <GOEN_Manager_Input.h>
#include <GOEN_Manager_System.h>

#include "data.h"

class App_Test : Manager_Input
{
    public:

        Manager_Display * p_mgr_display;
        /*Manager_Input   * p_mgr_input;*/
        Manager_System  * p_mgr_system;


        Model_Camera camera;
        Model_Rotation rot_bak;
        Model_Vector target;

        bool app_running;

        //SANDBOX TESTING
        sImage pcx;
        int textureID[10];
        float   xrot ;                           // X Rotation ( NEW )
        float   yrot ;                           // Y Rotation ( NEW )
        float   zrot ;                           // Z Rotation ( NEW )

        //SANDBOX TESTING
        u8 * model_animated[99];
		u8 * model_selected; 
		int animation_pause;
        int32 frame;
        int32 max_frame;
        int32 frame_speed;

        int32 rot_x,rot_y;
        Model_Vector position;

        int init( Manager_Display * xp_mgr_display /*, Manager_Input * xp_mgr_input*/ , Manager_System * xp_mgr_system );
        int load();
        int start();


        void button_pressed(u16 x_button);
        void button_dragged(u16 x_button);
        void button_unpressed(u16 x_button);
        void touchscreen_pressed();
        void touchscreen_dragged();
        void touchscreen_unpressed();



        //SANDBOX TESTING
        void load_Texture();
        void display_Model();
        //SANDBOX TESTING
    protected:
    private:
};



#endif // APP_TEST_H

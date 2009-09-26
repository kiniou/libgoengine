#ifndef _Manager_DISPLAY_H
#define _Manager_DISPLAY_H

#include <nds.h>
#include <malloc.h>
#include <nds/arm9/image.h>
//#include <nds/arm9/trig_lut.h>
//#include <nds/arm9/input.h>
#include <nds/arm9/videoGL.h>


#include "Model_Object.h"
#include "Model_Camera.h"
#include "Model_Scene.h"

class Manager_Display
{
    public:
        Model_Camera * p_camera;
        Model_Scene  * p_scene;


        Manager_Display();
        ~Manager_Display();

        void init();
        void begin_3D();
        void end_3D();
        void display_3D();

        void begin_2D();
        void end_2D();
        void display_2D();

        void display_all();
        void setup_screen();

        void flush_display();

        void set_camera(Model_Camera * xp_camera);
        void unset_camera(void);
        void set_scene(Model_Scene * xp_scene);
    protected:
    private:
};



#endif // _Manager_DISPLAY_H

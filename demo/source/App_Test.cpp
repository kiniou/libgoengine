#include "App_Test.h"

int App_Test::init( Manager_Display * xp_mgr_display /*, Manager_Input * xp_mgr_input */, Manager_System * xp_mgr_system )
{
    this->p_mgr_display = xp_mgr_display;
    //this->p_mgr_input   = xp_mgr_input;
    this->p_mgr_system  = xp_mgr_system;
    return 0;
}


int App_Test::load()
{
    return 0;
}

int App_Test::start()
{
    int code_out = 0;

    this->model_animated[ 0] = (u8 *)heavy_walk_01_bin;
    this->model_animated[ 1] = (u8 *)heavy_walk_02_bin;
    this->model_animated[ 2] = (u8 *)heavy_walk_03_bin;
    this->model_animated[ 3] = (u8 *)heavy_walk_04_bin;
    this->model_animated[ 4] = (u8 *)heavy_walk_05_bin;
    this->model_animated[ 5] = (u8 *)heavy_walk_06_bin;
    this->model_animated[ 6] = (u8 *)heavy_walk_07_bin;
    this->model_animated[ 7] = (u8 *)heavy_walk_08_bin;
    this->model_animated[ 8] = (u8 *)heavy_walk_09_bin;
    this->model_animated[ 9] = (u8 *)heavy_walk_10_bin;
    this->model_animated[10] = (u8 *)heavy_walk_11_bin;
    this->model_animated[11] = (u8 *)heavy_walk_12_bin;
    this->model_animated[12] = (u8 *)heavy_walk_13_bin;
    this->model_animated[13] = (u8 *)heavy_walk_14_bin;
    this->model_animated[14] = (u8 *)heavy_walk_15_bin;
    this->model_animated[15] = (u8 *)heavy_walk_16_bin;
    this->model_animated[16] = (u8 *)heavy_walk_17_bin;
    this->model_animated[17] = (u8 *)heavy_walk_18_bin;
    this->model_animated[18] = (u8 *)heavy_walk_19_bin;
    this->model_animated[19] = (u8 *)heavy_walk_20_bin;
    this->model_animated[20] = (u8 *)heavy_walk_21_bin;
    this->model_animated[21] = (u8 *)heavy_walk_22_bin;
    this->model_animated[22] = (u8 *)heavy_walk_23_bin;
    this->model_animated[23] = (u8 *)heavy_walk_24_bin;
    this->model_animated[24] = (u8 *)heavy_walk_25_bin;
    this->model_animated[25] = (u8 *)heavy_walk_26_bin;
    this->model_animated[26] = (u8 *)heavy_walk_27_bin;
    this->model_animated[27] = (u8 *)heavy_walk_28_bin;
    this->model_animated[28] = (u8 *)heavy_walk_29_bin;
    this->model_animated[29] = (u8 *)heavy_walk_30_bin;
    this->model_animated[30] = (u8 *)heavy_walk_31_bin;
    this->model_animated[31] = (u8 *)heavy_walk_32_bin;
    this->model_animated[32] = (u8 *)heavy_walk_33_bin;
    this->model_animated[33] = (u8 *)heavy_walk_34_bin;
    this->model_animated[34] = (u8 *)heavy_walk_35_bin;
    this->model_animated[35] = (u8 *)heavy_walk_36_bin;
    this->model_animated[36] = (u8 *)heavy_walk_37_bin;
    this->model_animated[37] = (u8 *)heavy_walk_38_bin;
    this->model_animated[38] = (u8 *)heavy_walk_39_bin;
    this->model_animated[39] = (u8 *)heavy_walk_40_bin;



    //Animations variables
	this->frame = 0;
    this->max_frame = 40;

	//Debug variables for animations
	int32 test_time = 0; 
 
	this->xrot = 0.0f;
    this->yrot = 0.0f;
    this->zrot = 0.0f;

    this->p_mgr_display->setup_screen();

    this->target.set_vec_ox(0);
    this->target.set_vec_oy(0);
    this->target.set_vec_oz(0);

    this->camera.setLookAt(CAMERA_MODE_TARGET,&(this->target));
    this->camera.computeLookAt();
	this->camera.dist_from_target = floattof32(23);
    this->p_mgr_display->set_camera(&(this->camera));

    this->p_mgr_display->init();
    this->load_Texture();

    this->app_running = 1;
    this->p_mgr_system->reset_timer();

	this->animation_pause = 1;	

    glSetToonTableRange( 0, 8, RGB15(8,8,8) );
    glSetToonTableRange( 8, 10, RGB15(12,12,12) );
    glSetToonTableRange( 10, 13, RGB15(16,16,16) );
    glSetToonTableRange( 13, 31, RGB15(31,31,31) );

	//glEnable(GL_TOON_HIGHLIGHT);
    while(this->app_running)
    {
        this->process_inputs();
        //printf("%d\n",this->p_mgr_system->last_millisec);
        //this->camera.setStep(this->p_mgr_system->last_millisec); // TODO : init and use millisec pointer within Model_Camera
        this->camera.setStep(17); // TODO : init and use millisec pointer within Model_Camera

        //Animations step calculation
        //this->frame += mulf32(this->frame_speed,this->p_mgr_system->last_millisec);
		if (!this->animation_pause) this->frame+= test_time;
		else this->frame=0;
        if (this->frame >= this->max_frame) this->frame = this->frame - this->max_frame;
		
		this->model_selected = this->model_animated[this->frame];
        //Start Display

        this->p_mgr_display->begin_3D();

        this->display_Model();

        this->p_mgr_display->end_3D();

        this->p_mgr_display->flush_display();
        //End Display

        iprintf("\x1b[2J");
        iprintf("\x1b[1;0Hframe  = %d\n",this->frame);
	    iprintf("\x1b[2;0Htest_timer  = %d\n",timerElapsed(0));
	    iprintf("\x1b[3;0Htest_ms  = %d\n",test_time);

		swiIntrWait(IRQ_TIMER0,1);
	    iprintf("\x1b[5;0H Timer ok\n");
		test_time = this->p_mgr_system->last_millisec;
        this->p_mgr_system->reset_timer();

//        printf("dst_from_target = %f\n",f32tofloat(this->camera.dist_from_target));
		swiWaitForVBlank(); 

    }

    return code_out;

}

void App_Test::display_Model()
{
//        gluLookAtf32(      this->camera.getPosition()->get_vec_ox(),this->camera.getPosition()->get_vec_oy(),this->camera.getPosition()->get_vec_oz(),
//                           this->camera.getLookAt()->get_vec_ox(),this->camera.getLookAt()->get_vec_oy(),this->camera.getLookAt()->get_vec_oz(),
//                           0,4096,0
//        );
//    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ANTIALIAS);
    glEnable(GL_OUTLINE);

    glLight(0, RGB15(31,31,31) , 0, floattov10(-6.0), floattov10(-1.0));

	glSetOutlineColor(0,RGB15(0,0,0));
    glPolyFmt(POLY_ID(0) | POLY_ALPHA(31)|POLY_CULL_NONE | POLY_FORMAT_LIGHT0 | POLY_TOON_HIGHLIGHT);
//    glPolyFmt(POLY_ALPHA(31)|POLY_CULL_NONE | POLY_FORMAT_LIGHT0);
    glColor3b(31,31,31);
    glBindTexture(GL_TEXTURE_2D, this->textureID[0]);

	glTranslatef(0,-6,0);
    glRotatef(90,-1,0,0);
    glRotatef(-90,0,0,1);
	glCallList( (u32 *) this->model_selected);
    glEnd();
}


void App_Test::button_pressed(u16 x_button)
{

    switch(x_button)
    {
        case KEY_A :
        //    sprintf(this->debug_str,".....A");
		this->animation_pause = !this->animation_pause;
        break;
        case KEY_B :
        //    sprintf(this->debug_str,".....B");
        break;
        case KEY_X :
        //    sprintf(this->debug_str,".....X");
        break;
        case KEY_Y :
        //    sprintf(this->debug_str,".....Y");
        break;
        case KEY_L :
        //    sprintf(this->debug_str,".....L");
        break;
        case KEY_R :
        //    sprintf(this->debug_str,".....R");
        break;
        case KEY_UP :
        //    sprintf(this->debug_str,"....UP");
        break;
        case KEY_DOWN :
        //    sprintf(this->debug_str,"..DOWN");
        break;
        case KEY_LEFT :
        //    sprintf(this->debug_str,"..LEFT");
        break;
        case KEY_RIGHT :
        //    sprintf(this->debug_str,".RIGHT");
        break;
        case KEY_START :
        //    sprintf(this->debug_str,".START");
        break;
        case KEY_SELECT :
        //    sprintf(this->debug_str,"SELECT");
        break;
    }
    //printf("APP_TEST :     pressed...%s\n",this->debug_str);
}
void App_Test::button_dragged(u16 x_button)
{
    switch(x_button)
    {
        case KEY_A :
        //    sprintf(this->debug_str,".....A");
        break;
        case KEY_B :
        //    sprintf(this->debug_str,".....B");
        break;
        case KEY_X :
        //    sprintf(this->debug_str,".....X");
        break;
        case KEY_Y :
        //    sprintf(this->debug_str,".....Y");
        break;
        case KEY_L :
        //    sprintf(this->debug_str,".....L");
        break;
        case KEY_R :
        //    sprintf(this->debug_str,".....R");
        break;
        case KEY_UP :
        //    sprintf(this->debug_str,"....UP");
            this->camera.moveFront( MOVE_ON);
        break;
        case KEY_DOWN :
        //    sprintf(this->debug_str,"..DOWN");
            this->camera.moveFront( -MOVE_ON);
        break;
        case KEY_LEFT :
        //    sprintf(this->debug_str,"..LEFT");
        break;
        case KEY_RIGHT :
        //    sprintf(this->debug_str,".RIGHT");
        break;
        case KEY_START :
        //    sprintf(this->debug_str,".START");

        break;
        case KEY_SELECT :
        //    sprintf(this->debug_str,"SELECT");
        break;
    }
    //if ( !(this->keys_bak & x_button) ) printf("APP_TEST :     dragged...%s\n",this->debug_str);
}
void App_Test::button_unpressed(u16 x_button)
{
   switch(x_button)
    {
        case KEY_A :
        //    sprintf(this->debug_str,".....A");
        break;
        case KEY_B :
        //    sprintf(this->debug_str,".....B");
        break;
        case KEY_X :
        //    sprintf(this->debug_str,".....X");
        break;
        case KEY_Y :
        //    sprintf(this->debug_str,".....Y");
        break;
        case KEY_L :
        //    sprintf(this->debug_str,".....L");
        break;
        case KEY_R :
        //    sprintf(this->debug_str,".....R");
        break;
        case KEY_UP :
        //    sprintf(this->debug_str,"....UP");
            this->camera.moveFront(MOVE_OFF);
        break;
        case KEY_DOWN :
        //    sprintf(this->debug_str,"..DOWN");
            this->camera.moveFront(MOVE_OFF);
        break;
        case KEY_LEFT :
        //    sprintf(this->debug_str,"..LEFT");
        break;
        case KEY_RIGHT :
        //    sprintf(this->debug_str,".RIGHT");
        break;
        case KEY_START :
        //    sprintf(this->debug_str,".START");
        break;
        case KEY_SELECT :
        //    sprintf(this->debug_str,"SELECT");
        break;
    }
    //printf("APP_TEST :   unpressed...%s\n",this->debug_str);
}
void App_Test::touchscreen_pressed()
{
    //printf("APP_TEST :     pressed.TOUCHSCR\n");
    this->camera.catchCamera();
    this->camera.animated = 1;
}
void App_Test::touchscreen_dragged()
{
    //if ( !(this->keys_bak & KEY_TOUCH) )  printf("APP_TEST :     dragged.TOUCHSCR\n");

    this->rot_y = (this->tp_bak.px - this->tp.px);
    this->rot_x = (this->tp_bak.py - this->tp.py);

    this->camera.RotateCamera(this->rot_y,this->rot_x);
}
void App_Test::touchscreen_unpressed()
{
    //printf("APP_TEST :   unpressed.TOUCHSCR\n");
    this->camera.animated = 0;
}



// SANDBOX : TESTING FUNCTIONS


void App_Test::load_Texture()
{
    loadPCX((u8*)heavy_pcx, &this->pcx);
    image8to16trans(&this->pcx,0);
    glGenTextures(1, &this->textureID[0]);
    glBindTexture(0, this->textureID[0]);
    glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_128 , TEXTURE_SIZE_128, 0, TEXGEN_TEXCOORD, this->pcx.image.data8);
    imageDestroy(&this->pcx);

//    loadPCX((u8*)start_button_1_pcx, &this->pcx);
//    image8to16trans(&this->pcx,0);
//    glGenTextures(1, &this->textureID[0]);
//    glBindTexture(0, this->textureID[0]);
//    glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_128 , TEXTURE_SIZE_32, 0, TEXGEN_TEXCOORD | GL_TEXTURE_COLOR0_TRANSPARENT, this->pcx.image.data8);
//    imageDestroy(&this->pcx);
//
//    loadPCX((u8*)hex_pcx, &this->pcx);
//    image8to16trans(&this->pcx,0);
//    glGenTextures(1, &this->textureID[1]);
//    glBindTexture(0, this->textureID[1]);
//    glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16 , TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD | GL_TEXTURE_COLOR0_TRANSPARENT, this->pcx.image.data8);
//    imageDestroy(&this->pcx);
//
//    loadPCX((u8*)GO_base_pcx, &this->pcx);
//    image8to16trans(&this->pcx,0);
//    glGenTextures(1, &this->textureID[3]);
//    glBindTexture(0, this->textureID[3]);
//    glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_8 , TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD | GL_TEXTURE_COLOR0_TRANSPARENT , this->pcx.image.data8);
//    imageDestroy(&this->pcx);
//


}

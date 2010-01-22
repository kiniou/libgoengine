#include <GOEN_Manager_Input.h>


Manager_Input::Manager_Input()
{
   this->lst_keys[ 0] = KEY_A;
   this->lst_keys[ 1] = KEY_B;
   this->lst_keys[ 2] = KEY_X;
   this->lst_keys[ 3] = KEY_Y;
   this->lst_keys[ 4] = KEY_L;
   this->lst_keys[ 5] = KEY_R;
   this->lst_keys[ 6] = KEY_UP;
   this->lst_keys[ 7] = KEY_DOWN;
   this->lst_keys[ 8] = KEY_LEFT;
   this->lst_keys[ 9] = KEY_RIGHT;
   this->lst_keys[10] = KEY_SELECT;
   this->lst_keys[11] = KEY_START;
   this->lst_keys[12] = 0;
   this->keys = 0;
   this->keys_bak = 0;
}

Manager_Input::~Manager_Input()
{
    //dtor
}

void Manager_Input::load_inputs()
{

/// @todo (kiniou#1#):Function that load some array with function pointer binded with inputs

}

void Manager_Input::process_inputs()
{
    int i = 0;
    scanKeys();         //Refresh snapshot of inputs

    this->keys = keysHeld();  //Get the snapshot of inputs

    while(this->lst_keys[i]!=0)
    {
        if (this->keys & this->lst_keys[i]) //some button dragged
        {

            if ( !(this->keys_bak & this->lst_keys[i]) ) //some button just pressed
            {

                this->button_pressed(this->lst_keys[i]);

            }

            this->button_dragged(this->lst_keys[i]);

        } else if (this->keys_bak & this->lst_keys[i]) {

            this->button_unpressed(this->lst_keys[i]);

        }
        i++;
    }

    if (this->keys & KEY_TOUCH) {

        //this->tp = touchReadXY();
        touchRead(&this->tp);

        if ( !(this->keys_bak & KEY_TOUCH) ){
            this->tp_bak = this->tp;
            
            this->touchscreen_pressed();
        }

        this->touchscreen_dragged();

    } else if (this->keys_bak & KEY_TOUCH) {
        this->touchscreen_unpressed();
    }

    keys_bak = keys;

}

void Manager_Input::button_pressed(u16 x_button)
{

    switch(x_button)
    {
        case KEY_A :
            sprintf(this->debug_str,".....A");
        break;
        case KEY_B :
            sprintf(this->debug_str,".....B");
        break;
        case KEY_X :
            sprintf(this->debug_str,".....X");
        break;
        case KEY_Y :
            sprintf(this->debug_str,".....Y");
        break;
        case KEY_L :
            sprintf(this->debug_str,".....L");
        break;
        case KEY_R :
            sprintf(this->debug_str,".....R");
        break;
        case KEY_UP :
            sprintf(this->debug_str,"....UP");
        break;
        case KEY_DOWN :
            sprintf(this->debug_str,"..DOWN");
        break;
        case KEY_LEFT :
            sprintf(this->debug_str,"..LEFT");
        break;
        case KEY_RIGHT :
            sprintf(this->debug_str,".RIGHT");
        break;
        case KEY_START :
            sprintf(this->debug_str,".START");
        break;
        case KEY_SELECT :
            sprintf(this->debug_str,"SELECT");
        break;
    }
    printf("MGR_INPUT:     pressed...%s\n",this->debug_str);
}

void Manager_Input::button_dragged(u16 x_button)
{
    switch(x_button)
    {
        case KEY_A :
            sprintf(this->debug_str,".....A");
        break;
        case KEY_B :
            sprintf(this->debug_str,".....B");
        break;
        case KEY_X :
            sprintf(this->debug_str,".....X");
        break;
        case KEY_Y :
            sprintf(this->debug_str,".....Y");
        break;
        case KEY_L :
            sprintf(this->debug_str,".....L");
        break;
        case KEY_R :
            sprintf(this->debug_str,".....R");
        break;
        case KEY_UP :
            sprintf(this->debug_str,"....UP");
        break;
        case KEY_DOWN :
            sprintf(this->debug_str,"..DOWN");
        break;
        case KEY_LEFT :
            sprintf(this->debug_str,"..LEFT");
        break;
        case KEY_RIGHT :
            sprintf(this->debug_str,".RIGHT");
        break;
        case KEY_START :
            sprintf(this->debug_str,".START");
        break;
        case KEY_SELECT :
            sprintf(this->debug_str,"SELECT");
        break;
    }
    printf("MGR_INPUT:     dragged...%s\n",this->debug_str);
}

void Manager_Input::button_unpressed(u16 x_button)
{
   switch(x_button)
    {
        case KEY_A :
            sprintf(this->debug_str,".....A");
        break;
        case KEY_B :
            sprintf(this->debug_str,".....B");
        break;
        case KEY_X :
            sprintf(this->debug_str,".....X");
        break;
        case KEY_Y :
            sprintf(this->debug_str,".....Y");
        break;
        case KEY_L :
            sprintf(this->debug_str,".....L");
        break;
        case KEY_R :
            sprintf(this->debug_str,".....R");
        break;
        case KEY_UP :
            sprintf(this->debug_str,"....UP");
        break;
        case KEY_DOWN :
            sprintf(this->debug_str,"..DOWN");
        break;
        case KEY_LEFT :
            sprintf(this->debug_str,"..LEFT");
        break;
        case KEY_RIGHT :
            sprintf(this->debug_str,".RIGHT");
        break;
        case KEY_START :
            sprintf(this->debug_str,".START");
        break;
        case KEY_SELECT :
            sprintf(this->debug_str,"SELECT");
        break;
    }
    printf("MGR_INPUT:   unpressed...%s\n",this->debug_str);
}


//void Manager_Input::button_RIGHT_unpressed() {}
void Manager_Input::touchscreen_pressed()
{
    printf("MGR_INPUT :    pressed.TOUCHSCR\n");
}
void Manager_Input::touchscreen_dragged()
{
    if ( !(this->keys_bak & KEY_TOUCH) ) printf("MGR_INPUT :    dragged.TOUCHSCR\n");
}
void Manager_Input::touchscreen_unpressed()
{
    printf("MGR_INPUT :  unpressed.TOUCHSCR\n");
}

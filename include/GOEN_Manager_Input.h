#ifndef _Manager_INPUT_H
#define _Manager_INPUT_H

#include <nds.h>

#include <nds/arm9/input.h>
#include <stdio.h>

class Manager_Input
{
    public:

        u16 lst_keys[13];
        //Input Variable
        u16 keys,keys_bak;
        touchPosition tp,tp_bak;

        char debug_str[6];

        Manager_Input();
        ~Manager_Input();

        void load_inputs();
        void process_inputs();

        virtual void button_pressed(u16 x_button);
        virtual void button_dragged(u16 x_button);
        virtual void button_unpressed(u16 x_button);
        virtual void touchscreen_pressed();
        virtual void touchscreen_dragged();
        virtual void touchscreen_unpressed();

    protected:
    private:
};



#endif // _Manager_INPUT_H

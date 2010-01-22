#ifndef _Model_2D_LOGO_H
#define _Model_2D_LOGO_H

#include <nds.h>

#define LOGO_TRANS_CURRENT 0
#define LOGO_TRANS_START 1
#define LOGO_TRANS_END 2

#define LOGO_TRANS_FORWARD 1
#define LOGO_TRANS_BACKWARD -1

#define LOGO_VALUES_NB 18

typedef int32 logo_values[LOGO_VALUES_NB];

class Model_2D_Logo
{
    public:
        int32 *    p_timer;

        int32      pos_x[3]
                  ,pos_y[3]
                  ,size_w[3]
                  ,size_h[3]
                  ,alpha[3]
                  ,rot_x[3]
                  ,rot_y[3]
                  ,rot_z[3]
                  ,time[3];

        int32 * main_current_time, * main_total_time;

        uint8      textureID;
        int32      texture_h,texture_w;
        int8      direction;  //-1:backward 1:forward

        void calc_transition();
        void set_textureID(uint8 x_textureID);
        void set_values(logo_values xp_values); // set all values with a 9x3 array
        void set_direction(int8 x_direction);
        void set_main_current_time(int32 * xp_main_current_time);
        void set_main_total_time(int32 * max_time);
        Model_2D_Logo();
        ~Model_2D_Logo();

    protected:
    private:
};

#endif // _Model_2D_LOGO_H

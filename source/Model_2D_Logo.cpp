#include "Model_2D_Logo.h"

Model_2D_Logo::Model_2D_Logo()
{
   //ctor
    this->pos_x[LOGO_TRANS_START] = 0;
    this->pos_x[LOGO_TRANS_END] = 0;
    this->pos_x[LOGO_TRANS_CURRENT] = 0;

    this->pos_y[LOGO_TRANS_START] = 0;
    this->pos_y[LOGO_TRANS_END] = 0;
    this->pos_y[LOGO_TRANS_CURRENT] = 0;

    this->size_w[LOGO_TRANS_START] = 0;
    this->size_w[LOGO_TRANS_END] = 0;
    this->size_w[LOGO_TRANS_CURRENT] = 0;

    this->size_h[LOGO_TRANS_START] = 0;
    this->size_h[LOGO_TRANS_END] = 0;
    this->size_h[LOGO_TRANS_CURRENT] = 0;

    this->alpha[LOGO_TRANS_START] = 0;
    this->alpha[LOGO_TRANS_END] = 31;
    this->alpha[LOGO_TRANS_CURRENT] = 0;

    this->rot_x[LOGO_TRANS_START] = 0;
    this->rot_x[LOGO_TRANS_END] = 0;
    this->rot_x[LOGO_TRANS_CURRENT] = 0;

    this->rot_y[LOGO_TRANS_START] = 0;
    this->rot_y[LOGO_TRANS_END] = 0;
    this->rot_y[LOGO_TRANS_CURRENT] = 0;

    this->rot_z[LOGO_TRANS_START] = 0;
    this->rot_z[LOGO_TRANS_END] = 0;
    this->rot_z[LOGO_TRANS_CURRENT] = 0;

    this->time[LOGO_TRANS_START] = 0;
    this->time[LOGO_TRANS_END] = 0;
    this->time[LOGO_TRANS_CURRENT] = 0;

    this->textureID = 0;
    this->direction = 0;
}

Model_2D_Logo::~Model_2D_Logo()
{
    //dtor
}


void Model_2D_Logo::calc_transition()
{
    /// @todo (kiniou#50#):replace normal division par divf32. (look for divf32 function)

    int32 time_current,time_total;

    time_total = this->time[LOGO_TRANS_END] - this->time[LOGO_TRANS_START];

    //this->time[LOGO_TRANS_CURRENT] += this->direction * x_millisec;



    if ( *(this->main_current_time) >= this->time[LOGO_TRANS_END])
    {
        this->time[LOGO_TRANS_CURRENT] = this->time[LOGO_TRANS_END];
    }
    else
    if (*(this->main_current_time) <= this->time[LOGO_TRANS_START])
    {
        this->time[LOGO_TRANS_CURRENT] = this->time[LOGO_TRANS_START];
    }
    else
    {
        this->time[LOGO_TRANS_CURRENT] = *(this->main_current_time);
    }

//    if (this->time[LOGO_TRANS_CURRENT] >= this->time[LOGO_TRANS_START]
//        && this->time[LOGO_TRANS_CURRENT] <= this->time[LOGO_TRANS_END] )
//    {

    time_current = this->time[LOGO_TRANS_CURRENT] - this->time[LOGO_TRANS_START];
//    }


    this->pos_x [LOGO_TRANS_CURRENT]  = this->pos_x [LOGO_TRANS_START]  + ( time_current * ( this->pos_x [LOGO_TRANS_END]  - this->pos_x [LOGO_TRANS_START]  ) / (float) time_total );
    this->pos_y [LOGO_TRANS_CURRENT]  = this->pos_y [LOGO_TRANS_START]  + ( time_current * ( this->pos_y [LOGO_TRANS_END]  - this->pos_y [LOGO_TRANS_START]  ) / (float) time_total );
    this->size_w[LOGO_TRANS_CURRENT]  = this->size_w[LOGO_TRANS_START]  + ( time_current * ( this->size_w[LOGO_TRANS_END]  - this->size_w[LOGO_TRANS_START]  ) / (float) time_total );
    this->size_h[LOGO_TRANS_CURRENT]  = this->size_h[LOGO_TRANS_START]  + ( time_current * ( this->size_h[LOGO_TRANS_END]  - this->size_h[LOGO_TRANS_START]  ) / (float) time_total );
    this->alpha [LOGO_TRANS_CURRENT]  = this->alpha [LOGO_TRANS_START]  + ( time_current * ( this->alpha [LOGO_TRANS_END]  - this->alpha [LOGO_TRANS_START]  ) / (float) time_total );
    this->rot_x [LOGO_TRANS_CURRENT]  = this->rot_x [LOGO_TRANS_START]  + ( time_current * ( this->rot_x [LOGO_TRANS_END]  - this->rot_x [LOGO_TRANS_START]  ) / (float) time_total );
    this->rot_y [LOGO_TRANS_CURRENT]  = this->rot_y [LOGO_TRANS_START]  + ( time_current * ( this->rot_y [LOGO_TRANS_END]  - this->rot_y [LOGO_TRANS_START]  ) / (float) time_total );
    this->rot_z [LOGO_TRANS_CURRENT]  = this->rot_z [LOGO_TRANS_START]  + ( time_current * ( this->rot_z [LOGO_TRANS_END]  - this->rot_z [LOGO_TRANS_START]  ) / (float) time_total );

}


void Model_2D_Logo::set_values(logo_values xp_values)
{

    this->pos_x [LOGO_TRANS_CURRENT] = xp_values[0];
    this->pos_x [LOGO_TRANS_START]   = xp_values[0];
    this->pos_x [LOGO_TRANS_END]     = xp_values[1];

    this->pos_y [LOGO_TRANS_CURRENT] = xp_values[2];
    this->pos_y [LOGO_TRANS_START]   = xp_values[2];
    this->pos_y [LOGO_TRANS_END]     = xp_values[3];

    this->size_w[LOGO_TRANS_CURRENT] = xp_values[4];
    this->size_w[LOGO_TRANS_START]   = xp_values[4];
    this->size_w[LOGO_TRANS_END]     = xp_values[5];

    this->size_h[LOGO_TRANS_CURRENT] = xp_values[6];
    this->size_h[LOGO_TRANS_START]   = xp_values[6];
    this->size_h[LOGO_TRANS_END]     = xp_values[7];

    this->alpha [LOGO_TRANS_CURRENT] = xp_values[8];
    this->alpha [LOGO_TRANS_START]   = xp_values[8];
    this->alpha [LOGO_TRANS_END]     = xp_values[9];

    this->rot_x [LOGO_TRANS_CURRENT] = xp_values[10];
    this->rot_x [LOGO_TRANS_START]   = xp_values[10];
    this->rot_x [LOGO_TRANS_END]     = xp_values[11];

    this->rot_y [LOGO_TRANS_CURRENT] = xp_values[12];
    this->rot_y [LOGO_TRANS_START]   = xp_values[12];
    this->rot_y [LOGO_TRANS_END]     = xp_values[13];

    this->rot_z [LOGO_TRANS_CURRENT] = xp_values[14];
    this->rot_z [LOGO_TRANS_START]   = xp_values[14];
    this->rot_z [LOGO_TRANS_END]     = xp_values[15];

    this->time  [LOGO_TRANS_CURRENT] = 0;
    this->time  [LOGO_TRANS_START]   = xp_values[16];
    this->time  [LOGO_TRANS_END]     = xp_values[17];

}

void Model_2D_Logo::set_direction(int8 x_direction)
{
    this->direction = x_direction;
}

void Model_2D_Logo::set_textureID(uint8 x_textureID)
{
    this->textureID = x_textureID;
}

void Model_2D_Logo::set_main_current_time(int32 * xp_main_current_time)
{
    this->main_current_time = xp_main_current_time;
}

void Model_2D_Logo::set_main_total_time(int32 * xp_main_total_time)
{
    this->main_total_time = xp_main_total_time;
}

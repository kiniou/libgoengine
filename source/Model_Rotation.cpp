/* File : Model_Rotation.h
 * Purpose : This class defines a Rotation and its methods
 * Author : Kevin "KiNiOu" ROY
 * Creation Date : 29 May 2007
 *
 * 01/06/2007 : Definitions of a Rotation
 *
 */

#include "Model_Rotation.h"


Model_Rotation::Model_Rotation ()
{
    this->rot_ox = 0;
    this->rot_oy = 0;
    this->rot_oz = 0;

}


Model_Rotation::Model_Rotation ( int32 x_rot_ox, int32 x_rot_oy, int32 x_rot_oz )
{
    this->rot_ox = x_rot_ox;
    this->rot_oy = x_rot_oy;
    this->rot_oz = x_rot_oz;

}

Model_Rotation::~Model_Rotation ( void )
{
    this->rot_ox = 0;
    this->rot_oy = 0;
    this->rot_oz = 0;
}

int32 Model_Rotation::get_rot_ox ( void )
{
    return ( this->rot_ox );
}

int32 Model_Rotation::get_rot_oy ( void )
{
    return ( this->rot_oy );
}

int32 Model_Rotation::get_rot_oz ( void )
{
    return ( this->rot_oz );
}

void Model_Rotation::set_rot_ox ( int32 x_rot_ox )
{
    this->rot_ox = x_rot_ox;
}

void Model_Rotation::set_rot_oy ( int32 x_rot_oy )
{
    this->rot_oy = x_rot_oy;
}

void Model_Rotation::set_rot_oz ( int32 x_rot_oz )
{
    this->rot_oz = x_rot_oz;
}

void Model_Rotation::inc_rot ( int32 x_inc_ox,  int32 x_inc_oy,   int32 x_inc_oz  )
{
    this->rot_ox += x_inc_ox;
    this->rot_oy += x_inc_oy;
    this->rot_oz += x_inc_oz;
}

void Model_Rotation::mult_rot ( int32 x_mult_ox, int32 x_mult_oy,  int32 x_mult_oz )
{
    this->rot_ox *= x_mult_ox;
    this->rot_oy *= x_mult_oy;
    this->rot_oz *= x_mult_oz;
}

/* File : Model_Vector.h
 * Purpose : This class defines a Vector and its methods
 * Author : Kevin "KiNiOu" ROY
 * Creation Date : 29 May 2007
 *
 * 01/06/2007 : Definitions of a Vector
 *
 */

#include "Model_Vector.h"

Model_Vector::Model_Vector ()
{
    this->vec_ox = 0;
    this->vec_oy = 0;
    this->vec_oz = 0;
}

Model_Vector::Model_Vector ( int32 x_vec_ox, int32 x_vec_oy, int32 x_vec_oz )
{
    this->vec_ox = x_vec_ox;
    this->vec_oy = x_vec_oy;
    this->vec_oz = x_vec_oz;

}

Model_Vector::~Model_Vector ( void )
{
    this->vec_ox = 0;
    this->vec_oy = 0;
    this->vec_oz = 0;

}

int32     Model_Vector::get_vec_ox  ( void )
{
    return (this->vec_ox);
}

int32     Model_Vector::get_vec_oy  ( void )
{
    return (this->vec_oy);
}

int32     Model_Vector::get_vec_oz  ( void )
{
    return (this->vec_oz);
}

void    Model_Vector::set_vec_ox  ( int32 x_vec_ox )
{
    this->vec_ox = x_vec_ox;
}

void    Model_Vector::set_vec_oy  ( int32 x_vec_oy )
{
    this->vec_oy = x_vec_oy;
}

void    Model_Vector::set_vec_oz  ( int32 x_vec_oz )
{
    this->vec_oz = x_vec_oz;
}

void    Model_Vector::inc_vec     ( int32 x_inc_ox,  int32 x_inc_oy,   int32 x_inc_oz  )
{
    this->vec_ox += x_inc_ox;
    this->vec_oy += x_inc_oy;
    this->vec_oz += x_inc_oz;
}

void    Model_Vector::mult_vec    ( int32 x_mult_ox, int32 x_mult_oy,  int32 x_mult_oz )
{
    this->vec_ox *= x_mult_ox;
    this->vec_oy *= x_mult_oy;
    this->vec_oz *= x_mult_oz;
}


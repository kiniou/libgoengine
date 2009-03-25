/* File : Model_Rotation.h
 * Purpose : This class defines a Rotation and its methods
 * Author : Kevin "KiNiOu" ROY
 * Creation Date : 29 May 2007
 *
 * 01/06/2007 : Definitions of a Rotation
 *
 */

#include <nds.h>

#ifndef _Model_ROTATION
#define _Model_ROTATION

class Model_Rotation
{

    private :
        int32 rot_ox;
        int32 rot_oy;
        int32 rot_oz;

    public :
        Model_Rotation  ();
        Model_Rotation  ( int32 x_rot_ox, int32 x_rot_oy, int32 x_rot_oz );
        ~Model_Rotation ( void );

        int32     get_rot_ox  ( void );
        int32     get_rot_oy  ( void );
        int32     get_rot_oz  ( void );

        void    set_rot_ox  ( int32 x_rot_ox );
        void    set_rot_oy  ( int32 x_rot_oy );
        void    set_rot_oz  ( int32 x_rot_oz );

        void    inc_rot     ( int32 x_inc_ox,  int32 x_inc_oy,   int32 x_inc_oz  );
        void    mult_rot    ( int32 x_mult_ox, int32 x_mult_oy,  int32 x_mult_oz );

};

#endif

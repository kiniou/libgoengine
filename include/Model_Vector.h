/* File : Model_Vector.h
 * Purpose : This class defines a Vector and its methods
 * Author : Kevin "KiNiOu" ROY
 * Creation Date : 29 May 2007
 *
 * 01/06/2007 : Definitions of a Vector
 *
 */

#include <nds.h>

#ifndef _Model_VECTOR_H
#define _Model_VECTOR_H



class Model_Vector
{

    private :
        int32 vec_ox;
        int32 vec_oy;
        int32 vec_oz;

    public :
        Model_Vector  ();
        Model_Vector  (int32 x_vec_ox, int32 x_vec_oy, int32 x_vec_oz);
        ~Model_Vector (void);

        int32     get_vec_ox  (void);
        int32     get_vec_oy  (void);
        int32     get_vec_oz  (void);

        void    set_vec_ox  (int32 x_vec_ox);
        void    set_vec_oy  (int32 x_vec_oy);
        void    set_vec_oz  (int32 x_vec_oz);

        void    inc_vec     (int32 x_inc_ox,  int32 x_inc_oy,   int32 x_inc_oz  );
        void    mult_vec    (int32 x_mult_ox, int32 x_mult_oy,  int32 x_mult_oz );

};
#endif

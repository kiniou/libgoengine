#include <math.h>
#include <stdlib.h>

#include <nds.h>
#include <nds/arm9/trig_lut.h>
#include <nds/arm9/videoGL.h>
#include <nds/arm9/video.h>

#include "Model_Camera.h"


/*
 * Constructor :
 * - initialise la camera en mode CAMERA_MODE_FRONT
 * - assigne le vecteur LookAt avec le vecteur Front
 */
Model_Camera::Model_Camera()
{
    this->setLookAt(CAMERA_MODE_FRONT,NULL);
    this->fov = 35;
    this->ratio = 1.33;
    this->min_z = 1;
    this->max_z = 1000;
//    this->fov = (int) (degreesToAngle(35));
//    this->ratio = divf32( floattof32(SCREEN_WIDTH) , floattof32(SCREEN_HEIGHT) );
//    this->min_z = floattof32(1);
//    this->max_z = floattof32(1000);
    this->dir_front = 0;
    this->dir_right = 0;
    this->dir_up = 0;
    this->dir_len = floattof32(0.05);
    this->dist_from_target = floattof32(3);
}

/*
 * Destructeur :
 * - rien a faire puisqu'il n'y a pas d'allocations dynamiques
 */
Model_Camera::~Model_Camera()
{

}

/*
 * setLookAt:
 * - set the camera mode with 'mode'
 * - if mode is CAMERA_MODE_TARGET, target 'l' must not be NULL
 *   else setLookAt will point target to front and mode will become CAMERA_MODE_FRONT
 */
void Model_Camera::setLookAt(int mode,Model_Vector * l)
{
    this->mode = mode;

    switch (this->mode)
    {
    case CAMERA_MODE_FRONT :
        this->v_lookat = &this->v_front_real;
        break;
    case CAMERA_MODE_TARGET :
        if ( l != NULL )
        {
            this->v_lookat = l;

        }
        else
        {
            this->v_lookat = &this->v_front_real;
            this->mode = CAMERA_MODE_FRONT;

        }
        break;
    }
    this->initCamera();
}

/* initCamera:
 * - Compute LookAt vector for the first time
 * - initialize max_step and step
 */
void Model_Camera::initCamera(void)
{
    this->max_step = 300;
    this->step = this->max_step;

    this->computeLookAt();

}



void Model_Camera::computeFrontReal(void)
{
    s16 alpha,beta;
    int32 m;
    int32 stp = this->step;

    this->r_cam_real.set_rot_ox( this->r_cam_real_bk.get_rot_ox() + mulf32(this->r_cam_stp.get_rot_ox(),stp) );
    this->r_cam_real.set_rot_oy( this->r_cam_real_bk.get_rot_oy() + mulf32(this->r_cam_stp.get_rot_oy(),stp) );

    alpha = f32toint(this->r_cam_real.get_rot_oy());
    beta  = f32toint(this->r_cam_real.get_rot_ox());

    //m = COS[beta & LUT_MASK];
    m = cosLerp(beta);

//    v_front_real.set_vec_ox( v_position.get_vec_ox() + mulf32(SIN[alpha & LUT_MASK] , m) );
//    v_front_real.set_vec_oz( v_position.get_vec_oz() + mulf32(COS[alpha & LUT_MASK] , m) );
//    v_front_real.set_vec_oy( v_position.get_vec_oy() + SIN[beta & LUT_MASK] );

    v_front_real.set_vec_ox( v_position.get_vec_ox() + mulf32(sinLerp(alpha) , m) );
    v_front_real.set_vec_oz( v_position.get_vec_oz() + mulf32(cosLerp(alpha) , m) );
    v_front_real.set_vec_oy( v_position.get_vec_oy() + sinLerp(beta) );
}


void Model_Camera::computeDirection(void)
{
    int32 alpha,beta,m;
    int32 stp = this->step;
    //Calcul des vecteurs front,left,(up?)
    this->r_cam_real.set_rot_ox( this->r_cam_real_bk.get_rot_ox() + mulf32(this->r_cam_stp.get_rot_ox(),stp) );
    this->r_cam_real.set_rot_oy( this->r_cam_real_bk.get_rot_oy() + mulf32(this->r_cam_stp.get_rot_oy(),stp) );
    alpha = f32toint( this->r_cam_real.get_rot_oy() );
    beta  = f32toint( this->r_cam_real.get_rot_ox() );

    //m = COS[beta & LUT_MASK];
    m = cosLerp(beta);
    v_front.set_vec_ox( mulf32(sinLerp(alpha) , m) );
    v_front.set_vec_oz( mulf32(cosLerp(alpha) , m) );
    v_front.set_vec_oy( sinLerp(beta)              );

    v_right.set_vec_ox( sinLerp((alpha - 128)) );
    v_right.set_vec_oz( cosLerp((alpha - 128)) );
    v_right.set_vec_oy( 0                             );
}


void Model_Camera::computePosition(void)
{
    s16 alpha,beta;
    int32 m,n;

    int32 stp = this->step;
    this->r_cam_real.set_rot_ox( this->r_cam_real_bk.get_rot_ox() + mulf32(this->r_cam_stp.get_rot_ox(),stp) );
    this->r_cam_real.set_rot_oy( this->r_cam_real_bk.get_rot_oy() + mulf32(this->r_cam_stp.get_rot_oy(),stp) );

    alpha = degreesToAngle( f32toint(this->r_cam_real.get_rot_oy()) );
    beta  = degreesToAngle( f32toint(this->r_cam_real.get_rot_ox()) );

    m = mulf32( cosLerp(beta) , this->dist_from_target);
    n = mulf32( sinLerp(beta) , this->dist_from_target);
    this->v_position.set_vec_ox( this->v_lookat->get_vec_ox() + mulf32(sinLerp(alpha) , m) );
    this->v_position.set_vec_oz( this->v_lookat->get_vec_oz() + mulf32(cosLerp(alpha) , m) );
    this->v_position.set_vec_oy( this->v_lookat->get_vec_oy() + n );

}

/* computeLookAt:
 * - compute 'LookAt' vector
 */

void Model_Camera::computeLookAt( void )
{
    switch (this->mode)
    {
    case CAMERA_MODE_FRONT:
        this->computeDirection();
        this->computeFrontReal();
        break;
    case CAMERA_MODE_TARGET:
        this->computePosition();
        break;
    }

}

/*
 * Getters
 */

Model_Vector * Model_Camera::getFront( void )
{
    return (&this->v_front);
}

Model_Vector * Model_Camera::getRight ( void )
{
    return (&this->v_right);
}

Model_Vector * Model_Camera::getUp   ( void )
{
    return (&this->v_up);
}

Model_Vector * Model_Camera::getLookAt( void )
{
    return (this->v_lookat);
}

Model_Vector * Model_Camera::getPosition( void )
{
    return (&this->v_position);
}

/*
 * Setters
 */

void Model_Camera::setStep( int32 timer)
{
    int32 inc_front = mulf32(this->dir_front , this->dir_len);
    int32 inc_right = mulf32(this->dir_right , this->dir_len);
    int32 inc_up    = mulf32(this->dir_up , this->dir_len);
    int32 inc_dist  = mulf32(this->dir_front , this->dir_len);

    if (this->animated) this->step += timer;
    if (this->step > this->max_step) this->step=this->max_step;

    switch(this->mode) {
        case CAMERA_MODE_FRONT:
            this->v_position.inc_vec( mulf32( this->v_front.get_vec_ox() , inc_front) , mulf32( this->v_front.get_vec_oy() , inc_front), mulf32( this->v_front.get_vec_oz() , inc_front) );
            this->v_position.inc_vec( mulf32( this->v_right.get_vec_ox() , inc_right) , mulf32( this->v_right.get_vec_oy() , inc_right), mulf32( this->v_right.get_vec_oz() , inc_right) );
            this->v_position.inc_vec( 0 , inc_up, 0 );
        break;
        case CAMERA_MODE_TARGET:
            this->dist_from_target -= inc_dist;
        break;
    }

    this->computeLookAt();

}



/*
 * Move Functions
 */

void Model_Camera::moveFront(int32 dir)
{
    this->dir_front = dir;
}

void Model_Camera::moveRight(int32 dir)
{
    this->dir_right = dir;
}

void Model_Camera::moveUp(int32 dir)
{
    this->dir_up = dir;
}


/*
 * Rotation function
 */


void Model_Camera::RotateCamera(int alpha,int beta)
{
    int32 len_x,len_y;
    int32 min=floattof32(-87),max=floattof32(87);


    this->r_cam_final.set_rot_ox( this->r_cam_catch.get_rot_ox() +  inttof32(beta)  );
    this->r_cam_final.set_rot_oy( this->r_cam_catch.get_rot_oy() +  inttof32(alpha) );

    if (this->r_cam_final.get_rot_ox()<min) this->r_cam_final.set_rot_ox(min);
    if (this->r_cam_final.get_rot_ox()>max) this->r_cam_final.set_rot_ox(max);

    if (
        (this->r_cam_final_bk.get_rot_ox() != this->r_cam_final.get_rot_ox()) ||
        (this->r_cam_final_bk.get_rot_oy() != this->r_cam_final.get_rot_oy())

    )
    {
        this->step = 0;
        this->r_cam_real_bk = this->r_cam_real;
        this->r_cam_final_bk = this->r_cam_final;

        len_x = this->r_cam_final_bk.get_rot_ox() - this->r_cam_real_bk.get_rot_ox();
        len_y = this->r_cam_final_bk.get_rot_oy() - this->r_cam_real_bk.get_rot_oy();
        this->r_cam_stp.set_rot_ox( divf32(len_x , this->max_step) );
        this->r_cam_stp.set_rot_oy( divf32(len_y , this->max_step) );
    }

}

void Model_Camera::catchCamera()
{
    this->r_cam_catch = this->r_cam_final;
}

void Model_Camera::releaseCamera()
{
    //this->r_cam_final = this->r_cam_catch;
}

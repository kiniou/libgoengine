#include <nds.h>
#include <nds/arm9/videoGL.h>

#include <GOEN_Model_Vector.h>
#include <GOEN_Model_Rotation.h>


#ifndef _Model_CAMERA
#define _Model_CAMERA

#define CAMERA_MODE_FRONT  0
#define CAMERA_MODE_TARGET 1

#define MOVE_ON  0x1000
#define MOVE_OFF 0x0000

class Model_Camera {

    public :
        Model_Vector   v_position; //Position de la camera

        Model_Vector   v_lookat_real;  //Position de la cible en mode CAMERA_MODE_FRONT (calculée par v_position + v_front_real)
        Model_Vector   v_front_real;   //Vecteur avant de la camera en mode CAMERA_MODE_FRONT (calculée avec la rotation r_front_real)
        Model_Vector   v_front; //Vecteur direction de l'avant de la camera
        Model_Vector   v_right; //Vecteur direction de la droite de la camera
        Model_Vector   v_up;    //Vecteur direction du haut de la camera

        Model_Rotation r_cam_real;    //Rotation reelle de la camera (calculée par r_cam_real_bk + (r_cam_real_stp * step)
        Model_Rotation r_cam_real_bk; //Rotation backup de la précédente rotation r_cam_real
	Model_Rotation r_cam_final;   //Rotation finale qui correspond à la rotation souhaitée
        Model_Rotation r_cam_final_bk;//Rotation backup de la précédente rotation finale
        Model_Rotation r_cam_catch;   //Rotation backup avant mouvement de la camera
        Model_Rotation r_cam_stp;//Increment de Rotation reelle

        Model_Vector * v_lookat;        //Position de la cible (d'un objet dans le cas du CAMERA_MODE_TARGET)
        int32       dist_from_target;   //Distance séparant la cible de la caméra (en mode CAMERA_MODE_TARGET)



        int32       mode; //Camera Mode
	int32       step; //Current step (ms)
	int32       max_step; //Maximum step (ms)
	int         animated; //Is the camera animated?

	float       fov;  //Field Of View
	float       ratio;//Ratio de l'ecran
	float       min_z;//Minimum Z de la camera
	float       max_z;//Maximum Z de la camera
//	int32       fov;  //Field Of View
//	int32       ratio;//Ratio de l'ecran
//	int32       min_z;//Minimum Z de la camera
//	int32       max_z;//Maximum Z de la camera

	int         dir_front; //1=avance, 0=stop, -1=recule
	int         dir_right; //1=droite, 0=stop, -1=gauche
	int         dir_up;    //1=haut  , 0=stop, -1=bas
	int32       dir_len;   //vitesse de déplacement en metre/ms


    public :
        Model_Camera();
        ~Model_Camera();


        void setLookAt(int mode,Model_Vector * l);
        void initCamera();

        Model_Vector * getFront( void );
        Model_Vector * getRight ( void );
        Model_Vector * getUp   ( void );

        Model_Vector * getLookAt(void );
        Model_Vector * getPosition( void );

        void computeLookAt( void );
        void computeFrontReal(void);
        void computeDirection(void);
        void computePosition(void);
        void setStep(int32 timer);

        void moveFront(int32 dir);
        void moveRight(int32 dir);
        void moveUp(int32 dir);

        void RotateCamera(int alpha,int beta);

        Model_Rotation * get_r_front();
        void catchCamera();
        void releaseCamera();
};

#endif //_Model_CAMERA

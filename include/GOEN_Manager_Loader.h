/* File : Manager_Loader.h
 * Purpose : This class defines a 3D Object Loader and its methods
 * Author : Kevin "KiNiOu" ROY
 * Creation Date : 08 October 2007
 *
 * 08/10/2007 : Definitions of a Loader
 *
 */

#ifndef _Manager_LOADER_H
#define _Manager_LOADER_H

#include <stdio.h>
#include <stdlib.h>

//#include <fat.h>

#include <GOEN_Model_Scene.h>

#define MAXCAR_IN_LINE 256

#define TYPE_OBJECT     1
#define TYPE_VECTOR     2
#define TYPE_NORMALE    3
#define TYPE_TEXTURE    4
#define TYPE_FACE       5

class Manager_Loader {

    public:

        int error;
        bool    initialized;

        Model_Face * list_faces;

        uint16 nb_objects;

        Manager_Loader();
        ~Manager_Loader();

        void init();

        Model_Scene * loadScene(char * filename);
        int countElement(FILE * f);
        int readNextObject(FILE * f, Model_Object * obj);
        int getNextElement(FILE * f, char * str);
        int getTypeLine(char * str);
};

#endif // _Manager_LOADER_H

#ifndef _Model_SCENE_H
#define _Model_SCENE_H

#include <string.h>

#include <GOEN_Model_Object.h>
#include <GOEN_Model_Camera.h>

class Model_Scene
{
    public:
        //Attributes
        Model_Object * objects;
        int nb_objects;

        uint32 * call_list;
        int * idx_objects;

        Model_Camera * cam;

        //Methods
        Model_Scene();
        ~Model_Scene();

};



#endif // _Model_SCENE_H

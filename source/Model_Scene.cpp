#include <GOEN_Model_Scene.h>


Model_Scene::Model_Scene()
{

    //Initialize Attributes
    this->objects = NULL;
    this->nb_objects = 0;

}

Model_Scene::~Model_Scene()
{

    //Delete all objects (if there are any...)
    if (this->objects!=NULL && this->nb_objects > 0)
    {
        delete(this->objects);
        this->objects=NULL;
        this->nb_objects=0;
    }

    //Delete CallList
}



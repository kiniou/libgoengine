#include "Model_Object.h"


Model_Object::Model_Object()
{
    //ctor
    this->nb_faces=0;
    this->nb_normals=0;
    this->nb_vectors=0;
    this->nb_texcoords=0;

    this->list_faces=NULL;
    this->list_normals=NULL;
    this->list_vectors=NULL;
    this->list_texcoords=NULL;
}

Model_Object::~Model_Object()
{
    //dtor
}



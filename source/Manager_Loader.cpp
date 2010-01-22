/* File : Manager_Loader.cpp
 * Purpose : This class defines a 3D Object Loader and its methods
 * Author : Kevin "KiNiOu" ROY
 * Creation Date : 08 October 2007
 *
 * 08/10/2007 : Implementations of the Loader
 *
 */
#include <GOEN_Manager_Loader.h>

Manager_Loader::Manager_Loader()
{
    this->init();
}

Manager_Loader::~Manager_Loader()
{

}

void Manager_Loader::init()
{
    //this->initialized = fatInitDefault();
}

Model_Scene * Manager_Loader::loadScene(char * filename)
{
    Model_Scene * scene;
    Model_Object * object;
//    int idx_obj;
    FILE * f;

    scene = NULL;
    object = NULL;

    f = NULL;
    f = fopen(filename,"r");

    if (f==NULL) return NULL;

    scene = new Model_Scene();
    this->countElement(f);

    scene->objects = new Model_Object[this->nb_objects];
    scene->nb_objects = this->nb_objects;

    //for (idx_obj=0;idx_obj<this->nb_objects;idx_obj++)
    //{
    //	this->error = this->readNextObject(f,&scene->objects[idx_obj]);
    //}

    fclose(f);
    f=NULL;
    return scene;

}

int Manager_Loader::countElement(FILE * f)
{
    char c=0;
    char eof = -1;

    if (f==NULL) return (-1);

    fseek(f,SEEK_SET,0);
    this->nb_objects=0;

    while ( c != eof )
    {
        c = fgetc(f);

        if (c=='\n')
        {
            c = fgetc(f);
        }
        if (c=='g') this->nb_objects++;
    }
    fseek(f,SEEK_SET,0);
    return 0;
}

int Manager_Loader::readNextObject(FILE * f,Model_Object * obj)
{
    char str[32];
    char eof = 0;
    //char type = 0;
    int nb_read = 0;
    int err = 0;
    int obj_match = 0;

    if (f==NULL) return (-1);

    eof = feof(f);

    while (!eof && obj_match != 2)
    {
        err = this->getNextElement(f,str);
        if (err>0) nb_read+=err;
        else return (err);

        eof = feof(f);

        switch (this->getTypeLine(str))
        {
        case TYPE_FACE :
            obj->nb_faces++;
            break;
        case TYPE_NORMALE :
            obj->nb_normals++;
            break;
        case TYPE_TEXTURE :
            obj->nb_texcoords++;
            break;
        case TYPE_VECTOR :
            obj->nb_vectors++;
            break;
        case TYPE_OBJECT :
            obj_match++;
            break;
        }
    }
    printf("[obj=%d]",obj_match);
    return nb_read;
}

int Manager_Loader::getNextElement(FILE * f, char * str)
{
    char c;
    int i,max,eof;

    if (f==NULL || str == NULL) return (-1);

    max = 32;
    c=0;
    eof=feof(f);

    for (i=0;i<max;i++)
    {
        str[i] = 0;
        c = fgetc(f);
        eof=feof(f);
        //Si on matche un espace ou un retour à la ligne ou un EOF, alors on sort de la boucle
        if (c==' ' || c=='\n' || eof)
        {
            break;
        }
        else
        {
            str[i] = c;
        }
    }
    //Erreur si on atteint max sans avoir matché un espace ou un retour à la ligne
    if (i==max) return (-3);
    //Sinon on renvoie le nombre de caractère lu (pour faire un retour en arrière dans le cas où on détecte un nouvel objet)
    else return i;
}

int Manager_Loader::getTypeLine(char * str)
{

    if (str == NULL) return (-1);

    printf("%s\n", str);
    if ( strcmp(str,"g" )==0 || strcmp(str,"o")==0 ) return (TYPE_OBJECT);
    if ( strcmp(str,"v" )==0 ) return (TYPE_VECTOR);
    if ( strcmp(str,"vn")==0 ) return (TYPE_NORMALE);
    if ( strcmp(str,"vt")==0 ) return (TYPE_TEXTURE);
    if ( strcmp(str,"f" )==0 ) return (TYPE_FACE);
    return (-2);
}

//void Manager_Loader::readElement(FILE * f)
//{
//
//}
//
//Model_Vector * Manager_Loader::readVector(FILE * f)

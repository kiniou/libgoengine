#ifndef _Model_FACE_H
#define _Model_FACE_H

#include <nds.h>

class Model_Face
{
    public:

        uint16 nb_vectors;
        uint16 * idx_vectors;
        uint16 nb_normals;
        uint16 * idx_normals;
        uint16 nb_texcoords;
        uint16 * idx_texcoords;

        Model_Face();
        ~Model_Face();
    protected:
    private:
};



#endif // _Model_FACE_H

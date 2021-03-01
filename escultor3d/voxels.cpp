#include "voxels.h"

voxels::voxels()
{
    struct Voxel{
        //cor e transparencia
        float r, g, b;
        float transp;

        //está ativo
        bool isOn;
    };
}

#ifndef IMAGE_H
#define IMAGE_H

#include <math.h>

#include "matrix.h"
#include "bmpfile.h"

int to_colour(num f);
void image_write(const char* filename, num* mat, int n);

#endif // IMAGE_H

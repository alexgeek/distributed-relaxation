#include "image.h"

/* image writing functions */

// maps [0,1] to [0,256] for 8 bit colour.
int to_colour (num f) {
  return 255 - floor(f == 1.0 ? 255 : f * 256.0);
}

// write grid to bitmap
void image_write(const char* filename, num* mat, int n)
{
  int depth = 24;
  bmpfile_t *bmp;
  rgb_pixel_t pixel = {0, 0, 0, 0};

  if ((bmp = bmp_create(n, n, depth)) == NULL) {
    fprintf(stderr, "Could not create bitmap.\n");
    return;
  }

  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      float f = mat[i*n + j];
      pixel.red = to_colour(f);
      pixel.green = to_colour(f);
      pixel.blue = to_colour(f);
      bmp_set_pixel(bmp, j, i, pixel);
    }
  }

  bmp_save(bmp, filename);
  bmp_destroy(bmp);
}

#include <constants.h>
#include "utils.c"
#include "gauss_filter.c"

/*********************************************************************************/

int main(int argc, char* argv[] )  {

  /* SE MUESTRA IMAGEN */
  IplImage* _img = load_img(argv[1] );
  show_image(_img);

  /* Se cambia de imagen a matriz */
  CvMat* mtx = cvCreateMat(img_h, img_w, CV_8UC3);
  cvConvert(_img, mtx);

  /* Acomoda cada pixel 3D en un arreglo */
  print_RGBimg(mtx);

  /* Aplica filtro Gaussian Blur a la imagen */
  gaussian_blur(mtx);

  return 0;
}
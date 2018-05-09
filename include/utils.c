
/***************************************************/
/* Carga imagen a programa */

IplImage* load_img(char* img_name ) {

  IplImage* img_proc = 0;
  // Carga una imagen
  img_proc = cvLoadImage(img_name, CV_LOAD_IMAGE_COLOR );

  // Verifica si la imagen se cargo exitosamente
  if(!img_proc ) {
    printf("No fue posible cargar la imagen: %s\n", img_name);
    exit(0);
  }
  img_h = img_proc->height;
  img_w = img_proc->width;
  printf("Procesando imagen de %dx%d.\n",img_w,
                                            img_h);
  // Crea ventana para mostrar imagen
  cvNamedWindow(TITLE_W, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(TITLE_W, SIZE_W, SIZE_W);
  
  return img_proc;
}

/***************************************************/

/* Muestra imagen con OpenCV */
void show_image (IplImage* img) {
  // Muestra la imagen
  cvShowImage(TITLE_W, img);
  // Espera por una señal del teclado para cerrar ventana
  cvWaitKey(0);
}

/***************************************************/

void print_RGBimg (CvMat* mtx )  {

  CvScalar pix;
  int xx;
  for(int j = 0; j < img_h; ++j) {
    for(int i = 0; i < img_w; ++i) {
        printf("(");
        for(int z = 0; z < RGB_CHANNEL; ++z) {
            pix = cvGet2D( mtx, j, i);
            xx = (int)(pix.val[z]);
            printf( "%d,",xx);
        }
        printf(")");
    }
    printf("\n");
  }

}
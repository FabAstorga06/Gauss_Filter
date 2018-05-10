#include "constants.h"
#include "image_utils.hpp"
#include "gaussian_blur.hpp"


int main(int argc, char** argv )  {

    /* Se checkean los parametros de entrada */    
    if (argc != PARAMS) {
    	printf("Inserte los parametros necesarios...\n");
	exit(1);
    }	
    int kernel_size = atoi(argv[1]);

    /****************************************************************/

    /* Se aplica filtro a imagen */
    Matrix _kernel = calc_kernel(kernel_size, kernel_size, 10.0);
    std::cout << "Cargando imagen..." << std::endl;
    Image _img = load_image(argv[2]);
    std::cout << "Aplicando filtro Gaussian Blur..." << std::endl;
    Image _new_img = apply_gaussian_filter(_img, _kernel);
    std::cout << "Guardando imagen..." << std::endl;
    save_image(_new_img, argv[3]);
    std::cout << "Listo!" << std::endl;

    return 0;
}

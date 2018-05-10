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
    Matrix filter = calc_kernel(kernel_size, kernel_size, 10.0);
    std::cout << "Cargando imagen..." << std::endl;
    Image image = load_image(argv[2]);
    std::cout << "Aplicando filtro Gaussian Blur..." << std::endl;
    Image newImage = apply_gaussian_filter(image, filter);
    std::cout << "Guardando imagen..." << std::endl;
    save_image(newImage, argv[3]);
    std::cout << "Listo!" << std::endl;

    return 0;
}

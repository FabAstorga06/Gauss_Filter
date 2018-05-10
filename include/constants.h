#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <png++/png.hpp>

#define RGB 3
#define PARAMS 4

static const std::string _dir = "img/";

typedef std::vector<double> Array;
typedef std::vector<Array> Matrix;
typedef std::vector<Matrix> Image;
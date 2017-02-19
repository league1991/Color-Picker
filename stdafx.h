#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>

#include <QtGui>
#include <QGLWidget>
#include <QImage>
#include <QFileDialog>

inline float randf(){return rand() / float(RAND_MAX);}
//inline float min(float a, float b){return a<b?a:b;}
//inline float max(float a, float b){return a>b?a:b;}

#include "SOM.h"
#include "Histogram.h"

#include "colorpicker.h"

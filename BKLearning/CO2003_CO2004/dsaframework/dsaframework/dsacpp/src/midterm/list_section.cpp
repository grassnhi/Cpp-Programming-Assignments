#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "list/XArrayList.h"
#include "util/FileIOLib.h"
#include "util/ArrayLib.h"

#include "list_api_use_demo.h"
#include "schain_demo.h"

int main(int argc, char **argv){
    XArrayList<Point3D> points = gen_points();
    cout << points.size() << endl;
    return 0;
}
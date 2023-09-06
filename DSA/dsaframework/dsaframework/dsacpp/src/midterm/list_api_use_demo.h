/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list_api_use_demo.h
 * Author: ltsach
 *
 * Created on July 15, 2021, 5:23 PM
 */

#ifndef LIST_API_USE_DEMO_H
#define LIST_API_USE_DEMO_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "list_api_use.h"
void rectangle_area_demo(){
    Point3D vv[] = {
        Point3D(0, 0, 0),
        Point3D(0, 5, 0),
        Point3D(6, 5, 0),
        Point3D(6, 0, 0),
    };
    XArrayList<Point3D> list;
    for(Point3D v: vv) list.add(v);
    cout << rectangle_area(list) << endl;
}

#endif /* LIST_API_USE_DEMO_H */


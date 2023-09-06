/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list_api_use.h
 * Author: ltsach
 *
 * Created on July 15, 2021, 5:18 PM
 */

#ifndef LIST_API_USE_H
#define LIST_API_USE_H
#include "list/XArrayList.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "list/XArrayList.h"
#include "util/FileIOLib.h"
#include "geom/Point3D.h"
#include <math.h>
using namespace std;
//M_PI

XArrayList<Point3D> make_circle(Point3D center, float radius, int npoints=100){
    XArrayList<Point3D> circle;
    float delta = 2*M_PI/npoints;
    for(int idx=0; idx < npoints; idx++){
        float x = center.getX() + radius * cos(idx * delta);
        float y = center.getY() + radius * sin(idx * delta);
        circle.add(Point3D(x, y));
    }
    return circle;
}
void store_circle(XArrayList<Point3D> points, string filename){
    vector<string> x_vec, y_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
    }
    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.write(filename);
}


XArrayList<Point3D> make_parabol(XArrayList<Point3D> xy){
    XArrayList<Point3D> xyz;
    XArrayList<Point3D>::Iterator it;
    for(it = xy.begin(); it != xy.end(); it++){
        Point3D point = *it;
        float x = point.getX();
        float y = point.getY();
        float z = x*x + y*y;
        xyz.add(Point3D(x, y, z));
    }
    return xyz;
}

XArrayList<Point3D> make_grid(float xmin, float xmax, float ymin, float ymax, float nitems=100){
    XArrayList<Point3D> grid;
    float dx = (xmax - xmin)/nitems;
    float dy = (ymax - ymin)/nitems;
    float x = xmin - dx;
    for(int xidx =0; xidx < nitems; xidx++){
        x += dx;
        float y = ymin - dy;
        for(int yidx =0; yidx < nitems; yidx++){
            y += dy;
            grid.add(Point3D(x, y));
        }
    }
    return grid;
}

void store_grid(XArrayList<Point3D> points, string filename){
    vector<string> x_vec, y_vec, z_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos, zos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        zos << fixed << setw(8) << setprecision(4) << point.getZ();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
        z_vec.push_back(zos.str());
    }
    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("z", z_vec);
    df.write(filename);
}

void store_parabol(XArrayList<Point3D> points, string filename){
    vector<string> x_vec, y_vec, z_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos, zos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        zos << fixed << setw(8) << setprecision(4) << point.getZ();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
        z_vec.push_back(zos.str());
    }
    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("z", z_vec);
    df.write(filename);
}

void bbox(XArrayList<Point3D>& points, Point3D& lt, Point3D& rb){
    float xmin = points.get(0).getX();
    float xmax = points.get(0).getX();
    float ymin = points.get(0).getY();
    float ymax = points.get(0).getY();
    XArrayList<Point3D>::Iterator it;
    for(it = points.begin(); it != points.end(); it++){
        Point3D point = *it;
        if( point.getX() < xmin) xmin = point.getX();
        if( point.getX() > xmax) xmax = point.getX();
        if( point.getY() < ymin) ymin = point.getY();
        if( point.getY() > ymax) ymax = point.getY();
    }
    lt = Point3D(xmin, ymax);
    rb = Point3D(xmax, ymin);
}

void store_bb(XArrayList<Point3D> points, string filename){
    Point3D lt, rb;
    bbox(points, lt, rb);
    //
    vector<string> x_vec, y_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
    }
    
    vector<string> lt_vec, rb_vec;
    stringstream ltos, rbos;
    ltos  << fixed << setw(8) << setprecision(4) << lt.getX() << "," \
          << fixed << setw(8) << setprecision(4) << lt.getY() << "," \
          << fixed << setw(8) << setprecision(4) << lt.getZ();
    rbos  << fixed << setw(8) << setprecision(4) << rb.getX() << ","  \
          << fixed << setw(8) << setprecision(4) << rb.getY() << ","  \
          << fixed << setw(8) << setprecision(4) << rb.getZ();
    lt_vec.push_back(ltos.str());
    rb_vec.push_back(ltos.str());

    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("lt", lt_vec);
    df.add("rb", rb_vec);
    
    df.write(filename, ';');
}
XArrayList<Point3D> gen_points(){
    XArrayList<Point3D> points;
    int size = 50;
    float mu[] = {1.0f, 1.0f, 1.0f};
    float sigma[] = {1.0f, 1.0f, 1.0f};
    Point3D *ptr = Point3D::genPointsNormal(size, mu, sigma, true, 2021);
    for(int idx=0; idx < size; idx++) points.add(Point3D(ptr[idx]));
    delete []ptr;
    return points;
}

XArrayList<Point3D> helix(float radius, int nsamples = 100, float dz=0.1, int npoints = 500){
    XArrayList<Point3D> points;
    float d_angle = 2*M_PI/nsamples;
    for(int n = 0; n < npoints; n++){
        float x = radius * cos(d_angle*n);
        float y = radius * sin(d_angle*n);
        float z = dz * n;
        points.add(Point3D(x, y, z));
    }
    return points;
}
void store_helix(XArrayList<Point3D> points, string filename){
    vector<string> x_vec, y_vec, z_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos, zos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        zos << fixed << setw(8) << setprecision(4) << point.getZ();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
        z_vec.push_back(zos.str());
    }
    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("z", z_vec);
    df.write(filename);
}

XArrayList<Point3D> linspace(Point3D start, Point3D stop, int num=100){
    XArrayList<Point3D> points;
    Vector3D dir = stop - start;
    float step = dir.length()/num;
    dir = dir.normalize();
    Point3D point = start;
    for(int n = 0; n < num; n++){
        points.add(point);
        point = point + step*dir;
    }
    return points;
}


float rectangle_area(XArrayList<Point3D>& vertices){
    Point3D A = vertices.get(0);
    Point3D B = vertices.get(1);
    Point3D C = vertices.get(2);
    float ab = (B - A).length();
    float bc = (C - B).length();
    return ab*bc;
}

Point3D center(XArrayList<Point3D>& points){
    Point3D mean;
    XArrayList<Point3D>::Iterator it;
    for(it = points.begin(); it != points.end(); it++)
      mean = mean + *it;
    return mean/points.size();
}

#endif /* LIST_API_USE_H */


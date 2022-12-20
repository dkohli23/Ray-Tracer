#ifndef VEC3_H
#define VEC3_H

// prevents the file from being re-rendered by cheking if its already defined

#include <cmath>
#include <iostream>

// imports the function to the current scope (when called in other files?)
using std::sqrt;

class vec3{
    public:
        vec3(): e(0, 0, 0) {}
        vec3(double e0, double e1, double e2): e(e0, e1, e2) {}

        // return the values of x, y,z
        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}


}
#include <iostream>
#include <math.h>
using namespace std;

int main() {

    // Image
    const int image_width = 256;
    const int image_height = 265;

    //Face shape
    const int face_radius = 50;
    
    //Eyes
    const int eye_radius = 7;
    
    const int l_eye_x = image_width/2 - face_radius/3;
    const int r_eye_x = image_width/2 + face_radius/3;
    
    const int eye_y = image_height/2 + face_radius/3;


    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j){
        int dy = abs(j - image_height/2);
        
        for (int i = 0; i < image_width; ++i){
            int dx = abs(i - image_height/2);
            
            int distance = int(sqrt(double((dx * dx) + (dy * dy))));
            int ir = 0;
            int ig = 0;
            int ib = 0;

            if (distance <= face_radius){
                int eye_dist = face_radius + 1;

                // left eye
                if (j > image_height/2 and i < image_width/2) {
                    int dx_eye = abs(i - l_eye_x);
                    int dy_eye = abs(j - eye_y);

                    eye_dist = int(sqrt(double((dx_eye * dx_eye) + (dy_eye * dy_eye))));   
                }
                // right eye
                else if (j > image_height/2 and i > image_width/2) {
                    int dx_eye = abs(i - r_eye_x);
                    int dy_eye = abs(j - eye_y);

                    eye_dist = int(sqrt(double((dx_eye * dx_eye) + (dy_eye * dy_eye)))); 
                }

                if (eye_dist <= eye_radius){
                    ir = 0;
                    ig = 0;
                    ib = 0;
                } else{
                    ir = static_cast<int>(255.999);
                    ig = static_cast<int>(255.999);
                    ib = 0;
                } 
            }
            else{
                auto r = double(i) / (image_width-1);
                auto g = double(j) / (image_height-1);
                auto b = 0.25;

                ir = static_cast<int>(255.999 * r);
                ig = static_cast<int>(255.999 * g);
                ib = static_cast<int>(255.999 * b);
            }
           
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}


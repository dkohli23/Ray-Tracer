#include <iostream>
using namespace std;

int main() {

    // Image
    const int image_width = 256;
    const int image_height = 265;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j){
        for (int i = 0; i < image_width; ++i){
            int ir = 0;
            int ig = 0;
            int ib = 0;

            if (77 <= j && j <= 177 && 77 <= i && i <= 177){
                ir = static_cast<int>(255.999);
                ig = static_cast<int>(255.999);
                ib = 0;
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


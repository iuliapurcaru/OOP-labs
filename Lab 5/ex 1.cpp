#include <iostream>

using namespace std;

class Volume
{
public:
    void volume()
    {
        cout << "Volumele corpurilor geometrice:" << endl;
    }

    void volume(int edge)
    {
        int vol = edge * edge * edge;
        cout << "Volumul cubului cu latura " << edge << " este: " << vol;
        cout << endl;
    }

    void volume(int rad, char c)
    {
        float vol = (4/(float)3)*3.14*rad*rad*rad;
        cout << "Volumul sferei cu raza " << rad << " este: " << vol;
        cout << endl;
    }

    void volume(int area, int height)
    {
        float vol = (area*height)/(float)3;
        cout << "Volumul piramidei cu aria bazei " << area << " si inaltimea " << height << " este: " << vol;
        cout << endl;
    }

};

int main()
{
    Volume message;
    Volume cube;
    Volume sphere;
    Volume pyramid;

    message.volume();
    cube.volume(3);
    sphere.volume(2, 's');
    pyramid.volume(8, 7);

    return 0;
}

#include <stdio.h>
#include <math.h>
struct vectorr{
    float x;
    float y;
};
int main()
{
    struct vectorr v1, v2;
    v1.x = 5;
    v1.y = 5;
    v2.x = 7;
    v2.y = 7;
    float d = sqrt(((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y)));
    printf("%f", d);
    return 0;   
}
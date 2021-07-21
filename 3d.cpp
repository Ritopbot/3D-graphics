#include <stdio.h>
#include "VectorFunctions.h"
#include <math.h>

#define width 120
#define height 30

int main()
{

    char gradient[] = " .':,\"!/r(l1Z4H9W8$@";
    char screen[width * height + 1];
    screen[width * height] = '\0';
    double ratio = 1.8;
    

    for (int t = 0; t < 10000; t++)
    {
        Vector3 spherePos = Vector3(0, 3, 0);
        Vector3 light = norm(Vector3(-0.5, 0.5, -1.0));
        for (size_t i = 0; i < width; i++)
        {
            for (size_t j = 0; j < height; j++)
            {
                Vector2 uv = Vector2(i, j) / Vector2(width, height) - 0.5;
                uv.x *= ratio;
                Vector3 ro = Vector3(-5, 0, 0);
                Vector3 rd = norm(Vector3(1, uv + 0.1));
                ro = rotateZ(ro, t * 0.01);
                rd = rotateZ(rd, t * 0.01);
                ro = rotateY(ro, t * 0.01);
                rd = rotateY(rd, t * 0.01);
                double diff = 0;
                Vector2 minIt = Vector2(99999);
                Vector3 n = 0;
                Vector2 it = sphIntersect(ro, rd, spherePos, 1);
                if (it.x > 0 && it.x < minIt.x)
                {
                    minIt = it;
                    n = norm(ro - spherePos + rd * it.x);
                }
                Vector3 boxN = Vector3(0);
                Vector2 it2 = boxIntersection(ro, rd, Vector3(1), boxN);
                if (it2.x > 0 && it2.x < minIt.x)
                {
                    minIt = it2;
                    n = boxN;
                }
                diff = dot(n, light);
                int col = 0;
                if (minIt.x < 99999)
                {
                    diff = diff * 0.5 + 0.5;
                    col = (int)(diff * 20.0);
                }
                if (col < 0) col = 0;
                if (col > 19) col = 19;
                screen[i + j * width] = gradient[col];
            }
        }
        printf("%s", screen);
    }
   getchar();
   return 0;
}

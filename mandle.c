#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

typedef float f;
f iterations, channel_offset, real, imaginary, temp, size = 60;
 
int v() 
{
    return (iterations > 999) ? 0 : 255u * (sin(0.04f * iterations + channel_offset++) / 2.000 + 0.500f);
}
 
void main() 
{
    for (f y = 0; y++ < size;)
    {
        for (f x = 0; x++ < size*2.00;)
        {
            channel_offset = 4;
            real = imaginary = iterations = 0;
            for (; real * real + imaginary * imaginary < 4 && iterations++ < 1000;)
            {
                temp      = real * real - imaginary * imaginary + x / .7  / size - 2.1;
                imaginary = real * imaginary * 2                + y / .35 / size - 1.4;
                real      = temp;
            }
            printf("%c[48;2;%d;%d;%dm ", 27, v(), v(), v());
        }
        
        puts("");
        usleep(60000);
    }
}

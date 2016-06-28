#include "gd.h"
#include <string.h>
int main(){
    gdImagePtr im;
    int black;
    int white;
    int brect[8];
    int x, y;
    char *err;

    char *s = "من جد وجد ومن زرع حصد"; /* String to draw. */
    double sz = 40.;
    char *f = "/home/khalid/dev/gd-draw-text/FreeMono.ttf";  /* User supplied font */

    /* obtain brect so that we can size the image */
    err = gdImageStringFT(NULL,&brect[0],0,f,sz,0.,0,0,s);
    if (err) {fprintf(stderr,err); return 1;}

    /* create an image big enough for the string plus a little whitespace */
    x = brect[2]-brect[6] + 6;
    y = brect[3]-brect[7] + 6;
    im = gdImageCreate(x,y);

    /* Background color (first allocated) */
    white = gdImageColorResolve(im, 255, 255, 255);
    black = gdImageColorResolve(im, 0, 0, 0);

    /* render the string, offset origin to center string*/
    /* note that we use top-left coordinate for adjustment
 * since gd origin is in top-left with y increasing downwards. */
    x = 3 - brect[6];
    y = 3 - brect[7];
    err = gdImageStringFT(im,&brect[0],black,f,sz,0.0,x,y,s);
    if (err) {fprintf(stderr,err); return 1;}
    /* ... Do something with the image, such as
saving it to a file... */
    FILE *fp;
    fp = fopen("name.png", "wb");
    if (!fp) {
        fprintf(stderr, "Can't save png image\n");
        return 0;
    }

    gdImagePng(im, fp);
    fclose(fp);
    /* Destroy it */
    gdImageDestroy(im);



}

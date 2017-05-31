#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include "armies.h"

#define BUFFER_SIZE 32767
int main(int argc, char **argv) {
    int army_w[NUM_ARMIES];
    int army_l[NUM_ARMIES];
    int army_d[NUM_ARMIES];
    memset(army_w, 0, sizeof(army_w));
    memset(army_l, 0, sizeof(army_l));
    memset(army_d, 0, sizeof(army_d));

    int ii = 0;
    int jj = 0;
    int kk = 0;

    for (ii = 0; ii < NUM_ARMIES; ii++) {
        for (jj = ii + 1; jj < NUM_ARMIES; jj++) {
            int ipts = 0;
            int jpts = 0;
            for (kk = 0; kk < 10; kk++) {
                if (armies[ii][kk] > armies[jj][kk]) {
                    ipts += kk + kk + 2;
                } else if (armies[ii][kk] < armies[jj][kk]) {
                    jpts += kk + kk + 2;
                } else {
                    ipts += kk + 1;
                    jpts += kk + 1;
                }
            }
            if (ipts > jpts) {
                army_w[ii]++;
                army_l[jj]++;
            } else if (ipts < jpts) {
                army_w[jj]++;
                army_l[ii]++;
            } else {
                army_d[ii]++;
                army_d[jj]++;
            }
        }
    }

    for (ii = 0; ii < NUM_ARMIES; ii++) {
        printf("Entry %4d %5d %5d %5d %.3f - %d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", ii, army_w[ii], army_l[ii], army_d[ii], (army_w[ii] + 0.5 * army_d[ii]) / (army_w[ii] + army_l[ii] + army_d[ii]), armies[ii][0], armies[ii][1], armies[ii][2], armies[ii][3], armies[ii][4], armies[ii][5], armies[ii][6], armies[ii][7], armies[ii][8], armies[ii][9] );
    }
}

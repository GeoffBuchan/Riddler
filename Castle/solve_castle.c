#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include "armies.h"

#define NUM_CASTLES 10
#define NUM_SOLDIERS 100

int main(int argc, char **argv) {
    int aa[NUM_CASTLES];
    int ii;
    int jj;
    int pts;
    int opts;
    int win;
    int tie;
    int max = 0;
    long long count = 0;

    for (aa[0] = 0; aa[0] < NUM_SOLDIERS; aa[0]++) {
        int arm = aa[0];
        printf("aa[0] = %d\n", aa[0]);
        for (aa[1] = 0; aa[1] + arm < NUM_SOLDIERS; aa[1]++) {
            printf(" aa[1] = %d\n", aa[1]);
            arm += aa[1];
            for (aa[2] = 0; aa[2] + arm < NUM_SOLDIERS; aa[2]++) {
                printf(" aa[2] = %d count %ld\n", aa[2], count);
                arm += aa[2];
                for (aa[3] = 0; aa[3] + arm < NUM_SOLDIERS; aa[3]++) {
                    arm += aa[3];
                    for (aa[4] = 0; aa[4] + arm < NUM_SOLDIERS; aa[4]++) {
                        arm += aa[4];
                        for (aa[5] = 0; aa[5] + arm < NUM_SOLDIERS; aa[5]++) {
                            arm += aa[5];
                            for (aa[6] = 0; aa[6] + arm < NUM_SOLDIERS; aa[6]++) {
                                arm += aa[6];
                                for (aa[7] = 0; aa[7] + arm < NUM_SOLDIERS; aa[7]++) {
                                    arm += aa[7];
                                    for (aa[8] = 0; aa[8] + arm < NUM_SOLDIERS; aa[8]++) {
                                        arm += aa[8];
                                        aa[9] = NUM_SOLDIERS - arm;
                                        count++;
                                        win = tie = 0;
                                        for (ii = 0; ii < NUM_ARMIES; ii++) {
                                            pts = opts = 0;
                                            for (jj = 0; jj < NUM_CASTLES; jj++) {
                                                if (armies[ii][jj] < aa[jj]) {
                                                    pts += jj + 1;
                                                } else if (armies[ii][jj] > aa[jj]) {
                                                    opts += jj + 1;
                                                }
                                            }
                                            if (pts > opts) {
                                                win++;
                                            } else if (pts == opts) {
                                                tie++;
                                            }
                                        }
                                        if (win + win + tie >= max) {
                                            max = win + win + tie;
                                            printf ("Best %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d has %4d win %3d tie\n", aa[0], aa[1], aa[2], aa[3], aa[4], aa[5], aa[6], aa[7], aa[8], aa[9], win, tie);
                                        }
                                        arm -= aa[8];
                                    }
                                    arm -=aa[7];
                                }
                                arm -= aa[6];
                            }
                            arm -= aa[5];
                        }
                        arm -= aa[4];
                    }
                    arm -= aa[3];
                }
                arm -= aa[2];
            }
            arm -= aa[1];
        }
    }

    printf ("Looped %ld times\n", count);
}

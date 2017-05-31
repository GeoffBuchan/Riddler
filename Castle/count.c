#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include "armies.h"

#define BUFFER_SIZE 32767
#define NUM_SOLDIERS 100
#define LOOP_SOLDIERS 101

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
    int ll = 0;
    int mm = 0;
    int nn = 0;
    int oo = 0;
    int pp = 0;
    int qq = 0;
    int rr = 0;
    long long count = 0;

    for (ii = 0; ii < LOOP_SOLDIERS; ii++) {
        int arm = ii;
        printf("ii = %d\n", ii);
        for (jj = 0; jj + arm < LOOP_SOLDIERS; jj++) {
            printf(" jj = %d\n", jj);
            arm += jj;
            for (kk = 0; kk + arm < LOOP_SOLDIERS; kk++) {
                printf(" kk = %d count %ld\n", kk, count);
                arm += kk;
                for (ll = 0; ll + arm < LOOP_SOLDIERS; ll++) {
                    arm += ll;
                    for (mm = 0; mm + arm < LOOP_SOLDIERS; mm++) {
                        arm += mm;
                        for (nn = 0; nn + arm < LOOP_SOLDIERS; nn++) {
                            arm += nn;
                            for (oo = 0; oo + arm < LOOP_SOLDIERS; oo++) {
                                arm += oo;
                                for (pp = 0; pp + arm < LOOP_SOLDIERS; pp++) {
                                    arm += pp;
                                    for (qq = 0; qq + arm < LOOP_SOLDIERS; qq++) {
                                        arm += qq;
                                        rr = 100 - arm;
                                        count++;
                                        arm -= qq;
                                    }
                                    arm -=pp;
                                }
                                arm -= oo;
                            }
                            arm -= nn;
                        }
                        arm -= mm;
                    }
                    arm -= ll;
                }
                arm -= kk;
            }
            arm -= jj;
        }
    }

    printf ("Looped %ld times\n", count);
}

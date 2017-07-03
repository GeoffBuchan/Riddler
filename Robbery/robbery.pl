#!/usr/bin/perl -w

use strict;
use Getopt::Long;

my $help;
my $num_houses = 1000;
my $trials = 100000;

my $stat = GetOptions( 'trials=i'      => \$trials
                     , 'help'          => \$help
                     , 'number=i'      => \$num_houses
                );

if ($help) {
    print STDERR "robbery.pl\n";
    print STDERR "Script estimate expected robbery values by position.\n";
    print STDERR "This is a roberry game where each house will randomly\n";
    print STDERR "steal all the money from another house in some order.\n";
    print STDERR "\n";
    print STDERR "-t --trials      How many trials to run (default $trials)\n";
    print STDERR "-n --number      Number of houses in the pool\n";
    print STDERR "-h --help        This help message\n";

    exit 1;
}

my $sum;

for my $t (1 .. $trials) {
    my @cash = map { 100; } (1 .. $num_houses);
    for my $thief ( 0 .. $num_houses - 1) {
        my $victim = int rand ($num_houses - 1);
        $victim++ if ($thief <= $victim);
        $cash[$thief] += $cash[$victim];
        $cash[$victim] = 0;
    }
    for my $s ( 0 .. $num_houses - 1) {
        $sum->[$s] += $cash[$s];
    }   
}

my $all_sum = 0;
for my $s (sort { $sum->[$b] <=> $sum->[$a] } ( 0 .. $num_houses - 1)) {
    printf "House %3s averages \$%.2f\n", $s, $sum->[$s] / $trials;
    $all_sum += $sum->[$s];
}

printf "Total average is \$%.2f\n", $all_sum / $trials;

#!/usr/bin/perl -w

use strict;
use Getopt::Long;

my $help;
my $prob = 0.5;
my $series = 4;
my $trials = 100000;

my $stat = GetOptions( 'trials=i'      => \$trials
                     , 'help'          => \$help
                     , 'probability=f' => \$prob
                     , 'series=i'      => \$series
                );

if ($help) {
    print STDERR "series.pl\n";
    print STDERR "Script to estimate how many games a series should last given a winning percentage.\n";
    print STDERR "\n";
    print STDERR "-t --trials      How many trials to run (default $trials)\n";
    print STDERR "-s --series      Number of games to win a series (default $series)\n";
    print STDERR "-h --help        This help message\n";
    print STDERR "-p --probability Odds of one team winning any game (default $prob)\n";

    exit 1;
}

my $sum_g = 0;

for my $t (1 .. $trials) {
    my ($a, $b) = (0, 0);

    my $g = 0;
    while ($a < $series && $b < $series) {
        if (rand() < $prob) {
            $a++;
        } else {
            $b++;
        }
        $g++;
    }
    $sum_g += $g;
}

printf "Series takes an average of %.3f games.\n", $sum_g / $trials;

#!/usr/bin/perl -w

use strict;
use Getopt::Long;

my $trials   = 1000;
my $verbose;
my $help;
my $file;

my $stat = GetOptions( 'trials=i'   => \$trials
                     , 'help'       => \$help
                     , 'file=s'     => \$file
                     , 'verbose'    => \$verbose
                );


open FILE, "<$file" or die "Unable to open $file!\n";

my @lines = <FILE>;
my $armies;
my $id = 1;
shift @lines;
for my $l (@lines) {
    my @cols = split /,/, $l;
    my @armies;
    for my $jj (0 .. 9) {
        $armies[$jj] = $cols[$jj];
    }
    $armies->{$id} = { armies => \@armies };
    $id++;
}

for my $k (keys %{$armies}) {
    $armies->{$k}{wins}  = 0 if (!$armies->{$k}{wins});
    $armies->{$k}{loss}  = 0 if (!$armies->{$k}{loss});
    $armies->{$k}{draws} = 0 if (!$armies->{$k}{draws});
    for my $j (keys %{$armies}) {
        if ($k < $j) {
            my $kpts = 0;
            my $jpts = 0;

            for my $jj (0 .. 9) {
                my $pts = $jj + 1;
                if ($armies->{$j}{armies}[$jj] > $armies->{$k}{armies}[$jj]) {
                    $jpts += $pts + $pts;
                } elsif ($armies->{$j}{armies}[$jj] < $armies->{$k}{armies}[$jj]) {
                    $kpts += $pts + $pts;
                } else {
                    $kpts += $pts;
                    $jpts += $pts;
                }
            }
            if ($kpts > $jpts) {
                $armies->{$j}{loss}++;
                $armies->{$k}{wins}++;
            } elsif ($kpts < $jpts) {
                $armies->{$j}{wins}++;
                $armies->{$k}{loss}++;
            } else {
                $armies->{$j}{draws}++;
                $armies->{$k}{draws}++;
            }
        }
    }
}

my $sum;
#for my $k (sort { $armies->{$b}{wins} + $armies->{$b}{draws} / 2 <=> $armies->{$a}{wins} + $armies->{$a}{draws} / 2 } keys %{$armies}) {
for my $k (keys %{$armies}) {
    printf "Entry %4d %5d %5d %5d %.3f %s\n", $k, $armies->{$k}{wins}, $armies->{$k}{loss}, $armies->{$k}{draws}, ($armies->{$k}{wins} + $armies->{$k}{draws} / 2) / ($armies->{$k}{draws} + $armies->{$k}{wins} + $armies->{$k}{loss}), join ',', @{$armies->{$k}{armies}};
    $sum->{w} +=  $armies->{$k}{wins};
    $sum->{l} +=  $armies->{$k}{loss};
    $sum->{d} +=  $armies->{$k}{draws};
}

print "$sum->{w} $sum->{l} $sum->{d}\n";

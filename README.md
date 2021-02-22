# Deblur
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 2 2020.11, Conda 4.9.2

Qiime2 deblur algorithm (Bolyen et al, 2019).

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
inputfile: Sequences, typically already filtered
trimlength: Length to use for trimming sequences

The plugin produces as output three files, each in QZA format and beginning with the user-specified output prefix:

prefix-deblur-stats.qza: Statistics
prefix-table.qza: Table of sequences
prefix-rep-seqs.qza: Sequences after trimming



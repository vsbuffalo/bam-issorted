# `issorted` -- Simple Check if a BAM File is Truly Sorted

`issorted` simply checks whether a BAM file is sorted by comparing each
alinement's position to the last. Normally, sorting information is kept in the
BAM header, but this is a more robust test of whether a file is sorted. It
might be useful to others, so I'm throwing it on Github.

To clone, be sure to use the `--recursive` option. To build, simply enter
`make` at the command line.

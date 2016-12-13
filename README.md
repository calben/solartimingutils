# solartimingutils
Sunrise and sunset time calculation utils in C

## Documentation

The documentation for this code can be found here: http://calben.github.io/solartimingutils/
Since this is a rather small library, the documentation isn't much!

## Compiling and Testing

I use the following to compile and test:

    gcc testsolarutils.c solarutils.c --std=c11 -lm -o testsolarutils.out
    ./testsolarutils.out
    
If the utility ends up becoming larger I may implement proper unit testing and continuous integration.
    

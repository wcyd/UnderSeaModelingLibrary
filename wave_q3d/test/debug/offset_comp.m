%
% offset_comp - compute offsets
%

A1 = [ 3.80206e+06  18110.8 -3.24185e-14 ; ...
           18110.8 -99.9788            0 ; ...
      -3.24185e-14        0          446 ] ;
g1 = [ -1477.11 ; -10399.8 ; 0 ] ;
o1 = [ -0.26619 ; 55.8006 ; -1.93486e-17 ] ;
r1 = A1 \ g1 

A2 = [ 3.98549e+06 -244.03 3.29736e-14 ; ...
           -244.03 318.089           0 ; ...
       3.29736e-14       0      467.25 ] ;
g2 = [ 1688.07 ; 293.787 ; 0 ] ;
o2 = [ 0.000480129 ; 0.923968 ; -3.38825e-20 ] ;
r2 = A2 \ g2

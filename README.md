Julia: 2D shader fractals
=====

Because any self-respecting "graphics enthusiast" needs to write a fractal viewer at least once.
--------

This is a super-compact C and GLSL Julia set viewer. The
Julia set `c` is the set of points `x` in the complex plane such that `f(x) =
z^2 - c` converges to zero. `julia` changes the value of `c` over time, which is
what creates the animation; the real and imaginary parts of `c` are sinusoids
with relatively prime periods, so you should be able to watch it for a _long_
time before you see it repeat.

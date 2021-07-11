# pipex

![img](https://github.com/kotabrog/ft_mini_ls/blob/main/img/sample.png)

## Overview

I made a program to draw fractal shapes in C language.

## Usage

```
git clone https://github.com/kotabrog/fract-ol.git
cd fract-ol
make
```

fractol accepts parameters as follows.
```
./fractol [type] [param]
```

## type list

### m (mandelbrot)
The Mandelbrot set is given as the set of points C that converge with the following asymptotic formula.  
```
z_0 = 0, z_n+1 = (z_n)^2 + c
```
example:
```
./fractol m
```

### n (mandelbrot2)
change the squared to the kth power.
```
z_0 = 0, z_n+1 = (z_n)^k + c
```
example:
```
./fractol n 3
```

### j (julia)

![img](https://github.com/kotabrog/ft_mini_ls/blob/main/img/sample.png)

```
param: [a(double)] [b(double)]
```

The Julia set is given as the set of points z_0 that converge with the following asymptotic formula.
```
z_n+1 = (z_n)^2 + c, c = a + bi
```
example: 
```
./fractol j 0.1 0.4
```
If you don't specify a or b,
the default values will be applied. (a = 0.3, b = 0.2)

- k (julia2)
change the squared to the kth power.
```
z_n+1 = (z_n)^k + c, c = a + bi
```
example:
```
./fractol k 0.1 0.4 3
```

## Author

[twiter](https://twitter.com/Kotabrog)

## Licence

[MIT](https://github.com/kotabrog/fract-ol/blob/main/LICENSE)

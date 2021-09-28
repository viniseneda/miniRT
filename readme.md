# miniRT
My miniRT implementation for 42 school São Paulo. 

## .rt file usage:

#### resolution:

```R 400 600"```

#### ambient light: 
```A 0.5 255,255,255```

ratio - color
#### camera: 

```C 0,0,-5 0,0,1 90```

position - orientation vector - viewing angle

#### point light:
```l 0,-10,10 0.5 255,255,255```

position - intensity - color

#### sphere: 
```sp 0,0,0 2 100,255,50```

position - radius - color

```sp 0,0,0 2 (0,200,200 0.8 0.3)```

it is possible to specify the difuse and specular properties of the material if wanted

#### cylinder: 
```cy 0,0,0 0,0,1 2 3 100,255,50```

position - orientation vector - radius - height - color/material

```cy c 0,0,0 0,0,1 2 3 100,255,50```

by adding a 'c' after the 'cy', the ray tracer will add a cap to the ends of the shape

```cy 0,0,0 0,0,1 (0 5) 2 3 100,255,50```

it is possible to tweak the min and max cylinder height. But it should affect the resulting total height, as it is composed of a transformation of a 1 unit height cylinder.

#### cone: 
```co 0,0,0 0,0,1 (0 5) 2 3 100,255,50```

the cone has almost the same properties as the cylinder (with the exception of the caps).
But in this case the tweaking of the min and max is highly recomended, as it allows for more interesting shapes.

#### plane: 
```pl 0,0,0 0,0,1 100,255,50```

position - orientation vector - color/material

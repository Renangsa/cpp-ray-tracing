# Assets Definitions

This is a definition of how each asset should be defined in the scene files

## Scene

The scene should have every object to be render, including cameras and lights. If the scene has more than one camera, all of them will be rendered.

To define a object, first write the object type (all lowercase), followed by its definition on the next line.

```javascript
<object_type>
[...definition...]
```

Some objects, can be defined in an outside file. But not all of them, it will be specified in the object description.

```javascript
<object_type>
file: <file_path>
```

## Camera Object Types

### Camera

The camera defines the position in the scene where the render will happen. Multiple cameras will result in multiple renders.

> Can be defined separately

```javascript
name

cx cy cz 	// (cx, cy, cz): center point
tx ty tz 	// (tx, ty, tz): target point
ux uy uz 	// [ux, uy, uz]: up direction vector

distance
height
width
```

## Object Types

### Sphere

```javascript
cx cy cz 	// (cx, cy, cz): center point
radius
R G B 		// (R, G, B): color [normalized]
```

### Plane

```javascript
cx cy cz	// (cx, cy, cz): center point
nx ny nz	// [nx, ny, nz]: normal vector
R G B		// <RGB>: color [normalized]
```

### Rect

```javascript
cx cy cz	// (cx, cy, cz): center point
nx ny nz	// [nx, ny, nz]: normal vector
size
R G B		// <RGB>: color [normalized]
```

### Triangle

```javascript
px py pz	// (px, py, pz): first vertice point
qx qy qz	// (qx, qy, qz): second vertice point
rx ry rz	// (rx, ry, rz): third vertice point
R G B
```

<!--
```javascript

```
-->

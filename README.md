# Scalar Triple Product

The Scalar Triple Product is a ternary operation that takes three vectors and returns a scalar.

Given vectors __x__, __y__, and __z__, the scalar triple product is \[__x__, __y__, __z__\] = (__x__ &times; __y__) &middot; __z__.

Because of the antisymmetry of the cross product, it then follows that \[__x__, __y__, __z__\] = (__x__ &times; __y__) &middot; __z__ = -(__y__ &times; __x__) &middot; __z__ = -\[__y__, __x__, __z__\]. In particular, any even permutation of the input vectors is equal, while any odd permutation is negated.

The geometric interpretation of the scalar triple product is that it is the volume of the parallelepiped with edges __x__, __y__, and __z__.  This is because \[__x__, __y__, __z__\] = (__x__ &times; __y__) &middot; __z__ = ||__x__ &times; __y__||||__z__||cos(&theta;). From before, ||__x__ &times; __y__|| is the area of the parallelogram with edges __x__ and __y__. Now since &theta; is the angle betwee __z__ and __x__ &times; __y__, then ||__z__||cos(&theta;) is the height of the parallelepiped. Then ||__x__ &times; __y__||||__z__||cos(&theta;) is the base of the parallelepiped times the height, and hence is the volume.

# Setup

You will need to have CMake installed on your computer, and properly added to your path.  In order to setup, run the following in a shell, then open the project in your preferred editor. Windows has been configured for use with Visual Studio.

Windows:
```
cd path/to/folder
setup.cmd
```
Linux:
```
cd path/to/folder
./setup
```

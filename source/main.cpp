/*
Title: Projection and Rejection
File Name: main.cpp
Copyright © 2016
Author: Andrew Litfin
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// The bread and butter of games programming is vector mathematics and linear algebra.
// The vast majority of the mathematics used in games falls under this category,
//  though it is not the only math used (e.g. discrete math, calculus).
// This tutorial series will take you through the basics of vector math.
// Future tutorials in this series will detail other aspects of linear algebra, particularly matrices.
// The exposition follows that of "Foundations of Game Engine Development" (Volume 1),
//  by Eric Lengyel.
// This file provides exposition, definitions, and explanations, and all other files implement vector classes
//  as you would see them in most game engines. The implementations are modeled after those of Eric Lengyel
//  in FGED, Volume 1 and the Tombstone Engine, though they are my own.
// Only Vector2D.h is heavily annotated, the others are mostly identical.

// This tutorial explains the scalar triple product.
// It is not necessary, but is still useful to know.

#include "../header/helpers.h"
#include "../header/Vector2D.h"
#include "../header/Vector3D.h"
#include "../header/Vector4D.h"

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// Required for the random functions in helpers to work.
	srand(static_cast<unsigned>(time(0)));
	// Shorten the precision of floating point output for ease of reading.
	std::cout.precision(4);

	// Scalar Triple Product
	// ---------------------
	{
		// The scalar triple product is an odd one out, but it is useful.
		// It relies on the cross product, and so is only defined when the cross product is defined, which for our purposes is only in 3D.

		// Denoted [a, b, c], it is equal to Dot(Cross(a, b), c) = Dot(Cross(b, c), a) = Dot(Cross(c, a), b)
		// The three are equal, as can be shown by expansion.
		// Hence [a, b, c] = [b, c, a] = [c, a, b]
		// Say instead we have [c, b, a].
		// Then [c, b, a] = Dot(Cross(c, b), a) = Dot(Cross(b, a), c) = Dot(-Cross(a, b), c) = -[a, b, c].
		// Hence the scalar triple product has a kind of anticommutativity, in that even permutations are equal but odd permutations are negated.

		// To see how it is equal to the (signed) volume of the parellelepiped with sides a, b, and c, consider the following:
		// For brevity, let a*b := Cross(a, b), a.b := Dot(a, b), and |a| := Magnitude(a)
		// Then [a, b, c] = (a*b).c = |a*b||c|cos(theta). From before, we know that |a*b| is the area of the parallelogram spanned by a and b.
		// Since theta is the angle between a*b and c, there exists a complementary angle phi between c and the parallelogram spanned by a and b.
		// Then the height of the parallelepiped is equal to |c|sin(phi). Since phi and theta are complementary, sin(phi) = cos(theta).
		// Hence [a, b, c] = |a*b||c|sin(phi), which is equal to the area of the base of the parallelepiped times its height.
		// Therefore [a, b, c] is the volume of the parallelepiped.

		Vector3D a(1, 0, 0);
		Vector3D b(0, 1, 0);
		Vector3D c(0, 0, 1);

		if (ScalarTriple(a, b, c) == 1.0f)
		{
			std::cout << "The volume of the unit cube is 1.\n";
		}

		// Note that a property of parallelepipeds is that the angle doesn't matter, if the height remains the same, so does the volume.
		// So c can have any x and y values we want, but so long as it has a z value of 1, the volume will still be 1.
		for (int i = 0; i < 10; i++)
		{
			c = Vector3D(randFloat(-10, 10), randFloat(-10, 10), 1);
			if (ScalarTriple(a, b, c) - 1.0f < FLT_EPSILON)
			{
				std::cout << "c = " << c << ", yet volume is still 1.\n";
			}
		}

		// In particular, the all vectors c such that comp_(a*b)(c) is constant all define equal-volume parallelepipeds.
		// For example:
		a = Vector3D(randFloat(-1, 1), randFloat(-1, 1), randFloat(-1, 1));
		b = Vector3D(randFloat(-1, 1), randFloat(-1, 1), randFloat(-1, 1));
		c = Vector3D(randFloat(-1, 1), randFloat(-1, 1), randFloat(-1, 1));
		// a, b, and c are now arbitrary vectors.
		Vector3D aCrossb = Cross(a, b);
		float volume = Dot(aCrossb, c);
		std::cout << "a = " << a << ", b = " << b << ", and c = " << c
			<< "\n giving Cross(a, b) = " << aCrossb << " and volume = " << volume << "\n";

		Vector3D cprime;
		// Now, a and b form basis vectors for the plane from which we can select any c and retain constant volume!
		for (int i = 0; i < 10; i++)
		{
			cprime = c + randFloat(-1, 1) * a + randFloat(-1, 1) * b;
			if (ScalarTriple(a, b, cprime) - volume < FLT_EPSILON)
			{
				std::cout << "cprime = " << cprime << ", yet volume is still " << volume << ".\n";
			}
		}
	}

	// As a post-script, two notes:
	// 1) If you ever do graphics and calculate Dot(n, L), you are actually taking a scalar triple product!
	// 2) Although this formulation relies on the cross product,
	//    there are alternate algebraic systems in which this idea of volumes of parallelepipeds can be extended to any dimension.
	//    However, such systems will not be introduced for some time.

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}

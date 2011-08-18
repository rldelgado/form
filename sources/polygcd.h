#pragma once
/* #[ License : */
/*
 *   Copyright (C) 1984-2010 J.A.M. Vermaseren
 *   When using this file you are requested to refer to the publication
 *   J.A.M.Vermaseren "New features of FORM" math-ph/0010025
 *   This is considered a matter of courtesy as the development was paid
 *   for by FOM the Dutch physics granting agency and we would like to
 *   be able to track its scientific use to convince FOM of its value
 *   for the community.
 *
 *   This file is part of FORM.
 *
 *   FORM is free software: you can redistribute it and/or modify it under the
 *   terms of the GNU General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your option) any later
 *   version.
 *
 *   FORM is distributed in the hope that it will be useful, but WITHOUT ANY
 *   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *   details.
 *
 *   You should have received a copy of the GNU General Public License along
 *   with FORM.  If not, see <http://www.gnu.org/licenses/>.
 */
/* #] License : */ 

#include <vector>

class poly; // polynomial class
class gcd_heuristic_failed {}; // class for throwing exceptions

// whether or not to use the heuristic before Zippel's algorithm
#define USE_GCD_HEURISTIC

// whether or not to use a heuristic check whether using the heuristic
// seems possible (saves time for too large polynomials, but costs
// time for small ones, so for Mincer it's better to turn it off)
//#define USE_GCD_HEURISTIC_POSSIBLE

// maximum number of words in a coefficient for gcd_heuristic to continue
const int GCD_HEURISTIC_MAX_DIGITS = 1000;

// maximum number of retries after the heuristic has failed
const int GCD_HEURISTIC_MAX_TRIES = 10;

// a fudge factor, which improves efficiency
const int GCD_HEURISTIC_MAX_ADD_RANDOM = 10;

// outside of the namespace, because these are called from C
int DoGCDfunction(PHEAD WORD *argin, WORD *argout);
WORD *DoPolyGCD(PHEAD WORD *a, WORD *b);

namespace poly_gcd {

	// functions to call the gcd routines
	const poly integer_gcd (const poly &a, const poly &b);
	const poly integer_content (const poly &a);
	
	const poly gcd (const poly &a, const poly &b);
	const poly content_univar (const poly &a, int x);
	const poly content_multivar (const poly &a, int x);

	const std::vector<WORD> coefficient_list_gcd (const std::vector<WORD> &a, const std::vector<WORD> &b, WORD p);

	// internal functions
	const poly gcd_heuristic (const poly &a, const poly &b, const std::vector<int> &x, int max_tries=GCD_HEURISTIC_MAX_TRIES);
	const poly gcd_Euclidean (const poly &a, const poly &b);
	const poly gcd_modular (const poly &a, const poly &b, const std::vector<int> &x);
	const poly gcd_modular_dense_interpolation (const poly &a, const poly &b, const std::vector<int> &x, const poly &correctlc, const poly &shape);
	const poly gcd_modular_sparse_interpolation (const poly &a, const poly &b, const std::vector<int> &x, const poly &lc, const poly &shape);
	
	const poly chinese_remainder (const poly &a1, const poly &m1, const poly &a2, const poly &m2);
	const poly substitute_last(const poly &a, int x, int c);
	const poly substitute_all(const poly &a, const std::vector<int> &x, const std::vector<int> &c);
}


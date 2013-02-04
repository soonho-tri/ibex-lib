//============================================================================
//                                  I B E X                                   
// File        : ibex_SetImage.cpp
// Author      : Gilles Chabert
// Copyright   : Ecole des Mines de Nantes (France)
// License     : See the LICENSE file
// Created     : Nov 27, 2012
// Last Update : Nov 27, 2012
//============================================================================

#include "ibex_SetImage.h"
#include "ibex_PdcImageSubset.h"
#include "ibex_LargestFirst.h"

using namespace std;

namespace ibex {

SetImage::SetImage(Function& f, Ctc& c_out, Pdc& p_in) : f(f), n(f.nb_var()), c_out(c_out), p_in(p_in) {
	assert(f.image_dim()==n);
}

void SetImage::pave(const IntervalVector& x, double epsilon) {

	Linside.clear();
	Lboundary.clear();

	PdcImageSubset p_fin(f,x,p_in);

	assert(x.size()==n);

	stack<IntervalVector> Ldomain;
	IntervalVector xtilde(n);
	IntervalVector ytilde(n);
	LargestFirst lf;

	Ldomain.push(x);
	while (! Ldomain.empty()) {
		xtilde = Ldomain.top();
		Ldomain.pop();
		try {
			c_out.contract(xtilde);
		} catch(EmptyBoxException &) {
			continue;
		}

		// use natural extension
		ytilde=f.eval_vector(xtilde);
		// improve with centered form
		ytilde&=f.eval_vector(xtilde.mid())+f.jacobian(xtilde)*(xtilde-xtilde.mid());
		if (p_in.test(xtilde)==YES && p_fin.test(cart_prod(xtilde,ytilde))==YES)
			Linside.push_back(ytilde);
		else if (xtilde.max_diam()<=epsilon)
			Lboundary.push_back(ytilde);
		else  {
			pair<IntervalVector,IntervalVector> boxes=lf.bisect(xtilde);
			Ldomain.push(boxes.first);
			Ldomain.push(boxes.second);
		}
	}
}


} // end namespace ibex
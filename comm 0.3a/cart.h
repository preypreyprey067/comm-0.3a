#ifndef __cart__
#define __cart__

#include "product.h"

class cart {
public:
	void add(const product& prd, float kgamt) {
		mtotal += prd.price() * kgamt;
	}

	float total() const{
		return mtotal;
	}

	void reset() {
		mtotal = 0;
	}

private:
	float mtotal = 0.00f;
};

#endif
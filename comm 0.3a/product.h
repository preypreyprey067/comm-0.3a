#ifndef __product__
#define __product__

#include <string>
#include <iostream>

class product {
public:
	using name_type = std::string;
	using price_type = float;

	explicit product(name_type name = "", price_type price = 0.00f) {
		info.name = name;
		info.price = price;
	}

	name_type name() const{
		return info.name;
	}

	name_type name(name_type newval) {
		name_type oldname = info.name;
		info.name = newval;
		return oldname;
	}

	price_type price() const {
		return info.price;
	}

	price_type price(price_type newval) {
		price_type oldprice = info.price;
		info.price = newval;
		return oldprice;
	}

	friend std::ostream& operator<<(std::ostream&, product);

private:
	struct {
		std::string name ;
		float price = 0.00f;
	} info;
};

std::ostream& operator<<(std::ostream& x, product y) {
	return x << y.name() << ", " << y.price();
}

#endif
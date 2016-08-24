/*
 * hour_glass_facade.h
 *
 *  Created on: 06.08.2016
 *      Author: vp
 */

#ifndef INT_SORTER_FACADE_H_
#define INT_SORTER_FACADE_H_

#include "hour_glass_worker.h"

struct IntSorterFacade {
private:
	sorter_t sorter = nullptr;

public:
	IntSorterFacade() {
		sorter = sorter_new();
	}
	virtual ~IntSorterFacade() {
		sorter_cleanup(sorter);
	}

	int get() {
		return sorter_get(sorter);
	}

	void put(const int& i) {
		sorter_put(sorter, i);
	}
};


#endif /* INT_SORTER_FACADE_H_ */

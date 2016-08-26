/*
 * hour_glass_facade.h
 *
 *  Created on: 06.08.2016
 *      Author: vp
 */

#ifndef INT_SORTER_FACADE_H_
#define INT_SORTER_FACADE_H_

#include "hour_glass_worker.h"
#include <memory>

struct IntSorterFacade {
	int get() {
		return sorter_get(sorter.get());
	}

	void put(const int& i) {
		sorter_put(sorter.get(), i);
	}

private:
	std::unique_ptr<IntSorter, void (*)(IntSorter *)> sorter{sorter_new(), sorter_cleanup};
};


#endif /* INT_SORTER_FACADE_H_ */

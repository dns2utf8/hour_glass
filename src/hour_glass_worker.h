/*
 * hour_glass_worker.h
 *
 *  Created on: 06.08.2016
 *      Author: Stefan Schindler
 */

#ifndef HOUR_GLASS_WORKER_H_
#define HOUR_GLASS_WORKER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IntSorter * sorter_t;

sorter_t sorter_new();
void sorter_cleanup(sorter_t sorter);
void sorter_put(sorter_t sorter, int e);
int sorter_get(sorter_t sorter);

#ifdef __cplusplus
}
#endif

#endif /* HOUR_GLASS_WORKER_H_ */

/*
 * row.h
 *
 *  Created on: 25 oct. 2018
 *      Author: Serah
 */

#pragma once

#include<vector>

#include "brick.h"


#ifndef ROW_H_
#define ROW_H_

class row_t
{

	private:

		std::vector<brick_t> row_;

	public:

		row_t();
		row_t(std::vector<int> v);
		virtual ~row_t();

		int get_size();
		int get_val(int inx);
		void push_back(brick_t a);
};

std::ostream &operator<<(std::ostream &os, row_t& row);

#endif /* ROW_H_ */

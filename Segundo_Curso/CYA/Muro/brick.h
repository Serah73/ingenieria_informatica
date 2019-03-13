/*
 * brick.h
 *
 *  Created on: 25 oct. 2018
 *      Author: Serah
 */

#ifndef BRICK_H_
#define BRICK_H_

#pragma once

#include <iostream>
#include <ostream>


class brick_t
{
	private:

		int width_;

	public:

		brick_t();
		brick_t(int width);
		virtual ~brick_t();

		int get();
		void set(int width);
};

std::ostream &operator<<(std::ostream &os, brick_t& brick);

#endif /* BRICK_H_ */

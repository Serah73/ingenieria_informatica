#pragma once

#include "car.hpp"

#include<vector>
#include<iostream>

void car_t::check_ut(int width, int height, std::vector<int> v)
{
    if(check(width, height, north() ) ) v.push_back(north() );
    if(check(width, height, south() ) ) v.push_back(south() );
    if(check(width, height, west() ) ) v.push_back(west() ) ;
    if(check(width, height, east() ) ) v.push_back(east() ) ;
}
#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>
#include <limits>
#include <algorithm>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
    merge_sort(0, size() - 1);
    
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}

/*

    static int contador
*/

void sorted_vector_t::merge_sort(int l, int r)
{
    if (l < r) {
        
        int c = (l + r) / 2;

        merge_sort(l, c);

        merge_sort(c + 1, r);

        count++;

        merge(l, c, r);    
    }
    
}


int sorted_vector_t::get_count(void) const
{
    return count;
}




////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v)
{
    const int size = r - l + 1;
    const int sentinel = numeric_limits<int>::max(); 

    v.resize(size);

    for(int i = 0; i < size; i++, l++)
        v.at(i) = at(l);

    v.push_back(sentinel);
    
}

void sorted_vector_t::merge(int l, int c, int d)
{
    vector<int> left_v;
    vector<int> right_v;

    create_vector_sentinel(l, c, left_v);
    create_vector_sentinel(c + 1, d, right_v);

    const int size = d - l + 1;

    int l_inx = 0;
    int r_inx = 0;

    for(int i = 0; i < size; i++)

        if (left_v.at(l_inx) < right_v.at(r_inx))

            at(l + i) = left_v.at(l_inx++);

        else

            at(l + i) = right_v.at(r_inx++);

}


////////////////////////////////////////////////////////////////////////////

}


ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}

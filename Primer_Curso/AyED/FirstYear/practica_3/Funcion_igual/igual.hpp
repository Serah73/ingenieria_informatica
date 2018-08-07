bool igual(matrix_item_t a, matrix_item_t b, double precision)
{
	if(fabs(a-b)<precision)
		return(true);
	else{
		return(false);
	}
}
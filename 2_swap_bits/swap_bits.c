unsigned char   swap_bits(unsigned char octet)
{
	unsigned char o1;
	unsigned char o2;

	o1 = octet >> 4;
	o2 = octet << 4;
	return(o1 | o2);
}

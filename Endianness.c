/* Returns 1 if the machine is little-endian, 0 if the 
 * machine is big-endian
 */

int Endianness(void)
{
	union {
		int theInteger;
		char singleByte;
	} endianTest;

	endianTest, theInteger = 1;
	return endianTest.singleByte;
}
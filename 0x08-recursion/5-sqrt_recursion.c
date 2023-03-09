#include "main.h"
int find_sqrt (int num, int root);
int _sqrt_recursion(int n);

/**
 * find_sqrt - Finds the natural square root of an inputted number
 * @num: Thenumber to find the square root of
 * @root: The root to be tested.
 *
 * Return: If the number has a natural square root - the square root.
 * If the number diesn't have a natural sqaure root --1.
 */
int find_sqrt(int num, int root)
{
	if((root * root) == num)
		return (root);

	if(root == num / 2)
		return (-1);

	return (find_sqrt(num, root + 1));
}

/**
 * _sqrt_recursion - Returns the natural sqaure root of a number.
 * @n: Th number to return the sqaure root of.
 *
 * Return: If n has a natural square root - the natural square root of n.
 * If n does not have a natural square root --1
 */

int _sqrt_recursion(int n)
{
	int root = 0;

	if(n<0)
	   return (-1);
	if(n==1)
	   return(1);
	return(find_sqrt(n, root));
}

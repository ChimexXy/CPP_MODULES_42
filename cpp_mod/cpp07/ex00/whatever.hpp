#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename tamp> void swap(tamp& a, tamp& b)
{
	tamp c;

	c = a;
	a = b;
	b = c;
}

template <typename tamp> tamp    min(tamp const& a, tamp const& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename tamp> tamp    max(tamp const& a, tamp const& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
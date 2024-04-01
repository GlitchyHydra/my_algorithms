#pragma once

#include <iterator>
#include <assert.h>

#include <vector>

namespace gts
{

	//expiremental size of array when insertion sort
	//can give the most effective boost
	//result from research is 17
	//round to nearest 2^n => 2^4 = 16 almost equal 17
#define THRESHOLD 16

	template <typename T>
	using Compare = bool(*)(const T& a, const T& b);

	template<typename T>
	void swap(T& a, T& b)
	{
		T tmp = std::move(a);
		a = std::move(b);
		b = std::move(tmp);
	}

	template <typename T, typename Compare>
	bool is_sorted(T begin, T end, Compare comp)
	{
		if (begin == end) return true;
		T next = begin;
		while (++next != end)
		{
			if (comp(*next, *begin))
				return false;
			++begin;
		}
		return true;
	}

	template <typename T, typename Compare>
	void insertion_sort(T begin, T end, Compare comp)
	{
		if (begin >= end)
		{
			return;
		}

		for (T iter_i = begin + 1; iter_i < end; ++iter_i)
		{
			auto tmp = *iter_i;
			T iter_j = iter_i;

			for (; iter_j > begin && comp(tmp, *(iter_j - 1)); iter_j--)
			{
				*(iter_j) = *(iter_j - 1);
			}
				
			*(iter_j) = tmp;
		}
	}

	template <typename T, typename Compare>
	auto get_pivot(T begin, T end, Compare comp)
	{
		T middle = begin;
		//index of median element in whole array
		middle += (end - begin) / 2;

		if (comp(*begin, *middle))
		{
			if (comp(*middle, *end))
				return *middle;
			else if (comp(*begin, *end))
				return *end;
			else
				return *begin;
		}
		else
		{
			if (comp(*begin, *end))
				return *begin;
			else if (comp(*middle, *end))
				return *end;
			else
				return *middle;
		}
	}

	template<typename T, typename Compare>
	T partition(T begin, T end, Compare comp)
	{
		auto pivot = gts::get_pivot(begin, end, comp);

		for (; begin != end + 1; begin++, end--)
		{
			//move left index
			for (; comp(*begin, pivot); ++begin);
			//move right index
			for (; comp(pivot, *end); --end);
			//end if left > right
			if (begin == end || begin == end + 1)
				return end;

			swap(*begin, *end);
		}
		return end;
	}

	template<typename T, typename Compare>
	void qsort_not_opt(T begin, T end, Compare comp)
	{
		if (end - begin <= 1)
			return;

		T pivot = gts::partition(begin, end - 1, comp) + 1;
		gts::qsort_not_opt(begin, pivot, comp);
		gts::qsort_not_opt(pivot, end, comp);
	}

	/*
	* procedure quickSort( var a : array T; p, r : Int )
      implements sort(a, p, r)
      while r − p > 1 do
      val i := any value from {p, ..r}
      val x := a(i)
      var q
      partition( a, p, r, x, q )
      if q − p < r − q − 1 then
      quickSort( a, p, q )
      p := q + 1
      else
      quickSort( a, q + 1, r )
      r := q
      end if
      end while
      end quickSort
	*/

	template <typename T, typename Compare>
	void qsort(T begin, T end, Compare comp)
	{
		while (end - begin > 1)
		{
			if (end - begin <= THRESHOLD)
			{
				gts::insertion_sort(begin, end, comp);
				break;
			}

			T middle = gts::partition(begin, end - 1, comp) + 1;

			if (middle - begin < end - middle)
			{
				qsort(begin, middle, comp);
				begin = middle;
			}
			else
			{
				qsort(middle, end, comp);
				end = middle;
			}
		}
	}

}
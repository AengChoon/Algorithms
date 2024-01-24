#pragma once
#include <set>

void MergeSort(const auto InBegin, const auto InEnd)
{
	for (ptrdiff_t Iteration = 0; Iteration < InEnd - InBegin; ++Iteration)
	{
		for (auto CurrentIterator = InBegin; CurrentIterator < InEnd - Iteration; ++CurrentIterator)
		{
			auto NextIterator = CurrentIterator + 1;
			if (NextIterator >= InEnd) { continue; }

			auto& CurrentValue = *CurrentIterator;
			auto& NextValue = *NextIterator;

			if (CurrentValue > NextValue)
			{
				std::swap(CurrentValue, NextValue);
			}
		}
	}
}

#pragma once
#include <cstddef>
#include <string_view>

void SelectionSort(const auto InBegin, const auto InEnd)
{
	for (ptrdiff_t IterationCount = 0; IterationCount < InEnd - InBegin; ++IterationCount)
	{
		auto* SourceAddress = InBegin + IterationCount; 
		auto& Source = *SourceAddress;

		auto* TargetAddress = SourceAddress;
		for (auto* DestinationAddress = SourceAddress + 1; DestinationAddress < InEnd; ++DestinationAddress)
		{
			auto& Destination = *DestinationAddress;

			if (*TargetAddress > Destination)
			{
				TargetAddress = DestinationAddress;
			}
		}
		std::swap(Source, *TargetAddress);
	}
}

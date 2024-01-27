#pragma once
#include <set>

/**
 * @brief
 * https://en.wikipedia.org/wiki/Bubble_sort\n
 * 평균 시간 복잡도 : O(N^2)\n
 * 최악 시간 복잡도 : O(N^2)\n
 * 메모리 복잡도 : O(1)\n
 * 안정성 : O
 *
 * @param InBegin 정렬을 진행할 데이터의 시작 주소(std::begin)
 * @param InEnd 정렬을 진행할 데이터의 끝 주소(std::end)
 */
void BubbleSort(auto* const InBegin, auto* const InEnd)
{
	// 요소의 개수만큼 반복
	for (ptrdiff_t Iteration = 0; Iteration < InEnd - InBegin; ++Iteration)
	{
		// 첫 번째 요소부터 시작
		for (auto* CurrentIterator = InBegin; CurrentIterator < InEnd - Iteration; ++CurrentIterator)
		{
			// 현재 타겟 요소의 다음 요소 주소
			auto NextIterator = CurrentIterator + 1;
			if (NextIterator >= InEnd) { break; }

			auto& CurrentValue = *CurrentIterator;
			auto& NextValue = *NextIterator;

			// 현재 타겟 요소의 값과 다음 요소의 값을 비교
			if (CurrentValue > NextValue)
			{
				// 정렬 기준에 부합하면 swap
				std::swap(CurrentValue, NextValue);
			}
		}
	}
}
